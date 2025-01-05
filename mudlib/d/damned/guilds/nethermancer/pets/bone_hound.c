inherit "/std/pet";

void create() {
    ::create();
    set_name("bone hound");
    set("race", "dog");
    set_combat_chance(120);
    set_id(({ "hound", "bone hound", "dog", "bone dog", "undead" }));
    set_body_type("quadruped");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(15);
    set_property("enhance criticals", 0);
    set_property("nethermancer pet", 1);
    set_property("pet name", "bone hound");
    set_overall_ac(100);
    set_short("Bone Hound");
    set_property("pet short", "Bone Hound");
    call_out("nether_form_check", 0);
    set_long("Made entirely of stark white bone, this hound appears to have no inner organs of any kind despite the fact that it freely moves about. Eyes are included amongst the absent organs, but you feel as if you know the creature is somehow looking at you very clearly.");
    set_aggr_status(0);
    return;
}

void nether_form_check() {
    if(this_object()->query_property("nether form")) set_short(""+this_object()->query_property("pet short")+" %^BOLD%^%^GREEN%^(%^CYAN%^nether form%^GREEN%^)%^RED%^");
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

    set_max_hp(500 + 75*pow);
    set_hp(500 + 75*pow);
    set_skill("attack", 19*pow);
    set_skill("melee", 19*pow);
    set_skill("dodge", 14*pow);
    set_skill("parry", 16*pow);
    set_property("melee damage", ([ "crushing" : 15 + (4 * pow) ]));
return;
}
