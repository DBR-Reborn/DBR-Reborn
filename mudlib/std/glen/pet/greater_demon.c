#include <colors.h>

inherit "/std/glen/pet/base_demon";


set_up(int pow) {
    power = pow;
    set_level(15+pow/10);
    set_max_hp(500 + 5*pow);
    set_hp(500 + 5*pow);
    set_skill("melee", 130 + pow);
    set_skill("chaos magic", 100+pow);
    set_max_mp(600 + 8*pow);
    set_mp(600 + 8*pow);
    set_spell_level("chaos ball", 6);
    add_spell("chaos ball", "$A");
    add_spell("vampiric blade", 6);
    set_combat_chance(90);
    if(!query_owner())
	set_owner("rogue");
    ::set_up(pow);
    return;
}

void create() {
    mat_ids = ({"demon", "large demon", "greater demon"});
    cont_ids = ({ "greater controlled"});
    initial_ids = ({ "large spirit", 
      "large presence", "large demonic presence"});

    initial_short = "Large Demonic Presence";
    mat_short = "Large Demon";
    mat_desc = "A large demon materializes.";
    long_desc = "This is a large demon.  They are about the "+
    "size of a large human, and quite formidable.";
    demon_type = 3;
    ::create();
    set_save(0);
    set_attack(1);
    set_carry(0);
    set_can_change_aggr(0);
    set_name("demon");
    set_id(initial_ids);
    set_short(initial_short);
    set("race", "demon");
    set_body_type("winged-humanoid");
    set_long(long_desc);
    set_name("demon");
    set_up(random(101));
    return;
}


