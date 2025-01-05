//      Wizard:  Myrddin
//      village_66.c
//      June 97

#include "../defs.h"

inherit "std/room";

void reset(){
  ::reset();
  if(!present("ininsectoid")) {
         new(HIV_MON+"ininsectoid")->move(this_object());
   }

   }  

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "Ancient Forest");
    set("long",
	"The forest is quiet and peaceful.  You continue to see the "
              "trail forced through the underbrush by the large creatures.  "
              "You begin to wonder where they came from, and why they "
              "suddenly appeared.\n" );
    set("night long",
             "The forest is dark and quiet.  You have to mentally prepare "
             "for the challenge ahead, as the dark and unknown do not "
             "help your courage.  You can still easily follow the trail left "
             "by the creatures.\n");
    set_smell("default", "The forest smells fresh and clean.");
    set_listen("default", "You hear nothing but the expected wildlife.");
    set_items(([
     ({ "forest", "trees" }) :
        "The forest is thick, filled with ancient trees.  You get the "
        "feeling nothing has been this way in ages, except you and your "
        "foe.",
     ({ "trail" }) :
        "It continues to the northwest and to the southeast.",
     ({ "underbrush" }) :
        "The thick underbrush hampers most movement, but it has been "
        "forced aside by the creatures as they moved toward the town.",
]));
    set_exits((["northwest":HIV_ROOMS+"village_67.c",
                     "southeast":HIV_ROOMS+"village_65.c"])); 
}

