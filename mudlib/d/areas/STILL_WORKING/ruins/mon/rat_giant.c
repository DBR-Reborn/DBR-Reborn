
#include "../ruins.h"
#include <std.h>
inherit MONSTER;
 
void create() {
   ::create();
set_name("giant rat");
set("id", ({"giant", "rat", "giant rat"}) );
set_level(8);
set("short", "giant rat");
   set("long", "A seven-foot long rat lies before you. It has red glowing
eyes and razor-sharp claws. The demon rat seems to grin at you with its
blood stained teeth.");
set("race", "rat");
   set_gender("neuter");
   set_money("silver", random(300)+200);
set_body_type("rat");
set_wielding_limbs( ({"left hand, right hand"}) );
set_skill("two handed blunt", 40);
   set_emotes(5, ({
"The giant rat grins at you.",
"The rat glances at you.",
}), 0);
   set_achats(30, ({
"The rat whips his tail at its attacker.",
"The rat jumps at empty space.",
"The rat's eyes glow more brightly.",
                   }) );
   new("/d/damned/virtual/war-hammer_2.weapon")->move(this_object());
force_me("wield hammer in left hand");
new("/d/damned/virtual/chain-vest.armour")->move(this_object());
force_me("wear chain vest");
   new("/d/damned/virtual/cloak.armour")->move(this_object());
   force_me("wear cloak");
}
