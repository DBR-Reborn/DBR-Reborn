//      Wizard:  Myrddin
//      village_23.c
//      June 97

#include "../defs.h"

inherit "/std/room";

void reset(){
  ::reset();
}  

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Craft Center");
    set("long",
	"This building can generally be described as a big empty "
              "room.  There are some worn tables around the edge of the "
              "room, and a bookcase at the back.\n" );
    set_smell("default", "Moving indoors finally gets you away from "
              "the smell of the smoke.");
    set_listen("default", "The building is silent.");
    set_items(([
     ({ "tables" }) :
         "A careful examination of the tables shows that each one has "
         "some sort of mark carved on it.  The mark would correspond "
         "to one of various skills.  Apparently this building is normally "
         "used to teach novices the skills of a trade when necessary.",
     ({ "bookcase" }) :
         "The bookcase has actually not been stripped like the rest of "
         "the village.  Unfortunately, all it contains is various "
         "woodcarvings.  Ugg.  Maybe you should start calling this "
         "village 'wood village', since they seem to have so much of it.",
     ({ "carvings", "woodcarving", "woodcarvings" }) :
         "They have carvings of just about anything you wouldn't want "
         "to  have.  A bear, a dancing farmer, even one carving of a "
         "man pulling a safe behind him with a rope.",
]));
    set_exits((["north":HIV_ROOMS+"village_16.c"])); 

}


void init() {
        ::init();
        add_action("pull","pull");
}
int pull(string str) {
        if (str == "safe") {
                write("As you pull the carving, a hidden trap door opens "
                         "beneath your feet, dropping you into a room below.");
                this_player()->move_player(HIV_ROOMS+"village_121");
                return 1;
        }
        else {
        notify_fail("Pull what?\n");
        return 0;
}}


