#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
  ::create();
  set_name("dracolich");
  set_combat_chance(100);
  set_id(({ "dracolich", "undead", "lich" }));
  set("race", "undead");
  set_body_type("winged-humanoid");
  set_property("enhance criticals", -3);
  set_level(23);
  set_overall_ac(20);
  set_overall_ac(4);
  set_short("[23]ominous Dracolich");
  set_long("This undead dragon is perhaps one of the most powerful of "
  "undead creatures.");
  set_property("physical resistance",
	       ([ "default" : 95, "iron" : 95, "steel" : 95, "wood" : 95,
	            "silver" : -20 ]));
  set_max_hp( 6 * 70 + 2000 );
  set_hp( 6 * 500 + 5*6 );
  set_skill("melee", 110 + 5*6);
  set_skill("dodge", 60 + 5*6);
  set_skill("parry", 65 +5*6);
  set_stats("strength", 90 + 8 * 6);
  set_property("melee damage", ([ "cold" : 39 + (4 * 6) ]) );
  set_stats("intelligence", 98);
  set_skill("elementalism", 75+3*6);
  set_skill("chaos lore", 75+3*6);
  set_skill("black magic", 90+2*6);
  set_spell_level("chill touch", 6);
  add_spell("chill touch", "$A");
  set_spell_level("cold blast", 6);
  add_spell("cold blast", "$A");
  set_max_mp(3000);
  set_mp(900+70*6);
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
  set_property("gang bang", 1);
  set_money("gold", random(200)*6);
  return;
}        
	    