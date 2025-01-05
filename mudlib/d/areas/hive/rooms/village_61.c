//      Wizard:  Myrddin
//      village_61.c
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
    set("short", "Burned Building");
    set("long",
	"You stand in the wreckage of a burned building.  Although "
              "it is not totaled, and will probably be rebuilt, you can not "
              "make out its previous function.  At least you don't see any "
              "bones in the rubble.  The village wall is to the north.\n" );
    set("night long",
             "You stand in the wreckage of a burned building.  The light "
             "from the nearby fire provide minimal light for you to see.  "
             "You see nothing here of note.\n" );
    set_smell("default", "The smell of smoke from the rubble "
                   "overpowers all other smells.");
    set_listen("default", "You hear some noise of people coming from "
                   "the west.");
    set_items(([
     ({ "wreckage", "rubble" }) :
         "This building is severely damaged.  The base of the walls "
         "remain, but everything else in it was destroyed.",
    ({ "fire" }) :
         "The fire casts its light brightly on this nearby spot.  It does "
         "not, however, allow you to see anything of note.",
    ({ "wall", "walls" }) :
         "The wall is solid and well made, if only wood.  There is an "
         "earth embankment on the inside serves to both support the "
         "wall itself and to provide a platform for attacking at "
         "opponents outside the wall.",
    ({ "embankment", "platform" }) :
         "It is made of dirt, with space for guards to patrol the wall on "
         "top.  The embankment is probably what saved the wall from "
         "damage from the fire.",
]));
    set_exits((["west":HIV_ROOMS+"village_14.c"])); 

}

