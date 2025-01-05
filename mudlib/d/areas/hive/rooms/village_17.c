//      Wizard:  Myrddin
//      village_17.c
//      June 97

#include "../defs.h"

inherit "std/vault";

void reset(){
  ::reset();
   }  

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "Village Path");
    set("long",
	"You are to the east of the village center, which you can "
              "still see to the west.  There is a large building you can "
              "enter to the north, while there is only the side of a building "
              "to the south.  The path continues back to the village center "
              "and east to the wall and through the villages east gate.\n" );
    set("night long",
             "You walk in the deep shadows of the night.  You can make "
             "out a glow coming from the north, but its light does not "
             "penetrate past the large building to the north.  You can "
             "make out the wall and the east gate in the darkness.\n" );
    set_smell("default", "The smell of smoke overpowers all other "
                   "smells inside the village.");
    set_listen("default", "You hear some noise coming from the north "
                    "end of the village.");
    set_items(([
     ({ "path" }) :
         "It is well worn from constant traffic within the village.",
     ({ "center" }) :
         "The village center is to the west.  It looks like there is a "
         "fountain there.",
     ({ "village" }) :
         "It is definitely small.  Not many people could live in it "
         "comfortably.",
      ({ "glow" }) :
         "The glow dominates the northern end of the village.  You "
         "cannot see its source with the large building to the north "
         "between you and the glow.",
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
    ({ "building", "buildings" }) :
         "The building to the north is large and looks like it might be an "
         "inn.  It has a sign on it with a bed on it anyway.  To the south "
         "you see the wall of a smaller building, probably a house of "
         "some sort.",
]));
    set_exits((["north":HIV_ROOMS+"village_22.c",
                     "east":HIV_ROOMS+"village_26.c",
                     "west":HIV_ROOMS+"village_12.c"])); 

	set_door("gate", HIV_ROOMS+"/village_26.c", "east",
 		0);
	set_open("gate", 0);
	set_locked("gate", 0);
	set_string("gate", "open", "You push the gate open.\n");

}

