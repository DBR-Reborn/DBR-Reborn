#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("energy mass");
    set_level(40);
    set("id", ({ "energy mass", "mass", "mass of energy", "large mass", "large mass of energy" }));
    set_short("%^BOLD%^%^BLUE%^A large mass of energy%^BOLD%^RED%^");
    set_long("This is a noticeably large mass of high density energy, swirling at a constant speed as it hovers above the ground. It serves the duty of supplying high power to an Elemental Mage for use in his many deadly magical plights.");
    set("race", "energy");
    set_gender("neuter");
    set_body_type("ingot");
    set_property("no kill", 1);
    set_property("no kill msg", "The mass of energy is immaterial and far too active to control, thus is impossible to hamper.");
    set_skill("attack", -1000);
    set_skill("melee", -1000);
    set_hp(17500);
    set_max_hp(17500);
    set_overall_ac(850);
    return;
}
