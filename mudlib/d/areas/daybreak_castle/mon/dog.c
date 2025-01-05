#include <std.h>

inherit MONSTER;

create() {
int zlevel,xskill,roll,xchange;

	::create();
	set_name("dog");
	set_id(({"dog"}));
	roll=random(10);
	switch(roll){
	case 0:zlevel=25;break;
	case 1:zlevel=25;break;
	case 2:zlevel=25;break;
	case 3:zlevel=25;break;
	case 4:zlevel=26;break;
	case 5:zlevel=26;break;
	case 6:zlevel=26;break;
	case 7:zlevel=27;break;
	case 8:zlevel=28;break;
	case 9:zlevel=29;break;
}
	set("race", "canine");
	set_short("["+zlevel+"]Dirty dog");
	set_long("A dirty dog wandering the streets for an owner.");
	set_body_type("quadruped");
	set_level(zlevel);
	xskill=4*zlevel;
	set_skill("dodge", xskill);
	set_speed(60);
	set_moving(1);
	set_skill("melee", xskill);
	set_skill("attack", xskill);
	xchange=random(2);
if(xchange)
	set_gender("male");
else set_gender("female");
}
