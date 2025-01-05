//      Wizard:  Myrddin
//      village_08.c
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
	"You suddenly exit the forest into a small clearing.  "
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
     ({ "forest", "trees" }) :
        "The forest is thick, filled with ancient trees.  It appears that the "
        "clearing was cut from the surrounding forest by the villagers.",
     ({ "path" }) :
        "It continues to the north and to the south.",
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
    set_exits((["north":HIV_ROOMS+"village_09.c",
                    "southwest":HIV_ROOMS+"village_07.c"])); 
}

