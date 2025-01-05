//      Wizard:  Myrddin
//      village_ent.c
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
    set("short", "Quiet Forest");
    set("long",
          "You step between a break in the trees to find a worn path.  "
          "It is obviously still used, though not by a lot of traffic.  The "
          "forest is a bit thin here, but it looks to be old, with a lot of "
          "old growth.  There is no sign of any danger.  The path "
          "continues to the north, and you can return the back "
          "through the trees.\n" );
    set("night long",
          "In the dark, the forest becomes a lot more ominous, but it "
          "still seems quiet and peaceful.  You can see the plains back "
          "through the trees, but the forest becomes much more dense "
          "as you travel farther into it.\n");
    set_smell("default", "The fresh smells of the outdoors make you "
          "happy you left the comfort of the city.");
    set_listen("default", "It is quieter than you would expect, with not "
          "many signs of life.");
    set_items(([
     ({ "forest" }) :
        "It is a bit sparse, and definitely quiet... but no, not too quiet.",
     ({ "path" }) :
        "It continues to the north.  It probably gets light traffic, such as "
        "hunters and farmers bringing produce to the Akkad markets.",
     ({ "trees" }) :
        "You can go between the trees, back out of the forest and from "
        "there to distant markets.",
     ]));
     set_exits((["north":HIV_ROOMS+"village_02.c"])); 
    add_exit("/d/damned/virtual/room_27_25.world", "leave");
}

