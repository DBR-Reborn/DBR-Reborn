#include <std.h>

inherit MONSTER;

create() {
    object ob, obw;
    ::create();
    set_name("priest");
    set_id( ({"undead", "priest"}));
    set_short("undead priest");
    set_long("this pious priest has been twisted into servitude.  "+
      "How horrible, you should free him.");
    set("race", "undead");
    set_level(20+random(4));
    set_body_type("human");
    set("aggressive", (: call_other, this_object(), "enemies_fun" :) );
    set_skill("necromancy", 120);
    set_spell_level("instill fear", 6);
    add_spell("instill fear", "$A");
    set_combat_chance(300);
    obw = new("/d/damned/virtual/war-hammer_6.weapon");
    ob = new("/std/spells/shadows/weapon_shadow");
    ob->set_auto_crits(([ "stun C" : 20, "paralysis D" : 50 ]));
    ob->set_extra_wc(([ "cold" : 40, "cutting" : 0 ]));
    ob->set_enh_critical(1);
    ob->start_shadow(obw, 0, "effects wear off");
    obw->move(this_object());
    new("/d/damned/virtual/robe.armour")->move(this_object());
    new("/d/damned/virtual/leather-hood.armour")->move(this_object());
    new("/d/damned/virtual/leather-boots.armour")->move(this_object());
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


