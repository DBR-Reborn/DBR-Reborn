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
    set_type("two handed blade");
    set_weight(10);
    set_material("metal/eog");
    set_value(10000);
    set_enh_critical(200);
    set_decay_rate(100000);
    set_property("brittle", 400);
    set_property("hit bonus", 200);
    set_property("auto critical", ([ "speed B" : 300 ]));
    set_property("auto critical", ([ "aether D" : 300 ]));
    set_property("auto critical", ([ "disruption D" : 300 ]));
    set_property("auto critical", ([ "cutting D" : 300 ]));
    set_property("auto critical", ([ "unholy D" : 300 ]));
    set_property("auto critical", ([ "vacuum D" : 300 ]));
    set_wc(550, "impaling");
    set_wc(550, "chaos");
    set_wc(550, "unholy");
    set_wc(550, "fire");
    set_wc(550, "holy");
    set_wc(550, "aether");
    set_wc(550, "plasma");
    set_wc(550, "vacuum");
    set_wc(550, "cutting");
    set_wc(550, "crushing");
    set_wc(550, "disruption");
    set_wc(550, "cold");
    set_ac(550, "impaling");
    set_ac(550, "unholy");
    set_ac(550, "fire");
    set_ac(550, "holy");
    set_ac(550, "aether");
    set_ac(550, "plasma");
    set_ac(550, "vacuum");
    set_ac(550, "cutting");
    set_ac(550, "crushing");
    set_ac(550, "disruption");
    set_ac(550, "cold");
    set_ac(550, "chaos");
    set_verb("destroy");
    return;
}
