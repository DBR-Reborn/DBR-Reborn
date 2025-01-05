#include <std.h>
#include "../zoo.h"

inherit MONSTER;

string lore1;

void create() {
	  int pow=6;
  ::create();
  switch(random(5)){
    case 0:lore1="plasma";break;
    case 1:lore1="vacid";break;
    case 2:lore1="nexus";break;
    case 3:lore1="aether";break;
    case 4:lore1="chaos";break;
    }
	
  set_name("undead dragon");
  set_combat_chance(120);
  set_id(({ "undead dragon", "dragon", "undead"}));
  set("race", "undead dragon");
  set_body_type("humanoid");
  set_property("magic resistance", 120);
  set_skill("resist stun", 375);
  set("see invis", 1);
  set_property("enhance criticals", -7);
  set_level(100);
  set_overall_ac(500);
  set_short("[100]%^BLUE%^"+lore1+" %^RED%^Dragon of the undead realm");
  set_long("This a a dragon that comes from the dead. It's scales are spattered with blood.");
  set_property("physical resistance", ([ "default" : 500]));
  set_property("magical resistance", ([ "default" : 500]));
  set_max_hp(pow * 5000 );
  set_hp(pow * 5000 );
  set_max_mp(5000 * pow);
  set_mp(5000 * pow);
  set_skill("melee", 85*pow);
  set_skill("dodge", 50*pow);
  set_skill("parry", 50*pow);
  set_skill("attack", 85*pow);
  set_stats("strength", 120 + (10 * pow));
  set_stats("intelligence", 120);
  set_skill("elementalism", 110+(15*pow));
  set_skill("black magic", 110+(15*pow));
  set_skill("paralysis magic", 110+(15*pow));
  set_spell_level("breathe fire", 6);
  add_spell("breathe fire", "$A");
  set_spell_level("syphon soul", 6);
  add_spell("syphon soul", "$A");
  add_spell("greater elemental strike", "$A");
  set_spell_level("greater elemental strike", 6);
  set_skill("concentrate", 500);
    force_me("use concentrate"); 
  set_property("gang bang", 1);
  set_money("gold", random(400)*6);
  set("aggressive",1);
  if(!present("dragon skin", this_object())) {
    new("/d/damned/guilds/necromancer/obj/dragon_skin")->move(this_object());
    }
  force_me("wear skin");
  return;
}  
  
  string query_element() { return lore1; }
