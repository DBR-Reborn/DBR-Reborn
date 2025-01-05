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
       set_name("Lesser Guardian of The Sword");
	set("id", ({"guardian", "centaur", "centaur guardian" }) );
	set_level(15 + random(5));
	this_object()->set("short", "Lesser Guardian of the Sword");
	set("long",
     " This is one of the most massive centaurs you have ever seen. His arms "
     " and chest are huge, and his eyes have an intelligent, yet guarded "
     "look about them. He looks VERY dangerous."
	);
      this_object()->set_race("centaur");
	this_object()->set_gender("male");
	set_body_type("centaur");
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_class("elementalist");
	
	set_hp(HPBASE * (int)this_player()->query_level());
	set_max_hp(HPBASE * (int)this_player()->query_level());

	LEV = (int)this_player()->query_level();
        set_combat_chance(100);
       set_casting_chance(100);
	set_skill("two handed polearm", 100 + (this_object()->query_level()) * 3);
         set_skill("concentrate", LEV * 4);
         set_skill("earth lore", LEV * 3);
         set_skill("elementalism", LEV * 3);
         add_spell("elemental strike", "$A");
         set_spell_level("elemental strike", 2);
	set("aggressive", 0);
	set("gang bang", 0);
	add_money("silver", 100 + random(200) );
      weap=new("/d/damned/virtual/spear_6.weapon");
      weap-> set_name("Crude Spear");
      weap-> set("id", "spear");
      weap-> set_hit_bonus(13);
      weap-> set_wc(19, "impaling");
   force_me("wield spear in left hand and right hand");
     force_me("use earth lore");
        force_me("use concentrate");
}
