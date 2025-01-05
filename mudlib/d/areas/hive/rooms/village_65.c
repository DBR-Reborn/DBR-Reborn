//      Wizard:  Myrddin
//      village_65.c
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
    set("short", "Ancient Forest");
    set("long",
	"The forest is quiet and peaceful.  You are not foolish "
              "enough to expect it to remain that way.  As you look "
              "carefully, you can see a trail forced through the underbrush "
              "by the large creatures.  It should be easy to follow back to "
              "its source.  Coming back from there may be more "
              "problematic.\n" );
    set("night long",
             "The forest is dark and quiet.  You fear an ambush at any "
             "spot from the creatures.  Even in the dark, you can make "
             "out a trail forces through the underbrush by the "
             "creatures.\n");
    set_smell("default", "The forest smells fresh after the smoke filled "
             "village. ");
    set_listen("default", "You hear nothing but the expected wildlife.");
    set_items(([
     ({ "forest", "trees" }) :
        "The forest is thick, filled with ancient trees.  You have past "
        "beyond the point you could expect any help from the village.",
     ({ "trail" }) :
        "It continues to the northwest and to the southeast.",
     ({ "underbrush" }) :
        "The thick underbrush hampers most movement, but it has been "
        "forced aside by the creatures as they moved toward the town.",
]));
    set_exits((["northwest":HIV_ROOMS+"village_66.c",
                     "southeast":HIV_ROOMS+"village_64.c"])); 
}

