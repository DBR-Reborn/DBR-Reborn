//      Wizard:  Myrddin
//      village_105.c
//      June 97

#include "../defs.h"

inherit "/std/vault";

void reset(){
  ::reset();
    if(!present("vranger_01")) {
         new(HIV_MON+"vranger_01")->move(this_object());
   }  
}

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Inn Room");
    set("long",
	"The inn room is small, but occupied.  It has the "
              "minimum required furniture to be considered a place to "
              "stay.  Most people who stay at this inn probably spend "
              "most of their time in the inns main room.\n" );
    set_smell("default", "You smell nothing special.");
    set_listen("default", "The room is quiet.");
    set_items(([
     ({ "shelves" }) :
         "They are empty except for a chamber pot, a bowl, and a water "
         "jug.",
     ({ "chamber pot", "bowl", "water jug", "jug" }) :
         "It is made of water and thankfully clean.  Is this really "
         "something a mighty adventurer should be interested in, "
         "especially when the village has been attacked?",
    ({ "bed" }) :
         "It's made of wood, with a soft matress on it.   Well, a bunch of "
         "hay wrapped in coarse cloth, but it beats the hard ground "
         "outside.",
     ({ "furniture" }) :
         "The room contains a bed and some shelves for storing any "
         "gear you may have, both made of wood.",
]));
    set_exits((["inn":HIV_ROOMS+"village_22.c"])); 

	set_door("door", HIV_ROOMS+"/village_22.c", "inn",
 		0);
	set_open("door", 0);
	set_locked("door", 0);
	set_string("door", "open", "You push the door open.\n");

}

