inherit "/std/pet";

void create() {
    ::create();
    set_name("elemental demon");
    set_id(({ "demon", "elemental demon", "fearsome demon", "fearsome elemental demon" }));
    set("race", "elemental");
    set_body_type("human");
    set_attack(1);
    set_carry(0);
    set_save(0);
set_property("no save", 1);
    set_level(45);
    set_combat_chance(120);
    set_short("A fearsome elemental demon");
    set_long("This ferocious creature is a very powerful demon shaped elemental. It's hands come fitted with razor sharp pulsing claws and its enormous eyes flash several different colors as the beast lets out a shuddering roar.");
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

    set_max_hp(5000 + (pow * 1500));
    set_hp(this_object()->query_max_hp());
    set_skill("attack", 150 + 40*pow);
    set_skill("melee", 150 + 40*pow);
    set_stats("strength", 50 + 50*pow);
    set_stats("intelligence", 50 + 50*pow);
    set_skill("elemental magic", 100 + 10+pow);
    add_spell("energy sphere", "$A");
    set_spell_level("energy sphere", pow);
    return;
}

void set_dur(int dur) {
    call_out("remove_pet", dur);
    return;
}

void remove_pet() {
    this_object()->force_me("drop all");
    message("info", "%^BLUE%^The Elemental Demon slowly begins to fade away, and before long is completely erased from existence.%^RESET%^", environment(this_object()));
    remove();
    return;
}
