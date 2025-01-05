#include <std.h>
#include "/wizards/garetjax/plateau/defs.h"
inherit MONSTER;

void create() {
	string var;
	object ob;
	int wc;
	int HPBASE, LEV;

	HPBASE = 75;

	::create();
	seteuid(geteuid());
	set_name("Centaur child");
	set("id", ({"child", "centaur", "centaur child" }) );
	set_level(12 + random(5));
	this_object()->set("short", "Centaur child");
	set("long",
    "The centaur child can never stop moving, jumping, and frisking around his"
    " pen. He has stores of energy, and tries to talk to everyone he sees. "
    "His legs are well muscled and his upper body will soon be as powerful as"
    " his elder cousins."
	);
      this_object()->set_race("centaur");
	this_object()->set_gender("male");
	set_body_type("centaur");
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_class("fighter");
	
	set_hp(HPBASE * (int)this_player()->query_level());
	set_max_hp(HPBASE * (int)this_player()->query_level());

     LEV = random(6) + 12;
	set_skill("melee", 95 + random(50));

	set("aggressive", 0);
	set("gang bang", 1);
}
