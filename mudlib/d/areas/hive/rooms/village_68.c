//      Wizard:  Myrddin
//      village_68.c
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
	"The forest is quiet and peaceful.  You trail forced through "
              "the underbrush by the large creatures continues directly "
              "toward the hill.  For some reason, it is beginning to look "
              "like a giant anthill to you.\n" );
    set("night long",
             "The forest is dark and quiet.  The trail through the "
             "underbrush continues to the north, straight at the hill.  "
             "Wait! Was that a giant ant silhouetted at the top of the "
             "hill?  Or is your imagination just playing tricks on you?\n");
    set_smell("default", "The forest smells fresh and clean.");
    set_listen("default", "You hear nothing but the expected wildlife.");
    set_items(([
     ({ "forest", "trees" }) :
        "The forest is thick, filled with ancient trees.  It reminds you of "
        "the power and strength of nature, and of its creatures.",
     ({ "trail" }) :
        "It continues to the north and to the south.",
     ({ "ant", "silhouette" }) :
        "Upon closer inspection, it must have been a rock and your "
        "imagination.",
     ({ "rock", "rocks" }) :
        "There seem to be a lot of rocks on the hill.",
     ({ "hill" }) :
        "The hill looks relatively barren from here.  From what you can "
        "see, it is very rocky and not many trees are growing on it.",
     ({ "underbrush" }) :
        "The thick underbrush hampers most movement, but it has been "
        "forced aside by the creatures as they moved toward the town.",
]));
    set_exits((["north":HIV_ROOMS+"village_69.c",
                     "south":HIV_ROOMS+"village_67.c"])); 
}

