 // Wizard: Shade Maelstorm //
 
 // Monster File: Baby Basilisk //
#include <std.h>
inherit MONSTER;
 static int KILL;
 
int chk_my_mon();

 void init() {
   ::init();
   if(!KILL) {
     KILL=1;
    if(!(this_player()->chk_sg_creature() || wizardp(this_player())) ) {
    call_out("kill_them",20,this_player());
    }
  }
}
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
   set_moving(0);
   set_speed(120);

 set_emotes(5, ({
   "The young basilisk jumps out of the grass and petrifies a small unsuspecting insect",
  "The young basilisk crouches in the long grass and gives a disturbing hiss. ",
   "Pouncing upon a small frog, the young basilisk petrifies it in an instant ",
   }), 0);

 
}

 
  void kill_them(object player) {
  if(!present(player)) {return ; }
   force_me("kill "+player->query_cap_name());
   KILL=0;
  }

int chk_sg_creature() {
  return 1;
 }
