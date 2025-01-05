#include <std.h>

inherit WEAPON;

void create() {
    ::create();
    set_ac(200);
    set_name("sword of honspron");
    set("id", ({ "honspron sword", "sword"}));
    set_short("%^ORANGE%^A rusty old sword%^RESET%^");
    set_long("This is Honspron’s rusty old sword");
    set_quality(6);
    set_type("blade");
    set_weight(10);
    set_material("metal/eog");
    set_value(10000);
    set_enh_critical(200);
	set_decay_rate(100000);
    set_property("brittle", 400);
    set_property("hit bonus", 100);
    set_property("auto critical", ([ "speed B" : 100 ]));
    set_wc(250, "impaling");
    set_wc(250, "chaos");
    set_wc(250, "unholy");
    set_wc(250, "fire");
    set_wc(250, "holy");
    set_wc(250, "aether");
    set_wc(250, "plasma");
    set_wc(250, "vacuum");
    set_wc(250, "cutting");
    set_wc(250, "crushing");
    set_wc(250, "disruption");
    set_wc(250, "cold");
    set_ac(250, "impaling");
    set_ac(250, "unholy");
    set_ac(250, "fire");
    set_ac(250, "holy");
    set_ac(250, "aether");
    set_ac(250, "plasma");
    set_ac(250, "vacuum");
    set_ac(250, "cutting");
    set_ac(250, "crushing");
    set_ac(250, "disruption");
    set_ac(250, "cold");
    set_ac(250, "chaos");
    set_verb("destroy");
    return;
}

