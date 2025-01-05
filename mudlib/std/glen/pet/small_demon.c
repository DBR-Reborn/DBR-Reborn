//    A lesser demon.
#include <colors.h>

inherit "/std/glen/pet/base_demon";

set_up(int pow) {
    power = pow;
    set_level(3+pow/30);
    set_max_hp(150 + pow*3);
    set_hp(150 + pow*3);
    set_skill("melee", 30 + pow/10);
    set_skill("chaos magic", 40 + pow/25);
    set_max_mp(150 + 70*pow);
    set_mp(150 + 70*pow);
    set_spell_level("disruption bolt", 1+pow/20);
    add_spell("disruption bolt", "$A");
    set_combat_chance(50);
    if(!query_owner())
	set_owner("rogue");
    ::set_up(pow);
    return;
}
void create() {
    mat_ids = ({"demon", "small demon", "smaller demon"});
    cont_ids = ({ "lesser controlled"});
    initial_ids = ({ "small spirit", 
      "small presence", "small demonic presence"});

    initial_short = "Small Demonic Presence";
    mat_short = "Smaller Demon";
    mat_desc = "A small demon materializes.";
    long_desc = "This is a smaller demon.  They are about the size of a goblin, " +
    "yet they are very fierce.  ";
    demon_type = 1;
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


