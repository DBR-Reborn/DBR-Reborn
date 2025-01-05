#include <std.h>
#include <necrop.h>

inherit MONSTER;

void create()
{
  ::create();
  set_name("lilith");
  set_gender("female");
  set("id", ({"witch", "lilith"}));
  set("short", "Lilith");
  set("race", "human");
  set_languages(({"elvish", "common", "serra"}));
  set("long",
      "Lilith is a tall and beautiful woman dressed in flowing white "
      "robes. Shining hair, the color of her robes flows down her back. "
      "Her serene face seems young but her eyes tell you she has the "
      "wisdom of one who has lived an extremely long time.");
  set_body_type("human");
  set_level(45);
  set_overall_ac(150);
  set("see invis", 1);
  set_skill("spell sense", 170);
  set_skill("elementalism", 200);
  set_skill("fire lore", 200);
  set_skill("air lore", 200);
  set_skill("electricity lore", 190);
  set_skill("plasma lore", 170);
  set_skill("wind lore", 180);
  set_skill("chaos lore", 175);
  set_skill("aether lore", 165);
  set_skill("nexus lore", 150);
  set_spell_level("greater elemental storm", 6);
  add_spell("greater elemental storm", "$A");
  set_spell_level("greater elemental bolt", 6);
  add_spell("greater elemental bolt", "$A");
  set_spell_level("greater elemental strike", 6);
  add_spell("greater elemental strike", "$A");
  set_spell_level("elemental transformation", 6);
  add_spell("elemental transformation", "$(ME)");
  set_spell_level("elemental aegis", 6);
  add_spell("elemental aegis", "$(ME)");
  set_spell_level("elemental bane", 6);
  add_spell("elemental bane", "$A");
  set_spell_level("elemental presence", 6);
  add_spell("elemental presence", "$(ME)");
  set_property("melee damage", (["fire": 70]));
  set_combat_chance(95);
  set_fingers(5);
  set_property("magic resistance", 40);
  set_class("elementalist");
}


string query_element() {return "nexus";}
