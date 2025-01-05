inherit "/std/pet";

void create() {
    ::create();
    set_name("elemental dragon");
    set_id(({ "dragon", "elemental dragon", "ferocious dragon", "ferocious elemental dragon" }));
    set("race", "elemental");
    set_body_type("human");
    set_attack(1);
    set_carry(0);
    set_save(0);
    set_level(60);
    set_combat_chance(120);
    set_short("A ferocious elemental dragon");
    set_long("Standing tall before your stunned eyes is a ten foot tall dragon, covered from head to toe in sharp shimmering scales. Powerful flowing breath foams about its mouth and its bright white eyes seem to blind you from identifying its facial expressions that do not likely favor the weak");
    set_can_change_aggr(1);
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
    if(pow > 6) {
	pow = 6;
    }
    set_max_hp(10000 + (pow * 2000));
    set_hp(this_object()->query_max_hp());
    set_skill("attack", 250 + 60*pow);
    set_skill("melee", 250 + 60*pow);
    set_stats("strength", 100 + 50*pow);
    set_stats("intelligence", 100 + 50*pow);
    set_stats("wisdom", 100 + 50*pow);
    set_skill("elemental magic", 150 + 15+pow);
    add_spell("energy sphere", "$A");
    set_spell_level("energy sphere", pow);
    add_spell("elemental breath", "$A");
    set_spell_level("elemental breath", pow);
    return;
}

void set_dur(int dur) {
    call_out("remove_pet", dur);
    return;
}

void remove_pet() {
    if(this_object()->query_property("permanent") != 1) {
	this_object()->force_me("drop all");
	message("info", "%^BLUE%^The Elemental Dragon slowly begins to fade away, and before long is completely erased from existence.%^RESET%^", environment(this_object()));
	remove();
	return;
    }
}
