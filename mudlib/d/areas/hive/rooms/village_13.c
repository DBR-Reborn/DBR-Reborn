//      Wizard:  Myrddin
//      village_13.c
//      June 97


#include "../defs.h"
#include <std.h>
inherit "std/room";

void reset(){
  ::reset();
  if(!present("tracker_02")) {
         new(HIV_MON+"tracker_02")->move(this_object());
         new(HIV_MON+"tracker_02")->move(this_object());
   }  
}

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set_property("night light", 1);
    set("short", "Village Path");
set("long",
	"You are in the northern side of the village.  To the "
              "east and west are fairly large buildings, probably public "
              "buildings of some sort. You are surprised to note some "
              "people quietly standing out of plain sight.  You can see the "
             "village center to the south, and smoke rising to the north.\n" );
    set("night long",
             "The pervading gloom is finally broken by the bright light "
             "coming from the north.  You can see what appears to be a "
             "roaring fire in the street ahead.  You also see the moving "
             "shapes of humanoid forms.  Large buildings are to the east "
             "and west, while the path continues to the north and to the "
              "south.\n");
    set_smell("default", "The smell of smoke overpowers all other "
                   "smells inside the village.");
    set_listen("default", "You hear the noise of people coming from "
                   "the north.");
    set_items(([
     ({ "path" }) :
         "It is well worn from constant traffic within the village.",
     ({ "village" }) :
         "It is definately small.  Not many people could live in it "
         "comfortably.",
    ({ "building", "buildings" }) :
         "They are the largest buildings you have seen in the village "
         "and, not suprisingly, made from wood.  They have a "
         "basic construction, but are probably functional.",
    ({ "light", "fire" }) :
         "The glow from the fire dominates the northern end of the "
         "village.  From here you can see flames rising at least 8 feet "
         "into the air, with figures standing around it.",
({ "people", "forms" }) :
         "They have placed themselves almost as if they don't want to "
         "be seen, and act in a very strange fashion.  They look like "
         "they are trying to watch for something dangerous "
         "approaching, but that doesn't seem to include you.",
]));
    set_exits((["north":HIV_ROOMS+"village_14.c",
                     "south":HIV_ROOMS+"village_12.c",
                     "east":HIV_ROOMS+"village_22.c",
                     "west":HIV_ROOMS+"village_24.c"])); 
}

