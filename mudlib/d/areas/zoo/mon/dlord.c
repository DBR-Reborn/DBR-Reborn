#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
  ::create();
  set_name("demon");
  set_id(({ "demon lord", "lord" }));
  set_short("[25]Demon Lord");
  set_body_type("winged-humanoid");
  set("race", "demon");
  set_long(
  "The demon is a huge, red, winged creature with mischeivous eyes.");
  set_level(25);
  set_max_hp(1700 + 90*6);
  set_hp(1700 + 90*6);
  set_skill("melee", 99 + 6 * 7);
  set_skill("parry", 78 + 6 * 6);
  set_skill("dodge", 80 + 6 * 6);
  set_skill("chaos magic", 110);
  set_max_mp(1300 + 90* 6);
  set_mp(1300 + 90*6);
  set_melee_damage(([ "disruption" : 40 + 7*6 ]));
  set_spell_level("disruption bolt", 6);
  add_spell("disruption bolt", "$A");
  set_spell_level("chaos ball", 6);
  add_spell("chaos ball", "$A");
  set_spell_level("chaos storm", 6);
  add_spell("chaos storm", "$A");
  set_skill("concentrate", 200);
  force_me("use concentrate");
  set_combat_chance(120);
  set_property("gang bang", 1);
  set_money("gold", random(200)*6);
  return;
}
