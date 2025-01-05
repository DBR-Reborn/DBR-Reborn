#include <std.h>

inherit MONSTER;

create() {
    object ob, obw;
    ::create();
    set_name("page");
    set_id( ({"undead", "page"}));
    set_short("undead page");
    set_long("this page has come back from his unlife to serve his master.");
    set("race", "undead");
    set_level(17+random(4));
    set_body_type("human");
    set("aggressive", (: call_other, this_object(), "enemies_fun" :) );
    set_skill("necromancy", 120);
    set_spell_level("instill fear", 6);
    add_spell("instill fear", "$A");
    set_combat_chance(15);
    obw = new("/d/damned/virtual/hammer_3.weapon");
    ob = new("/std/spells/shadows/weapon_shadow");
    ob->set_auto_crits(([ "stun C" : 20, "paralysis D" : 30 ]));
    ob->set_extra_wc(([ "cold" : 20, "cutting" : 20 ]));
    ob->set_enh_critical(1);
    ob->start_shadow(obw, 0, "effects wear off");
    obw->move(this_object());
    force_me("equip");
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


