#include <std.h>

inherit MONSTER;

create() {
int zlevel,xskill,roll,xchange;

	::create();
	set_name("rat");
	set_id(({"rat"}));
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
	set("race", "rodent");
	set_short("["+zlevel+"]rat");
	set_long("A dirty rat with pieces of mushroom hanging from every orafice, it scurries from corner to corner looking for more food to scavenge.");
	set_body_type("quadruped");
	set_level(zlevel);
	xskill=4*zlevel;
	set_skill("dodge", xskill);
	set_skill("melee", xskill);
	set_skill("attack", xskill);
	xchange=random(2);
if(xchange)
	set_gender("male");
else set_gender("female");
}
