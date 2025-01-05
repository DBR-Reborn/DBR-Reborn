inherit "/std/pet";

void create() {
    ::create();
    set_name("vampiric beast");
    set("race", "undead");
    set_combat_chance(120);
    set_id(({ "hound", "vampiric hound", "vampire", "scarred hound", "scarred vampiric hound", "scarred vampire", "undead" }));
    set_body_type("quadruped");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(30);
    set_property("enhance criticals", -1);
    set_property("nethermancer pet", 1);
    set_property("pet name", "vampiric hound");
    set_overall_ac(200);
    set_short("Scarred Vampiric Hound");
    set_property("pet short", "Scarred Vampiric Hound");
    call_out("nether_form_check", 0);
    set_long("Horribly torn with numerous visible battle scars, this large stark white beast appears as if it had been brutally murdered in a different life. Complete with badly blood stained teeth, claws at least two inches long, and a pulsing magical field in the center of its gaping mouth this creature surely is not one most individuals would want to cross in any manner.");
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

    set_max_hp(2200 + 220*pow);
    set_hp(2200 + 220*pow);
    set_max_hp(1900 + 190*pow);
    set_mp(1900 + 190*pow);
    set_skill("attack", 29*pow);
    set_skill("melee", 29*pow);
    set_skill("dodge", 22*pow);
    set_skill("parry", 25*pow);
    set_skill("black magic", 27*pow);
    set_skill("owedquar's will", 27*pow);
    add_spell("lifesteal", "$A");
    set_spell_level("lifesteal", spellpow);
    add_spell("black shroud", "$A");
    set_spell_level("black shroud", spellpow);
    set_property("melee damage", ([ "cutting" : 26 + (8 * pow), "crushing" : 26 + (8 * pow), "impaling" : 26 + (8 * pow)  ]));
return;
}
