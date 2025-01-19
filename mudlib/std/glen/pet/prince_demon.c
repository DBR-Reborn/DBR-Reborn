#include <colors.h>

inherit "/std/glen/pet/base_demon";


set_up(int pow) {
    power = pow;
    set_level(35+pow/6);
    set_max_hp(8000 + 50*pow);
    set_hp(8000 + 50*pow);
    set_skill("melee", 400 + pow*2);
    set_skill("chaos magic", 500+pow*5);
    set_skill("resist stun", 500+pow*5);
    set_max_mp(10000 + 50*pow);
    set_mp(10000 + 50*pow);
    set_spell_level("chaos ball", 6);
    add_spell("chaos ball", "$A");
    set_spell_level("chaos storm", 6);
    add_spell("chaos storm", "$A");
    set_spell_level("vampiric blade", 6);
    set_spell_level("essence blade", 6);
    set_spell_level("soultaker blade", 6);
    set_spell_level("demonic rebirth", 6);
    set_combat_chance(120);
    set_property("enhance criticals", 
      query_property("enhance criticals") -2);
    if(!query_owner())
	set_owner("rogue");
    return;
}

void create() {
    mat_ids = ({"demon", "prince", "prince demon", "giant demon"});
    cont_ids = ({ "prince controlled"});
    initial_ids = ({ "giant spirit", 
      "giant presence", "giant demonic presence"});

    initial_short = "Giant Demonic Presence";
    mat_short = "Prince Demon";
    mat_desc = "A giant demon materializes.";
    long_desc = "This is a giant demon."+
    "He isnt that large, but he is very intimidating";

    demon_type = 5;
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

int spawn(int x){
    object ob;
    ob =new("/std/glen/pet/lord_demon");
    ob->move(environment(this_object()));
    ob->set_up(random(100));
    ob->materialize();
    ob->set_speed(random(60)+ 60);
    ob->spawn(30+random(70));
    ob->set_dur(600+power*5);
    ob->set_owner(query_owner());
    call_out("spawn", x, x);
    return 1;
}

