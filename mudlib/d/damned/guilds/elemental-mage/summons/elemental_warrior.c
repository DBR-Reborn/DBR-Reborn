inherit "/std/pet";

void create() {
    ::create();
    set_name("elemental warrior");
    set_id(({ "warrior", "elemental warrior", "swift warrior", "swift elemental warrior" }));
    set("race", "elemental");
    set_body_type("human");
    set_attack(1);
    set_carry(0);
    set_save(0);
    set_level(30);
    set_short("A swift elemental warrior");
    set_long("This average sized elemental appears to be extremely nimble, standing only five feet tall but motioning its glowing body with the speed and fluency of a master martial artist. It forever serves its summoner and will give its very life for his or her cause."); 
    set_can_change_aggr(0);
    return;
}

void set_owner(string who) {
    object ob;

    ob = find_player(who);
    if(!ob) {
	::set_owner(who);
	return;
    }
    set_languages(({ "common", "elementalish", (string)ob->query_primary_lang() }));
    ::set_owner(who);
    return;
}

void set_up(int pow) {
    set_max_hp(3000 + (pow * 500));
    set_hp(3000 + (pow * 500));
    set_skill("attack", 100 + 25*pow);
    set_skill("melee", 100 + 25*pow);
    set_stats("strength", 50 + 25*pow);
    return;
}

void set_dur(int dur) {
    call_out("remove_pet", dur);
    return;
}

void remove_pet() {
    this_object()->force_me("drop all");
    message("info", "%^BLUE%^The Elemental Warrior slowly begins to fade away, and before long is completely erased from existence.%^RESET%^", environment(this_object()));
    remove();
    return;
}
