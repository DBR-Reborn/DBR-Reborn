//      Wizard:  Myrddin
//      village_28.c
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
    set("short", "Young Forest");
    set("long",
	"You are moving through the forest along a well trod path.  "
              "The forest is not particularly thick or old.  The trees grow "
              "farther apart than you would expect from an old forest.  "
              "Toward the west the forest appears to get thicker and "
              "older, but to the east it appears to get even thinner.  You "
              "expect the forest will end completely before too long if you "
              "travel in that direction.\n" );
    set("night long",
             "The well used path leads through the thinning forest.  You "
             "cannot see very far in the darkness, but the forest does not "
             "seem to be threatening or ominous.\n");
    set_smell("default", "The air is fresh with the smells of the"
                   " forest. ");
    set_listen("default", "You hear the quiet murmur of the forests "
                    "wildlife.");
    set_items(([
    ({ "forest", "woods", "trees", "depths" }) :
         "The forest is looks is thinning as you head to the southeast, "
         "naturally opening up into grasslands.",
    ({ "path" }) :
         "It continues southeast and west, deeper into the forest.",
]));
    set_exits((["west":HIV_ROOMS+"village_27.c",
                    "southeast":HIV_ROOMS+"village_29.c"])); 
}

