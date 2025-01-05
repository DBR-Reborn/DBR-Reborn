/* Weapon coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit WEAPON;
 
void create() {
   mixed str;
   ::create();
   set_name("deathblade");
   set("id", ({"deathblade", "sword", }) );
   set("short", "Deathblade");
   set("long",
   "This broadsword has a finely-crafted and very ornate hilt made entirely "
   "of black crystal.  Its blade is thick and and black, the material of the blade is unknown.  "
   "There seems to be an inscription on the sword's blade."
   );
   set_weight(250);
   set_value(10000);
   set_type("blade");
   set_wc(20, "impaling");
   set_wc(80, "disruption");
set_wc(35, "crushing");
   set_wc(50, "cutting");
   set_ac(7);
   set_property("no add quality", 1);
//   set_property("no decay", 1);
   set_quality(6);
   set("read", "The inscription reads: \"The personal blade of Dethblayde\"");
/*   set_property("enchantment", 1);
   str = ({ ({"This sword glows with an unholy light.\n", "detect magic" }) });
   set_property("extra long", str); */
   set_wield("Your heart momentarily feels a chilling attack as you wield the sword.");
   set_unwield("The will of Dethblayde left an impression on your heart as you unwield this dreaded blade.");
//   set_hit( (: call_other, this_object(), "weapon_hit" :) );
   set_material("metal/itsaugton");
   set_property("brittle", 10);
   set_decay_rate(1000);
}
 
/*int weapon_hit(object attacker) {
   string target;
   int align;
 
   target = lower_case((string)attacker->query_name());
   if(random(2) == 0) {
      if(interact("angel", target)) {
         write("%^BOLD%^%^YELLOW%^The divine being withers as the deathblade hits the angel's soul!");
         say("%^BOLD%^%^YELLOW%^The divine being withers as the deathblade hits the angel's soul!");
         return random(15)+15;
      }
      else if((string)attacker->query_race() == "seraph" || (string)attacker->query_race() == "lich") {
         write("%^BOLD%^%^YELLOW%^The blade sizzles as it drains energy from the divine creature!");
         say("%^BOLD%^%^YELLOW%^The blade sizzles as it drains energy from the divine creature!");
         return random(15)+5;
      }
      else
         return random(10);
   }
   return 0;
}

int restore_me(string file) {
  ::restore_me(file);
set_hit( (: call_other, find_object_or_load("/wizards/dethblayde/weapons/deathblade"), "weapon_hit" :) );
  return 1;
}

  */
