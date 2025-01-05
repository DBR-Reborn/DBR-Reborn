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
/*
 *  General news daemon, by Beek
 *  Oct 10, 1994
 *
 * Interface:
 *
 * id NEWS_D->post(group, subject, message)
 * id NEWS_D->followup(group, id, message)
 * NEWS_D->remove_post(group, id)
 * message NEWS_D->get_message(group, id)
 * id array NEWS_D->get_messages(group, filter)
 * id array NEWS_D->get_thread(group, thread)
 * NEWS_D->get_groups()
 * id array NEWS_D->query_removed(group, id array)
 *
 * Internews interface stuff:
 * NEWS_D->remote_post(group, poster, subject, message)
 * NEWS_D->query_export_list(xxx)
 */
#include <daemons.h>

#define SAVE_FILE "/data/news/news"
#define ARCHIVE_DAYS 10
#define ARCHIVE_DIR "/data/news/archive"
#define SECURE_POSITIONS ({"player","HM","apprentice","immortal","councillor","senator","moff","founder"})
#define RN_TIME 120 

void archive_posts();

private mapping data = ([]);
object foo;
private int __NewsPtr;
private string *__NewsDir;

void create() {
  if (clonep()) destruct(this_object());

  seteuid("NewsSave");
  if (!restore_object(SAVE_FILE))
    return;
  archive_posts();
  __NewsDir = get_dir("/data/news/rn/");
  __NewsPtr = 0;
  manage_rn();
}

void save_me() {
    unguarded( (: save_object, SAVE_FILE :) );
}

int check_security(string group) {
  object ob;
 
  if (foo == this_object()) {
    ob = previous_object(2);
//write("first");
    if (!ob) {
      ob = this_player();
//write("inner");
    }
  }
  else {
//write("sec");
    ob = previous_object(3);
  }
  if (!ob) {
    if (foo && ((base_name(foo) == "/std/news/rn") ||
                (base_name(foo) == "/bin/moff/newsadm") ||
                (base_name(foo) == "/adm/obj/copy_term") )) {
     ob = this_player();
//write("ugh");
    }
    else return 0;
  }  
  if (ob == this_object()) return 0;
  if (numeric_rank(ob) >= member_array(data[group]["security"],SECURE_POSITIONS))
    return 1;
  return 0;
}


private int get_new_id(string group) {
    return data[group]["next_id"]++;
}

int post(string group, string subject, string message) {
    int post_id;
    mapping map = allocate_mapping(5);

    // Check for rnban
    if(this_player()->query_property("rncurse")) {
      write("You cannot post right now. Please try again later.");
      return 0;
      }

    if (!data[group]) return 0;
    if (!check_security(group)) return 0;
    post_id = get_new_id(group);
    map["TIME"] = time();
    map["THREAD"] = post_id;
    map["SUBJECT"] = subject;
    map["MESSAGE"] = message;
    map["POSTER"] = capitalize(this_player()->query_name());
    data[group][post_id] = map;
    save_me();
    return post_id;
}

int post_automated(string poster, string group, string subject, string message) {
    int post_id;
    mapping map = allocate_mapping(5);

    if (!data[group]) return 0;
    post_id = get_new_id(group);
    map["TIME"] = time();
    map["THREAD"] = post_id;
    map["SUBJECT"] = subject;
    map["MESSAGE"] = message;
    map["POSTER"] = capitalize(poster);
    data[group][post_id] = map;
    save_me();
    return post_id;
}


int remote_post(string group, string poster, string subject, string message) {
    mapping map = allocate_mapping(5);
    int post_id;
    
    // Check for rnban
    if(this_player()->query_property("rncurse")) {
      write("You cannot post right now. Please try again later.\n");
      return 0;
      }
    
    if (file_name(previous_object()) != INTERNEWS_D) return -1;
    if (!data[group]) return 0;
    post_id = get_new_id(group);
    map["TIME"] = time();
    map["THREAD"] = post_id;
    map["SUBJECT"] = subject;
    map["MESSAGE"] = message;
    map["POSTER"] = poster;
    map["REMOTE"] = 1;
    data[group][post_id] = map;
    save_me();
    return post_id;
}

void clear_all_messages() {
    string *k,fn;
    int j;

    fn = file_name(previous_object());
    if (fn != "/bin/moff/_newsadm") return;
    k = keys(data);
    for (j=0;j<sizeof(k);j++)
      data[k[j]] = (["next_id":1,"security":data[k[j]]["security"]]);
    write(identify(data));
    save_me();
}
 
    
void add_group(string group, string secure) {
    string fn = file_name(previous_object());

    if (fn != "/bin/moff/_newsadm") return;

    if (member_array(secure,SECURE_POSITIONS) == -1) return;
    data[group] = (["next_id":1,"security":secure]);
    save_me();
}


void remove_group(string group) {
    string fn = file_name(previous_object());

    if (fn != "/bin/moff/_newsadm") return;
    foo = this_object();
    if (!check_security(group)) { write("nope"); return; }
    map_delete(data, group);
    save_me();
}

int followup(string group, int id, string message) {
    int post_id;
    int tmp;
    mapping map = allocate_mapping(6);
    string subject;

    // Check for rnban
    if(this_player()->query_property("rncurse")) {
      write("You cannot post right now. Please try again later.\n");
      return 0;
      }

    if (!data[group]) return 0;
    if (!data[group][id]) return 0;
    if (!check_security(group)) return 0;
    post_id = get_new_id(group);
    subject = ">" + data[group][id]["SUBJECT"];

    /* the original article is the thread id */
    while (tmp = data[group][id]["FOLLOW"])
        id = tmp;
    map["TIME"] = time();
    map["THREAD"] = id;
    map["SUBJECT"] = subject;
    map["MESSAGE"] = message;
    map["POSTER"] = capitalize(this_player()->query_name());
    data[group][post_id] = map;
    save_me();
    return post_id;
}


