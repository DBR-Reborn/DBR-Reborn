#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"
inherit MONSTER;

void create() {
  string var;
  ::create();
   set_name("halfling");
   set("id", ({"halfling", "man"}) );
   set_level(2 + random(2));
   switch(random(3)) {
     case 0: var = "A short halfling"; break;
     case 1: var = "A stout halfling"; break;
     case 2: var = "A fat halfling"; break;
   }
     this_object()->set("short", var);
   set("long", @HALF1
This halfling is taking a break from whatever work he does.  He
stands with his arms crossed as if he has an important reason to
be here.  He wears the regular bright colorful clothing that most
halflings wear, and no shoes on his feet.
HALF1
   );
   set("race", "halfling");
   set_gender("male");
   set_money("silver", random(50)+25);
   set_body_type("human");
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_emotes(5,
     ({
      "The halflings kicks a pebble.",
      "The man looks you over.",
      "The halfling stares into the sky.",
      "The halfling stretches his arms.",
      "The halfling starts pacing.",
     }), 0);
   set_achats(20,
     ({
      "The halfling says, 'Arg!  Leave me alone!'",
      "The halfling whines, 'I'm telling our sheriff.'",
      "The halfling rolls up his sleeves.",
      "The halfling says, 'Your worse then those rogues.'",
     }) );
   new(TARAOBJ+"shirt")->move(this_object());
   force_me("wear shirt");
   new(TARAOBJ+"pants")->move(this_object());
   force_me("wear pants");
}
