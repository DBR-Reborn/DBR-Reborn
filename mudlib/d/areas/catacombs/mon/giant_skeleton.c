/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;
 
void create() {
int zlevel;
   ::create();
   set_name("giant skeleton");
   set("id", ({"giant skeleton", "skeleton"}) );
   zlevel=(10+random(5)+random(5));
if (zlevel == 10) set_short("[10]giant skeleton");
else 
if (zlevel == 11) set_short("[11]giant skeleton");
else
if (zlevel == 12) set_short("[12]giant skeleton");
else
if (zlevel == 13) set_short("[13]giant skeleton");
else
if (zlevel == 14) set_short("[14]giant skeleton");
else
if (zlevel == 15) set_short("[15]giant skeleton");
else
if (zlevel == 16) set_short("[16]giant skeleton");
else
if (zlevel == 17) set_short("[17]giant skeleton");
else
if (zlevel == 18) set_short("[18]giant skeleton");
else
if (zlevel == 19) set_short("[19]giant skeleton");
else set_short("[20]giant skeleton");
	set_level(zlevel);

   set("long",
   "A twelve-foot-tall skeleton stands before you, and it looks nasty.  "
   "This undead creature is one of the evil lich's soldiers of death."
   );
   set("race", "undead");
   set_overall_ac(30);
   set_gender("neuter");
   set_body_type("human");
   set("aggressive", (: call_other, this_object(), "not_other_monsters" :) );
   set_moving(1);
   set_speed(120);
   new("/d/damned/virtual/broad-sword_5.weapon")->move(this_object());
   force_me("wield broad sword in right hand");
}
 
int not_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}
 
int chk_my_mob() { return 1; }
