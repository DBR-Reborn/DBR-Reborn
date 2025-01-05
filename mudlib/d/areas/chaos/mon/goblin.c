#include <std.h>
#include "../chaos.h"

inherit MONSTER;


create() {
	::create();
	set_name("goblin");
	set_id("goblin");
	set_short("[25]nasty sword wielding green goblin");
	set_long("A goblin from the Night gobling clan, know for its ferocity and strength, also know from an animosity to almost everything...");
	set_level(25);
	set_body_type("human");
	set("race", "goblin");
	set_skill("melee", 15);
	set_wielding_limbs( ({"left hand"}) );
	set_gender("male");
	set_skill("dodge", 5);
	set_skill("attack", 10);
	set_skill("block", 10);
	set_alignment(-10);
if(!present("sword")) {
new(ITM+"sword.c")->move(this_object());
force_me("wield sword in left hand"); }
if(!present("shield")) {
new(ITM+"shield.c")->move(this_object());
force_me("wear shield");
}
set_languages( ({"common"}) );
	set_speech(3, "common", ({"Burrrp!", "I nid sum mur shooms!"}) );
	set_achats(20, ({ "I'll be remuvin yer ed wit me rusti soad!", "Ha, aha, ah...huh?" }) );
	set_money("gold", 5);
}
