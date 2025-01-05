#include <std.h>
#include "/wizards/garetjax/plateau/defs.h"
inherit MONSTER;

void create() {
	string var;
	object ob;
	int wc;
	int HPBASE, LEV;

	HPBASE = 100;

	::create();
	seteuid(geteuid());
	set_name("Hideous Spentaur");
	set("id", ({"spider", "centaur", "spentaur", "centaur spider" }) );
	set_level(18 + random(5));
      this_object()->set("short", "A Hideous Mix of Centaur and Spider");
	set("long",
      "This is absolutely without a doubt, the most hideous creature you have "
      "ever seen. The bottom half of it is a horse, and the top half, a mix "
      "of human and spider. Its many eyes twitch back and forth, and saliva "
      "drips from its spider like fangs. You DONT want to get bitten by this "
      "freak of nature."
	);
      this_object()->set_race("centaur");
	this_object()->set_gender("male");
	set_body_type("centaur");
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_class("fighter");
	
	set_hp(HPBASE * (int)this_player()->query_level());
	set_max_hp(HPBASE * (int)this_player()->query_level());

     LEV = random(6) + 14;
	set_skill("melee", 100 + (this_object()->query_level()) * 3);
       add_spell("instill poison", "$A");
       set_spell_level("instill poison", 4);
       set_casting_chance(100);
       set_skill("body alteration", LEV * 4);
      set_combat_chance(100);

	set("aggressive", 0);
	set("gang bang", 0);
	add_money("silver", 100 + random(200) );
}
