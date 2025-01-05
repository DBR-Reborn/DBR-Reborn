#include "../zoo.h"

inherit MONSTER;

void create() {
int pow=6;
  ::create();
  set_name("lord of death");
  set_combat_chance(100);
  set_id(({ "lord", "lord of death", "undead"}));
  set("race", "undead");
  set_body_type("humanoid");
  set_property("magic resistance", 120);
  set_skill("resist stun", 275);
  set("see invis", 1);
  set_property("enhance criticals", -5);
  set_level(55);
  set_overall_ac(300);
  set_short("(55)Lord of Death");
  set_long("A Lord of Death stands before you. It is a shadow of its former self... pure death.");
  set_property("physical resistance", ([ "default" : 300]));
  set_property("magical resistance", ([ "default" : 300]));
  set_max_hp(pow * 2000 );
  set_hp(pow * 2000 );
  set_max_mp(1000 * pow);
  set_mp(1000 * pow);
  set_skill("melee", 250 + 5*pow);
  set_skill("dodge", 80 + 5*pow);
  set_skill("parry", 85 +5*pow);
  set_skill("attack", 250 + 5*pow);
  set_stats("strength", 120 + 5 * pow);
  set_property("melee damage", ([ "cold" : 60 + (10 * pow), "unholy" : 60 + (10 * pow), "infernal" : 60 + (10 * pow), "disruption" : 60 + (10 * pow) ]) );
  set_stats("intelligence", 120);
  set_skill("elementalism", 115+3*pow);
  set_skill("aether lore", 115+3*pow);
  set_skill("black magic", 150+5*pow);
  set_spell_level("lifesteal", 6);
  add_spell("lifesteal", "$A");
  set_spell_level("decay", 6);
  add_spell("decay", "$A");
  add_spell("cold blast", "$A");
  set_spell_level("cold blast", 6);
  add_spell("greater elemental strike", "$A");
  set_spell_level("greater elemental strike", 6);
  set_skill("concentrate", 200);
  force_me("use concentrate");
  set("aggressive",1);
  set_property("gang bang", 1);
  set_money("gold", random(200)*6);
  return;
}

string query_element() { return "aether"; }

void die(object ob) {
    message("info", "%^GREEN%^%^BOLD%^A soul escapes back to the nether world",
	  environment());
::die();

   }