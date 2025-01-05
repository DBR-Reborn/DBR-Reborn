// Guard
// Wiztower
// Coded by Glitch for DBR
// 07-05-00

#include <std.h>
inherit "/std/monster";

void create() {
   ::create();
   set_name("prisoner");
   set("id", ({"prisoner", "human"}));
   set_level(random(3));
   set_gender("male");
   set("short","A prisoner");
   set("long", "You see before you a pitifull example of an human. He is dirty and his hair is matted with filth.");
   set("race", "human");
   set_body_type("human");
   set_wielding_limbs("right hand");
   set_achats(30, ({
      "The prisoner begs for mercy.",
      "The prisoner says, 'Please stop! I'll give you anything!",
      "The prisoner flips you the bird.",
      }) );
}



