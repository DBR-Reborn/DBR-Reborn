
/* Copyright 1994 - Tim Hollebeek
 *
 * Permission is granted to copy and use this code elsewhere, provided
 * that all code derived from this code retain this header and credit
 * the author (Tim Hollebeek) for the source, that all improvements
 * to this code be communicated to the above mentioned author for possible
 * inclusion in this code, that all derived works are made publicly
 * available to whoever wants them, and no profit is made off of this
 * code or any other derived works or any other package or system this
 * is used in without express written permission of the author.
 */
/* written quickly by Beek, Oct 12, 1994 */
#include <std.h>
#include <daemons.h>

#define NEWSRC_SAVE_DIR "/data/news/rn/"

#define MAIN_ALT(x)  MULTI_D->query_main(x->query_name())

inherit DAEMON;

private void main_loop();

private void unsubscribe(string);
private void show_headers();
private void post(string, function);
private void show_last(string, int);

protected void ask_what_next(string);
protected void ask_about_group(string);

#define STRIP_UNSUB(x) ((x) ? ((x)[0] == '#' ? (x)[1..strlen(x)] : x) : 0)
#define IS_UNSUB(x) ((x) && ((x)[0] == '#'))

#define ALL_ARTICLES    1

int options = 0;
string restrict_poster;
object who;
mapping read = ([]);
string *groups;
int *ids;

/* The following code is imported from the first newsreader I ever
   wrote, which is also one of the first LPC objects I ever wrote :) */
/* It's hideously inefficient and in need of a rewrite, but it will
   do for now */
int included(int id,string read) {
    string *ranges;
    int i,begin,end;

    if (!read) return 0;
    ranges=explode(read,",");
    for (i=0;i<sizeof(ranges);i++) {
	if (sscanf(ranges[i],"%d-%d",begin,end)==2) {
	    if ((begin<=id) && (id<=end)) return 1;
	} else {
	    sscanf(ranges[i],"%d",begin);
	    if (id==begin) return 1;
	}
    }
    return 0;
}

int GetRight(string range) {
    int begin,end;

    if (sscanf(range,"%d-%d",begin,end)==2) return end;
    sscanf(range,"%d",begin);
    return begin;
}

int GetLeft(string range) {
    int begin,end;

    if (sscanf(range,"%d-%d",begin,end)==2) return begin;
    sscanf(range,"%d",begin);
    return begin;
}

string AddToList(string list,int num) {
    string *ranges;
    int i,left,right;

    if (list == "") list = 0;
    if (included(num,list)) return list;
    if (!list) return sprintf("%d",num);
    ranges=explode(list,",");
    for (i=0;i<sizeof(ranges);i++) {
	left=GetLeft(ranges[i]);
	if (num<left) {
	    right=-1;
	    if (i) right=GetRight(ranges[i-1]);
	    if ((right+1==num) && (num==left-1)) {
		ranges[i-1]=sprintf("%d-%d",GetLeft(ranges[i-1]),GetRight(ranges[i]));
		ranges=ranges[0..i-1]+ranges[i+1..(sizeof(ranges)-1)];
	    } else if (right+1==num) {
		ranges[i-1]=sprintf("%d-%d",GetLeft(ranges[i-1]),num);
	    } else if (num==left-1) {
		ranges[i]=sprintf("%d-%d",num,GetRight(ranges[i]));
	    } else {
		ranges=ranges[0..i-1]+({sprintf("%d",num)})+ranges[i..(sizeof(ranges)-1)];
	    }
	    return implode(ranges,",");
	}
    }
    if (GetRight(ranges[sizeof(ranges)-1])==num-1) {
	ranges[sizeof(ranges)-1]=sprintf("%d-%d",GetLeft(ranges[sizeof(ranges)-1]),num);
    } else ranges+=({sprintf("%d",num)});
    return implode(ranges,",");
}
/* end imported code */

private void add_read(string group, int id) {
    if (read[group] && read[group][0] == '#') {
	read[group] = "#" + AddToList(read[group][1..strlen(read[group])], id);
    } else {
	read[group] = AddToList(read[group], id);
    }
}

private void exit(int aborted) {
    if (!aborted) 
write("No news is good news.");
    seteuid("NewsRNSave");
    write_file(NEWSRC_SAVE_DIR+MAIN_ALT(who), save_variable(read), 1);
    seteuid(getuid());
    destruct(this_object());
}

