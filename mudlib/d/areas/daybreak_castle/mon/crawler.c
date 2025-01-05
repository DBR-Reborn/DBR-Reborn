#include <std.h>

inherit MONSTER;

create() {
  ::create();
	set_name("creepy crawler");
	set_id( ({"insect", "creeper crawler", "crawler"}));
	set("race", "insect");
	set_short("[2]creeper crawler");

	set_long("The crawler looks like a cross between a giant green cutworm and a cephalopod.  The carrion crawler is a scavenger of subterranean areas, feeding primarily upon carrion.");
	set_body_type("insectoid");
	set_level(2);
    set_stats("intelligence", 10);
	set_property("base hp regen", 50);
	set_property("melee damage", ([ "slashing" :10]));
	set_property("melee damage", ([ "crushing" :5]));
	set_skill("melee", 10);
	set_overall_ac(10);
	set_skill("dodge", 40);
    set_skill("parry", 5);
    set_stats("dexterity", 30);
}
