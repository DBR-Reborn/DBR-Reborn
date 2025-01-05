//      Wizard:  Myrddin
//      village_16.c
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
    set("short", "Village Path");
    set("long",
	"You are at the west end of the village.  There are pretty "
              "large buildings to the north and the south, but you cannot "
              "easily tell their purpose.  The path runs to the east and "
              "ends at the west wall.\n" );
    set("night long",
             "You walk in the deep shadows of the night.  There is very "
             "little light at this part of the village.  You can see buildings "
             "looming to the north and the south, while the path ends to "
             "the west at the villages wall.\n" );
    set_smell("default", "The smell of smoke overpowers all other "
                   "smells inside the village.");
    set_listen("default", "It is very quiet.");
    set_items(([
      ({ "path" }) :
         "It is well worn from constant traffic within the village.",
      ({ "village" }) :
         "It is definitely small.  Not many people could live in it "
         "comfortably.",
      ({ "glow", "light" }) :
         "You can dimly see some light coming from the north of the "
         "village, probably near the path.",
     ({ "building", "buildings" }) :
         "Both buildings seem large enough to be public buildings or "
         "businesses of some sort, but you cannot be sure of their use "
         "from outside.  Apparently their use is common knowledge so "
         "they don't need any signs (or maybe people in these parts just "
         "can't read).",
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
         "up.",
]));

    set_exits((["north":HIV_ROOMS+"village_25.c",
                     "south":HIV_ROOMS+"village_23.c",
                     "east":HIV_ROOMS+"village_15.c"])); 
}

void init() {
        ::init();
        add_action("climb","climb");
}
int climb(string str) {
        if (str == "up") {
                write("You climb up the planks to the wall above.");
                this_player()->move_player(HIV_ROOMS+"village_117");
                return 1;
        }
        else {
        notify_fail("Climb what?\n");
        return 0;
}}



