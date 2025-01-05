/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;


 
void create() {
int zlevel;
   ::create();
	

   set_name("giant mummy");
   set("id", ({"giant mummy", "mummy"}) );
	
	zlevel=(10+random(5)+random(5));
if (zlevel == 10) set_short("[10]giant mummy");
else 
if (zlevel == 11) set_short("[11]giant mummy");
else
if (zlevel == 12) set_short("[12]giant mummy");
else
if (zlevel == 13) set_short("[13]giant mummy");
else
if (zlevel == 14) set_short("[14]giant mummy");
else
if (zlevel == 15) set_short("[15]giant mummy");
else
if (zlevel == 16) set_short("[16]giant mummy");
else
if (zlevel == 17) set_short("[17]giant mummy");
else
if (zlevel == 18) set_short("[18]giant mummy");
else
if (zlevel == 19) set_short("[19]giant mummy");
else set_short("[20]giant mummy");
	set_level(zlevel);
   set("long",
   "A giant 15-foot-tall mummy stands before you.  The wrappings on its "
   "body are coming loose, revealing rotted flesh underneath.",
   );
   set("race", "undead");
   set_overall_ac(20);
   set_skill("necromancy", 85);
   set_skill("concentrate", 85);
   set_gender("neuter");
   set("aggressive", (: call_other, this_object(), "not_other_monsters" :) );
   set_moving(1);
   set_speed(120);
   set_body_type("human");
   set_combat_chance(25);
   add_spell("drain life", "$A");
   set_spell_level("drain life", 4);
   add_spell("cold blast", "$A");
   set_spell_level("cold blast", 4);
   add_spell("decay", "$A");
   set_spell_level("decay", 4);
   add_spell("curse", "$A");
   set_spell_level("curse", 4);
   force_me("use concentrate");
}
 
int not_other_monsters(object who) {
   if(who->is_player()) return 1;
   else return 0;
}
 
