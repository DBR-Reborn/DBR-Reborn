#include <colors.h>

inherit "/std/glen/pet/base_demon";


set_up(int pow) {
    power = pow;
    set_level(7+pow/30);
    set_max_hp(300 + 5*pow);
    set_hp(300 + 5*pow);
    set_skill("melee", 70 + pow/3);
    set_skill("chaos magic", 95);
    set_max_mp(300 + 5*pow);
    set_mp(300 + 5*pow);
    set_spell_level("disruption bolt", 6);
    add_spell("disruption bolt", "$A");
    set_spell_level("chaos ball", 1+pow/20);
    add_spell("chaos ball", "$A");
    add_spell("vampiric blade", 6);
    set_combat_chance(70);
    if(!query_owner())
	set_owner("rogue");
    ::set_up(pow);
    return;
}

void create() {
    mat_ids = ({"demon", "normal demon", "standard demon"});
    cont_ids = ({ "controlled"});
    initial_ids = ({ "spirit", 
      "presence", "demonic presence"});

    initial_short = "Demonic Presence";
    mat_short = "Demon";
    mat_desc = "A demon materializes.";
    long_desc = "This is a demon.  They are about the "+
    "size of a human, and quite fierce.";
    demon_type = 2;
    ::create();
    set_save(0);
set_property("no save", 1);
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


