//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn2.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 0);
    set_property("indoors", 0);
    set("short", "An Intersection Of Paths");
    set("long", "Two heavily travelled paths intersect here, one leading "
    				 "north and south, the other leading east and west. The "
                "path here is hard packed dirt littered with foot and hoove "
                "prints. Tall trees tower about the paths and a plush green "
                "carpet of grasses and ferns separates the trail from the "
                "trees. You can barely make out the side of a building to "
                "the east." );
    add_exit("city_enter.c","south");
    add_exit("newfirn3.c", "north");
    add_exit("newfirn34.c", "west");
    add_exit("newfirn4.c", "east");
    set_items(([
     ({ "paths","path","trail","trails" }) :
        "The paths have been here for a while, as evident from the hard "
        "packed dirt which composes it, and from the numerous tracks "
        "abuntant in the dirt.",
     ({ "dirt"}) :
     	  "The dirt is a fine quality black soil containing minimal amounts "
        "of sand.",
     ({ "prints","print","hooves","foot prints" }) :
        "The prints are from various creatures. Most of them appear to be "
        "from men or elves.",
     ({ "trees","tree","grass","fern","ferns","grasses" }) :
        "The trees tower above forming a gorgeous canopy and a stable "
        "environment on the ground. At the foot of the trees is a lush "
        "spread of grasses, ferns, and other small plants." ]));
    set_smell("default", "The air is cool and fresh.");
    set_listen("default", "You can hear a breeze above as well as some "
    							  "activity from the north.");
}
void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("guard")) {
      new("/wizards/gellor/newfirn/mobs/rabbit1.c")->move(this_object());}
}
