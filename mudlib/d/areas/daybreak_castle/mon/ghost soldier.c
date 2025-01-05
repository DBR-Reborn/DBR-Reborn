// /daybreak_castle/areas/mon/ghost soldier.c
// Eos 6-20-2020

inherit "/std/monster";


void create() {
	::create();
	set_name("ghost soldier");
	set_id( ({"ghost","ghost soldier", "soldier"}));
	set_level(7);
	set("long","This ghost soldier may have not know he is dead. The soldier continues to march through these halls as it once did when he was alive");
	set("short","[7]Ghost Soldier");
	set("race","undead");
	set_gender("male");
	set_body_type("human");
	set_overall_ac(8);
	set("undead",1);
	set_melee_damage(90);
	reset();
}
