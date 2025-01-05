// Wizard : Hood
// File : m_guard.c
// Militia guard.

#include <std.h>
#include <shao.h>

inherit MONSTER;

int chk_my_mon();



void create() {
int zlevel;
object money;
::create();
set_name("guard");
set("id",({"guard","militia guard","shop guard","werebear"}) );
zlevel=(10+random(6));
set_level(zlevel);
set("short","Militia Guard");
set("long","This guard has an aggressive and "+
"fearce look in his eyes.  Although he does not appear to be one "
"of the elite.  His massive body appears to be very muscular"+
" and trim.  "
"His fur is a greyish white with black stripes.  "
"The only distinguishing mark is a symbol that has been "+
"burned into his skin over his right eye.\n");
set("race","werebear");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(75);
	set_combat_chance(30);
	set_skill("martial arts",120);
	set_skill("resist stun",130);
	set_property("magic resistance",20);
	set_melee_damage("impact");
set_stats("strength",200);
	set_wielding_limbs( ({"right hand", "left hand"}) );
set("aggressive","special_func");
	money=new("std/obj/coins");
	money->set_money("mithril",(random(50)+30));
	money->move(this_object());
	set_languages(({"middle-english","common","yin","serra","orcish"}));
if(zlevel<40){
new("/d/damned/virtual/chain-mail.armour")->
move(this_object());
new("/d/damned/virtual/great-helm.armour")->
move(this_object());
new("/d/damned/virtual/studded-leather-glove.armour")->
move(this_object());
new("/d/damned/virtual/studded-leather-glove.armour")->
move(this_object());
new("/d/damned/virtual/studded-leather-pants.armour")->
move(this_object());
new("/d/damned/virtual/metal-boots.armour")->
move(this_object());
new(ARMOR_PATH+"sg_belt")->
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

