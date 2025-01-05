 // Wizard: Shade Maelstorm //
 
 // Monster File: Adult Basilisk //
#include <std.h>
inherit MONSTER;
 
void create() {
   ::create();
  set_name("An adult basilisk");

   set_level(5+random(5));
set("id", ({"basilisk", "adult basilisk" }));
  set_money("silver", random(50));
   set("short", "An adult basilisk");
   set("long",

  "This basilisk is quite larger to the baby ones in the nursery garden. They "
 "appear to be almost full grown, and would have been stoning things larger than "
 "insects by the looks of it. The basilisk doesnt seem to like you being here. ");
  set("race", "basilisk");
   set_overall_ac(30);
   set_gender("neuter");
   set_body_type("basilisk");
   set_moving(0);
   set_speed(120);


 
}
 
