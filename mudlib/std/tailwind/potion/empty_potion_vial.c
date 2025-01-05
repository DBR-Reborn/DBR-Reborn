#include <std.h>
 
inherit "/std/Object";
 
void create() {
   ::create();
   set_name("vial");
   set("short", "an empty vial");
   set("id", ({"vial", "small vial", "poison", "potion"}) );
   set("long",
       "It is a small, empty vial, specially designed for holding potions and poisons.");
   set_weight(3);
   set_value(3);
   return;
}
 
int is_empty_potion_vial() { return 1; }

int is_empty_poison_vial() { return 1; }