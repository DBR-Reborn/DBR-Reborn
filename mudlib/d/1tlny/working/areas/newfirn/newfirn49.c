//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn49.c
#include <std.h>
inherit VAULT;
void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "South Side Of Market");
    set("long", "You stand just north of the main road and on the "
    				 "south side of the Market. Merchants and customers "
                "come here to trade, buy, sell, and even rip-off "
                "each other. Rumor has it that sometimes the King "
                "comes here to encourage the business and spark "
                "even more commerce for the town!" );
    add_exit("newfirn46.c", "north");
    add_exit("newfirn3.c", "south");
    add_exit("newfirn48.c", "west");
    add_exit("newfirn50.c", "east");
    set_smell("default", "The air smells like all sorts of things; "
    							 "leather, metal, food, and who knows what "
                         "else!");
    set_listen("default", "Mostly what you hear is people communicating "
                          "in all different ways; shouting, talking, "
                          "complaining, thanking.");
}
