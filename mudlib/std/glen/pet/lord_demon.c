#include <colors.h>

inherit "/std/glen/pet/base_demon";


set_up(int pow) {
    power = pow;
    set_level(30+pow/8);
    set_max_hp(2500 + 15*pow);
    set_hp(2500 + 15*pow);
    set_skill("melee", 320 + pow);
    set_skill("chaos magic", 350+pow*4);
    set_skill("resist stun", 100+pow*5);
    set_max_mp(2500 + 15*pow);
    set_mp(2500 + 15*pow);
    set_spell_level("chaos ball", 6);
    add_spell("chaos ball", "$A");
    set_spell_level("chaos storm", 6);
    add_spell("chaos storm", "$A");
    set_spell_level("vampiric blade", 6);
    set_spell_level("essence blade", 6);
    set_spell_level("soultaker blade", 6);
    set_combat_chance(120);
    if(!query_owner())
	set_owner("rogue");
    return;
}

void create() {
    mat_ids = ({"demon", "lord demon", "huge demon"});
    cont_ids = ({ "lord controlled"});
    initial_ids = ({ "huge spirit", 
      "huge presence", "huge demonic presence"});

    initial_short = "Huge Demonic Presence";
    mat_short = "Lord Demon";
    mat_desc = "A huge demon materializes.";
    long_desc = "This is a huge demon.  They are about the "+
    "size of a storm giant, and downright scary.";
    demon_type = 4;
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

int spawn(int x){
    object ob;
    switch(random(3)){
    case 0:
	ob =new("/std/glen/pet/small_demon");
	break;
    case 1:
	ob =new("/std/glen/pet/normal_demon");
	break;
    case 2:
	ob =new("/std/glen/pet/greater_demon");
	break;
    }
    ob->move(environment(this_object()));
    ob->set_up(random(100));
    ob->materialize();
    ob->set_speed(random(10)+2);
    ob->set_dur(300+power*5);
    ob->set_owner(query_owner());
    call_out("spawn", x, x);
    return 1;
}


