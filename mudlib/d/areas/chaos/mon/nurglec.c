#include <std.h>
#include "../chaos.h"

inherit MONSTER;


create() {
	::create();
	set_name("chaos champion");
	set_id( ({"champion", "lothar bubonicus", "lothar", "chaos champion"}));
    set_level(38);
	set_short("[38]Lothar Bubonicus the Bloated One, Chaos Champion of Nurgle");
	set_long("Lothar Bubonicus the Bloated One, Chaod Champion of Nurgle.  This is one of the great champions of Nurgle, his body is bloate with foul contagions from the bowels of the world.  Sores and boils, pus and slime dribble over every part of his body.
His leathery and gangerious skin oozes horrid juices as he moves, each squeezing out and forming a pool of poisonous liquid. He carries a staff, a strange staff, made out of the spinal column of a minotaur, topped with a glowing skull at the top.");
	set_stats("constitution", 200);
	set_body_type("human");
	set("race", "chaos");
	//set_skill("melee", 80);
	//set_skill("attack", 90);
	//set_skill("blade", 80);
	//set_skill("blunt", 80);
	//set_skill("parry", 70);
	set_skill("two handed blunt", 250);
	set_wielding_limbs( ({"left hand", "right hand"}));
	set_overall_ac(35);
	set_property("magic resistance", 33);

	set_gender("male");
	//set_skill("dodge", 50);
	//set_skill("block", 80);
	//set_max_hp(1750);
	//set_hp(1750);

	set_property("base hp regen", 10);
	set_skill("necromancy", 150);
	set_combat_chance(75);
	set_casting_chance(33);
	add_spell("decay", "$A");
	add_spell("rot", "$R");
	add_spell("rot", "$A");
	add_spell("drain life", "$A");
	add_spell("curse", "$A");
	set_spell_level("rot", 2);
	set_spell_level("decay", 3);
	set_spell_level("drain life", 3);
	set_spell_level("curse", 6);
	set_alignment(-1000);
set_languages( ({"common"}) );
	set_money("gold", 1000);
	new(OBJ+"plaguestaff.c")->move(this_object());
	force_me("wield staff in left hand and right hand");
}
