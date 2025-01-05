#include <std.h>

inherit MONSTER;


create() {
int name;
	::create();
	set_name("peasant");
	set_id( ({"human", "peasant"}));
name = random(5);
switch(name){
	case 0:name="[2]Poor peasant";break;
	case 1:name="[2]Ragged dressed peasant";break;
	case 2:name="[2]Pale faced peasant";break;
	case 3:name="[2]Lanky armed Peasant";break;
	case 4:name="[2]Smelly peasant";break;
}
	set_short(name);
	set_long("One of the peasants from the city of Kislev, a great city except for some of its econmoic down-falls.  The peasants are always weary of strangers, as most of them know each other.");
	set_level(2);
	set_body_type("human");
	set("race", "human");
	set_skill("melee", 15);
	set_wielding_limbs( ({"left hand"}) );
	set_gender("male");
	set_skill("dodge", 5);
	set_skill("attack", 10);
	set_skill("block", 10);
	set_alignment(100);
set_languages( ({"common"}) );
	set_speech(10, "common", ({"Help!, Chaos is here!", "Run for yer lives!", "The horror, the horror of it all!", "I can't stand the carnage!", "Leave the town while you can!", "All hope is lost! We are all doomed!", "Death is upon us, all is hopeless!"}));
	set_money("silver", random(30));
}
