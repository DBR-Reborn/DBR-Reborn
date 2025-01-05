#include <std.h>
inherit "/std/monster";

void create() {
   ::create();
   set_name("gnoll");
   set("id", ({"gnoll"}));
   set_level(5+random(2));
   set("short","A Gnoll");
   set("long", "A large and strong looking gnoll.");
   set("race", "gnoll");
   set_body_type("human");
   set_wielding_limbs( ({"right hand","left hand"}) );

   new("/d/damned/virtual/halberd_5.weapon")->move(this_object());
   new("/d/damned/virtual/breast-plate.armour")->move(this_object());
   new("/d/damned/virtual/plate-greaves.armour")->move(this_object());
   force_me("wield halberd in left hand and right hand");
   force_me("equip");
   set_achats(30, ({
      "The gnoll spits something disgusting at you.",
      "The gnoll swings his halberd at you.",
      "The gnoll snarls at you.",
      "The gnoll lets loose with a juicy, smelly fart.",
      }) );
}


