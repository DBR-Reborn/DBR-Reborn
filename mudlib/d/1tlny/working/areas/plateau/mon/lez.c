#include <std.h>
#include "/wizards/garetjax/plateau/defs.h"
inherit MONSTER;

void create() {
	string var;
	object ob;
	int wc;
	int HPBASE, LEV;

	HPBASE = 125;

	::create();
	seteuid(geteuid());
       set_name("A Lesbian");
	set("id", ({"lesbian", "centaur", "centaur mom" }) );
	set_level(14 + random(5));
	this_object()->set("short", " A Lesbian");
	set("long",
   "A nasty ugly lezbian."
	);
      this_object()->set_race("sprite");
	this_object()->set_gender("female");
	set_body_type("human");
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_class("elementalist");
	
	set_hp(HPBASE * (int)this_player()->query_level());
	set_max_hp(HPBASE * (int)this_player()->query_level());

	LEV = (int)this_player()->query_level();
        set_combat_chance(100);
       set_casting_chance(100);
	set_skill("melee", 90 + (this_object()->query_level()) * 3);
         set_skill("concentrate", LEV * 4);
         set_skill("earth lore", LEV * 2);
         set_skill("elementalism", LEV * 2);
         add_spell("elemental strike", "$A");
         set_spell_level("elemental strike", 1);
	set("aggressive", 0);
	set("gang bang", 1);
	add_money("silver", 100 + random(200) );
     force_me("use earth lore");
        force_me("use concentrate");
}
