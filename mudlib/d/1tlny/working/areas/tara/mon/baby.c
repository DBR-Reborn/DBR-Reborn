#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"
inherit MONSTER;

void create() {
  string var;
  ::create();
   set_name("baby");
   set("id", ({"baby", "halfling", "child"}) );
   set_level(1);
   switch(random(3)) {
     case 0: var = "A crying baby"; break;
     case 1: var = "A stinky baby"; break;
     case 2: var = "A playing baby"; break;
   }
     this_object()->set("short", var);
   set("long", @BABY
A halfling baby, he sits in his crib, pondering a way to escape.  
He wears a cloth diaper, speaking of the unimaginable suffering those
who take care of him must endure.  He looks at you, obviously
not knowing what to think of you.
BABY
   );
   set("race", "halfling");
   set_skill("melee", 2);
   set_skill("dodge", 2);
   set_skill("parry", 2);
   set_max_hp(75);
   set_gender("male");
   set_body_type("human");
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_emotes(5,
     ({
      "The baby begins to cry.",
      "The baby looks you over and giggles playfully.",
      "The baby gets an evil look on his face, and poops in his diaper.",
      "The baby angrily screams out.",
      "The baby plays with a toy.",
     }), 0);
   set_achats(25,
     ({
      "The baby lets out an annoying scream.",
      "The infant cringes away from you.",
      "The baby gets so scared, he pee's in his diaper.",
     }) );
   new(TARAOBJ+"diaper")->move(this_object());
   force_me("wear diaper");
}
