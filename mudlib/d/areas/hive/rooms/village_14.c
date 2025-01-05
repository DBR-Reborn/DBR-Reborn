//      Wizard:  Myrddin
//      village_14.c
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
    set_property("night light", 2);
    set("short", "Bonfire");
    set("long",
	"You are in the north end of the village.  The path ends at "
              "the northern wall... there is no north gate.  A huge bonfire "
              "has been constructed, and there seems to be enough fuel to "
              "keep it burning day and night.  A large crowd has gathered "
              "around the bonfire.  It looks like most of the remaining "
              "population of the village is here.  There are buildings to "
              "the east and west, but they appear badly burned.\n" );
    set("night long",
              "The huge bonfire rages in the night.  A large crowd has "
              "gathered around the bonfire.  It looks like most of the "
              "remaining population of the village is here.  The are "
              "buildings to the east and the west appear damaged.  The "
              "patch continues to the south, but ends at the wall to the "
              "north.\n");
    set_smell("default", "The smell of smoke overpowers all other "
                    "smells inside the village.");
    set_listen("default", "There is a lot of noise coming from the "
                    "gathered crowd.");
    set_items(([
     ({ "path" }) :
         "A large portion of the path is under the bonfire at the "
         "moment.",
     ({ "village" }) :
         "It is definately small.  Not many people could live in it "
         "comfortably.",
     ({ "building", "buildings" }) :
         "They are the badly damaged.  It looks as if they have been "
         "badly burned, which causes you to wonder why there is such "
         "a large bonfire going.  It must be a large risk.",
    ({ "bonfire", "fire" }) :
         "The fire is raging brightly in the street.  Several people carry "
         "lighted brands, while others splash the nearby wood buildings "
         "with water in an effort to keep them damp.  Apparently the "
         "villagers feel the fire somehow keeps them protected.",
    ({ "people", "villagers", "population", "crowd" }) :
         "It looks as if practically everyone left in the village is here.  "
         "They all seem to be armed and act as if they may be attacked "
         "any instant.  Apparently they are in the process of planning "
         "the defense of the village, and perhaps a counterattack.",
    ({ "fuel" }) :
         "In case you hadn't guessed, it lots of wood.  It seems to be a "
         "very common commodity in this village.",
    ({ "wall", "walls" }) :
         "The wall is solid and well made, if only wood.  There is an "
         "earth embankment on the inside serves to both support the "
         "wall itself and to provide a platform for attacking at "
         "opponents outside the wall.",
    ({ "embankment", "platform" }) :
         "It is made of dirt, with space for guards to patrol the wall on "
         "top.  It has some planks along the edge next to the street, "
         "probably to help keep the dirt from sliding down into the "
         "town.",
    ({ "planks" }) :
         "They are really over glorified  tree branches.  They look at bit "
         "worn, as there are notches in some of them.",
    ({ "notches" }) :
         "Now that you look carefully, the notches are placed at regular "
         "intervals... going up.  You think this is how they get onto the "
         "wall.  It would make sense to have the ladder on the opposite "
         "side of the village from the gate, so attackers would have to "
         "make it all along the inner wall, while exposed to archers, to "
         "get down into the village proper.  Perhaps you could 'climb "
         "up'.",
]));
    set_exits((["south":HIV_ROOMS+"village_13.c",
                     "east":HIV_ROOMS+"village_61.c",
                     "west":HIV_ROOMS+"village_62.c"])); 

}


void init() {
        ::init();
        add_action("climb","climb");
}
int climb(string str) {
        if (str == "up") {
                write("You climb up the planks to the wall above.");
                this_player()->move_player(HIV_ROOMS+"village_107");
                return 1;
        }
        else {
        notify_fail("Climb what?\n");
        return 0;
}}



