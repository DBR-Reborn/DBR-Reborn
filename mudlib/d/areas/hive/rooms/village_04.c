//      Wizard:  Myrddin
//      village_04.c
//      June 97

#include "../defs.h"

inherit "std/room";

void reset(){
  ::reset();
  if(!present("father")) {
         new(HIV_MON+"father")->move(this_object());
   }
  if(!present("mother")) {
         new(HIV_MON+"mother_01")->move(this_object());
   }
  if(!present("woman")) {
         new(HIV_MON+"woman")->move(this_object());
         new(HIV_MON+"woman")->move(this_object());
   }
  if(!present("child_01")) {
         new(HIV_MON+"child_01")->move(this_object());
         new(HIV_MON+"child_01")->move(this_object());
         new(HIV_MON+"child_01")->move(this_object());
   }
  if(!present("child_02")) {
         new(HIV_MON+"child_02")->move(this_object());
   }  
  }

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "Forest Path");
    set("long",
	"You come upon a pitiful sight, as a mass of frightened "
              "villagers follows the path toward the southwest.  They "
              "seem to be fleeing from something toward the north, but "
              "you see no immediate danger. The surrounding forest "
              "looks quite old, and you can't help staring at it out of "
              "worry about its hidden dangers.\n" );
    set("night long",
             "The path continues to the north and to the southwest.  In "
              "the dark, with frightened villagers surrounding you, the "
             "forest seems quite threatening.\n");
    set_smell("default", "The smells of the forest are mingled with the "
             "stink of the unwashed villagers.");
    set_listen("default", "The villagers cry softly, and quietly talk "
             "among themselves.");
    set_items(([
     ({ "forest", "woods", "trees", "depths" }) :
        "The forest is thick, filled with ancient trees.  Though not at "
        "their oldest, you still feel a bit smaller in the presence of the "
        " nearby trees.",
     ({ "path" }) :
        "It continues to the north and to the southwest.",
     ({ "band", "travelers", "villagers" }) :
        "There are not a lot of them, and they look pretty pathetic.  You "
        "doubt that they are even carrying anything of value.  What "
        "would cause them to take up such a miserable journey?",
]));
    set_exits((["north":HIV_ROOMS+"village_05.c",
                    "southwest":HIV_ROOMS+"village_03.c"])); 
}

