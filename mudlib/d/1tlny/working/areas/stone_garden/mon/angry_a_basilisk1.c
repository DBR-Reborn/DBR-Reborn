 // Wizard: Shade Maelstorm //
 
  // Monster File; Angry adult basilisk 1 starts at room 6 and patrols.
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
  set_name("Adult basilisk");
   set_cmd_array(({"north", "southeast", "south", "north", "north", "west", "northeast",
 "east", "west", "southwest", "south"}));

set_cmd_interval(20);
set_cmd_cycle(1);

   set_level(5+random(5));
set("id", ({"basilisk", "adult basilisk" }));
  set_money("silver", random(50));
   set("short", "An Adult Basilisk");
   set("long",

  "This basilisk seems rather large. It appears to have grown well in this "
  "dark damp temple. Its red fiery eyes stand out, and it lets out an "
  "shivering Hisss. "
   );
  set("race", "basilisk");
   set_overall_ac(30);
   set_gender("neuter");
   set_body_type("basilisk");
   set_moving(0);
   set_speed(120);


 
}

 
  void kill_them(object player) {
  if(!present(player)) {return ; }
   force_me("kill "+player->query_cap_name());
   KILL=0;
  }

int chk_sg_creature() {
  return 1;
 }
