/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
   ::create();

   set_name("lost boy");
   set("id", ({"lost boy", "lost", "boy"}) );
   set_level(1);
   set("short", "[1]lost boy");
   set("long",
   "The lost boy is covered in dirt.  He sticks his tongue at you as he knows you can't help him"
   "and flashes a stick in your face.  What a brat!"
   );
   set("race", "boy");
   set_gender("male");
   set_alignment(50);
   set_money("silver", random(50)+25);
   set_body_type("human");
   set_skill("stick", 15);
   set_wielding_limbs( ({"right hand", "left hand"}) );
   set_wimpy(15);
/*
   set_emotes(5,
                ({
                  "The lost boy spits at you.",
                  "The lost boy drools over his stick.",
                  "The lost boy picks up a handful of dirt and hurls it at you.",
                  "The lost boy picks his nose.",
                }), 0);
   set_achats(30,
                ({
                  "The lost boy flails his arms wildly.",
                  "The lost boy cries in pain!",
                  "The lost boy spits at you.",
                }) );
*/
  
}
