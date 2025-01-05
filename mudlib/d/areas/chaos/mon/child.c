#include <std.h>

inherit MONSTER;


create() {
int name, sex;
	::create();
	set_name("child");
	set_id( ({"human", "peasant", "child"}));
name = random(5);
switch(name){
	case 0:name="[1]Frightened child";break;
	case 1:name="[1]Crying child";break;
	case 2:name="[1]Thin malnutritioned child";break;
	case 3:name="[1]Obese child";break;
	case 4:name="[1]Soiled child";break;
}
	set_short(name);
	set_long("A Child hiding from the warriors of chaos, who would invariably slaughter everyone that they see.");
	set_level(1);
	set_body_type("human");
	set("race", "human");
	set_skill("melee", 5);
	set_wielding_limbs( ({"left hand"}) );
sex=random(2);
if(sex)
	set_gender("male");
	else set_gender("female");
	set_skill("dodge", 5);
	set_skill("attack", 10);
	set_skill("block", 10);
	set_alignment(100);
set_languages( ({"common"}) );
	set_speech(10, "common", ({"I'm scared!", "Where are my parents?", "I want to go home..", "I'm hungry", "Help!"}));
	set_money("copper", random(10));
}
