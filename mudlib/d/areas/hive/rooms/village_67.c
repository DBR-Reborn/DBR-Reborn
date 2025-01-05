
//      Wizard:  Myrddin
//      village_67.c
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
	"The forest is quiet and peaceful.  You continue to see the "
              "trail forced through the underbrush by the large creatures.  "
              "The trail turns toward the north, heading directly toward "
              "the hill.\n" );
    set("night long",
             "The forest is dark and quiet.  The trail through the "
             "underbrush continues, but turns north, toward the hill.\n");
    set_smell("default", "The forest smells fresh and clean.");
    set_listen("default", "You hear nothing but the expected wildlife.");
    set_items(([
     ({ "forest", "trees" }) :
        "The forest is thick, filled with ancient trees.  It reminds you of "
        "the power and strength of nature, and of its creatures.",
     ({ "trail" }) :
        "It continues to the north and to the southeast.",
     ({ "hill" }) :
        "The hill is still too far away to see clearly through the trees, "
        "but it is definitely directly to the north from here.",
     ({ "underbrush" }) :
        "The thick underbrush hampers most movement, but it has been "
        "forced aside by the creatures as they moved toward the town.",
]));
    set_exits((["north":HIV_ROOMS+"village_68.c",
                     "southeast":HIV_ROOMS+"village_66.c"])); 
}

