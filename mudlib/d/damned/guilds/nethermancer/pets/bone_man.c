inherit "/std/pet";

void create() {
    ::create();
    set_name("bone man");
    set("race", "skeleton");
    set_combat_chance(120);
    set_id(({ "man", "bone man", "man of bone", "skeleton", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(4);
    set_property("enhance criticals", 0);
    set_property("nethermancer pet", 1);
    set_property("pet name", "bone man");
    set_overall_ac(0);
    set_short("Bone Man");
    set_property("pet short", "Bone Man");
    call_out("nether_form_check", 0);
    set_long("This is a relatively small skeleton, standing only about four feet tall. It is comprised completely of stark white bone and its entire body moves very awkwardly as it moves in any fashion.");
    set_aggr_status(0);
    return;
}

void nether_form_check() {
    if(this_object()->query_property("nether form")) set_short("Bone Man %^BOLD%^%^GREEN%^(%^CYAN%^nether form%^GREEN%^)%^RED%^");
}

void set_owner(string who) {
    object ob;

    ob = find_player(who);
    if(!ob) {
	::set_owner(who);
	return;
    }

    set_languages(({ "common", "undead-tongue", (string)ob->query_primary_lang() }));
    ::set_owner(who);
    return;
}

void set_up(int pow) {
    set_max_hp(100 + 20*pow);
    set_hp(100 + 20*pow);
    set_skill("attack", 8*pow);
    set_skill("melee", 8*pow);
    set_skill("dodge", 5*pow);
    set_skill("parry", 7*pow);
    set_property("melee damage", ([ "crushing" : 5 + (1 * pow) ]));
return;
}

