//      Wizard:  Myrddin
//      village_64.c
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
    set("short", "Outside the Wall");
    set("long",
	"You stand in the open zone outside the damaged north wall "
             "of the village.  Although the villagers have attempted some "
             "repairs on the wall, you can still squeeze through it you "
             "wish.  To the north, the heavy forest continues.\n" );
    set("night long",
	"You stand in the darkness outside the damaged north wall "
              "of the village.  Although the villagers have attempted some "
              "repairs on the wall, you can still squeeze through it you "
              "wish.  The light from the fire inside the village bathes the "
              "village with an unnatural light.  To the north, the heavy "
              "forest continues.\n" );
    set_smell("default", "You start to smell some smoke over the "
             "smells of the forest. ");
    set_listen("default", "You cannot hear anything from the village "
            "but a deep silence.");
    set_items(([
     ({ "forest", "trees" }) :
        "The forest is thick, filled with ancient trees.  It has been "
        "cleared for a distance around the village to provide warning of "
        "anyone approaching.",
    ({ "village" }) :
        "The village looks pretty small.  It is most likely a gathering "
        "place for the nearby farmers and hunters rather than a place "
        "for a multitude to live and work.",
     ({ "fire", "light" }) :
        "The fire makes the village look like a scene from the "
        "underworld, but you cant help but think that whatever is in "
        "the forest will be worse.",
     ({ "wall", "walls" }) :
        "The wall is made of wood.  Probably the same wood cut to "
        "make a clearing.  It is about ten feet tall and looks pretty "
        "sturdy.  Directly to your south, the wall has been badly "
        "damaged by fire, and the supporting level seems to have been "
        "dug up from the outside.",
]));
    set_exits((["northwest":HIV_ROOMS+"village_65.c",
                    "south":HIV_ROOMS+"village_63.c"])); 
}

