#include <move.h>
#include <std.h>
#include <objects.h>

inherit DAEMON;


int cmd_stand(string str) {

	if(this_player()->query_state() == "stand") {
     notify_fail("You are already standing");
     return 0;
      }
    if(this_player()->query_state() == "prone") {
    this_player()->set_state("stand");
    say(this_player()->query_cap_name()+" stands up.", this_player());
     write("You stand up.");
     return 1;
      }
    if(this_player()->query_state() == "rest") {
    this_player()->set_state("stand");
    say(this_player()->query_cap_name()+" stands up off the ground.", this_player());
     write("You get up off the ground.");
     return 1;
      }
    if(this_player()->query_state() == "sit") {
    this_player()->set_state("stand");
    say(this_player()->query_cap_name()+" stands up.", this_player());
     write("You stand up.");
     return 1;
      }
}

int
help() {
   write("Command: stand\nSyntax: stand\n"+
      "This command allows you to stand. Standing is a good thing.\n"
   );
   return 1;
}