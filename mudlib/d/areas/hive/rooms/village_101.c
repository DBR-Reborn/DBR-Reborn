//      Wizard:  Myrddin
//      village_101.c
//      June 97

#include "../defs.h"

inherit "std/room";

void reset(){
  ::reset();
}  

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "Deep Forest");
    set("long",
	"You are surrounded by large and ancient trees.  They "
              "completely block out any view of the sky.  To make "
              "matters worse, heavy underbrush hampers your every "
              "move.  Face it, you are completely lost.  You should have "
              "stayed on the path like you were warned.\n" );
    set_smell("default", "It smells like a primal forest.");
    set_listen("default", "You hear exactly what you would expect to if "
                   "you were lost hundreds of miles from civilization.  "
                   "Woodland sounds.");
    set_items(([
     ({ "forest", "woods", "trees", "depths" }) :
        "The forest is thick, filled with ancient trees.  They all look the "
        "same too you.  Yes, identical.  No, you can't mark them "
       "somehow.",
     ({ "path" }) :
        "It's not here.  You left it like an idiot.",
     ({ "underbrush" }) :
        "It is thick and wild.  It boxes you in.  It smells nasty.  It's what "
        "you deserve for wandering off on your own.",
]));
    
     add_exit(HIV_ROOMS+"village_102", "southeast");
     add_invis_exit("southeast");

}

