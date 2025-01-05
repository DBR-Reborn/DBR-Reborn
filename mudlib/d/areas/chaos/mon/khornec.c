#include <std.h>
#include "../chaos.h"


inherit MONSTER;


create() {
	::create();
	set_name("chaos champion");
	set_id( ({"champion", "angron", "chaos champion"}));
	set_short("[36]Angron the Executioner, Chaos Champion of Khorne");
	set_long("Angron the Executioner, Chaos Champion of Khorne.  This is one of the great champions of Khorne, dried and fresh blood is splattered and caked all along his great armor of screaming souls.  He is unearthly strong, with biceps and calf muscles of around a foot and a have in diameter, obviously a sign of chaos.  His head is encircled with a crown of fingers, constantly pattering their disgusting fingers against his head.  He carries a large and very viscous looking two handed axe.
It could quite possibly take off your arms and legs and not to mention your head in one stroke!.");
	set_level(36);
	set_stats("strength", 175);
	set_body_type("human");
	set("race", "chaos");
	//set_skill("melee", 80);
	//set_skill("attack", 120);
	//set_skill("blade", 80);
	//set_skill("blunt", 80);
	//set_skill("parry", 70);
	set_skill("two handed blade", 220);
	set_wielding_limbs( ({"left hand", "right hand"}));
	set_overall_ac(30);
	set_property("magic resistance", 33);

	set_gender("male");
	//set_skill("dodge", 70);
	//set_skill("block", 60);
	//set_max_hp(1500);
	//set_hp(1500);

	set_property("base hp regen", 30);
	set_alignment(-1000);
set_languages( ({"common"}) );
	set_money("gold", 1000);
new(OBJ+"axeodeath.c")->move(this_object());
force_me("wield axe in left hand and right hand");
new(OBJ+"heavyarmor.c")->move(this_object());
force_me("wear armor");
}