private void end_follow(string group, int id, function when_done) {
    string file;
    string message;

    file = who->query_edit_filename();
    seteuid("NewsRNSave");
    message = read_file(file);
    rm(file);
    seteuid(getuid());
    NEWSSERVER->followup(group, id, message);
    evaluate(when_done);
}

private void abort_post(function when_done) {
    string file;

    file = who->query_edit_filename();
    if (file && file_exists(file)) {
    seteuid("NewsRNSave");
    rm(file);
    seteuid(getuid());
    }
    write("Post aborted.");
    evaluate(when_done);
}

private void follow(string group, int id, string insert) {
    string fname = "/tmp/rm."+who->query_name();

    write_file(fname, insert, 1);
    who->edit(fname,
      (: end_follow, group, id, (: ask_what_next, 0 :) :),
      (: abort_post, (: ask_what_next, 0 :) :) );
}

private void end_article() {
    printf("End of article -- ");
    ask_what_next(0);
}

private void show_article(int id) {
    string *tmp;
    mapping article;

    article = NEWSSERVER->get_message(groups[0], id);
    if (!article["MESSAGE"]) article["MESSAGE"] = "";
    tmp = ({ sprintf("Post %i (%i more) in %s:",
      ids[0], sizeof(ids)-1, groups[0])
    , "Poster: " + article["POSTER"]
    , "Subject: %^BOLD%^" + article["SUBJECT"] + "%^RESET%^"
    , "Date: " + cztime(article["TIME"])
    , "" })
    + explode(article["MESSAGE"], "\n");
    add_read(groups[0], id);
    who->more(tmp, "news", (: end_article :));
}

private string quote_text(string orig) {
    if (orig[strlen(orig)-1] == '\n') orig = orig[0..strlen(orig)-2];
    return "> " + replace_string(orig, "\n", "\n> ") + "\n";
}

private void next_group() {
    groups = groups[1..sizeof(groups)];
    main_loop();
}

protectedvoid ask_what_next(string response) {
    int num;

    switch (response) {
    case "u": /* unsubscribe */
	unsubscribe(groups[0]);
	next_group();
	return;
    case "p":
	post(groups[0], (: ask_what_next, 0 :));
	return;
    case "c": /* catch up */
	{
	    int i,n;
	    for (i=0, n=sizeof(ids); i<n; i++) 
		add_read(groups[0], ids[i]);
	}
	next_group();
	return;
    case "q": /* quit group */
	next_group();
	return;
    case "=": /* list headers */
	show_headers();
	break;
    case "F":
    case "f": /* followup */
	{ 
	    string insert;

	    if (ids[0] == -1) {
		write("No current article");
		break;
	    }
	    insert = "";
	    if (response == "F") {
		mapping article = NEWSSERVER->get_message(groups[0], ids[0]);
		insert = sprintf("%s writes:\n%s", article["POSTER"],
		  quote_text(article["MESSAGE"]));
	    }
	    follow(groups[0], ids[0], insert);
	    return;
	}
    case "rem":
	if (ids[0] == -1) {
	    write("No current article");
	    break;
	}
	if (NEWSSERVER->remove_post(groups[0], ids[0])) {
	    write("Removed.");
	    ids = ids[1..sizeof(ids)];
	    if (!sizeof(ids)) {
		write("End of group " + groups[0] + "\n");
		next_group();
		return;
	    }
	    break;
	} else {
	    write("Failed.");
	}
	break;
    case "?":
    case "h":
	write(@ENDHELP
c - mark all articles in this group as read
f - post followup to last article
F - same as 'f' but include article preceded by "> "
h or ? - this help
n - read next article
p - post an article to this group
q - go back to newsgroup mode
u - unsubscribe to this group
= - list articles remaining in group
l # - list last # of articles in group
a number - read a specified article
ENDHELP);
	break;
    case "":
    case "n":
        if (!ids) {
            next_group();
            return;
        }
	if (ids[0] == -1)
	    ids = ids[1..sizeof(ids)];
	if (sizeof(ids) > 1) {
	    ids = ids[1..sizeof(ids)];
	    show_article(ids[0]);
	} else {
	    write("End of group" + groups[0] + "\n");
	    next_group();
	}
	return;
    default:
	if (response && sscanf(response, "%d", num)) {
	    if (member_array(num, NEWSSERVER->get_messages(groups[0])) == -1) {
		write("No such message.");
	    } else {
		if (ids[0] != -1) ids = ids[1..sizeof(ids)];
		ids -= ({ num, -1 });
		ids = ({ num }) + ids;
		show_article(ids[0]);
		return;
	    }
	}
	if (response && sscanf(response, "l %d", num)) {
	   show_last(groups[0],num);
	}
    }
    printf("What next? [cfFhnpq(rem)u?=] ");
    input_to("ask_what_next");
}


