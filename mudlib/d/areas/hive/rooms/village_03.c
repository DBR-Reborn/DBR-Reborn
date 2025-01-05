//      Wizard:  Myrddin
//      village_03.c
//      June 97

#include "../defs.h"

inherit "std/room";

void reset(){
  ::reset();
  if(!present("tracker")) {
         new(HIV_MON+"tracker_01")->move(this_object());
   }  
}

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "Forest Path");
    set("long",
	"The path continues to the northeast and to the southwest.  "
              "The surrounding forest looks quite old.  You can hardly "
              "imagine all creatures that must spend their lives in its "
              "depths.  The path is your only safety from being lost for a "
              "long, long time. It looks like a ragged band of travellers is "
              "following the path.\n" );
    set("night long",
             "The path continues to the northeast and to the southwest.  "
             "In the dark, the forest no longer seems peaceful, though it "
             "is not really threatening either.  You feel like you are being "
             "watched by some ancient forces, perhaps judging you.\n");
    set_smell("default", "The smells of the forest are heavy and "
             "undisturbed by the smells of civilization.");
    set_listen("default", "You definitely hear the sounds of nearby "
             "travelers.");
    set_items(([
     ({ "forest", "woods", "trees", "depths" }) :
        "The forest is thick, filled with ancient trees.  Though not at "
        "their oldest, you still feel a bit smaller in the presence of the "
        "nearby trees.",
     ({ "path" }) :
        "It continues to the northeast and to the southeast.",
     ({ "creatures", "forces" }) :
        "You imagine they would be big.  With nasty claws and teeth.",
    ({ "band", "travelers" }) :
        "There are not a lot of them, and they look pretty pathetic.  You "
        "doubt that they are even carrying anything of value.  What "
        "would cause them to take up such a miserable journey?",
]));
    
    set_exits((["southeast":HIV_ROOMS+"village_02.c",
                    "northeast":HIV_ROOMS+"village_04.c"])); 
}

