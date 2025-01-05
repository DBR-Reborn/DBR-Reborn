#include <std.h>

inherit MONSTER;


void create()
{
  ::create();
  set_name("snake");
  set_level(2);
  set("short",  "A large slithering snake");
  set("long",
      "A large snake with scintilating green scales that shimmer in the "
       "light. Large fangs drip with poison as the snake hisses at you");
  set("race","reptile");
  set_overall_ac(5);
  set_melee_damage((["crushing":5, "poison":5]));
  set_body_type("serpent");
  set_skill("melee", 20);
  set_skill("attack", 20);
  set_skill("dodge", 20);
  set_skill("parry", 20);
  set("aggressive", 1);
  set_emotes(10, ({"The snake slithers around behind you.",
		   "The snake hisses venomously at you."}), 1);
}


