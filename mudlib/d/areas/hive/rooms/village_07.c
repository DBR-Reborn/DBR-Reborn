//      Wizard:  Myrddin
//      village_07.c
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
	"The forest is quiet and peaceful.  You resolve not to let it "
              "fool you.  Disasters and bandits always strike when "
              "everything is calm and quiet.  The trees of the forest are "
              "ancient, and they are thick enough to hide nasty "
              "surprises.\n" );
    set("night long",
             "The path continues to the northeast and to the southwest.  "
             "In the dark, you are easily able to convince yourself that an "
             "ambush is waiting for you just past the next tree.\n");
    set_smell("default", "The fresh smells of the forest don't trick you "
             "for an instant.  There is something dangerous out there. ");
    set_listen("default", "It is quiet.  Yes, too quiet.");
    set_items(([
     ({ "forest", "trees" }) :
        "The forest is thick, filled with ancient trees.  You are deep "
        "within the woods now, and feel the weight of all creation on "
        "your shoulders.",
     ({ "path" }) :
        "It continues to the northeast and to the south.",
     ({ "tree" }) :
        "Yes!  That one!  An ambush waiting to happen if you ever saw "
        "one!",
]));
    set_exits((["northeast":HIV_ROOMS+"village_08.c",
                     "southwest":HIV_ROOMS+"village_06.c"])); 
}

