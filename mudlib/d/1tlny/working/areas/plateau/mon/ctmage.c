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
       set_name("Centaur Mage");
	set("id", ({"mage", "centaur", "centaur mage" }) );
	set_level(15 + random(5));
	this_object()->set("short", "Centaur Mage");
	set("long",
    "This centaur is much less hardy then the rest of the centaurs. His upper "
    "body is weak and frail, and his horse half looks underdeveloped. He has this dangerous glint in his eyes, that warns you that this creature is not as much of a pushover as he looks to be."
      );
      this_object()->set_race("centaur");
	this_object()->set_gender("male");
	set_body_type("centaur");
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_class("arch-mage");
	
	set_hp(HPBASE * (int)this_player()->query_level());
	set_max_hp(HPBASE * (int)this_player()->query_level());

	LEV = (int)this_player()->query_level();
        set_combat_chance(100);
       set_casting_chance(100);
	set_skill("dodge", 70 + (this_object()->query_level()) * 2);
         set_skill("concentrate", LEV * 4);
         set_skill("conjuration", LEV * 3);
         add_spell("exploding fireball", "$A");
         set_spell_level("exploding fireball", 6);
    add_spell("internal flame", "$A");
    set_spell_level("internal flame", 2);
	set("aggressive", 0);
        force_me("use concentrate");
}
