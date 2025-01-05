#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
  ::create();
  set_name("nethergeist");
  set_combat_chance(100);
  set_id(({ "nethergeist", "undead", "shadowy nethergeist"}));
  set("race", "undead");
  set_body_type("humanoid");
  set_property("enhance criticals", -5);
  set_level(30);
  set_overall_ac(60);
  set_overall_ac(30);
  set_short("[30]shadowy Nethergeist");
  set_long("This undead is perhaps one of the most powerful of "
  "undead creatures.");
  set_property("physical resistance",
	       ([ "default" : 96, "iron" : 96, "steel" : 96, "wood" : 96,
	            "silver" : -20 ]));
  set_max_hp( 6 * 90 + 2000 );
  set_hp( 6 * 700 + 5*6 );
  set_skill("melee", 210 + 5*6);
  set_skill("dodge", 80 + 5*6);
  set_skill("parry", 85 +5*6);
  set_stats("strength", 110 + 8 * 6);
  set_property("melee damage", ([ "unholy" : 39 + (5 * 6) ]) );
  set_stats("intelligence", 120);
  set_skill("elementalism", 95+3*6);
  set_skill("chaos lore", 95+3*6);
  set_skill("black magic", 120+2*6);
  set_spell_level("chill touch", 6);
  add_spell("chill touch", "$A");
  set_spell_level("wind of death", 6);
  add_spell("wind of death", "$A");
  set_max_mp(5000);
  set_mp(1100+70*6);
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
  set_skill("concentrate", 200);
    force_me("use concentrate");
  set_property("gang bang", 1);
  set_money("gold", random(200)*6);
  return;
}