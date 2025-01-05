inherit "/std/pet";

void create() {
    ::create();
    set_name("blood fiend");
    set("race", "undead");
    set_combat_chance(120);
    set_id(({ "fiend", "vampire", "blood fiend", "thirsty vampire", "thirsty fiend", "thirsty blood fiend", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(26);
    set_property("enhance criticals", -1);
    set_property("nethermancer pet", 1);
    set_property("pet name", "blood fiend");
    set_overall_ac(200);
    set_short("Thirsty Blood Fiend");
    set_property("pet short", "Thirsty Blood Fiend");
    call_out("nether_form_check", 0);
    set_long("This undead being appears horribly pale, with razor sharp claws and blood stained teeth visible from the creature's seemingly always open mouth. Its entire body is very muscular and looks very battle hardened, giving the impression that this vampire is one that is not afraid of resistance when it decides to feed off of a target.");
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

    set_max_hp(1800 + 180*pow);
    set_hp(1800 + 180*pow);
    set_skill("attack", 27*pow);
    set_skill("melee", 27*pow);
    set_skill("dodge", 19*pow);
    set_skill("parry", 22*pow);
    set_skill("necromancy", 24*pow);
    add_spell("lifesteal", "$A");
    set_spell_level("lifesteal", spellpow);
    set_property("melee damage", ([ "cutting" : 24 + (7 * pow), "crushing" : 24 + (7 * pow), "impaling" : 24 + (7 * pow)  ]));
return;
}
