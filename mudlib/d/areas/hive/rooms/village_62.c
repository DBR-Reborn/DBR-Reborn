//      Wizard:  Myrddin
//      village_62.c
//      June 97

#include "../defs.h"

inherit "std/room";

void reset(){
  ::reset();
  if(!present("tracker_02")) {
         new(HIV_MON+"tracker_02")->move(this_object());
         new(HIV_MON+"tracker_02")->move(this_object());
     }  
   }  

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "Burned Building");
    set("long",
	"You stand in the wreckage of a burned building.  The "
              "building itself is totaled, a complete loss.  In the wreckage, "
              "you can make out a large, inhuman corpse.  Some of the "
              "villages defenders are taking the time to gawk at it.  The "
              "village wall is to the north.\n" );
    set("night long",
             "You stand in the wreckage of a burned building.  The "
             "nearby fire lights an eerie scene, a large inhuman corpse.  "
             "Some of the villages defenders are looking at it.\n" );
    set_smell("default", "The smell of smoke from the rubble "
                   "overpowers all other smells.");
    set_listen("default", "You hear the murmur of the villages "
                   "defenders.");
    set_items(([
     ({ "wreckage", "rubble" }) :
         "This building is a complete loss, with everything in the "
         "building destroyed.",
    ({ "fire" }) :
         "The fire casts its light brightly on this nearby spot.  The light "
         "lets you get a pretty good look at the corpse.",
    ({ "corpse" }) :
         "The corpse is badly burned, and was probably responsible for "
         "the fire that destroyed the building.  Its death by fire is "
         "probably the reason the frightened defenders are so eagerly "
         "lighting such a large bonfire in the wooden village.  A close "
         "examination show the corpse to be insectoid in appearance, "
         "with no sight of carried weaponry.",
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
    set_exits((["west":HIV_ROOMS+"village_63.c",
                     "east":HIV_ROOMS+"village_14.c"])); 

}

