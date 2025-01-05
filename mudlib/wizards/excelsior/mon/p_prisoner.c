// /wizards/excelsior/mon/p_prisoner

#include <std.h>

inherit MONSTER;

void create() {
	::create();
	set_name("prisoner");
	set("id",({"prisoner","political prisoner"}));
	set("short","[10]beaten political prisoner");
	set("long","This beaten prisoner looks like he has been 'interrogated' "+
		"many times. He could put up much of a fight to anybody now.");
	set_level(10);
	set("race","high man");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(11);
	set_max_hp(200);
	set_hp(130);
}
