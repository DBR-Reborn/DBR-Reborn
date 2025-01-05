#include <std.h>

inherit MONSTER;


int no_other_monsters;
create() {
	::create();
	set_name("horror");
	set_id(({"horror", "blue horror", "demon"}));
	set_short("[30]Blue Horror of Tzeentch");
	set_long("One of the lesser demons of Tzeentch called a horror, these horrors take two forms, A strong and energetic pink horror, and a depressed blue horror.");
	set_level(30);
	set_body_type("human");
	set("race", "demon");
	set_skill("melee", 40);
	set("aggressive", (: call_other, this_object(), "no_other_monsters" :) );
	set_wielding_limbs( ({"left hand"}) );
	set_gender("male");
	set_skill("dodge", 40);
	set_property("melee damage", ([ "fire" :30]));
	set_skill("attack", 40);
	set_skill("block", 40);
	set_skill("conjuration", 100);
	set_property("magic resistance", 50);
	set_combat_chance(30);
	set_spell_level("missile", 4);
	add_spell("missile", "$A");
	set_alignment(-1000);
}
int no_other_monsters(object who) {
	if(who->is_player()) return 1;
	else return 0;
}
