/*
  Vial that holds weapon poison created by players when they use
  the Poison Lore skill.  This object is created by a plant press
  and should not be created by any other object or bad things may
  happen.
 
  Duridian 4/1/96

  Modified by Tailwind for the Alchemist Guild

  Tailwind 5/22/99

*/
 
#include <std.h>
 
inherit "/std/Object";
 
int potion_level = 0;
string crit_type = "none";
string crit_level = "X";
object tp;
 
void create() {
   ::create();


   set_name("vial");
   set_id( ({"vial", "liquid", "poison", "potion"}) );
   set_short("a vial of strange liquid");
   set_long("A small vial containing a strange liquid.");
   set_weight(3);
   set_value(3);
}
 
void init() {
   ::init();
   add_action("drink_func", "drink");
   add_action("potion_weapon", "apply");
}

int is_potion() { return 1; }
int query_potion_level() { return potion_level; }
void set_crit_type(string c_type) { crit_type = c_type; }
void set_crit_level(string c_level) { crit_level = c_level; }
// string query_crit_type() { return crit_type; }
// string query_crit_level() { return crit_level; }
int query_is_potion() { return 1; }
 
void set_potion_level(int x) {
  potion_level = x;
  set_value(x * 5);
  return;
}
 
int query_vial() { return 0; }
 
int potion_weapon(string str) {
   string tmp1, tmp2;
   object weap;
 
   if(sscanf(str, "%s to %s", tmp1, tmp2) != 2) return 0;
 
   if(present(tmp1, this_player()) != this_object()) return 0;
 
   weap = present(tmp2, this_player());

   if(!weap) {
      write("You don't have "+article(str)+".");
      return 1;

   }
 
   if(!weap->is_weapon()) {
      write("That is not a weapon.");
      return 1;
   }

  write("You apply a healing potion to your weapon, which doesn't do anything.");

   remove();
   return 1;
} 

/*
// Don't allow poisons to be stackable, else you'll wind up with
// weapons with poison levels up the wazoo.
   if((int)weap->query_poisoning()) {
      write("No more poison may be applied to this weapon.");
      return 1;
   }
*/
int drink_func(string str) {
   object ob;
 
   if((!str) || ((str != "vial") && (str != "small vial") && (str != "potion"))) {
      notify_fail("Drink what?\n");
      return 1;
   }
 
   if(this_player()->query_current_attacker()) {
      write("You cannot do that while in combat!");
      return 1;
   }
 

   write("You drink "+query_short()+" and feel better!");
   
   message("info", (string)this_player()->query_cap_name() +
      " drinks "+query_short()+" and looks better!",
      all_inventory(environment(this_player())), ({ this_player() }) );
   this_player()->add_potion_healing(potion_level);
   remove();
   return 1;
}
