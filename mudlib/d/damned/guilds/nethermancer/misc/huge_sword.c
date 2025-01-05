#include <std.h>

inherit WEAPON;

void create() {
    ::create();
    set_ac(0);
    set_name("A huge skull sword");
    set("id", ({ "sword", "skull sword", "huge sword", "huge skull sword" }));
    set_short("A huge skull sword");
	set_long("This is an enormous black and cyan sword, with its blade extending over seven feet long and its entire hilt made up of a menacing and open mouthed skull. The eyes of the skull radiate an eerie light suggesting that this is no ordinary weapon, in fact this may even be a weapon that has a very soul of its own.");
	set_type("two handed blade");
    set_quality(6);
    set_property("no add quality", 1);
    set_weight(150);
    set_material("metal/elrodnite");
    set_value(6500);
    set_wc(90, "cutting");
    set_wc(75, "unholy");
	set_wc(75, "cold");
    set_verb("lacerate");
    return;
}
