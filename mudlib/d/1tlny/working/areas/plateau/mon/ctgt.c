#include <std.h>
#include "/wizards/garetjax/plateau/defs.h"
inherit MONSTER;

void create() {
	string var;
	object ob, weap;
	int wc;
	int HPBASE, LEV;

	HPBASE = 125;

	::create();
	seteuid(geteuid());
	set_name("Centaur Guard");
	set("id", ({"guard", "centaur", "centaur guard" }) );
	set_level(14 + random(5));
	this_object()->set("short", "Centaur Guard");
	set("long",
   "This is one of the fiercest Centaur creatures you have ever seen."
   " His arms and chest are massively built, and his 4 equine legs look like "
   "they could run forever. He is wearing no clothing, yet has an air of "
   "sophistication and superiority about him, that awe you into reverence of "
   "this great creature. "
	);
      this_object()->set_race("centaur");
	this_object()->set_gender("male");
	set_body_type("centaur");
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_class("fighter");
	
	set_hp(HPBASE * (int)this_player()->query_level());
	set_max_hp(HPBASE * (int)this_player()->query_level());

       LEV = random(6) + 15;
	set_skill("two handed polearm", 100 + (this_object()->query_level()) * 3);
     set_skill("dodge", LEV * 7);

	set("aggressive", 0);
	set("gang bang", 0);
	add_money("silver", 100 + random(200) );
      weap=new("/d/damned/virtual/spear_6.weapon");
      weap-> set_name("Crude Spear");
      weap-> set("id", "spear");
      weap-> set_hit_bonus(13);
      weap-> set_wc(19, "impaling");
   force_me("wield spear in left hand and right hand");
}
