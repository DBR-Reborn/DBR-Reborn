inherit "/std/pet";

void create() {
    ::create();
    set_name("elemental fighter");
    set_id(({ "fighter", "elemental fighter", "smug fighter", "smug elemental fighter" }));
    set("race", "elemental");
    set_body_type("human");
    set_attack(1);
    set_carry(0);
    set_save(0);
set_property("no save", 1);
    set_level(15);
    set_short("A smug elemental fighter");
    set_long("This is a well built humanoid shaped elemental, completely obedient to its master summoner. Its entire body shimmers faintly with power and moves very quickly, as it is well versed in hand to hand combat.");
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
    set_max_hp(pow * 300);
    set_hp(pow * 300);
    set_stats("strength", 50 + 25*pow);
    set_skill("attack", 50 + 15*pow);
    set_skill("melee", 50 + 15*pow);
    return;
}

void set_dur(int dur) {
    call_out("remove_pet", dur);
    return;
}

void remove_pet() {
    this_object()->force_me("drop all");
    message("info", "%^BLUE%^The Elemental Fighter slowly begins to fade away, and before long is completely erased from existence.%^RESET%^", environment(this_object()));
    remove();
    return;
}
