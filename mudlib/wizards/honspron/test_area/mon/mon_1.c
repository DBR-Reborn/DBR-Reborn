#include <std.h>
#include "../test_area.h"

inherit MONSTER;

object ob;

void create() {

	int pow = 3+random(5);
	
    ::create();
    set_name("pet 1");
    set("race", "human");
    set_combat_chance(120);
    set("id", ({ "pet 1", "pet"}));
    set_body_type("human");
    set_level(20*pow);
    if (pow <= 5){
    set_property("enhance criticals", -5);
    set_overall_ac(250);
    }
    if (pow >= 6){
    set_property("enhance criticals", -10);
    set_overall_ac(1111);
    }
    set_short("["+pow*20+"]Pet 1");
    set_long("This thing looks... different...");
    set_skill("concentrate", 500);
    force_me("use concentrate");
    //force_me("equip");
    set_max_hp(50000 + 5000*pow);
    set_hp(50000 + 5000*pow);
    set_max_mp(40000 + 4000*pow);
    set_mp(40000 + 4000*pow);
    //set_skill("offhand training", 150*pow);
    set_skill("dual attack", 150*pow);
    set_skill("attack", 150*pow);
    set_skill("melee", 150*pow);
    //set_skill("blunt", 145*pow);
    set_skill("dodge", 100*pow);
    set_skill("parry", 120*pow);
    set_skill("black magic", 111*pow);
    set_skill("necromancy", 111*pow);
    set_skill("assassin's magic", 111*pow);
    set_skill("paralysis magic", 111*pow);
    set_skill("elementalism", 111*pow);
    set_skill("nexus lore", 111*pow);
    force_me("use nexus lore");
    add_spell("greater elemental strike", "$A");
    set_spell_level("greater elemental strike", 6);
    //add_spell("pain", "$A");
   //set_spell_level("pain", 6);
    add_spell("decay", "$A");
    set_spell_level("decay", 6);
    if (pow > 4){
    add_spell("syphon soul", "$A");
    set_spell_level("syphon soul", 6);
    }
    if (pow > 5){
    add_spell("dark breath", "$A");
    set_spell_level("dark breath", 6);
    }
	set_property("melee damage", ([ "aether" : 100 + (10 * pow), "plasma" : 100 + (10 * pow), "infernal" : 100 + (10 * pow), "disruption" : 100 + (10 * pow) ]) );
	set_property("gang bang", 1);
    //set_money("gold", 1000000);
    //set_money("mithril", 1000000);
return;
}