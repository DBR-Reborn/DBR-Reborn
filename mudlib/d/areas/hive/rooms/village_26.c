//      Wizard:  Myrddin
//      village_26.c
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
    set("short", "Village Gate");
    set("long",
	 "You in the cleared space in front of the villages gate.  You "
               "can see tree trunks still dotting the cleared land and the "
               "forest to the south.  The path seems to run straight "
               "through the gate and into the village.\n" );
    set("night long",
             "Approaching the village at night makes you distinctly "
             "nervous.  The walls loom out of the shadows of the night, "
              "but you can make out no details of your surroundings.  "
              "You try to move silently as you approach the gate to attract "
              "no unwanted attention.\n");
    set_smell("default", "The smells of human habitation mix with the "
                    "smells of the forest.  The smell of smoke lingers over it "
                    "all.");
    set_listen("default", "The village is completely silent.");
    set_items(([
    ({ "forest", "woods", "trees", "depths" }) :
         "The forest is looks like it thins to the east, perhaps opening up "
         "into grasslands.  Nearby farmers would explain a lot about the "
         "existence of this village.  The trees have been cleared for a "
         "short distance around the village.",
    ({ "trunks" }) :
         "That's what you have left after you cut down a tree.  It looks "
         "like a lot of trees have been cut down, but the village is made "
         "of wood, so that shouldn't be a surprise.",
    ({ "path" }) :
         "It continues south into the forest and north into the village.",
    ({ "village" }) :
         "It is definitely small.  Not many people could live in it "
         "comfortably.  Perhaps no one lives in it anymore.",
    ({ "wall", "walls" }) :
        "The wall is made of wood.  Probably the same wood cut to "
        "make a clearing.  It is about ten feet tall and looks pretty "
        "sturdy.  Not enough to hold off a determined attack, but "
        "quite sufficient to protect against bandits or wildlife.",
    ({ "gate" }) :
         "The gate is made of good hardwood bound in iron bands.  It "
         "would difficult to force entry into the village... assuming that "
         "anyone was bothering to defend the gate, that is.",
     ({ "glow" }) :
         "The glow is obviously coming from the northern end of the "
         "village.  Something over there must be burning quite merrily. ",
]));
              set_exits((["west":HIV_ROOMS+"village_17.c",
                      "east":HIV_ROOMS+"village_27.c"])); 

	set_door("gate", HIV_ROOMS+"/village_17.c", "west",
 		0);
	set_open("gate", 0);
	set_locked("gate", 0);
	set_string("gate", "open", "You push the gate open.\n");
}


