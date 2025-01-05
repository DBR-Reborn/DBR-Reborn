#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("energy mass");
    set_level(80);
    set("id", ({ "energy mass", "mass", "mass of energy", "titanic mass", "titanic mass of energy" }));
    set_short("%^BOLD%^%^WHITE%^A titanic mass of purely dense energy%^BOLD%^%^RED%^");
    set_long("This is by far the largest mass of energy you have ever seen, and the fact it is very well compacted illustrates the expert summoning power required by the one who created it. It swirls at a truly mindblowing speed and emits ear numbing humming sounds at a constant endless pace. This mass is the ultimate tool of the most highly seasoned Elemental Mages, and can be utilized to call forth the most legendary teachings of the elements known to all.");
    set("race", "energy");
    set_gender("neuter");
    set_body_type("ingot");
    set_property("no kill", 1);
    set_property("no kill msg", "The mass of energy is immaterial and far too active to control, thus is impossible to hamper.");
    set_skill("attack", -1000);
    set_skill("melee", -1000);
    set_hp(50000);
    set_max_hp(50000);
    set_overall_ac(1750);
    return;
}
