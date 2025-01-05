//    A DEMON PRINCE.

#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
  ::create();
  set_combat_chance(120);
  set_level(40);
    set_property("enhance criticals",-4);
    set_property("magic resistance", 120);
    set_skill("resist stun", 175);
    set_overall_ac(100);
    set_money("gold", random(200)*6); 
	set_property("gang bang", 1);
    set("see invis", 1);
  set_property("physical resistance",
	      ([ "default" : 92, "iron" : 92, "steel" : 92, "wood" : 92 ]));
  set_name("demon");
  set_id(({ "demon prince", "prince", "demon" }));
  set_short("[40]Demon Prince");
  set_body_type("winged-humanoid");
  set("race", "demon");
  set_long(
  "A member of Royality among the Infinite Abyss, this Demon Prince is clad in \
writhing black armour that seems to reach out to the living. It's menacing \
glare is only enhanced by a towering 15 foot height, razor sharp teeth \
glittering from it's foul maw, and blood-crested claws. It laughs \
menancingly at the foolish mortal who dares to challenge it. \n");
set_skill("concentrate", 150);
  set("concentrate", 1);
  force_me("use concentrate");
  set_max_hp(2700 + 90*6);
  set_hp(2700 + 90*6);
  set_skill("melee", 40 + 6 * 10);
  set_skill("parry", 100 + 6 * 6);
  set_skill("dodge", 100 + 6 * 6);
  set_skill("chaos magic", 150);
  set_skill("necromancy", 150);
  set_skill("elementalism", 100);
   set_skill("chaos lore", 100);
  set_max_mp(3000 + 90* 6);
  set_mp(3000 + 90*6);
  set_property("melee damage", ([ "disruption" : 40 + (10 * 6) ]) );
  set_property("melee damage", ([ "unholy" : 40 + (10 * 6) ]) );
  set_spell_level("chaos ball", 6);
  add_spell("chaos ball", "$A");
  set_spell_level("chaos storm", 6);
  add_spell("chaos storm", "$A");
  add_spell("elemental storm", "$A");
  set_spell_level("elemental storm", 6);
  add_spell("greater elemental strike", "$A");
  set_spell_level("greater elemental strike", 6);
  add_spell("lifesteal", "$A");
  set_spell_level("lifesteal", 6);
  set_stats("strength", 115);
  set_stats("intelligence", 115);
  set("aggressive",1);
  return;
}


string query_element() { return "chaos"; }


