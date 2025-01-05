 
#include <std.h>
inherit WEAPON;
 
void create() {
   ::create();
   set_name("Centaur Spear");
   set("id", ({"spear", "centaur spear" }) );
   set("short", "Centaur Spear");
   set("long",
    "A long hefty pole, with a crude rock spear head on the end."
   );
   set_weight(100);
   set_value(20);
   set_type("two handed polearm");
   set_wc(17, "impaling");
   set_ac(0);
   set_quality(6);
   set_hit_bonus(10);
   set_parry_bonus(-4);
    set_property("no add quality", 1);
}
