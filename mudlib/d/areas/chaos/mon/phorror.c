#include <std.h>
#include "../chaos.h"

inherit MONSTER;

create() {
	::create();
	set_name("horror");
	set_id(({"horror", "pink horror", "demon"}));
	set_short("[35]Pink Horror of Tzeentch");
	set_long("One of the lesser demons of Tzeentch called a horror, these horrors take two forms, A strong and energetic pink horror, and a depressed blue horror.");
	set_level(35);
	set_body_type("human");
	set("race", "demon");
	//set_skill("melee", 75);
	set_property("melee damage", ([ "fire" : 40]));
	set_wielding_limbs( ({"left hand"}) );
	set_gender("male");
	//set_skill("dodge", 50);
	//set_skill("attack", 60);
	//set_skill("block", 40);
	set_skill("conjuration", 150);
	set_property("magic resistance", 100);
	set_combat_chance(30);
	set_spell_level("fireball", 3);
	add_spell("fireball", "$A");
	set_alignment(-1000);
}
void die(object who){
//int here;
//here = environment(object who);
	message("info","The%^B_MAGENTA%^Pink horror%^RESET%^splits into two%^B_BLUE%^Blue Horrors!!!%^RESET%^", environment(this_object()), this_object());
new(MON+"bhorror.c")->move(environment());
new(MON+"bhorror.c")->move(environment());
::die(who);
return;
}
