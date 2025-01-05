#include <std.h>

inherit MONSTER;

string random_short();
 
void create() {
   string rand_short;
   ::create();
   rand_short = random_short();
   set_name("rabbit");
   set("id", ({"rabbit", "bunny", "rabit"}) );
   set_level(4);
   set("short", "[4]rabbit");
   set("long",
   "The rabbit is covered in dirt and cob webs. He sticks his lucky foot at you as he knows you won't be able to get it from him"
   "The rabbit also raises his upper whiskers showing you his sharp teeth. Does not look like a friendly rabbit!"
   );
   set("race", "animal");
   set_gender("male");
   set_alignment(100);
   set_money("silver", random(70)+25);
   set_body_type("animal");
   set_skill("parry", 25);
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_wimpy(25);
/*
   set_emotes(5,
                ({
                  "The rabbit spits at you.",
                  "The rabbit drools over his lucky foot.",
                  "The rabbit kicks up a small pile of rabbit dung as it hurls at you.",
                  "The rabbit gets into an agressive stance.",
                }), 0);
   set_achats(30,
                ({
                  "The rabbit flails his paws wildly.",
                  "The rabbit cries in pain!",
                  "The rabbit snips at you.",
                }) );
*/
  
}
