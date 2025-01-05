#include "std.h"

inherit "/std/vault";

void init() {
   ::init();
   add_action("filter_cmd","");
}

int filter_cmd(string str) {
   string verb;
     verb = query_verb();
   if(verb == "north" && present("demon guard")) {
       write("The demon pushes you back with a strong force");

       return 1;
   }
   return 0;
}
     
void create() {
     ::create();
     set_property("indoors", 1);
     set_property("light", 1);
     set("short", "Guard room");
     set("long", "This room is set with several torches affixed to the
walls.  The room is circular in shape with a huge stone door towards the
north.  There are two pictures on either side of the door.\n");
     set_smell("default", "The air is getting cooler for some reason.");
     set_listen("default", "You hear a subtle clashing sound.");
     set_items( ([
            ({"pictures", "picture"}):
     "The first picture depicts a grand demon lord casting a spell on a
silver knight.  The second picture shows the knight being imprisioned by
some spell.",
     "door":
     "This door crafted from stone and seems to be sturdily fastened to the
wall.",
     ({"torch", "torches"}):
     "Wierd that demons would even need torches but they are burning brightly and affixed to the wall.",
      ]) );
     add_exit("dm3", "west");
     add_exit("gr1", "north");
     set_door("door", "gr1", "north", "door key");
     set_string("door","open","The stone door slides open easily.\n");
     set_lock_level("door",99);
     set_post_exit_functions( ({"north", "west"}),({"lock_door","lock_door"}) );
     set_open("door",0);
     set_locked("door",1);
}

void reset() {
     ::reset();
	if(!present("guard")){
        new(MON_PATH+"guard1")->move(this_object());
        new(MON_PATH+"guard1")->move(this_object());
     }
}

int lock_door() {
     set_open("door",0);
     set_locked("door",1);
     return 1;
}
