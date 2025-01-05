#include <std.h>

inherit MONSTER;

create() {
    object ob, obw;
    ::create();
    set_name("noble");
    set_id( ({"undead", "noble"}));
    set_short("undead noble");
    set_long("has come back to life, and is rather irritated!");
    set("race", "undead");
    set_level(22+random(5));
    set_body_type("human");
    set("aggressive", (: call_other, this_object(), "enemies_fun" :) );
    set_skill("necromancy", 120);
    set_spell_level("instill fear", 6);
    add_spell("instill fear", "$A");
    set_combat_chance(30);
    obw = new("/d/damned/virtual/scimitar_5.weapon");
    ob = new("/std/spells/shadows/weapon_shadow");
    ob->set_auto_crits(([ "stun C" : 80, "paralysis D" : 60 ]));
    ob->set_extra_wc(([ "cold" : 40, "cutting" : 50 ]));
    ob->set_enh_critical(3);
    ob->start_shadow(obw, 0, "effects wear off");
    obw->move(this_object());
    set_skill("block", query_skill("parry") *5/4);
    new("/d/damned/virtual/large-shield.armour")->move(this_object());
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


