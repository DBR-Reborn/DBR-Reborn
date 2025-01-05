#include <std.h>
#include "../chaos.h"

inherit MONSTER;


create() {
	::create();
	set_name("chaos champion");
	set_id( ({"champion", "aekold", "chaos champion"}));
	set_short("[38]Aekold the Shifter, Chaos Champion of Tzeentch");
	set_long("Aekold the Shifter, Chaos Champion of Tzeentch.  This is on of the most powerful champions of Tzeentch.  Electricity jumps from his body like festering fleas on a dirty dog.  His body keeps changing as a result of the dark powers of chaos, always shifting into different patterns, shapes and color.  Wing have sprouted from his back, dark and malicious, they stretch out in power.");
	set_level(38);
	//set_stats("strength", 80);
	set_body_type("winged-humanoid");
	set("race", "chaos");
	set_stats("intelligence", 150);
	//set_skill("melee", 80);
	//set_skill("attack", 120);
	//set_skill("blade", 80);
	//set_skill("blunt", 80);
	set_combat_chance(80);
	set_casting_chance(20);
	//set_skill("parry", 70);
	set_skill("two handed blade", 220);
	set_wielding_limbs( ({"left hand", "right hand"}));
	set_overall_ac(30);
	set_property("magic resistance", 120);

	set_gender("male");
	//set_skill("dodge", 70);
	//set_skill("block", 60);
	//set_max_hp(1350);
	//set_hp(1350);

	set_property("base hp regen", 20);
	set_property("base mp regen", 100);
	set_mp(2000);
	set_max_mp(2000);
	set_skill("magery", 150);
	set_skill("conjuration", 150);
	set_spell_level("power word, stun", 5);
	set_spell_level("lightning bolt", 4);
	set_spell_level("power word, blind", 4);
	set_spell_level("fire shield", 5);
	set_spell_level("power word, kill", 2);
	set_spell_level("internal flame", 2);
	add_spell("power word, stun", "$A");
	add_spell("lightning bolt", "$A");
	add_spell("power word, blind", "$A");
	add_spell("fire shield", "$(ME)");
	add_spell("power word, kill", "$A");
	add_spell("internal flame", "$A");
	set_alignment(-1000);
set_languages( ({"common"}) );
	set_money("gold", 1000);
new(OBJ+"lightningswd.c")->move(this_object());
force_me("wield sword in left hand");
new(OBJ+"heavyarmor.c")->move(this_object());
force_me("wear armor");
}
