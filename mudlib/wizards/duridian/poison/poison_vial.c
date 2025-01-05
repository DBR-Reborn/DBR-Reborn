/*
  Vial that holds weapon poison created by players when they use
  the Poison Lore skill.  This object is created by a plant press
  and should not be created by any other object or bad things may
  happen.
 
  Duridian 4/1/96
*/
 
#include <std.h>
 
inherit "/std/Object";
 
int poison_level = 0;
string crit_type = "none";
string crit_level = "X";
object tp;
 
void create() {
   ::create();
   set_name("vial");
   set_id( ({"vial", "liquid", "poison"}) );
   set_short("a vial of strange liquid");
   set_long("A small vial containing a strange liquid.");
   set_weight(3);
   set_value(3);
}
 
void init() {
   ::init();
   add_action("drink_func", "drink");
   add_action("poison_weapon", "apply");
}
 
int query_poison_level() { return poison_level; }
void set_crit_type(string c_type) { crit_type = c_type; }
void set_crit_level(string c_level) { crit_level = c_level; }
string query_crit_type() { return crit_type; }
string query_crit_level() { return crit_level; }
 

void set_poison_level(int x) {
  poison_level = x;
  set_value(x * 5);
  return;
}
 
int query_vial() { return 0; }
 
int poison_weapon(string str) {
   string tmp1, tmp2;
   object weap;
 
   if(sscanf(str, "%s to %s", tmp1, tmp2) != 2) return 0;
 
   if(present(tmp1, this_user()) != this_object()) return 0;
 
   weap = present(tmp2, this_user());
   if(!weap) {
      write("You don't have "+article(str)+".");
      return 1;
   }
 
   if(!weap->is_weapon()) {
      write("That is not a weapon.");
      return 1;
   }
 
// Don't allow poisons to be stackable, else you'll wind up with
// weapons with poison levels up the wazoo.
   if((int)weap->query_poisoning()) {
      write("No more poison may be applied to this weapon.");
      return 1;
   }
 
   weap->add_poisoning(poison_level);
// Apply any critical the poison vial may be carrying to the weapon.
   if(crit_type != "none")
      weap->set_auto_critical(crit_type+" "+crit_level);
 
   write("You apply the poison and discard the empty vial.");
   message("other_action", (string)this_user()->query_cap_name() +
      " applies "+query_short()+" to "+ (string)weap->query_short() +
      ".", environment(this_user()), ({ this_user() }) );
   remove();
   return 1;
}
 
int drink_func(string str) {
   object ob;
 
   if((!str) || ((str != "vial") && (str != "small vial") && (str !=
"poison"))) {
      notify_fail("Drink what?\n");
      return 1;
   }
 
   if(this_user()->query_current_attacker()) {
      write("You cannot do that while in combat!");
      return 1;
   }
 
   write("You drink "+query_short()+" and gag violently!");
   if(crit_type == "blindness") {
      write("The poison blinds you!");
      seteuid(getuid());
      ob = new("/wizards/duridian/poison/duridian_blind_shadow");
      ob->start_shadow(this_user(), 20+random(10), "The blinding effects of
the poison wear off.");
   }
   message("info", (string)this_user()->query_cap_name() +
      " drinks "+query_short()+" and gags violently!",
      all_inventory(environment(this_user())), ({ this_user() }) );
   this_user()->add_poisoning(poison_level);
   remove();
   return 1;
}

