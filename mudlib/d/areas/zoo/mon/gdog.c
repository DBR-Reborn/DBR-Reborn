#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    ::create();
    set_name("ghast dog");
    set("race", "spirit");
    set_combat_chance(120);
    set_id(({ "dog", "ghast dog", "wailing dog", "wailing ghast dog", "undead" }));
    set_body_type("quadruped");
    set_level(22);
    set_property("enhance criticals", 0);
    set_property("nethermancer pet", 1);
    set_property("pet name", "ghast dog");
    set_overall_ac(150);
    set_short("[22]Wailing Ghast Dog");
    set_property("pet short", "Wailing Ghast Dog");
    call_out("nether_form_check", 0);
    set_long("Standing with four paws on the ground yet immaterial in nature, this hound can only be described as unnatural. Unlike the common spirit however, this creature is made of very thick mist and cannot be seen through at all regardless of the administered stare. Wailing noises come from its mouth as it seems to freely move about in the same manner as a completely material being.");
    set_max_hp(900 + 90*6);
    set_hp(900 + 90*6);
    set_skill("attack", 24*6);
    set_skill("melee", 24*6);
    set_skill("dodge", 18*6);
    set_skill("parry", 21*6);
    set_property("melee damage", ([ "cutting" : 20 + (6 * 6), "crushing" : 20 + (6 * 6) ]));
    set_property("gang bang", 1);
    set_money("gold", random(200)*6);
return;
}
