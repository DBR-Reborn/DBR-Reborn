//      Wizard:  Myrddin
//      village_83.c
//      June 97

#include "../defs.h"

inherit "std/room";

void reset(){
  ::reset();
  if(!present("insectoid_g01")) {
         new(HIV_MON+"insectoid_g01")->move(this_object());
   }  
}  

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "Lower Hill");
    set("long",
             "You are on the east edge of the hill.  Large rocks block "
             "your movement toward the top, but you can still follow the "
             "edge of the hill toward the back.\n" );
    set("night long",
             "In the dark, one part of the hill looks much like another.  "
             "Shadows broken by jutting rocks, blending with thick "
             "brush, and the rustle of nearby insectoids.\n");
    set_smell("default", "The forest smells fresh and clean.");
    set_listen("default", "You hear subtle scratchings and quiet "
              "movement coming from all over the hill.  The sounds of "
              "normal wildlife are noticeably absent.");
    set_items(([
     ({ "trees" }) :
        "Their are still trees desperately trying to grow on the hill.  "
        "They look small and scrawny compared to their brethren on "
        "the fertile soil below the hill.",
     ({ "rock", "rocks" }) :
        "They are all over the hill, and come in various sizes.  Some "
        "seem small enough to throw, while the ones blocking your "
        "movement to the west are massive, showing cracks from their "
        "own weight.",
     ({ "hill" }) :
        "The hill rises above the rest of the forest like an island in an "
        "ocean.  It would be interesting to learn how this hill came to be "
        "when there are no others in the area.  It certainly would make "
        "an ideal defensive point for the entire region.",
     ({ "groundcover", "undergrowth"  }) :
        "There is still a lot of brush growing on the hill, as it is better "
        "able to adapt to the thin soil of the hillside.  It, with the "
        "pervasive rocks, tends to block your view of the surrounding "
        "terrain.",
     ({ "crack", "cracks" }) :
        "As you look more carefully at the largest crack in the rocks, "
        "you realize that you might be able to 'climb up' to the top of "
        "the hill.  However, you dont have the equipment you would "
        "need to get back down.  It would be a one way trip.",
]));
    set_exits((["north":HIV_ROOMS+"village_82.c",
                     "south":HIV_ROOMS+"village_84.c"])); 
}


void init() {
        ::init();
        add_action("climb","climb");
}
int climb(string str) {
        if (str == "up") {
                write("You make the difficult climb up crack in the rock to "
                         "the hill above.");
                this_player()->move_player(HIV_ROOMS+"village_98");
                return 1;
        }
        else {
        notify_fail("Climb what?\n");
        return 0;
}}


