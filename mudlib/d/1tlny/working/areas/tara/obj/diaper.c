#include <std.h>
#include "/wizards/shanus/defs/tara.h"

inherit ARMOUR;

void create() {
  ::create();
   set_name("diaper");
   set_id( ({ "diaper" }) );
   set_short("A diaper");
   set_long("A babies diaper, it is made out of a disposable "+
   "material, and used to hold in the wastes of a baby. "+
   "If so desired, it can be pooped or peed in.");
   set_weight(15);
   set_value(1);
   set_type("armour");
   set_limbs( ({ "right leg", "left leg" }) );
   set_ac(1);
   set_material("misc/cloth");
   set_wear("You tie the diaper across your waste.  It should hold "
   "in any accidents.");
   set_remove("You remove the diaper from your waste.  Who knows "
   "where it's been.");
   return;
}

void init() {
  ::init();
   add_action("poop", "poop");
   add_action("pee", "pee");
   return;
}

int poop(string str) {
  if(str && present(str, this_user()) == this_object()) {
   if(query("pooped")) return notify_fail("This diaper has already "+
   "been pooped in!\n");
   set("pooped", 1);
   write("Letting go of all sense of decency, you let out a large "+
   "load of waste into the diaper.");
   message("info", this_user()->query_cap_name() + " gets a strained "+
   "look on his face, and lets out a load of waste into his diaper.  "+
   "An overwhelming smell fills the air, disgusting all around.",
      all_inventory(environment(this_user())),
      ({ this_user() }));
   set_short("A dirty diaper");
   set_value(0);
   return 1;
   }
   return 0;
}

int pee(string str) {
  if(str && present(str, this_user()) == this_object()) {
   if(query("peed")) return notify_fail("The diaper has already "+
   "been urinated in!\n");
   set("peed", 1);
   write("Unable to find a restroom, you let out your pee into the "+
   "diaper.  You are satisfied.");
   message("info", this_user()->query_cap_name() + " decides to forgo "+
   "civil methods, and pee's directly into his diaper.  The smell of "+
   "urine fills the air, making it hard to breath.",
     all_inventory(environment(this_user())),
     ({ this_user() }));
   set_short("A wet diaper");
   set_value(0);
   return 1;
  }
  return 0;
}
