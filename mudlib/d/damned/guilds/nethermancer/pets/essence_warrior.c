inherit "/std/pet";

void create() {
    object ob;
    ::create();
    set_name("essence warrior");
    set("race", "spirit");
    set_combat_chance(120);
    set_id(({ "warrior", "essence warrior", "shimmering warrior", "shimmering essence warrior", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(300);
    set_save(1);
    set_level(51);
    set_property("enhance criticals", -1);
    set_property("nethermancer pet", 1);
    set_property("pet name", "essence warrior");
    set_overall_ac(350);
    set_short("Shimmering Essence Warrior");
    set_property("pet short", "Shimmering Essence Warrior");
    call_out("nether_form_check", 0);
    set_long("Comprised entirely of a staggeringly dense mist from head to toe, this nearly nine foot tall warrior looks both considerably imposing and amazing. Massive immaterial armour appears to cover every one of its limbs, including a truly menacing mask resembling that of a truly ferocious demon lord. A very large and fully material skull sword seems to float in its hands, miraculously serving as its weapon despite the fact that the concept itself breaks natural laws."); 
    set_aggr_status(0);
    ob = new("/d/damned/guilds/nethermancer/misc/huge_sword.c");
    ob->move(this_object());
    set_skill("concentrate", 200);
    force_me("wield sword in right hand and left hand");
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

    set_max_hp(7000 + 700*pow);
    set_hp(7000 + 700*pow);
    set_max_mp(6100 + 610*pow);
    set_mp(6100 + 610*pow);
    set_skill("attack", 52*pow);
    set_skill("melee", 52*pow);
    set_skill("two handed blade", 52*pow);
    set_skill("dodge", 38*pow);
    set_skill("parry", 45*pow);
    set_skill("empowerment", 47*pow);
    set_skill("spiritmancy", 47*pow);
    add_spell("unholy rage", "$(ME)");
    set_spell_level("unholy rage", spellpow);
    add_spell("devour soul", "$A");
    set_spell_level("devour soul", spellpow);
    set_property("melee damage", ([ "crushing" : 40 + (11 * pow), "cold" : 40 + (11 * pow), "unholy" : 40 + (11 * pow)  ]));
return;
}
