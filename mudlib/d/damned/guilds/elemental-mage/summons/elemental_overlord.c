inherit "/std/pet";

void create() {
    ::create();
    set_name("elemental overlord");
    set_id(({ "overlord", "elemental overlord", "imposing overlord", "imposing elemental overlord", "elemental" }));
    set("race", "elemental");
    set_body_type("human");
    set_attack(1);
    set_carry(0);
    set_save(0);
    set_level(75);
    set_overall_ac(800);
    set_combat_chance(200);
    set_short("%^BOLD%^%^MAGENTA%^An imposing elemental overlord%^BOLD%^%^RED%^");
    set_long("Hovering a few inches above the ground which blows beneath it, this relatively large mage shaped elemental is by far the most staggering entity you have ever laid your eyes upon. Its entire body crackles with fierce bolts of highly active energy and spheres of pulsing power swirl in each of its hands, fitted with finger blades nearly six inches long. Its eyes flash for a split second as it covers itself completely in a dazzling aura, striking fear deep into your heart.");
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
set_max_hp(1000);
set_hp(1000);
    set_skill("martial arts", 250);
    set_skill("attack", 400 + 75*pow);
    set_skill("melee", 400 + 75*pow);
    set_skill("concentrate", 200);
    set_stats("strength", 150 + 60*pow);
    set_stats("intelligence", 150 + 60*pow);
    set_stats("wisdom", 150 + 60*pow);
    set_skill("elemental magic", 200 + 25+pow);
    add_spell("planar wrath", "$A");
    set_spell_level("planar wrath", pow);
    return;
}

void set_dur(int dur) {
    call_out("remove_pet", dur);
    return;
}

void remove_pet() {
    this_object()->force_me("drop all");
    message("info", "%^BLUE%^The Elemental Overlord slowly begins to fade away, and before long is completely erased from existence.%^RESET%^", environment(this_object()));
    remove();
    return;
}