private void show_headers() {
    int i = 1, n;
    mapping article;

    for (n=sizeof(ids); i<n; i++) {
	article = NEWSSERVER->get_message(groups[0], ids[i]);
	printf("[%3d] %-15s %s\n", ids[i], article["POSTER"], article["SUBJECT"]);
    }
}

private void show_last(string group, int last) {
    function filter;

    if (member_array(group, NEWSSERVER->get_groups()) == -1) {
	write("No such group.");
	return;
    }
    filter = (: 1 :);
    write(format_page(NEWSSERVER->get_last_messages(group, filter, last),1));
}

private void unsubscribe(string group) {
    if (read[group])
	read[group] = "#" + read[group];
    else
	read[group] = "#";
}

private void subscribe(string group) {
    read[group] = STRIP_UNSUB(read[group]);
}

private string temp_kludge;

private int *get_unread(string group) {
    int *ret;
    int *deleted;
    function filter;
    int i;

    if (options & ALL_ARTICLES) {
	if (restrict_poster) filter = (: $2["POSTER"] == restrict_poster :);
	else filter = (: 1 :);
    } else {
	temp_kludge = STRIP_UNSUB(read[group]);
	if (restrict_poster) filter = (: !included($1, temp_kludge) && $2["POSTER"] == restrict_poster :);
	else filter = (: !included($1, temp_kludge) :);
    }

    ret = NEWSSERVER->get_messages(group, filter);
    if (!sizeof(ret)) return 0;
    deleted = NEWSSERVER->query_removed(group, ret);
    i = sizeof(deleted);
    while (i--) {
	add_read(group, deleted[i]);
    }
    ret -= deleted;
    if (!sizeof(ret)) return 0;
    return ret;
}

private void main_loop() {
    if (!sizeof(groups)) {
	exit(0);
	return;
    }
    ids = get_unread(groups[0]);
    while (!ids) {
	groups = groups[1..sizeof(groups)];
	if (sizeof(groups))
	    ids = get_unread(groups[0]);
	else break;
    }
    if (!ids) {
	exit(0);
	return;
    }
    ask_about_group(0);
}

private void start_main_loop() {
    if (!groups)
	groups = NEWSSERVER->get_groups();
    /* remove unsubscribed groups */
    groups = filter_array( group, (: !read[$1] || read[$1][0] != '#' :) );
    if (!sizeof(groups)) {
	exit(0);
	return;
    }
    main_loop();
}

private void list_groups() {
    string *groups,*secur; 
    int i,n;
    int ur;
    string urs,*outstr;
    mapping tmp;

    tmp = NEWSSERVER->get_groups2(who);
    groups = tmp["name"];
    secur = tmp["security"];
    n = sizeof(groups);
    outstr = allocate(n);
    for (i=0; i<n; i++) {
	ur = sizeof(get_unread(groups[i]));
	urs = (ur ? "(" + ur + ")" : "(READ)");
	if (IS_UNSUB(read[groups[i]]))
	    urs = "(UNSUB)";
        outstr[i] = sprintf("%7s %10s %s", urs, secur[i], groups[i]);
    }
    write(format_page(sort_array(outstr,1),2));
/*	IVAN
    write("This players name is "+this_player()->query_name());
    this_player()->more(format_page(sort_array(outstr,1),2));
*/
}

protected void ask_subscribe(string response, string group) {
    switch (response) {
    case "y":
	subscribe(group);
	groups = ({ group }) + groups;
	main_loop();
	return;
    case "n":
	main_loop();
	return;
    default:
	printf("%s is currently unsubscribed.  Resubscribe? [yn] ", group);
	input_to("ask_subscribe", 0, group);
    }
}

private void goto_group( string group ) {
    if (member_array(group, NEWSSERVER->get_groups()) == -1) {
	write("No such group.");
	ask_about_group(0);
	return;
    }
    if (IS_UNSUB(read[group])) {
	ask_subscribe(0, group);
    } else {
	groups = ({ group }) + groups;
	main_loop();
    }
}



    file = read_file(file);
    if (file)
	read = restore_variable(file);
    seteuid(getuid());
}

