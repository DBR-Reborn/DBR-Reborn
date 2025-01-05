//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn7.c
#include <std.h>
inherit VAULT;
void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "A Bend In The Path");
    set("long", "You have reached a bend in the path. From here you "
    				 "can go either west or north. Just to the west can "
                "be seen a small house and a bit north is some sort "
                "of shop. This path seems to be less used than that "
                "to the west as there is some grasses growing on it "
                "and the dirt is not trenched out in the middle." );
    add_exit("newfirn6.c", "west");
    add_exit("newfirn8.c", "north");
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
