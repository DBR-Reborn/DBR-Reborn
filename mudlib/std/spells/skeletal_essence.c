inherit "/std/pet";

void create() {
    ::create();
    set_name("skeletal essence");
    set("race", "spirit");
    set_combat_chance(120);
    set_id(({ "essence", "skeleton", "skeletal essence", "misty essence", "misty skeleton", "misty skeletal essence", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(28);
    set_property("enhance criticals", 0);
    set_property("nethermancer pet", 1);
    set_property("pet name", "skeletal essence");
    set_overall_ac(200);
    set_short("Misty Skeletal Essence");
    set_property("pet short", "Misty Skeletal Essence");
    call_out("nether_form_check", 0);
    set_long("This rather shrouded creature appears to be made up of such dense mist that one could say it looks real and not immaterial. It has the makeup of a very complex skeleton with rather sharp toes and fingers as well as glowing holes in its palms for releasing magical energy. No sounds are heard in any of its movements, not even those of slight drafts from the mist in motion.");
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

    set_max_hp(1500 + 150*pow);
    set_hp(1500 + 150*pow);
    set_skill("attack", 28*pow);
    set_skill("melee", 28*pow);
    set_skill("dodge", 21*pow);
    set_skill("parry", 24*pow);
    set_skill("assassin's magic", 25*pow);
    set_skill("warcasting", 25*pow);
    add_spell("mind freeze", "$A");
    set_spell_level("mind freeze", spellpow);
    add_spell("electrocute", "$A");
    set_spell_level("electrocute", spellpow);
    set_property("melee damage", ([ "cutting" : 24 + (7 * pow), "crushing" : 24 + (7 * pow) ]));
return;
}
