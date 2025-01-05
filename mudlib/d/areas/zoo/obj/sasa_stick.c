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
    set_type("blunt");
    set_weight(10);
    set_material("metal/eog");
    set_value(10000);
    set_enh_critical(200);
    set_decay_rate(100000);
    set_property("brittle", 600);
    set_property("hit bonus", 500);
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
    set_ac(500, "impaling");
    set_ac(500, "unholy");
    set_ac(500, "fire");
    set_ac(500, "holy");
    set_ac(500, "aether");
    set_ac(500, "plasma");
    set_ac(500, "vacuum");
    set_ac(500, "cutting");
    set_ac(500, "crushing");
    set_ac(500, "disruption");
    set_ac(500, "cold");
    set_ac(500, "chaos");
    set_verb("beat");

   set_wield((: call_other, this_object(), "check_samoan" :));
    return;
}

int check_samoan() {

  if((string)this_player()->query_race() != "samoan") {

    write("Only the God Sasa may wield this weapon!");

    return 0;

  }
return 1;
}
