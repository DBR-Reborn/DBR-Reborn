#include <move.h>
#include <std.h>
#include <objects.h>

inherit DAEMON;


int cmd_sit(string str) {

	if(this_player()->query_state() == "sit") {
     notify_fail("You are already sitting down");
     return 0;
      }
    if(this_player()->query_state() == "rest") {
    this_player()->set_state("sit");
    say(this_player()->query_cap_name()+" sits up.", this_player());
     write("You sit up.");
     return 1;
      }
    if(this_player()->query_state() == "prone") {
    this_player()->set_state("sit");
    say(this_player()->query_cap_name()+" sits up.", this_player());
     write("You sit up.");
     return 1;
      }
    if(this_player()->query_state() == "stand") {
    this_player()->set_state("sit");
    say(this_player()->query_cap_name()+" sits down.", this_player());
     write("You sit down.");
     return 1;
      }
}

int
help() {
   write("Command: sit\nSyntax: sit\n"+
      "This command allows you to sit. Sitting helps you recover faster... maybe...\n"
   );
   return 1;
}