//      Wizard:  Myrddin
//      village_69.c
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
    set("short", "Base of the Hill");
    set("long",
	"The forest rapidly thins out as you reach the base of the "
              "hill.  Although you cant see anything specific due to all "
              "the rocks and ground cover, you get the impression of "
              "movement over almost the entire hill.  This does not look "
              "safe.\n" );
    set("night long",
             "The forest rapidly thins out as you reach the base of the "
             "hill.  The hill looks stark and ominous in the dark, the "
             "jutting rocks looking like tombstones in the night.\n");
    set_smell("default", "The forest smells fresh and clean.");
    set_listen("default", "You hear nothing but the expected wildlife.");
    set_items(([
     ({ "forest", "trees" }) :
        "The forest is thins out here, as it is unable to find a lot of good "
        "ground on the rock filled hill.",
     ({ "trail" }) :
        "You lose track of the trail as the underbrush thins out over the "
        "rocky ground.",
   ({ "rock", "rocks" }) :
        "There seem to be a lot of rocks on the hill, of various sizes and "
        "shapes.",
     ({ "hill" }) :
        "The hill is pretty large, and is covered with rocks.  With the "
        "prevalence of rocks and the natural defensiveness of the hill, "
        "you could easily imagine a castle being built here over the next "
        "century to provide a stronghold near the village.",
     ({ "underbrush" }) :
        "The underbrush thins out over the rocky ground, just like the "
        "forest.",
    ({ "groundcover" }) :
        "Although the forest and underbrush thin out greatly on the "
        "rocky hill, they are still present wherever the rocks give way to "
        "earth.",
]));
    set_exits((["northwest":HIV_ROOMS+"village_70.c",
                     "north":HIV_ROOMS+"village_71.c",
                     "northeast":HIV_ROOMS+"village_72.c"])); 
}

