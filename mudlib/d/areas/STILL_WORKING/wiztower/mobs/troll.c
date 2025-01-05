// Guard
// Wiztower
// Coded by Glitch for DBR
// 07-05-00

#include <std.h>
inherit "/std/monster";

void create() {
   ::create();
   set_name("troll");
   set("id", ({"troll", "ugly troll"}));
   set_level(7+random(2));
   set_gender("male");
   set_skill("blade",(50+random(20)));
   set_skill("attack", (50+random(20)));
   set("short","A ugly troll");
   set("long", "A big ugly green troll.");
   set("race", "troll");
   set_property("aggressive",1);
   set_body_type("human");
   set_money("gold",10+random(5));
   set_wielding_limbs("right hand");
   new("/d/damned/virtual/broad-sword_5.weapon")->move(this_object());
   new("/d/damned/virtual/breast-plate.armour")->move(this_object());
   new("/d/damned/virtual/plate-greaves.armour")->move(this_object());
   force_me("equip");
   set_achats(30, ({
      "The troll growls at you.",
      "The troll lumbers forward.",
      "The clangs his sword against his breast plate.",
      }) );
}



