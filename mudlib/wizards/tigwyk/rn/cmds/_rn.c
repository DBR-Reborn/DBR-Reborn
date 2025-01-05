#include <std.h>


int cmd_rn(string str) {
    if(!wizardp(this_player()) && this_player()->query_level() < 2) {
       write("You must be at least level 2 to use rn.");
       return 1;
    }
    return new("/std/news/rn")->start_up(str);
}

void create() {
  ::create();
  set_skill_name("rn");
  set_syntax(({ "[-all] [-poster name] [group]","-post [group]","-list"
       ,"-last [group] [#]","-r [group] [#]" }));
  set_see_also(({ "rn_howto" }));
  set_help_str(
"'rn' starts up the SWMUD news reader. Just typing rn by"
"itself reads the unread news.\n\n"
"'rn -all' reads all the news.\n\n"
"'rn group' reads the unread posts in a specific group.\n\n"
"'rn -all group' reads all the posts in a group.\n\n"
"To post, use 'rn -post group', or do followups from within rn.\n\n"
"'rn -list' lists all the groups, similar to the 'L' command"
"within rn.\n\n"
"'rn -poster whoever' restricts the posts to be read"
"to the posts made by 'whoever'.\n\n"
"'rn -last group #' lists the headers for the last # of posts in a"
"specific group.\n\n"
"'rn -r group #' lists article # in group only.\n\n"
"While in rn, the 'h' command can be used to get a list of the following"
"options at most prompts.\n\n"
"Please note that you cannot move while in rn (or any editing process, for"
"that matter). Plan accordingly.\n\n"
"c - mark all articles in this group as read\n"
"f - post followup to last article\n"
"F - same as 'f' but include article preceded by \"> \"\n"
"rem - removes an article if you are the poster\n"
"h or ? - this help\n"
"n - read next article\n"
"p - post an article to this group\n"
"q - go back to newsgroup mode\n"
"u - unsubscribe to this group\n"
"= - list articles remaining in group\n"
"l # - list last # of articles in group\n"
"a number - read a specified article");
}

