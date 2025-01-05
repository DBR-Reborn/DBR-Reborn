#include <std.h>

inherit "/std/pet";

int power;

void create() {
    ::create();
    set_name("mammet");
    set_id(({ "mammet" }));
    set("race", "magical-creation");
    set_body_type("human");
    set_attack(1);
    set_carry(1);
    set_save(1);
    set_level(15);
    set_can_change_aggr(1);
    set_short("Mammet");
    set_long("This mammet is animated magically.  It is vaguely humanoid in shape.");
    set_aggr_status(0);
    return;
}

void set_owner(string who) {
    object ob;

    ob = find_player(who);
    if(!ob) {
	::set_owner(who);
	return;
    }
    set_languages(({ "grken", "drow", "common", "elvish", 
	"dwarvish", "serra", "yin", "treefolk",
	(string)ob->query_primary_lang() }) );
    ::set_owner(who);
    return;
}

int id(string str) {
    if(::id(str)) return 1;
    return ::id(replace_string(str, query_property("material_name")+" ",
	""));
}

void restore_stuff() {
    ::restore_stuff();
    set_short((string)query_property("material_name")+" Mammet");
    return;
}

void set_up(int pow) {
    int i, idx, tmp2, *ac_values;
    mixed auto_crit;
    mapping tmp;
    string s_tmp, *ac_keys, tmp1, nothing;

    set_material(query_property("material name"));
    set_level(15 + pow);
    set_short((string)query_property("material_name")+" Mammet");
    set_overall_ac(query_overall_ac() + pow*(int)prop("hardness")/60);
    set_max_hp( query_hp() + pow*(int)prop("hardness")/6);
    set_property("enhance criticals", -3 + (int)query_property("enhance criticals"));
    set_hp(query_max_hp());

    set_stats("strength", 70 + 10 * pow);
    return;
}

