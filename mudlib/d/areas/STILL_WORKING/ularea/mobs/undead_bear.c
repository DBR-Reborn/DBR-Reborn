#include <std.h>

inherit MONSTER;

create() {
    object ob, obw;
    ::create();
    set_name("bear");
    set_id( ({"undead", "bear", "grizzly"}));
    set_short("undead grizzly bear");
    set_long("This grizzly bear is huge, and angry.  "+
      "This is the largest bear you have ever seen");
    set("race", "undead");
    set_level(30+random(4));
    set_body_type("quadruped");
    set("aggressive", (: call_other, this_object(), "enemies_fun" :) );
    set_skill("necromancy", 120);
    set_spell_level("instill fear", 6);
    add_spell("instill fear", "$A");
    set_combat_chance(80);
    set_skill("attack", query_skill("attack") * 2);
    set_skill("melee", query_skill("melee") * 2);
}

int query_num_rounds() {
    return ::query_num_rounds();
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
