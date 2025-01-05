// Wizard : Hood
// File : Sg_guard.c
// Shao-tan Gate guard

#include <std.h>
#include <shao.h>

inherit MONSTER;

int chk_my_mon();



void create() {
int zlevel;
object money;
::create();
set_name("guard");
set("id",({"guard","city guard","shao-tan guard","weretiger"}) );
zlevel=(13+random(6));
set_level(zlevel);
set("short","Shao-tan Guard");
set("long","This guard has an aggressive and "+
"fearce look in his eyes.  Although he does not appear to be one "
"of the elite.  His massive body appears to be very muscular"+
" and trim.  "
"His fur is a greyish white with black stripes.  "
"The only distinguishing mark is a symbol that has been "+
"burned into his skin over his right eye.\n");
set("race","weretiger");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(100);
	set_combat_chance(30);
	set_skill("martial arts",175);
	set_skill("resist stun",150);
	set_property("magic resistance",95);
	set_melee_damage("impaling");
	set_wielding_limbs( ({"right hand", "left hand"}) );
	money=new("std/obj/coins");
	money->set_money("mithril",(random(50)+30));
	money->move(this_object());
	set_languages(({"middle-english","common","yin","serra","orcish"}));
	set_emotes(10,({"The guard says: 'Welcome to Shao-tan, but be warned "+
	": Murder, theft, and chaos are not tolerated here.","The guard "+
"watches you appraisingly...",
"The guard glances up and down the street, and then checks his weapon.\n"}),0);
	set_emotes(20,({"%^RED%^The guard growls and flexes his sharp claws.",
	"The guard laughs at your skills of combat.","The guard says :"+
	" 'You had better run for your life mortal, before you have "+
	"lost it.'","The guard says : 'You REALLY fucked up this time!'",
	"The guard says : 'Should I break you in half or rip off your head?'"}),1);
zlevel = random(6);
switch(random(zlevel)){
case 0:new("/d/damned/virtual/battle-axe_6.weapon")->
move(this_object());
force_me("wield axe in right hand and left hand");
break;
case 1:new("/d/damned/virtual/machete_6.weapon")->
move(this_object());
force_me("wield machete in right hand");
new("/d/damned/virtual/large-shield.armour")->
move(this_object());
force_me("wear shield on left hand");
break;
case 2:new("/d/damned/virtual/bastard-sword_6.weapon")->
move(this_object());
force_me("wield sword in right hand and left hand");
break;
case 3:new("/d/damned/virtual/battle-axe_1.weapon")->
move(this_object());
force_me("wield axe in left hand");
break;
case 4:new("/d/damned/virtual/machete_1.weapon")->
move(this_object());
new("/d/damned/virtual/large-shield.armour")->
move(this_object());
force_me("wear shield on left hand");
force_me("wield machete in right hand");
break;
case 5:new("/d/damned/virtual/bastard-sword_1.weapon")->
move(this_object());
force_me("wield sword in left hand and right hand");
break;
case 6:new("/d/damned/virtual/katana_6.weapon")->
move(this_object());
new("/d/damned/virtual/large-shield.armour")->
force_me("wear shield on right hand");
force_me("wield katana in left hand");
break;
}
if(zlevel<40){
new("/d/damned/virtual/breast-plate.armour")->
move(this_object());
new("/d/damned/virtual/great-helm.armour")->
move(this_object());
new("/d/damned/virtual/studded-leather-glove.armour")->
move(this_object());
new("/d/damned/virtual/studded-leather-glove.armour")->
move(this_object());
new("/d/damned/virtual/scale-greaves.armour")->
move(this_object());
new("/d/damned/virtual/metal-boots.armour")->
move(this_object());
new(ARMOR_PATH+"sg_belt")->
move(this_object());
force_me("wear plate");
force_me("wear helm");
force_me("wear glove on right hand");
force_me("wear glove 2 on left hand");
force_me("wear greaves");
force_me("wear belt");
force_me("wear boots");
}
}
int chk_my_mon(){return 1;}

