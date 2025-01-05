//      Wizard:  Gellor
//      New Firn'Ville Dwelling
//      dwelling2.c
#include <std.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "A Dwelling");
    set("long", "This is the dwelling of a citizen of New Firn'Ville. "
                "There is nothing special about it. The walls are a lightly "
                "stained wood which lightly scents the air. The "
                "floor, made of loosely laid wood planks, creaks loudly "
                "beneath your feet. Above you is a vaulted log ceiling "
                "which, by evidence of mildew and moisture, is not in the "
                "best condition.");
            add_exit("newfirn3.c","east");
    set_items(([
     ({ "wall","walls" }) :
        "The walls are made of well cut and assembled wooden boards. The "
        "of wood is difficult to discern. A quick inspection reveals no "
        "serious leaks or drafts from the walls. Looks like a solid job.",
     ({ "floor","planks" }) :
        "The wood floor gives away it's age by it's loud, incessant "
        "creaking. Also it no longer has the brillant sheen of a newly "
        "stained and laquered floor. The boards used in it's construction "
        "are roughly 7 feet long and six inches wide.",
     ({ "ceiling","roof" }) :
        "The ceiling is vaulted at about a 35 degree angle with the apex "
        "about 20 feet above the floor. It is constructed of cheap "
        "wood, probably pine, and is beginning to weather." ]));
    set_smell("default", "You can smell various woods here and the faint "
    							 "scent of recently eaten food.");
    set_listen("default", "This dwelling is very quiet. You don't hear "
    							  "much in here.");
}
