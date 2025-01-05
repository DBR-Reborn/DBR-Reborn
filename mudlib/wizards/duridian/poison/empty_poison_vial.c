#include <std.h>
 
inherit "/std/Object";
 
void create() {
   ::create();
   set_name("vial");
   set("short", "a small vial");
   set("id", ({"vial", "small vial"}) );
   set("long",
       "It is a small, empty vial, specially designed for holding
poisons.");
   set_weight(3);
   set_value(3);
   return;
}
 
int is_empty_poison_vial() { return 1; }

