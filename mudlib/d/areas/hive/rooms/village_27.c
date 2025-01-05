//      Wizard:  Myrddin
//      village_27.c
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
    set("short", "Outside the Gate");
    set("long",
	"You are on the border of the forest and a small clearing.  "
              "Remarkably, there is a village built within the clearing.  "
              "Perhaps it is a trading post for the hunters and farmers in "
              "the area.  It is surrounded by wooden walls, and you do not "
              "see any activity at the village.  Now that you "
              "think about it, you do not hear any of the sounds you "
              "would expect from a village either.  Just silence.\n" );
    set("night long",
             "The path opens up into a small clearing dominated by a "
             "tiny village. There seems to be a glow coming from the "
             "north edge of the village, allowing you to see some of its "
             "shape.  However, other than the glow, you can see no "
             "sign that the village is occupied.\n");
    set_smell("default", "You start to smell some smoke over the "
             "smells of the forest. ");
    set_listen("default", "You cannot hear anything from the village "
            "but a deep silence.");
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
         "It continues east into the forest and west into the village.",
    ({ "gate" }) :
         "The gate is made of good hardwood bound in iron bands.  It "
         "would difficult to force entry into the village... assuming that "
         "anyone was bothering to defend the gate, that is.",
     ({ "village" }) :
        "The village looks pretty small.  It is most likely a gathering "
        "place for the nearby farmers and hunters rather than a place "
        "for a multitude to live and work.",
     ({ "glow" }) :
        "It looks like it is coming from inside the village.  After much "
        "thought on the glow itself and the smell of smoke, you begin "
        "to suspect a fire.",
     ({ "wall", "walls" }) :
        "The wall is made of wood.  Probably the same wood cut to "
        "make a clearing.  It is about ten feet tall and looks pretty "
        "sturdy.  Not enough to hold off a determined attack, but "
        "quite sufficient to protect against bandits or wildlife.",
]));
    set_exits((["west":HIV_ROOMS+"village_26.c",
                    "east":HIV_ROOMS+"village_28.c"])); 
}

