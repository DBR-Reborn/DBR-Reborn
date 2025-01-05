#include <daemons.h>

inherit "/std/vault";

private int open;


void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/wizards/shade/stone_garden/rooms/small_hut", "east");
   add_exit("sg_toolshed", "west");
  add_exit("sg_junkyard","southwest");
   set_door("stone door", "/wizards/shade/stone_garden/rooms/small_hut", "east",
  "stone garden key");
   set_open("stone door", 0);
   set_locked("stone door", 1);

   set("short","Hidden stone clearing");
   set("long",
"You find yourself in a hidden stone clearing. A sheer stone rockwall rises to the northeast, while several dusty paths head off in various directions. Trees line the clearing in a ring, with the centre of the clearing totally bare, except for a few dead logs and an old campfire in the centre. There is a small toolshed to the west and a stone door entering the rackface to the east.");
 add_item("rockwall","A sheer rock face rises up about 25-30 feet into the air. It forms part of a ridge, that goes further to the north and south. Its smooth face, preventing anyone from climbing it.");
 add_item("trees","Tall birch trees stand upright surrounding this clearing, like sentinels. Their base is of solid rock, and their branches span over the clearing, high above the campfire remains,");
 add_item("log","This petrified stone log is one of about 5 which encircle the campfire.");
 add_item("logs","There are a few old deadwood logs here, encircling the campfire.");
 add_item("campfire","The old campfire is consists mainly of ashes, and a few charred pieces of wood here. The charred wood seems much lighter than the trees around, and knocking on the wood reveals it is not made of stone.");
add_item("ashes","There are grey ashes in the campfire remains, remnants of prior campfire burnings.");
  add_item("vault door", "This is a large vault door.\n");
}



