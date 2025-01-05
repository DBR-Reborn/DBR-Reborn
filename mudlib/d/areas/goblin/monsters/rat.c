#include <std.h>
#include "../goblin.h"

inherit MONSTER;

create() {
int zlevel,xskill,xchange;

	::create();
	set_name("rat");
	set_id(({"rat"}));

zlevel=(1+random(4));
if (zlevel == 5) set_short("[5]rat");
else 
if (zlevel == 4) set_short("[4]rat");
else
if (zlevel == 3) set_short("[3]rat");
else
if (zlevel == 2) set_short("[2]rat");
else
if (zlevel == 1) set_short("[1]rat");
else set_short("[0]rat");
	
xchange=random(2);
if(xchange)
	set_gender("male");
else set_gender("female");
	set("race", "rodent");
	set_long("A dirty rat with pieces of mushroom hanging from every orafice, it scurries from corner to corner looking for more food to scavenge.");
	set_body_type("quadruped");
	set_level(zlevel);
	xskill=4*zlevel;
	set_skill("dodge", xskill);
	set_skill("melee", xskill);
	set_skill("attack", xskill);


}
