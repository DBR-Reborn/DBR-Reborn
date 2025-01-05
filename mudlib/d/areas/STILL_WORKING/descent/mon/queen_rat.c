#include <std.h>

inherit MONSTER;

create() {
int zlevel,xskill,roll,xchange;

	::create();
	set_name("rat");
	set_id(({"rat", "queen", "queen rat", "giant rat", "giant"}));
	set("race", "rodent");
	set_short("The queen rat");
	set_long("While it's hard to believe that any rat could be bigger than those you passed in the cramped tunnel, this queen rat puts your doubts to rest. She is five freakin' feet big, and has more muscle than you do! You FEAR her.");
	set_body_type("quadruped");
	set_level(50);
	set_skill("dodge", 310);
	set_skill("melee", 360);
	set_skill("attack", 360);
	set_gender("female");
}
