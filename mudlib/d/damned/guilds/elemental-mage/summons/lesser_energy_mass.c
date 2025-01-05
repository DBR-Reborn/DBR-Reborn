#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("energy mass");
    set_level(10);
    set("id", ({ "energy mass", "mass", "mass of energy", "small mass", "small mass of energy" }));
    set_short("%^BOLD%^%^CYAN%^A small mass of energy%^BOLD%^%^RED%^");
    set_long("This is a small compact mass of somewhat swirling energy. It is the primary object used by an Elemental Mage to cast his/her various types of magics, as power is drawn directly from it during incantations.");
    set("race", "energy");
    set_gender("neuter");
    set_body_type("ingot");
    set_property("no extra lores", 1);
    set_property("no kill", 1);
    set_property("no kill msg", "The mass of energy is immaterial and far too active to control, thus is impossible to hamper.");
    set_skill("attack", -1000);
    set_skill("melee", -1000);
    set_hp(5000);
    set_max_hp(5000);
    set_overall_ac(300);
    return;
}
