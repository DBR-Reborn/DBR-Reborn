//  A note for the maze in the Demon gorge//
 
#include <std.h>
inherit "/std/Object";
 
object who;
 
void init() {
   ::init();
   add_action("read", "read");
   add_action("drop", "drop");
}
   
void create() {
   ::create();
     set("id", ({"paper", "burnt paper", "burnt piece of paper", "burnt paper"}) );
     set_name("burnt piece of paper");
     set("short", "a burnt piece of paper");
     set("long", "There is some writing left on this burnt piece of paper.");
   set_weight(10);
   set("value", 0);
}
 
int read(string str) {
   if(!str) {
      return 0;
   }   
     if((str != "paper") && (str != "piece of paper") && (str != "burnt piece of paper")) {
      notify_fail("Read what?\n");
      return 0;
   }
     write(
     "    I seem to be getting a good idea of how this maze is \n"
     "set up.  The rooms are mostly connecting to the correct \n"
     "room corresponding the direction given.  In some cases \n"
     "the exits transport you to another area.  If you look \n"
     "carefully at the room you can clearly see which rooms will \n"
     "transport you.  The biggest problem I am having is with \n"
     "those damn Demons and this never ending heat.  I only hope \n"
     "I can get to a lower level and come face to face with the \n"

         );
   return 1;
}
 
int drop(string str) {
   if(!str)
      return 0;
     if((str != "paper") && (str != "piece of paper") && (str != "burnt piece of paper"))
      return 0;
     write("The burnt piece of paper crumbles to dust when it hits the ground.");
   say(this_player()->query_cap_name()+" drops a piece of paper and it crumbles into dust.");
   this_object()->remove();
   return 1;
}
