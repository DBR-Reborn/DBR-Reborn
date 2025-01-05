//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn8.c
#include <std.h>
inherit VAULT;
void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "Just North Of Turn In Trail");
    set("long", "To the south is a bend in the path which turns "
		"to the west. This part continues north towards "
		"several buildings and an intersection . Just to "
		"the northwest is a shop." );
    add_exit("newfirn9.c", "north");
    add_exit("newfirn7.c", "south");
    set_items(([
     ({ "path" }) :
        "The loose-dirt path is narrow here causing anything more than a "
        "cart to be a crowd. Otherwise the path is nothing more than "
        "dirt.",
     ({ "trees","tree","woods","forest" }) :
        "The trees tower above the road forming a pleasant shady area "
        "for travellers and wildlife. A high-man standing beside a tree "
        "would be dwarfed by the tree's immense girth." ]));
    set_smell("default", "You smell clean air.");
    set_listen("default", "Nothing of significance can be heard.");
}
