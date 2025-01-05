#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    ::create();
    set_name("vampiric beast");
    set("race", "undead");
    set_combat_chance(120);
    set_id(({ "hound", "vampiric hound", "vampire", "scarred hound", "scarred vampiric hound", "scarred vampire", "undead" }));
    set_body_type("quadruped");
    set_level(30);
    set_property("enhance criticals", -1);
    set_property("pet name", "vampiric hound");
    set_overall_ac(200);
    set_short("[30]Scarred Vampiric Hound");
    set_property("pet short", "Scarred Vampiric Hound");
    call_out("nether_form_check", 0);
    set_long("Horribly torn with numerous visible battle scars, this large stark white beast appears as if it had been brutally murdered in a different life. Complete with badly blood stained teeth, claws at least two inches long, and a pulsing magical field in the center of its gaping mouth this creature surely is not one most individuals would want to cross in any manner.");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    set_max_hp(2200 + 220*6);
    set_hp(2200 + 220*6);
    set_max_hp(1900 + 190*6);
    set_mp(1900 + 190*6);
    set_skill("attack", 29*6);
    set_skill("melee", 29*6);
    set_skill("dodge", 22*6);
    set_skill("parry", 25*6);
    set_skill("necromancy", 27*6);
    set_skill("owedquar's will", 27*6);
    add_spell("lifesteal", "$A");
    set_spell_level("lifesteal", 6);
    add_spell("black shroud", "$A");
    set_spell_level("black shroud", 6);
    set_property("melee damage", ([ "cutting" : 26 + (8 * 6), "crushing" : 26 + (8 * 6), "impaling" : 26 + (8 * 6)  ]));
	set_property("gang bang", 1);
    set_money("gold", random(200)*6);
return;
}
