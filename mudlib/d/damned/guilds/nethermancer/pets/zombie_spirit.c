inherit "/std/pet";

void create() {
    ::create();
    set_name("zombie spirit");
    set("race", "spirit");
    set_combat_chance(120);
    set_id(({ "spirit", "zombie", "zombie spirit", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(25);
    set_property("enhance criticals", 0);
    set_property("nethermancer pet", 1);
    set_property("pet name", "zombie spirit");
    set_overall_ac(175);
    set_short("Zombie Spirit");
    set_property("pet short", "Zombie Spirit");
    call_out("nether_form_check", 0);
    set_long("Constructed of thick and bright white mist, this amalgamation of a zombie and a ghost seems to move about in the same annoying manners as a zombie would and does not hover about like a typical spirit. However, judging by the density and activity of the mist combined with the deafening screams of the creature you can safely assume that this monster is more powerful than either of the undead comprising it.");
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

    set_max_hp(1100 + 110*pow);
    set_hp(1100 + 110*pow);
    set_skill("attack", 24*pow);
    set_skill("melee", 24*pow);
    set_skill("dodge", 18*pow);
    set_skill("parry", 21*pow);
    set_skill("paralysis magic", 23*pow);
    add_spell("mind freeze", "$A");
    set_spell_level("mind freeze", spellpow);
    set_property("melee damage", ([ "cutting" : 23 + (7 * pow), "crushing" : 23 + (7 * pow) ]));
return;
}
