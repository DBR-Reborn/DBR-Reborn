
#include "../ruins.h"
#include <std.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("giant rat");
    set("id", ({"giant", "rat", "giant rat"}) );
    set("short", "giant rat");
    set("long", "A seven-foot long rat lies before you. It has red glowing
eyes and razor-sharp claws. The demon rat seems to grin at you with its
blood stained teeth.");
set_level(17);
set("race", "rat");
   set_gender("neuter");
// set_money("silver", random(300)+200);
set_body_type("rat");
set ("aggressive", 1);
set_skill("blade", 40);
set_skill("parry", 20);
set_skill("dodge", 30);
set_wielding_limbs( ({"left hand, right hand"}) );
   set_emotes(5, ({
"The giant rat grins at you.",
"The rat glances at you.",
}), 0);
   set_achats(30, ({
"The rat whips his tail at its attacker.",
"The rat jumps at empty space.",
"The rat's eyes glow more brightly.",
                   }) );
   new("/d/damned/virtual/long-sword_5.weapon")->move(this_object());
new("/d/damned/virtual/wall-shield.armour")->move(this_object());
new("/d/damned/virtual/chain-vest.armour")->move(this_object());
   new("/d/damned/virtual/cloak.armour")->move(this_object());
force_me("wield sword in left hand");
force_me("equip");
}
