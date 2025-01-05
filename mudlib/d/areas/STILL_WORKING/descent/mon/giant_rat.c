#include <std.h>

inherit MONSTER;

create() {
int zlevel,xskill,roll,xchange;

	::create();
	set_name("rat");
	set_id(({"rat", "giant rat", "giant"}));
	set("race", "rodent");
	set_short("A giant rat");
	set_long("This is the biggest rat you've ever seen. It's about four feet long, has a big nasty tail, and even bigger teeth. It is gnawing a bone right now, but you have no illusions that it won't want fresh meat soon.");
	set_body_type("quadruped");
	set_level(47);
	set_skill("dodge", 300);
	set_skill("melee", 350);
	set_skill("attack", 350);
	xchange=random(2);
if(xchange)
	set_gender("male");
else set_gender("female");
}
