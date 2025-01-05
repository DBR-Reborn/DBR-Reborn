#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    ::create();
    set_name("shadow beast");
    set("race", "beast");
    set_combat_chance(120);
    set_id(({ "beast", "shadow beast", "flesh beast", "shadow and flesh beast", "beast of shadow", "beast of shadow and flesh", "undead" }));
    set_body_type("quadruped");
    set_level(62);
    set_property("enhance criticals", -2);
    set_property("nethermancer pet", 1);
    set_property("pet name", "shadow beast");
    set_overall_ac(450);
    set_short("[62]Beast of Shadow and Flesh");
    set_property("pet short", "Beast of Shadow and Flesh");
    call_out("nether_form_check", 0);
    set_long("A somewhat annoying hum graces the room as you gaze upon this highly irregular and simultaneously fearsome six foot tall creature, the hum entirely generated from the portions of glowing shadows and souls comprising random parts of its body. The rest of the body is made up of terribly tough and torn black flesh alongside eerily glowing claws on all of its paw like limbs and eyes as red as the most pure of blood.");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    set_max_hp(10000 + 1000*6);
    set_hp(10000 + 1000*6);
    set_max_mp(8600 + 860*6);
    set_mp(8600 + 860*6);
    set_skill("attack", 64*6);
    set_skill("melee", 64*6);
    set_skill("dodge", 47*6);
    set_skill("parry", 57*6);
    set_skill("curse lore", 59*6);
    set_skill("warcasting", 59*6);
    add_spell("greater curse", "$A");
    set_spell_level("greater curse", 6);
    add_spell("electrical storm", "$A");
    set_spell_level("electrical storm", 6);
    set_property("melee damage", ([ "cold" : 46 + (13 * 6), "unholy" : 46 + (13 * 6), "disruption" : 46 + (13 * 6)  ]));
	set_property("gang bang", 1);
    set_money("gold", random(200)*6);
    set("aggressive",1);
return;
}
