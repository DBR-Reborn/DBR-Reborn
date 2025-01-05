//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn6.c
#include <std.h>
inherit VAULT;
void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 0);
    set("short", "South Of A Building");
    set("long", "The road narrows even more here. The trees crowd the "
    				 "trail more closely than to the west, in fact some of "
                "the bark has been damaged on some of them due to carts "
                "and other things having to squeeze by oncoming traffic. "
                "To the north is a small building resembling a typical "
                "dwelling. To the east the road turns northward." );
    add_exit("dwelling2.c", "north");
    add_exit("newfirn5.c", "west");
    add_exit("newfirn7.c", "east");
    set_items(([
     ({ "road","path","trail" }) :
        "The loose-dirt path is narrow here causing anything more than a "
        "cart to be a crowd. Otherwise the path is nothing more than "
        "dirt.",
     ({ "trees","tree","woods","forest" }) :
        "The trees tower above the road forming a pleasant shady area "
        "for travellers and wildlife. A high-man standing beside a tree "
        "would be dwarfed by the tree's immense girth.",
     ({ "bark" }) :
     	  "On some of the trees, the bark has been gashed in and damaged "
        "from carts and other equipment slamming against it and scrapping "
        "it while passing by. The trees do not seem to have suffered too "
        "much from the damage however.",
     ({ "building","dwelling" }) :
     	  "It is small, probably providing shelter for one or two inhabitants. "
        "The exterior is a cheap looking brick and the roof appears to be "
        "made of wood planks." ]));
    set_smell("default", "You smell clean air.");
    set_listen("default", "Nothing of significance can be heard.");
}
