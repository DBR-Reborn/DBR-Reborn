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
       set_name("Centaur Mom");
	set("id", ({"mom", "centaur", "centaur mom" }) );
	set_level(14 + random(5));
	this_object()->set("short", "Centaur Mom");
	set("long",
    "The top half of this beautiful creature, is a perfectly sculpted human "
     "female. She is wearing no clothes, and has very long hair. She has an "
     "intelligent look to her that most of the male centaurs lack, and is "
    "calm and very sure of herself. One of her young is always near her, and she is very protective of them."
	);
      this_object()->set_race("centaur");
	this_object()->set_gender("female");
	set_body_type("centaur");
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
