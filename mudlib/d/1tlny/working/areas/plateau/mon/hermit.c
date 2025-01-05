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
	set_name("Centaur Hermit");
      set_id("hermit");
	set_level(14 + random(5));
     set_short("An Evil Centaur Hermit");
	set("long",
    "This haggard old centaur drools from one side of his mouth, and raves "
    "on and on about the death defying jump to the fifth and sixth sword "
    "pieces. There are blood stains all over his clothes."
	);
      this_object()->set_race("centaur");
	this_object()->set_gender("male");
	set_body_type("centaur");
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_class("fighter");
	
	set_hp(HPBASE * (int)this_player()->query_level());
	set_max_hp(HPBASE * (int)this_player()->query_level());

	LEV = (int)this_player()->query_level();
	set_skill("knife", 100 + (this_object()->query_level()) * 3);
      set_skill("perception", LEV * 10);
      set_skill("back stab", LEV * 10);
	set("aggressive", 0);
	set("gang bang", 0);
	add_money("silver", 100 + random(200) );
    new(PLATOBJ+"hermdag")->move(this_object());
   force_me("wield dagger in right hand");
}

void init()  {
     ::init();
    force_me("use back stab at " + this_player() -> query_cap_name());
}
