// Wizard : Hood
// File : thug.c
// Whore house bouncer guard.

#include <std.h>
#include <shao.h>

inherit MONSTER;

int chk_my_mon();



void create() {
int zlevel;
object money;
::create();
set_name("thug");
if(zlevel>14){
set("id",({"thug","massive thug","club guard","guard","werebear"}) );
set("short","Tall muscular thug");
}
if(zlevel<14){
set("id",({"thug","werebear","club guard"}));
set("short","Thug");
}
zlevel=(10+random(6));
set_level(zlevel);
set("long","This werebear looks like he hasn't "
"washed in a long long time. He has a sly but cautious"
" look in his eyes.  His fur is black but you suspect "
"it may be a different colour if not so dam dirty."
"Although dirty and generaly a low life, he does "
"appeer to be well nurished and has a fair bit of "
"muscles under the dirty appearance.\n");
set("race","werebear");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(15);
	set_combat_chance(30);
	set_melee_damage("impact");
set_stats("strength",150);
	set_wielding_limbs( ({"right hand", "left hand"}) );
set("aggressive","special_func");
	money=new("std/obj/coins");
	money->set_money("gold",(random(50)+30));
	money->move(this_object());
	set_languages(({"middle-english","common","yin","serra","orcish"}));
if(zlevel<40){
new("/d/damned/virtual/chain-mail.armour")->
move(this_object());
new("/d/damned/virtual/studded-leather-pants.armour")->
move(this_object());
force_me("wear mail");
force_me("wear helm");
force_me("wear glove on right hand");
force_me("wear glove 2 on left hand");
force_me("wear pants");
force_me("wear belt");
force_me("wear boots");
}
}
int chk_my_mon(){return 1;}

