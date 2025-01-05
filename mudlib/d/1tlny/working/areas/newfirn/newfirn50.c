//      Wizard:  Gellor
//      New Firn'Ville
//      newfirn50.c
#include <std.h>
inherit VAULT;
void create() {
    ::create();
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "South East Corner Of The Market");
    set("long", "This is the south east corner of New Firn'Ville's "
    				 "Market. Commerce is carried out here on a full time "
                "basis by many races and professions. Perhaps you can "
                "find something of value to buy around here. But look "
                "out! Some of the merchants might try to cut a deal "
                "which is too good to be true!" );
    add_exit("newfirn47.c", "north");
    add_exit("newfirn49.c", "west");
    set_smell("default", "The air smells like all sorts of things; "
    							 "leather, metal, food, and who knows what "
                         "else!");
    set_listen("default", "Mostly what you hear is people communicating "
                          "in all different ways; shouting, talking, "
                          "complaining, thanking.");
}
