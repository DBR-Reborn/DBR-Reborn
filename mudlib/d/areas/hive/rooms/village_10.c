//      Wizard:  Myrddin
//      village_10.c
//      June 97

#include "../defs.h"

inherit "/std/vault";

void reset(){
  ::reset();
   }  

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "Village Path");
    set("long",
	"You are inside the village near the southern gate.  To the "
              "east and west are small buildings, probably houses for the "
              "few people that choose to live in the village.  The path "
              "continues north towards the center of the village and south "
              "to the wall and through the gate.\n" );
    set("night long",
             "The entire village seems abandoned and dead.  Shadows "
              "cast on the walls of nearby buildings show you no details, "
              "though the lack of light from the inside implies that they "
              "are abandoned.  A bright glow comes from the north end "
              "of the village.  The path continues to the north and "
              "south to the wall and through the gate.\n");
    set_smell("default", "The smell of smoke overpowers all other "
              "smells inside the village.");
    set_listen("default", "The village is quiet, but you think you hear "
                    "some noise from the north end of the village.");
    set_items(([
     ({ "path" }) :
         "It is well worn from constant traffic within the village.",
     ({ "village" }) :
         "It is definately small.  Not many people could live in it "
         "comfortably.",
    ({ "wall", "walls", "embankment" }) :
         "The wall is solid and well made, if only wood.  The earth "
         "embankment on the inside serves to both support the wall "
         "itself and to provide a platform for attacking at opponents "
         "outside the wall.",
     ({ "gate" }) :
         "The gate is made of good hardwood bound in iron bands.  It "
         "would difficult to force entry into the village... assuming that "
         "anyone was bothering to defend the gate, that is.  As you look "
         "around, you note that the crossbar used to lock the gate is "
         "missing.  They couldn't lock the gate if they wanted to.",
    ({ "building", "buildings", "house", "houses" }) :
         "They are, not surprisingly, made from wood.  They have a "
         "basic construction, but are probably functional.",
     ({ "glow" }) :
         "The glow dominates the northern end of the village.  You are "
         "still too far away to see its source.  Maybe the town itself is "
         "on fire.",
]));
    set_exits((["north":HIV_ROOMS+"village_11.c",
                     "south":HIV_ROOMS+"village_09.c",
                     "east":HIV_ROOMS+"village_20.c",
                     "west":HIV_ROOMS+"village_19.c"])); 

	set_door("gate", HIV_ROOMS+"/village_09.c", "south",
 		0);
	set_open("gate", 0);
	set_locked("gate", 0);
	set_string("gate", "open", "You push the gate open.\n");

}

