inherit "/std/pet";

void create() {
    ::create();
    set_name("chaos shadow");
    set("race", "shadow");
    set_combat_chance(120);
    set_id(({ "shadow", "chaos", "pure chaos", "chaos shadow", "pure chaos shadow", "shadow of chaos", "shadow of pure chaos", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(300);
    set_save(1);
    set_level(55);
    set_property("enhance criticals", -2);
    set_property("nethermancer pet", 1);
    set_property("pet name", "chaos shadow");
    set_overall_ac(400);
    set_skill("concentrate", 200);
    set_short("Shadow of Pure Chaos");
    set_property("pet short", "Shadow of Pure Chaos");
    call_out("nether_form_check", 0);
    set_long("This is a small but apparently very active amalgamation of what can only be described as pure abysmal chaos. An incarnation of several of the most damned netherworld souls, this truly appears to be quite a formidable foe especially as it body almost endlessly swirls with numerous dark and distorted colors.");
    set_aggr_status(0);
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

    set_max_hp(7500 + 750*pow);
    set_hp(7500 + 750*pow);
    set_max_mp(6600 + 660*pow);
    set_mp(6600 + 660*pow);
    set_skill("attack", 55*pow);
    set_skill("melee", 55*pow);
    set_skill("dodge", 40*pow);
    set_skill("parry", 48*pow);
    set_skill("owedquar's will", 50*pow);
    set_skill("chaos magic", 50*pow);
    add_spell("black fire", "$A");
    set_spell_level("black fire", spellpow);
    add_spell("hell blast", "$A");
    set_spell_level("hell blast", spellpow);
    set_property("melee damage", ([ "cold" : 45 + (11 * pow), "unholy" : 45 + (11 * pow), "disruption" : 45 + (11 * pow)  ]));
return;
}
