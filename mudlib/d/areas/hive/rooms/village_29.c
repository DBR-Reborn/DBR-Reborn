//      Wizard:  Myrddin
//      village_29.c
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
	"You are moving along a well trod path through the sparse "
              "forest.  The trees appear to be relatively young, slowly "
              "expanding the size of the ancient forest to the west.  "
              "Toward the east, the forest ends and the grasslands stretch "
              "toward the horizon.\n" );
    set("night long",
             "The well used path leads through the sparse forest.  You "
             "cannot see very far in the darkness, but if there was "
             "anything approaching you would still have some advance "
             "warning due to the lack of cover.\n");
    set_smell("default", "The air is fresh with the smells of the"
                   " forest and the plains. ");
    set_listen("default", "You hear nothing but the wind blowing "
                  "quietly through the trees.");
    set_items(([
    ({ "forest", "woods", "trees", "depths" }) :
         "The forest is very thin, and the trees look quite young.",
    ({ "plains" }) :
         "They spread from horizon to horizon once you get out of the "
         "forest.  The land looks like it would be perfect for farming.",
    ({ "path" }) :
         "It continues south into the plains and northwest, deeper into "
         "the forest.",
]));
    set_exits((["northwest":HIV_ROOMS+"village_28.c",
                    "south":HIV_ROOMS+"village_30.c"])); 
}

