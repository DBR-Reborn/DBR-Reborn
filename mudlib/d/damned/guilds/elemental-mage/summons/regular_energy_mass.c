#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("energy mass");
    set_level(25);
    set("id", ({ "energy mass", "mass", "mass of energy", "medium mass", "medium mass of energy", "medium sized mass", "medium sized mass of energy" }));
    set_short("%^BOLD%^%^GREEN%^A medium sized mass of energy%^BOLD%^%^RED%^");
    set_long("This is a medium sized mass of compact swirling energy. It serves the purpose of providing considerable energy for an Elemental Mage to cast his/her powerful magic when it is drawn from by the spellcaster.");
    set("race", "energy");
    set_gender("neuter");
    set_body_type("ingot");
    set_property("no extra lores", 1);
    set_property("no kill", 1);
    set_property("no kill msg", "The mass of energy is immaterial and far too active to control, thus is impossible to hamper.");
    set_skill("attack", -1000);
    set_skill("melee", -1000);
    set_hp(10000);
    set_max_hp(10000);
    set_overall_ac(600);
    return;
}
