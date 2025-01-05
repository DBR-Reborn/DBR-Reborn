#include <move.h>
#include <std.h>
#include <objects.h>

inherit DAEMON;


int cmd_rest(string str) {
	if(this_player()->query_state() == "rest") {
     notify_fail("You are already resting");
     return 0;
      }
    if(this_player()->query_state() == "prone") {
    notify_fail("You are prone and need to stand or sit.");
     return 0;
      }
    if(this_player()->query_state() != "rest") {
    this_player()->set_state("rest");
    say(this_player()->query_cap_name()+" lays down to rest.", this_player());
     write("You lay down.");
     return 1;
      }
}

int
help() {
   write("Command: rest\nSyntax: rest\n"+
      "This command allows you to lay down and rest. This allows you to recover quickly... if your lucky\n"
   );
   return 1;
}