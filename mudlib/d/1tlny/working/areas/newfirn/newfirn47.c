//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn47.c
#include <std.h>
inherit VAULT;
void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "East Side Of The Market");
    set("long", "You stand on the east side of the Market. The "
    				 "atmosphere here is one of business and commerce. "
                "Most of the time there is at least one person here "
                "wheeling and dealing things of value. Word has it "
                "that thieves like to frequent the market too. Better "
                "keep your eyes peeled!" );
    add_exit("newfirn44.c", "north");
    add_exit("newfirn50.c", "south");
    add_exit("newfirn46.c", "west");
    add_exit("newfirn35.c", "east");
    set_smell("default", "The air smells like all sorts of things; "
    							 "leather, metal, food, and who knows what "
                         "else!");
    set_listen("default", "Mostly what you hear is people communicating "
                          "in all different ways; shouting, talking, "
                          "complaining, thanking..");
}
