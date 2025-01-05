#include "../zoo.h"

inherit MONSTER;

void create() {
int pow=12;
  ::create();
  set_name("everlasting");
  set_combat_chance(120);
  set_id(({ "everlasting", "everlasting death", "undead"}));
  set("race", "undead");
  set_body_type("humanoid");
  set_property("magic resistance", 120);
  set_skill("resist stun", 375);
  set("see invis", 1);
  set_property("enhance criticals", -5);
  set_level(65);
  set_overall_ac(500);
  set_short("(65)ghastly being of everlasting death");
  set_long("Your eyes struggle to focus as you appear to see right through the everlasting");
  set_property("physical resistance", ([ "default" : 500]));
  set_property("magical resistance", ([ "default" : 500]));
  set_max_hp(pow * 3000 );
  set_hp(pow * 3000 );
  set_max_mp(2000 * pow);
  set_mp(2000 * pow);
  set_skill("melee", 250 + 10*pow);
  set_skill("dodge", 80 + 10*pow);
  set_skill("parry", 85 +10*pow);
  set_skill("attack", 250 + 10*pow);
  set_stats("strength", 120 + 10 * pow);
  set_property("melee damage", ([ "cold" : 100 + (10 * pow), "unholy" : 100 + (10 * pow), "infernal" : 100 + (10 * pow), "disruption" : 100 + (10 * pow) ]) );
  set_stats("intelligence", 120);
  set_skill("elementalism", 115+3*pow);
  set_skill("nexus lore", 115+3*pow);
  set_skill("black magic", 150+5*pow);
  set_skill("paralysis magic", 115+3*pow);
  set_spell_level("lifesteal", 6);
  add_spell("lifesteal", "$A");
  set_spell_level("decay", 6);
  add_spell("decay", "$A");
  add_spell("syphon soul", "$A");
  set_spell_level("syphon soul", 6);
  add_spell("stun blast", "$A");
  set_spell_level("stun blast", 6);
  add_spell("cold blast", "$A");
  set_spell_level("cold blast", 6);
  add_spell("greater elemental strike", "$A");
  set_spell_level("greater elemental strike", 6);
  set_skill("concentrate", 500);
    force_me("use concentrate");
  set("aggressive",1);
  set_property("gang bang", 1);
  set_money("gold", random(200)*6);
  return;
}


string query_element() { return "nexus"; }

void die(object ob) {
   object ob1;

   seteuid(getuid());
  ob1 = new(MON+"lod");
  ob1->move(environment());
    message("info", "%^GREEN%^%^BOLD%^An everlasting returns to the undead realm... Leaving behind another it its place...",
	  environment());
::die();

   }