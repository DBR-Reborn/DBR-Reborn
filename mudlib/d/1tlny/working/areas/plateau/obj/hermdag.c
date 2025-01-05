
#include <std.h>
inherit WEAPON;
 
void create() {
   ::create();
   set_name("The Hermit's Dagger");
   set_id(({"dagger","hermit dagger"}));
   set("short", "Hermit Dagger");
   set("long",
      "A very sleek well balanced dagger, that seems perfect for back stabbing."
   );
   set_weight(20);
   set_value(200);
   set_type("knife");
   set_wc(13, "impaling");
   set_ac(0);
   set_quality(6);
   set_hit_bonus(10);
   set_parry_bonus(-20);
    set_property("no add quality", 1);
     set_material("metal/catoetine");
      set_property("throwable",1);
}
