#include <std.h>

inherit MONSTER;


void create()
{
  ::create();
  set_name("worm");
  set_level(5);
  set("short",  "A large purple crawling worm");
  set("long",
      "A large snake with scintilating purple scales that shimmer in the "
       "light. A large round mouth oozes poison as the worm crawls towards you");
  set_gender("nueter");
  set("race","reptile");
  set_overall_ac(100);
  set_melee_damage((["impaling":20, "stress":5]));
  set_body_type("serpent");
  set_skill("melee", 70);
  set_skill("attack", 65);
  set_skill("dodge", 5);
  set_skill("parry", 20);
  set("aggressive", 1);
  set_emotes(10, ({"The worm crawls toward you.",
		   "The worm crunches it teeth at you at you."}), 1);
}


