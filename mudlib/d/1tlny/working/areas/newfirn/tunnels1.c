//      Wizard:  Gellor
//      New Firn'Ville
//      tunnels1.c
#include <std.h>
inherit VAULT;
void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "A Hole In The Ground");
    set("long", "There is a hole in the ground of this forest "
    				 "cove. The light reveals a small rope ladder along "
                "one side of the hole. A grassy knoll surrounds the "
                "hole and eventually meets the forest. To the west "
                "is a main path." );
    add_exit("tunnel1.c", "down");
    add_exit("newfirn3.c", "west");
    set_items(([
     ({ "road","path","trail" }) :
        "You can see an established path to the west.",
     ({ "trees","tree","woods","forest" }) :
        "The forest provides a temperate climate thanks to the thick "
        "canopy above which keeps out hot sun and cold rain.",
     ({ "hole","rope","ladder" }) :
     	  "From what you can see, the ladder is made of some old, but "
        "good rope and goes down as far as you can see." ]));
    set_smell("default", "The smell of wet dirt fills the air.");
    set_listen("default", "Nothing of significance can be heard.");
}
