inherit "/std/pet";

void create() {
    ::create();
    set_name("revenant");
    set("race", "zombie");
    set_combat_chance(120);
    set_id(({ "zombie", "revenant", "decaying revenant", "decaying zombie", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(12);
    set_property("enhance criticals", 0);
    set_property("nethermancer pet", 1);
    set_property("pet name", "revenant");
    set_overall_ac(100);
    set_short("Decaying Revenant");
    set_property("pet short", "Decaying Revenant");
    call_out("nether_form_check", 0);
    set_long("A sickening amount of decay and rot cover the entire body of this rather large zombie. Death defying moans come from its mouth upon all of its movements toward you, not to mention the extremely odorous blood dripping from all of its exposed joints during those same motions.");
    set_aggr_status(0);
    set_skill("concentrate", 200);
    force_me("use concentrate");
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
    int spellpow = pow;
    if(spellpow > 6) spellpow = 6;

    set_max_hp(500 + 50*pow);
    set_hp(500 + 50*pow);
    set_max_mp(400 + 40*pow);
    set_mp(400 + 40*pow);
    set_skill("attack", 16*pow);
    set_skill("melee", 16*pow);
    set_skill("dodge", 12*pow);
    set_skill("parry", 14*pow);
    set_skill("owedquar's will", 13*pow);
    set_skill("black magic", 13*pow);
    add_spell("chilling touch", "$A");
    set_spell_level("chilling touch", spellpow);
    add_spell("shadow bolt", "$A");
    set_spell_level("shadow bolt", spellpow);
    set_property("melee damage", ([ "crushing" : 12 + (3 * pow) ]));
return;
}
