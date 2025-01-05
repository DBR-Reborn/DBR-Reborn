//      Wizard:  Myrddin
//      village_22.c
//      June 97

#include "../defs.h"

inherit "/std/vault";

void reset(){
  ::reset();
    if(!present("ranger")) {
         new(HIV_MON+"ranger")->move(this_object());
         new(HIV_MON+"ranger")->move(this_object());
         new(HIV_MON+"ranger")->move(this_object());
  }
if(!present("farmer_01")) {
         new(HIV_MON+"farmer_01")->move(this_object());
         new(HIV_MON+"farmer_01")->move(this_object());
         new(HIV_MON+"farmer_01")->move(this_object());
  }  
    if(!present("mayor")) {
         new(HIV_MON+"mayor")->move(this_object());
  }
    if(!present("vranger_01")) {
         new(HIV_MON+"vranger_01")->move(this_object());
  }
}

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Village Inn");
    set("long",
	"You have entered what is obviously the inn.  It has a few "
              "tables, a small bar, a couple rooms and a sectioned off "
              "kitchen (apparently it's not a big enough inn to get a "
              "separate room for its kitchen).  However, it looks more like "
              "a command center for the villages defenders than an inn at "
              "this moment.  You don't even see the innkeeper.\n" );
    set_smell("default", "Moving indoors finally gets you away from "
              "the smell of the smoke.  You can catch the lingering smell "
              "of cooking food.");
    set_listen("default", "The building is filled with the bustle of "
                    "people in frantic action.");
    set_items(([
     ({ "table", "tables" }) :
         "There are three tables in the inn, all covered with different "
         "maps of the village and the surrounding terrain.  Apparently, "
         "they are being used in planning the defense of the village and "
         "in scouting out the enemy.",
    ({ "bar" }) :
         "The bar is, like most things in this village, made of wood and "
         "not very impressive.  There is a sign in the middle of the bar.  "
         "A quick glance behind it shows, to your disappointment, that "
         "all of its supplies were removed long ago.",
    ({ "room", "rooms" }) :
         "It looks like the inn has not one, but TWO rooms normally "
         "available for renting.  The owner must be proud.  You could "
         "probably 'open door1' or 'open door2' to get into them.",
    ({ "kitchen" }) :
         "You peak behind the 5 foot wall separating the kitchen from "
         "the rest of room.  There is a stove with some cold food on it, a "
         "hinged panel on the floor and a wood pile.",
    ({ "panel" }) :
         "You open the panel on the floor and look inside.  It covers a "
         "hole about two feet deep directly dug into the dirt below the "
         "inn.  You surmise they kept food here for the inn (to keep it "
         "cold and fresh, the latest modern convenience).  "
         "Unfortunately, the hole is currently empty.",
    ({ "food" }) :
         "The food on the stove is cold and does not look good at all.  It "
         "is certainly responsible for the lingering smells in the room, "
         "but the ranger who fixed it is certainly not a cook.  You, in a "
         "fit of brilliance, choose to ignore it.",
    ({ "stove" }) :
         "A wood burning stove.  It is made of thick iron which is still "
         "quite hot after cooking the latest meal.",
    ({ "wood", "pile", "wood pile" }) :
         "A small pile of wood, to be used in the stove when cooking.",
    ({ "sign" }) :
         "The sign reads, 'Closed for the duration of the crisis'.",
    ({ "map", "maps" }) :
         "You look more closely at the maps scattered on the table.  "
         "They show the village in the center with the surrounding "
         "terrain.  Most of the nearby woods are  marked as 'clear', but "
         "most of the rocky hill to the north is marked 'unknown', with "
         "several 'hostile' markers along the base of the hill.",
]));
    set_exits((["west":HIV_ROOMS+"village_13.c",
                     "south":HIV_ROOMS+"village_17.c",
                     "room1":HIV_ROOMS+"village_104.c",
                     "room2":HIV_ROOMS+"village_105.c"])); 

	set_door("door1", HIV_ROOMS+"/village_104.c", "room1",
 		0);
	set_open("door1", 0);
	set_locked("door1", 0);
	set_string("door1", "open", "You push the door to room1 "
                             "open.\n");


	set_door("door2", HIV_ROOMS+"/village_105.c", "room2",
 		0);
	set_open("door2", 0);
	set_locked("door2", 0);
	set_string("door2", "open", "You push the door to room2 "
                              "open.\n");


}

