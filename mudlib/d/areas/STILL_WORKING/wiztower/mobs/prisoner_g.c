// Guard
// Wiztower
// Coded by Glitch for DBR
// 07-05-00

#include <std.h>
inherit "/std/monster";

void create() {
   ::create();
   set_name("prisoner");
   set("id", ({"prisoner", "gnone"}));
   set_level(1);
   set_gender("male");
   set("short","A prisoner");
   set("long", "You see before you a pitifull example of a gnome. He's dirty and his hair is matted with filth. You hate to even touch this drooling creature.");
   set("race", "gnone");
   set_body_type("human");
   set_wielding_limbs("right hand");
   set_achats(30, ({
      "The prisoner begs for mercy.",
      "The prisoner tries to kick you in the groin.",
      "The prisoner flips you the bird.",
      }) );
}



