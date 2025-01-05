
#include <std.h>
#include "/wizards/garetjax/plateau/defs.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "An Ominous Tower");
   set_long(
     "Strangely, non of the creatures from the room below have decided to make "
     "this room their home, and this room manages to be even creapier. Once you"
     " enter, all the sound ceases, eventhough you should still be able to "
     "hear the mice from down below. This room is just too quiet."
    );
     add_exit("stower3", "down");
       add_exit("upup3", "up");
       add_invis_exit("up");
    add_pre_exit_function("up", "go_up");
     set_smell("default", "The air is dank, and humid.");
     set_listen("default", "An unidentifiable humming.");
  }

   void reset()   {
       ::reset();
        new(PLATMON + "guard") -> move(this_object());
}


 int go_up()    {
    if(present("guardian"))
       {
     write("The Guardian blocks your path.");
     return 0;
     }
    else return 1;
}

