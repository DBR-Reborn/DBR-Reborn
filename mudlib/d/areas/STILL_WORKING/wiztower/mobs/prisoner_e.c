// Guard
// Wiztower
// Coded by Glitch for DBR
// 07-05-00

#include <std.h>
inherit "/std/monster";

void create() {
   ::create();
   set_name("prisoner");
   set("id", ({"prisoner", "elf"}));
   set_level(2);
   set_gender("female");
   set("short","A prisoner");
   set("long", "You see before you a pitifull example of an elf. He is dirty and his hair is matted with filth.");
   set("race", "elf");
   set_body_type("human");
   set_wielding_limbs("right hand");
   set_achats(30, ({
      "The prisoner begs for mercy.",
      "The prisoner says, 'I'll show you where treasure is hidden if you stop.",
      "The prisoner flips you the bird.",
      }) );
}



