#include <std.h>
#include "/wizards/garetjax/plateau/defs.h"
inherit MONSTER;

void create() {
	string var;
	object ob;
	int wc;
	int HPBASE, LEV;

	HPBASE = 120;

	::create();
	seteuid(geteuid());
       set_name("Centaur Alchemist");
	set("id", ({"alchemist", "centaur", "centaur alchemist" }) );
	set_level(20 + random(5));
	this_object()->set("short", "Centaur Alchemist");
	set("long",
       "This is one of the wierdest creatures you have ever seen. Aside from being a centaur, this creature's skin shines like gold, and both his horse hair and head hair have been totally shaved off. He fidgets all over the place, and never seems to look at something for more then a few seconds. He cant stop mumbling about his magic telescope, every few minutes glances in that direction."
      );
      this_object()->set_race("centaur");
	this_object()->set_gender("male");
	set_body_type("centaur");
	set_wielding_limbs( ({"right hand", "left hand"}) );
	set_class("arch-mage");
	
	set_hp(HPBASE * (int)this_player()->query_level());
	set_max_hp(HPBASE * (int)this_player()->query_level());

     LEV = random(5) + 15;
        set_combat_chance(100);
       set_casting_chance(100);
	set_skill("dodge", 100 + (this_object()->query_level()) * 2);
     set_skill("parry", 115 + LEV *2);
         set_skill("concentrate", LEV * 4);
         set_skill("conjuration", 30 + LEV * 5);
      set_skill("melee", LEV * 3);
         add_spell("exploding fireball", "$A");
         set_spell_level("exploding fireball", 6);
    add_spell("internal flame", "$A");
    set_spell_level("internal flame", 6);
	set("aggressive", 0);
     add_money("gold", 200 + random(20));
        force_me("use concentrate");
}
