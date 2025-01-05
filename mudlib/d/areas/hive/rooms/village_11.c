//      Wizard:  Myrddin
//      village_11.c
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
	"You are in the southern side of the village.  To the "
              "east and west are small buildings, probably houses for the "
              "few people that choose to live in the village.  You can see "
              "the village center to the north.\n" );
    set("night long",
             " Shadows cast on the walls of nearby buildings show you no "
             "details, creating an ominous feeling to the village, "
              "though the lack of light from the inside implies that they "
              "are abandoned.  A bright glow comes from the north end "
              "of the village.  You also see a dim light in the building to "
              "the east.  The path continues to the north and to the "
              "south.\n");
    set_smell("default", "The smell of smoke overpowers all other "
                   "smells inside the village.");
    set_listen("default", "You hear some noise coming from the north "
                    "end of the village.");
    set_items(([
     ({ "path" }) :
         "It is well worn from constant traffic within the village.",
     ({ "village" }) :
         "It is definitely small.  Not many people could live in it "
         "comfortably.",
      ({ "glow" }) :
         "The glow dominates the northern end of the village.  You are "
         "still too far away to see its source.  Maybe the town itself is "
         "on fire.",
     ({ "building", "buildings" }) :
         "They are, not surprisingly, made from wood.  They have a "
         "basic construction, but are probably functional.",
     ({ "light", "dim light" }) :
         "It is coming from the house to the east.  A lantern, perhaps?",
]));
    set_exits((["north":HIV_ROOMS+"village_12.c",
                     "south":HIV_ROOMS+"village_10.c",
                     "east":HIV_ROOMS+"village_21.c",
                     "west":HIV_ROOMS+"village_18.c"])); 
}

