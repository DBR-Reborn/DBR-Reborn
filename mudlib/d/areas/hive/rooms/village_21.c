//      Wizard:  Myrddin
//      village_21.c
//      June 97

#include "../defs.h"

inherit "/std/room";

void reset(){
  ::reset();
    if(!present("oldman")) {
         new(HIV_MON+"oldman")->move(this_object());
   }  
}

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "House");
    set("long",
	"This building looks like a small house.  With someone "
              "actually still in it.  It looks like it has been pretty much "
              "stripped down, just like the other houses in the village, but "
              "apparently not everyone left.  A bed and some furniture "
              "are all that are left of note in the room.\n" );
    set_smell("default", "Moving indoors finally gets you away from "
              "the smell of the smoke.  However, you can's say it smells "
              "exactly good inside here either.");
    set_listen("default", "The building is quiet.");
    set_items(([
     ({ "house" }) :
         "It looks like there is a serviceable bed in here, as well as some "
         "clothes and other belongings.",
     ({ "clothes" }) :
         "They are not in terrible condition, but they aren't exactly good "
         "quality either.  Better stick to what you are already wearing.",
    ({ "bed", "frame" }) :
         "It's basically some blankets stuffed with hay on a crude "
         "wooden frame.  This isn't the Akkad hotel after all.",
     ({ "furniture" }) :
         "Well, it is in better shape then the bed frame, but you can't "
         "see making any money selling it.  Not that there is anyone to "
         "sell it to, unless you actually want to lug it all the way back to "
         "Akkad.",
]));
    set_exits((["west":HIV_ROOMS+"village_11.c"])); 

}

