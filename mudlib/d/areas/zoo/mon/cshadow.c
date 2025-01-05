#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    ::create();
    set_name("chaos shadow");
    set("race", "shadow");
    set_id(({ "shadow", "chaos", "pure chaos", "chaos shadow", "pure chaos shadow", "shadow of chaos", "shadow of pure chaos", "undead" }));
    set_body_type("human");
    set_level(55);
    set_property("enhance criticals", -2);
    set_property("pet name", "chaos shadow");
    set_overall_ac(400);
    set_skill("concentrate", 200);
    set_short("[55]Shadow of Pure Chaos");
    set_property("pet short", "Shadow of Pure Chaos");
    call_out("nether_form_check", 0);
    set_long("This is a small but apparently very active amalgamation of what can only be described as pure abysmal chaos. An incarnation of several of the most damned netherworld souls, this truly appears to be quite a formidable foe especially as it body almost endlessly swirls with numerous dark and distorted colors.");
    force_me("use concentrate");
    set_max_hp(7500 + 750*6);
    set_hp(7500 + 750*6);
    set_max_mp(6600 + 660*6);
    set_mp(6600 + 660*6);
    set_skill("attack", 55*6);
    set_skill("melee", 55*6);
    set_skill("dodge", 40*6);
    set_skill("parry", 48*6);
    set_skill("owedquar's will", 50*6);
    set_skill("chaos magic", 50*6);
    add_spell("black fire", "$A");
    set_spell_level("black fire", 6);
    add_spell("hell blast", "$A");
    set_spell_level("hell blast", 6);
    set_property("melee damage", ([ "cold" : 45 + (11 * 6), "unholy" : 45 + (11 * 6), "disruption" : 45 + (11 * 6)  ]));
    set_money("gold", random(200)*6); 
	set_property("gang bang", 1);
	set("aggressive",1);
    return;
}

