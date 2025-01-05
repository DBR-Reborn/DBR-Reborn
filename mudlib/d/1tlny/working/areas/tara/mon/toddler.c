#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"
inherit MONSTER;

void create() {
  string var;
  ::create();
   set_name("toddler");
   set("id", ({"toddler", "halfling", "child"}) );
   set_level(1);
   switch(random(3)) {
     case 0: var = "A fed up toddler"; break;
     case 1: var = "A happy toddler"; break;
     case 2: var = "A sleeping toddler"; break;
   }
     this_object()->set("short", var);
   set("long", @TODD
This toddler is obviously disgruntled about having to stay
with babies.  He believes he's ready to move on from his small bed,
into his own room like his sister.
TODD
   );
   set("race", "halfling");
   set_skill("melee", 5);
   set_skill("dodge", 5);
   set_skill("parry", 5);
   set_gender("male");
   set_body_type("human");
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_emotes(5,
     ({
      "The toddler hits a baby in the face.",
      "The toddler looks disgruntled.",
      "The toddler yells for some food!",
      "The toddler kicks around some toys.",
      "The toddler looks at you hopefully.",
     }), 0);
   set_achats(20,
     ({
      "The toddler gets a mean look on his face.",
      "The toddler asks, 'Did I do something wrong?!'",
      "The toddler picks up a toy as a weapon.",
     }) );
   new(TARAOBJ+"t_shorts")->move(this_object());
   force_me("wear shorts");
}
