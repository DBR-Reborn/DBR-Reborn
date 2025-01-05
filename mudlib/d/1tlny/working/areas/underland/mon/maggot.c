#include <std.h>

inherit MONSTER;


create() {
	::create();
        set_name("maggot");
        set_id("maggot", "parasite");
       set_short("burrowing maggot");
        set_long(
"The small maggot burrows in some rotting flesh. The gross shade "
"of yellow makes the parasite very noticable in the bloody flesh.");
	set_level(1);
       set("race", "worm");
	set_skill("melee", 10);
        set_skill("parry", 2);
	set_skill("attack", 10);
	set_stats("strength", 20);
       set_skill("dodge", 4);
        set_stats("intelligence", 0);
	set_stats("dexterity", 20);
	set_stats("constitution", 10);
	set_stats("charisma", -10);
        set_stats("wisdom", 0);
	set_gender("male");
	set_alignment(-10);
   add_limb("torso", "FATAL", 158, 0,0);
   add_wielding_limb("torso");
}