mapping get_message(string group, int id) {
    /* sigh */
    if (check_security(group))
    return copy(data[group][id]);
}

int remove_post(string group, int id) {
    string afile, amsg;
    if (!check_security(group)) return 0;
    if (capitalize(this_player()->query_name()) != data[group][id]["POSTER"] && !moffp(this_player())) return 0;

    afile = sprintf("%s/removed", ARCHIVE_DIR);
    amsg = sprintf("---\nGROUP: %s ID: %d\nposter: %s\nsubject: %s\ndate: %s\n%s\n\n", 
           group,id,data[group][id]["POSTER"], data[group][id]["SUBJECT"], ctime(data[group][id]["TIME"]), data[group][id]["MESSAGE"]);
    unguarded( (: write_file, afile, amsg :) );

    data[group][id]["SUBJECT"] = "***REMOVED***";
    data[group][id]["MESSAGE"] = "***REMOVED***\n";
    data[group][id]["REMOVED"] = 1;
    return 1;
}

mapping temp_kludge3;
function temp_kludge4;

int *get_messages(string group, function filter) {
    int *ret;

    if (!check_security(group)) return 0;
    ret = keys(data[group]) - ({ "next_id" }) - ({ "security" });
    if (!filter) filter = (: 1 :);
    temp_kludge3 = data[group];
    temp_kludge4 = filter;
    ret = filter_array(ret, (: evaluate(temp_kludge4, $1, temp_kludge3[$1]) :) );
    return sort_array(ret, 1);
}

string *get_last_messages(string group, function filter, int num) {
    int *ret;
    string *out;
    int i,m,n;

    if (!check_security(group)) return 0;
    ret = keys(data[group]) - ({ "next_id" }) - ({ "security" });
    if (!filter) filter = (: 1 :);
    temp_kludge3 = data[group];
    temp_kludge4 = filter;
    ret = filter_array(ret, (: evaluate(temp_kludge4, $1, temp_kludge3[$1]) :) );
    ret = sort_array(ret, 1);
    n = sizeof(ret);
    m = n-num;
    if (m < 0) m = 0;
    out = allocate(n-m); 
    for (i=m;i<n;i++) {
       out[i-m] = sprintf("[%3d] %-15s %s", ret[i], data[group][ret[i]]["POSTER"], data[group][ret[i]]["SUBJECT"]);
    }
    return out;
}



mapping tmp_map;

int *query_removed(string group, int *ids) {
    tmp_map = data[group];
    return filter_array(ids, (: tmp_map[$1]["REMOVED"] :) );
}

private int temp_kludge;
private mapping temp_kludge2;

int *get_thread(string group, int thread) {
    temp_kludge = thread;
    temp_kludge2 = data[group];
    return filter_array(keys(data[group]), (: $1 != "next_id" && temp_kludge2[$1]["THREAD"] == temp_kludge :));
}

mapping get_groups2(object ob) {
  string *tmp,*tmp2;
  int i;

  foo = previous_object();
  tmp = filter_array(keys(data), "check_security", this_object());
  foo = this_object();
  tmp2 = allocate(sizeof(tmp));
  for (i=0;i<sizeof(tmp);i++) {
    tmp2[i] = data[tmp[i]]["security"];
  }
  return (["name":tmp,"security":tmp2]);
}

string *get_groups() {
  string *tmp;
  foo = previous_object();
  tmp = filter_array(keys(data), "check_security", this_object());
  foo = this_object();
  return sort_array(tmp, 1);
}

private void archive_post(string group, int id) {
    string file = sprintf("%s/%s", ARCHIVE_DIR, group);
    string msg = sprintf("---\nposter: %s\nsubject: %s\ndate: %s\n%s\n\n", data[group][id]["POSTER"], data[group][id]["SUBJECT"], ctime(data[group][id]["TIME"]), data[group][id]["MESSAGE"]);
    unguarded( (: write_file, file, msg :) );
    map_delete(data[group], id);
}


void archive_posts() {
    string *groups;
    int *ids;
    int i,j,ni,nj;
    mapping group;
    int archive_time = time() - ARCHIVE_DAYS * 24 * 60 * 60;

    groups = keys(data);
    ni = sizeof(groups);

    for (i=0; i<ni; i++) {
        group = data[groups[i]];
        ids = keys(group) - ({ "next_id" }) - ({ "security" });
        nj = sizeof(ids);

        for (j=0; j<nj; j++) {
            if (group[ids[j]]["TIME"] < archive_time)
                archive_post(groups[i], ids[j]);
        }
    }
}

protected void manage_rn() {
    string pl;
 
    if(!pointerp(__NewsDir) || !sizeof(__NewsDir)) return;
    if(__NewsPtr >= sizeof(__NewsDir)) __NewsPtr = 0;
    pl = __NewsDir[__NewsPtr];
    seteuid("NewsSave");
    if(!file_exists("/data/news/rn/"+pl)) {
        call_out("manage_rn", RN_TIME);
        seteuid(getuid());
        return;
      }
    if(!user_exists(pl)) rm("/data/news/rn/"+pl);
    seteuid(getuid());
    call_out("manage_rn", RN_TIME);
    __NewsPtr++;
}


