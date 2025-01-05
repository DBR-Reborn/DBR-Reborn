inherit "/std/pet";

void create() {
    ::create();
    set_name("black essence");
    set("race", "spirit");
    set_combat_chance(120);
    set_id(({ "essence", "black essence", "shrouded essence", "shrouded black essence", "spirit", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(38);
    set_property("enhance criticals", -1);
    set_property("nethermancer pet", 1);
    set_property("pet name", "black essence");
    set_overall_ac(250);
    set_short("Shrouded Black Essence");
    set_property("pet short", "Shrouded Black Essence");
    call_out("nether_form_check", 0);
    set_long("As black as the night and as frightening in appearance as any material creature, this immaterial being truly appears to be a force to be reckoned with. Its entire body hovers about a foot above the ground and it shimmers at a seemingly never ending rate, giving impressions that it never has a period of rest and is always primed for inflicting harm at its most potent potential."); 
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

    set_max_hp(3300 + 330*pow);
    set_hp(3300 + 330*pow);
    set_max_hp(3000 + 300*pow);
    set_mp(3000 + 230*pow);
    set_skill("attack", 35*pow);
    set_skill("melee", 35*pow);
    set_skill("dodge", 27*pow);
    set_skill("parry", 31*pow);
    set_skill("necromancy", 34*pow);
    set_skill("owedquar's will", 34*pow);
    add_spell("decay", "$A");
    set_spell_level("decay", spellpow);
    add_spell("black fire", "$A");
    set_spell_level("black fire", spellpow);
    set_property("melee damage", ([ "cutting" : 30 + (8 * pow), "crushing" : 30 + (8 * pow), "impaling" : 30 + (8 * pow)  ]));
return;
}
