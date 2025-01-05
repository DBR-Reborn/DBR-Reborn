//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn9.c
#include <std.h>
inherit VAULT;
void create() {
    ::create();
    set_property("light", 1);
      set_property("indoors", 0);
    set("short", "East Of A Shop");
    set("long", "Loose black soils covers the way north and south. A "
    				 "fancy brick sidewalk runs west to a shop in front of "
                "which is a small sign. The area to the west has been "
                "fenced in and contains many plants not common around "
                "this area. Perhaps they are herbs or something." );
    add_exit("newfirn8.c", "south");
    add_exit("newfirn10.c", "north");
    add_exit("faelana_shop.c", "west");
    set_smell("default", "The scent of herbs fills the air.");
    set_listen("default", "You can hear a wind in the trees above.");
}
