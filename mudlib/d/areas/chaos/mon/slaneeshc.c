#include <std.h>
#include "../chaos.h"

inherit MONSTER;


create() {
	::create();
	set_name("chaos champion");
	set_id( ({"champion", "gilberion", "chaos champion"}));
	set_short("[38]Gilberion the Lewd, Chaos Champion of Slaanesh");
	set_long("Gilberion the lewd, Chaos Champion of Slaaneesh.  This is one of the great champions of Slaanesh, his body is twisted in the form of pleasure and chaos.  Wings have sprouted from his back, and two more arms have grown on his body.  His armor is a pastel color of pink and purple, with studded gems that line his body like gentle kisses placed there by some unearthly being. 
Each of his limbs carries a different weapon, each tainted with the touch of chaos. ");
	set_level(38);
	set_body_type("winged-humanoid");
	add_limb("upper right arm", "upper right hand", 100, 0, 5);
	add_limb("upper left arm", "upper left hand", 100, 0, 5);
	add_limb("upper left hand", "", 50, 0, 5);
	add_limb("upper right hand", "", 50, 0, 5);
	set("race", "chaos");
	//set_skill("melee", 80);
	set_skill("offhand training", 200);
	//set_skill("dual attack", 70);
	//set_skill("attack", 80);
	//set_skill("blade", 80);
	//set_skill("blunt", 80);
	//set_skill("parry", 50);
	set_wielding_limbs( ({"left hand", "upper left hand", "right hand", "upper right hand"}));
	set_overall_ac(20);
	set_property("magic resistance", 33);

	set_gender("male");
	set_skill("dodge", 70);
	set_skill("block", 40);
	set_max_hp(1100);
	set_hp(1100);

	set_alignment(-1000);
set_languages( ({"common"}) );
	set_money("gold", 1000);
if(!present("sword")) {
	new(OBJ+"searingswd.c")->move(this_object());
force_me("wield sword in upper left hand");
}
if(!present("mace")) {
new(OBJ+"maceneuro.c")->move(this_object());
force_me("wield mace in upper right hand");
}
new("/d/damned/virtual/long-sword_5.weapon")->move(this_object());
force_me("wield sword in left hand");
new("/d/damned/virtual/morning-star_5.weapon")->move(this_object());
force_me("wield star in right hand");
}
