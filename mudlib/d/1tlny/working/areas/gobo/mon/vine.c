// vine

#include <std.h>
inherit MONSTER;

void create() {
   string var;
   ::create();
   set_name("vines");
   set("id", ({"vines"}) );
   set_level(1);
   set("short", "Thorny Green Vines");
   set("long",
   "Long green vines hang from the ceiling. "+
   "Upon closer look, you notice that sharp thorns "+
   "protrude from the green stems. ");
   set("race", "plant");
   set_gender("neuter");
   set_body_type("plant");
   set_hp(40);
   set_melee_damage((["impaling":5, "crushing":8]));
   set_skill("melee",15);
   set_skill("parry",10);
   set_overall_ac(15);
   set("aggressive", 1);

}
