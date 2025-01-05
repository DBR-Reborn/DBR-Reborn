/* Weapon coded by Duridian for DarkeMud. */
 
#include <std.h>
inherit WEAPON;
 
void create() {
   ::create();
   set_name("scythe");
 set("id", ({ "scythe" }) );
   set("short", "wicked scythe");
   set("long",
 "This appears to be a very sharp scythe used mainly in pruning of bushes and grasses."
   );
   set_weight(200);
   set_value(750);
   set_type("blade");
   set_wc(23, "cutting");
   set_ac(5);
   set_quality(3+random(3));
   set_parry_bonus(10);
}
