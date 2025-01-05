 // Wizard: Shade Maelstorm //
 
 // Monster File: Baby Basilisk //
#include <std.h>
inherit MONSTER;
 
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
"Pouncing upon a small frog, the young basilisk petrifies it in an instant "
   }), 0);

 
}
 

void catch_tell(string str) {
string a,b;
object tp,ob;

if(sscanf(str, "%s gives you %s",a,b) == 2) {
a=lower_case(a);
tp=present(a,environment(this_object()));
 ob=present("rose","this_object());

 if(!tp) {return }
if(ob) {
write("The basilisk eats up the rose greedily. Its harsh red eyes go a light orange color, it seems to like those roses.");
 force_me("follow "+this_player());
 callout("run_away",100);
     }
  }
 }

 void run_away() {
object ob;
 write("The basilisk gets bored and runs off into the countryside.");
 tell_room("The basilisk runs away from "+this_player()->query_cap_name+" in search of new adventures.");
 ob->remove();
 }
