inherit "/std/pet";

void create() {
    ::create();
    set_name("fanged spirit");
    set("race", "spirit");
    set_combat_chance(120);
    set_id(({ "spirit", "fanged spirit", "ghost", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(33);
    set_property("enhance criticals", -1);
    set_property("nethermancer pet", 1);
    set_property("pet name", "fanged spirit");
    set_overall_ac(250);
    set_short("Fanged Spirit");
    set_property("pet short", "Fanged Spirit");
    call_out("nether_form_check", 0);
    set_long("This is a rather peculiar ghostly being, for it appears to have both immaterial and material aspects. The entire main body of the spirit is blood red mist, butseveral three inch teeth hang down from the mouth area thatm are actually real and look as if they can do serious damage to even a well armoured warrior. Coupled along with this anomaly are wails so high pitched that even the most patient person would strongly consider running for cover from.");
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

    set_max_hp(2600 + 260*pow);
    set_hp(2600 + 260*pow);
    set_max_hp(2300 + 230*pow);
    set_mp(2300 + 230*pow);
    set_skill("attack", 32*pow);
    set_skill("melee", 32*pow);
    set_skill("dodge", 24*pow);
    set_skill("parry", 28*pow);
    set_skill("necromancy", 30*pow);
    set_skill("spiritmancy", 30*pow);
    add_spell("curse", "$A");
    set_spell_level("curse", spellpow);
    add_spell("devour soul", "$A");
    set_spell_level("devour soul", spellpow);
    set_property("melee damage", ([ "cutting" : 29 + (8 * pow), "crushing" : 29 + (8 * pow), "impaling" : 29 + (8 * pow)  ]));
return;
}
