#include <std.h>

inherit WEAPON;

void create() {
    ::create();
    set_ac(200);
    set_name("sasa stick");
    set("id", ({ "stick", "sasa stick"}));
    set_short("%^BLUE%^Sasa Stick%^RESET%^");
    set_long("This is a large stick that Sasa uses to beat you with.");
    set_quality(6);
    set_type("two handed blunt");
    set_weight(10);
    set_material("metal/eog");
    set_value(10000);
    set_enh_critical(50);
    set_decay_rate(100000);
    set_property("brittle", 600);
    set_property("hit bonus", 250);
    set_property("auto critical", ([ "speed B" : 200 ]));
    set_property("auto critical", ([ "aether D" : 300 ]));
    set_property("auto critical", ([ "disruption D" : 300 ]));
    set_property("auto critical", ([ "cutting D" : 300 ]));
    set_wc(500, "impaling");
    set_wc(500, "chaos");
    set_wc(500, "unholy");
    set_wc(500, "fire");
    set_wc(500, "holy");
    set_wc(500, "aether");
    set_wc(500, "plasma");
    set_wc(500, "vacuum");
    set_wc(500, "cutting");
    set_wc(500, "crushing");
    set_wc(500, "disruption");
    set_wc(500, "cold");
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
    set_verb("beat");
    return;
}
