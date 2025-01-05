//      Wizard:  Myrddin
//      village_02.c
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
    set("short", "Forest Path");
    set("long",
	"The path continues to the northwest and to the south.  The "
              "surrounding forest is getting denser as you travel further "
              "into it.  If you tried to leave the path, you would probably "
              "not be able to find your way back.\n" );
    set("night long",
             "The path continues to the northwest and to the south.  In "
             "the dark, the forest becomes a lot more ominous, but it still "
             "seems quiet and peaceful.  You definitely don't want to "
             "leave the path into the wilds of the forest.\n");
    set_smell("default", "The fresh smells of the outdoors make you "
             "happy you left the comfort of the city.");
    set_listen("default", "The woods are even quieter, but you think "
             "you can hear some noise to the northwest.");
    set_items(([
     ({ "forest", "woods", "trees" }) :
        "The forest is no longer sparse.  If you go much farther into it, "
        "you will probably find yourself in the old forest.",
     ({ "path" }) :
        "It continues to the northwest and to the south.",
]));
       set_exits((["south":HIV_ROOMS+"village_ent.c",
                    "northwest":HIV_ROOMS+"village_03.c"])); 
}

