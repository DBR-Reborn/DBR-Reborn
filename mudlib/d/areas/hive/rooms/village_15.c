//      Wizard:  Myrddin
//      village_15.c
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
    set("short", "Village Path");
    set("long",
	"You are to the west of the village center, which you can "
              "still see to the east.  There is a large building you can enter "
              "to the north, while there is only the side of a building to "
              "the south.  The path continues back to the village center "
              "and to the west.\n" );
    set("night long",
             "You walk in the deep shadows of the night.  You can make "
             "out a glow coming from the north, but its light does not "
             "penetrate past the large building to the north.\n" );
    set_smell("default", "The smell of smoke overpowers all other "
                   "smells inside the village.");
    set_listen("default", "You hear some noise coming from the north "
                    "end of the village.");
    set_items(([
     ({ "path" }) :
         "It is well worn from constant traffic within the village.",
     ({ "center" }) :
         "The village center is to the east.  It looks like there is a "
         "fountain there.",
     ({ "village" }) :
         "It is definitely small.  Not many people could live in it "
         "comfortably.",
      ({ "glow" }) :
         "The glow dominates the northern end of the village.  You "
         "cannot see its source with the large building to the north "
         "between you and the glow.",
     ({ "building", "buildings" }) :
         "The building to the north is large and looks to be a store of "
         "some sort.  To the south you see the wall of a smaller "
         "building, probably a house of some sort.",
]));
    set_exits((["north":HIV_ROOMS+"village_24.c",
                     "east":HIV_ROOMS+"village_12.c",
                     "west":HIV_ROOMS+"village_16.c"])); 
}

