// Guard
// Wiztower
// Coded by Glitch for DBR
// 07-05-00

#include <std.h>
inherit "/std/monster";

void create() {
   ::create();
   set_name("guard");
   set("id", ({"guard", "human guard"}));
   set_level(3+random(2));
   set_gender("male");
   set("short","A guard");
   set("long", "The dungeon guard pays close attention to who passes and looks competant with his choosen weapon.");
   set("race", "human");
   set_body_type("human");
   set_money("gold",10+random(5));
   set_wielding_limbs("right hand");
   new("/d/damned/virtual/rapier_3.weapon")->move(this_object());
   new("/d/damned/virtual/breast-plate.armour")->move(this_object());
   new("/d/damned/virtual/plate-greaves.armour")->move(this_object());
   force_me("equip");
   set_achats(30, ({
      "The guard lunges at you.",
      "The guard spits at you.",
      "The guard flips you the bird.",
      }) );
}



