
#include <std.h>
#include <daemons.h>
#include <balance.h>
#include <colors.h>

inherit MONSTER;

int do_damage(string limb, int amt) {
    int r = random(20);

    object prev = previous_object();

    if(r < 3)
	do_base_critical( this_object(), prev, ({ "disruption A" }), "torso" );
    if(r >= 3 && r < 6)
	do_base_critical( this_object(), prev, ({ "disruption B" }), "torso" );
    if(r >= 6 && r < 8)
	do_base_critical( this_object(), prev, ({ "disruption C" }), "torso" );
    if(r == 8)
	do_base_critical( this_object(), prev, ({ "disruption D" }), "torso" );
    if(r == 9)
	do_base_critical( this_object(), prev, ({ "disruption E" }), "torso" );
    if(r < 10)
	message("info", CBOLD + CBLUE + 
	  "The insanity of the demon harms you!", prev);

    return ::do_damage(limb, amt);

}

create() {
    object ob, obw;
    ::create();
    set_name("fallen-angel");
    set_id(({"fallen-angel", "angel", "demon"}));
    set_short("A dissident skeletal demon");
    set_long("hate emanates from this demon.  Its mere "+
      "presence seems to imbalance the universe.  "+
      "Your life flashes before your eyes when it looks "+
      "your direction.");
    set_level(65+random(14));
    set_body_type("winged-humanoid");
    set("race", "undead");
    set_wielding_limbs( ({"left hand"}) );
    set_gender("male");
    set_alignment(-10);
    set_languages( ({"common"}) );
    force_me("speak common");
    set_max_hp(query_max_hp() * 2);
    set_hp(query_max_hp());
    set_property("enhance criticals", -1*query_level() / 10);
    set_skill("curse lore",320);
    set_spell_level("darken soul", 6);
    set_spell_level("shatter soul", 6);
    set_spell_level("disease bone rot", 6);
    set_spell_level("disease rot", 6);
    add_spell("darken soul", "$A");
    add_spell("shatter soul", "$A");
    add_spell("disease rot", "$A");
    add_spell("disease bone rot", "$A");
    set_casting_chance(300);
    set_combat_chance(300);
    set_skill("martial arts",query_skill("attack"));
    set_property("melee damage",
      query_property("melee damage") + (["disruption" : 85]));
    set("aggressive",1);
}

