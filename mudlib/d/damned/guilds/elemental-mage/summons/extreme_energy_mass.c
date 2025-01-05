#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("energy mass");
    set_level(60);
    set("id", ({ "energy mass", "mass", "mass of energy", "enormous mass", "enormous mass of energy" }));
    set_short("%^BOLD%^%^YELLOW%^An enormous mass of swirling energy%^BOLD%^%^RED%^");
    set_long("This is an extremely huge mass of quickly swirling high density energy, hovering endlessly above the ground and releasing a loud humming sound which is constant and never ending. This large mass serves as the power source of a highly trained Elemental Mage with the abilities to cast staggering offensive magic.");
    set("race", "energy");
    set_gender("neuter");
    set_body_type("ingot");
    set_property("no kill", 1);
    set_property("no kill msg", "The mass of energy is immaterial and far too active to control, thus is impossible to hamper.");
    set_skill("attack", -1000);
    set_skill("melee", -1000);
    set_hp(30000);
    set_max_hp(30000);
    set_overall_ac(1300);
}
