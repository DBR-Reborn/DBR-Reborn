#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    ::create();
    set_name("blood fiend");
    set("race", "undead");
    set_combat_chance(120);
    set_id(({ "fiend", "vampire", "blood fiend", "thirsty vampire", "thirsty fiend", "thirsty blood fiend", "undead" }));
    set_body_type("human");
    set_level(26);
    set_property("enhance criticals", -1);
    set_property("pet name", "blood fiend");
    set_overall_ac(200);
    set_short("[26]Thirsty Blood Fiend");
    set_property("pet short", "Thirsty Blood Fiend");
    call_out("nether_form_check", 0);
    set_long("This undead being appears horribly pale, with razor sharp claws and blood stained teeth visible from the creature's seemingly always open mouth. Its entire body is very muscular and looks very battle hardened, giving the impression that this vampire is one that is not afraid of resistance when it decides to feed off of a target.");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    set_max_hp(1800 + 180*6);
    set_hp(1800 + 180*6);
    set_skill("attack", 27*6);
    set_skill("melee", 27*6);
    set_skill("dodge", 19*6);
    set_skill("parry", 22*6);
    set_skill("necromancy", 24*6);
    add_spell("lifesteal", "$A");
    set_spell_level("lifesteal", 6);
    set_property("melee damage", ([ "cutting" : 24 + (7 * 6), "crushing" : 24 + (7 * 6), "impaling" : 24 + (7 * 6)  ]));
    set_money("gold", random(200)*6); 
	set_property("gang bang", 1);
    return;
}

