//      Wizard:  Myrddin
//      village_63.c
//      June 97

#include "../defs.h"

inherit "std/room";

void reset(){
  ::reset();
  if(!present("ranger")) {
         new(HIV_MON+"ranger")->move(this_object());
         new(HIV_MON+"ranger")->move(this_object());
         new(HIV_MON+"ranger")->move(this_object());
    }
  if(!present("vranger_01")) {
         new(HIV_MON+"vranger_01")->move(this_object());
     }  
   }  

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "Burned Building");
    set("long",
	"You stand in the wreckage of a burned building.  The "
              "building itself is totaled, a complete loss.  The north wall "
              "here appears to have been badly damaged by the fire.  In "
              "fact, it looks like you could even squeeze through it now.\n" );
    set("night long",
             "You stand in the wreckage of a burned building.  The "
             "fire to the east shows the building to be a complete loss.  "
             "You also note that the north wall looks damaged.  In "
              "fact, it looks like you could even squeeze through it now.\n" );
    set_smell("default", "The smell of smoke from the rubble "
                   "overpowers all other smells.");
    set_listen("default", "You hear the murmur of the villages "
                   "defenders.");
    set_items(([
     ({ "wreckage", "rubble" }) :
         "This building is a complete loss, with everything in the "
         "building destroyed.",
    ({ "fire" }) :
         "The fire can still be seen clearly, but its light has dimmed "
         "greatly by time it reaches here.",
   ({ "wall", "walls" }) :
         "The wall is badly damaged from the fire.  In fact, a close "
         "examination show that it has collapsed in many places, in a "
         "way just the fire wouldnt explain.  The defenders have put up "
         "some makeshift supports to partially rebuild the wall.  You "
         "sigh as you recognize the locking crossbars from the villages "
         "gates being used as the primary supports.  You would think "
         "they could find some strong supports from somewhere else in "
         "village built with wood.  You would also think they would be "
         "a little smarter about proper defense.  The earth embankment "
         "also looks damaged somehow.",
    ({ "embankment", "platform" }) :
         "A close look at the embankment shows that the dirt has been "
         "dug out, probably from the outside.  You realize that either "
         "that insect can tunnel, or it brought along some dwarf miners "
         "when it attacked the village.",
]));
    set_exits((["north":HIV_ROOMS+"village_64.c",
                     "east":HIV_ROOMS+"village_62.c"])); 

}

