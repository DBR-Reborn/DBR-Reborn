#include <std.h>

inherit MONSTER;

create() {
    object ob, obw;
    ::create();
    set_name("hound");
    set_id( ({"undead", "hound", "dog"}));
    set_short("undead hound");
    set_long("was surely a loyal pet.  The afterlife has made "+
      "it rather fearsome!");
    set("race", "undead");
    set_level(18+random(4));
    set_body_type("quadruped");
    set("aggressive", (: call_other, this_object(), "enemies_fun" :) );
    set_skill("necromancy", 120);
    set_spell_level("instill fear", 6);
    add_spell("instill fear", "$A");
    set_combat_chance(5);
    set_skill("attack", query_skill("attack") * 2);
}

int query_num_rounds() {
    return ::query_num_rounds() + 1;
}


int enemies_fun(object who){
    string *enemies;
    string name;
    if(who->query_class() == "underlord"){
	return 0;
    }
    if(who->query_level() < 6)
	return 0;
    if(who->query_race() == "undead")
	return 0;
    kill_ob(who, 1);
    return 1;
}


