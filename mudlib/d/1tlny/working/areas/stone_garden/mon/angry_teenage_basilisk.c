 // Wizard: Shade Maelstorm //
 
 // Monster File: Baby Basilisk //
#include <std.h>
inherit MONSTER;
 
int chk_my_mon();
void create() {
   ::create();
  set_name("Baby basilisk");

   set_level(5+random(5));
set("id", ({"basilisk", "baby basilisk" }));
  set_money("silver", random(50));
   set("short", "A Baby basilisk");
   set("long",

   "A relatively young basilisk seems to be playing in the grass with some "
   "insects. You look at its form, so sleek and playful, its shiny chitinous "
   "black shell shimmering. "
   );
  set("race", "basilisk");
   set_overall_ac(30);
   set_gender("neuter");
   set_body_type("basilisk");
set("aggressive ",1);
   set_moving(0);
   set_speed(120);

 set_emotes(5, ({
   "The young basilisk jumps out of the grass and petrifies a small unsuspecting insect",
  "The young basilisk crouches in the long grass and gives a disturbing hiss. ",
   "Pouncing upon a small frog, the young basilisk petrifies it in an instant ",
   }), 0);

 
}

chk_my_mon() {return 1;}
 
  int no_other_monsters(object who) {
  if(who->is_player()) return 1;
  else return 0;
}