private void start_reading(string group) {
    if (group) {
	if (member_array(group, NEWSSERVER->get_groups()) == -1) {
	    write("No such group.");
	    return;
	}
	if (IS_UNSUB(read[group])) {
	    groups = ({});
	    ask_subscribe(0, group);
	    return;
	} else {
	    groups = ({ group });
	}
    } else {
	string *new_groups;

	new_groups = (string *)NEWSSERVER->get_groups() - keys(read);
	if (sizeof(new_groups)) {
	    ask_about_new_groups(0, new_groups);
	    return;
	}
    }
    start_main_loop();
}

private void post(string group, function when_done) {
    if (member_array(group, NEWSSERVER->get_groups()) == -1) {
	write("No such group.");
	return;
    }
    printf("Subject: ");
    input_to("get_subject", 0, group, when_done);
}

private void end_post(string subj, string group, function when_done) {
    string file;
    string message;

    file = who->query_edit_filename();
    seteuid("NewsRNSave");
    message = read_file(file);
    rm(file);
    seteuid(getuid());
    NEWSSERVER->post(group, subj, message);
    evaluate(when_done);
}

protected void get_subject(string subj, string group, function when_done) {
    who->edit("/tmp/rn/rn."+who->query_name(), 
      (: end_post, subj, group, when_done :), 
      (: abort_post, when_done :));
}

int syntax_error() {
    return notify_fail("rn [-all] [-post] [newsgroup]\n");
}

#define READING    0
#define POSTING    1
#define LISTING    2
#define LASTING    3
#define Q_READING  4
#define ONE_ARTICLE 5

int start_up(string str) {
    string *args;
    string gname;
    int n,num,LAST;
    int what;

    who = previous_object(1);

    if (str) {
	args = explode(str, " ");
	n = sizeof(args);
	while (n && args[0][0]=='-') {
	    switch (args[0]) {
	    case "-all":
		options |= ALL_ARTICLES;
		break;
	    case "-post":
		what = POSTING;
		break;
	    case "-lit":
		what = LISTING;
		break;
	    case "-last":
		if (n != 3 && n !=2) {
		   write("rn: must specify group after -last");
		   return 1;
		}
		LAST = 1;
		what = LASTING;
		break;    
	    case "-poster":
		if (n == 1) {
		    write("rn: must specify poster after -poster");
		    return 1;
		}
		restrict_poster = args[1];
		args = args[1..n--];
		break;
	    case "-read":
		if (n==1) {
		    write("rn: must specify group after -read");
		    return 1;
		}
		what = Q_READING;
		options |= ALL_ARTICLES;
		break;
            case "-r":
                if (n!=3) {
                    write("rn: rn -r <group> <num>");
                    return 1;
                }
                what = ONE_ARTICLE;
                options |= ALL_ARTICLES;
                break;
	    default:
		write("rn: unknown flag '"+args[0]+"'");
		return 1;
	    }
	    args = args[1..n--];
	}
        if ((!(LAST || ONE_ARTICLE) && n>1) || ((LAST || ONE_ARTICLE) && n>2))
	    return syntax_error();
	if (n)
	    gname = args[0];
    }
    switch(what) {
    case POSTING:
	if (!gname)
	    return notify_fail("Must specify group to post to.\n");
	post(gname, 0);
	break;
    case LISTING:
	load_newsrc(NEWSRC_SAVE_DIR + MAIN_ALT(this_player()));
	list_groups();
	break;
    case READING:
	load_newsrc(NEWSRC_SAVE_DIR + MAIN_ALT(this_player()));
	start_reading(gname);
	break;
    case LASTING:
        if (n == 1) num = 10;
	else if (sscanf(args[1],"%d",num) != 1)
	    return notify_fail("Incorrect Argument to rn -last command.\n");
	show_last(gname,num);
	break;
    case Q_READING:
	load_newsrc(NEWSRC_SAVE_DIR + MAIN_ALT(this_player()));
	groups = ({gname});
	ids = get_unread(gname);
	ask_what_next(0);
	break;
    case ONE_ARTICLE:
        if (sscanf(args[1],"%d",num) != 1)
          return notify_fail("Incorrect Argument to rn -r command.\n");
        if (member_array(gname, NEWSSERVER->get_groups()) == -1)
          return notify_fail("No such group.");
       groups = ({gname});
        ids = get_unread(gname);
        if (member_array(num,get_unread(gname) || ({})) == -1)
          return notify_fail("That article does not exist (may be archived.)\n");
        ids = ({num});
        load_newsrc(NEWSRC_SAVE_DIR + MAIN_ALT(this_player()));
        show_article(num);
        break;

    }
    return 1;
}

object query_who() { return who; }



}
