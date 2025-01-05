#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
  ::create();
  set_name("abomination");
  set_id(({ "abomination", "undead", "unholy abomination" }));
  set("race", "undead");
  set_body_type("winged-humanoid");
  set_property("enhance criticals", -4);
  set_level(30);
  set_overall_ac(50);
  set_combat_chance(100);
  set_short("[30]Unholy Abomination");
  set_long("This undead thing is perhaps one of the most ugliest things you have ever seen");
  set_property("physical resistance",
	       ([ "default" : 96, "iron" : 96, "steel" : 96, "wood" : 96,
	            "silver" : -20 ]));
  set_max_hp( 6 * 80 + 2000 );
  set_hp( 6 * 600 + 5*6 );
  set_skill("melee", 160 + 5*6);
  set_skill("dodge", 70 + 5*6);
  set_skill("parry", 75 +5*6);
  set_stats("strength", 100 + 8 * 6);
  set_property("melee damage", ([ "unholy" : 39 + (4 * 6) ]) );
  set_stats("intelligence", 108);
  set_skill("elementalism", 85+3*6);
  set_skill("chaos lore", 85+3*6);
  set_skill("black magic", 100+2*6);
  set_spell_level("chill touch", 6);
  add_spell("chill touch", "$A");
  set_spell_level("cold blast", 6);
  add_spell("cold blast", "$A");
  set_max_mp(4000);
  set_mp(1000+70*6);
  set_spell_level("lifesteal", 6);
  add_spell("lifesteal", "$A");
  set_spell_level("decay", 6);
  add_spell("decay", "$A");
  add_spell("greater elemental bolt", "$A");
  set_spell_level("greater elemental bolt", 6);
  add_spell("elemental storm", "$A");
  set_spell_level("elemental storm", 6);
  add_spell("elemental strike", "$A");
  set_spell_level("elemental strike", 6);
  set_money("gold", random(200)*6); 
  set_property("gang bang", 1);
  set_skill("concentrate", 200);
  force_me("use concentrate");
  return;
}


string query_element() { return "chaos"; }



