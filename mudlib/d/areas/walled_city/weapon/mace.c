/* Weapon coded by Duridian for DarkeMud. */
 
//Updated by Eos on 07/25/2020
 
#include <std.h>
inherit WEAPON;
 
void create() {
   ::create();
   set_name("mace");
   set_id( ({"mace"}));
   set("short", "mace");
   set("long",
   "This mace features a heavy spiked ball on the end of a short "
   "handle.  It looks like an effective instrument for causing bodily "
   "damage."
   );
   set_weight(30);
   set_value(95);
   set_type("blunt");
   set_wc(13, "crushing");
   set_ac(4);
   set_quality(3);
}
