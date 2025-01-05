inherit "/std/pet";

void create() {
    ::create();
    set_name("shadow beast");
    set("race", "beast");
    set_combat_chance(120);
    set_id(({ "beast", "shadow beast", "flesh beast", "shadow and flesh beast", "beast of shadow", "beast of shadow and flesh", "undead" }));
    set_body_type("quadruped");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(500);
    set_save(1);
    set_level(62);
    set_property("enhance criticals", -2);
    set_property("nethermancer pet", 1);
    set_property("pet name", "shadow beast");
    set_overall_ac(450);
    set_short("Beast of Shadow and Flesh");
    set_property("pet short", "Beast of Shadow and Flesh");
    call_out("nether_form_check", 0);
    set_long("A somewhat annoying hum graces the room as you gaze upon this highly irregular and simultaneously fearsome six foot tall creature, the hum entirely generated from the portions of glowing shadows and souls comprising random parts of its body. The rest of the body is made up of terribly tough and torn black flesh alongside eerily glowing claws on all of its paw like limbs and eyes as red as the most pure of blood.");
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

    set_max_hp(10000 + 1000*pow);
    set_hp(10000 + 1000*pow);
    set_max_mp(8600 + 860*pow);
    set_mp(8600 + 860*pow);
    set_skill("attack", 64*pow);
    set_skill("melee", 64*pow);
    set_skill("dodge", 47*pow);
    set_skill("parry", 57*pow);
    set_skill("curse lore", 59*pow);
    set_skill("warcasting", 59*pow);
    add_spell("greater curse", "$A");
    set_spell_level("greater curse", spellpow);
    add_spell("electrical storm", "$A");
    set_spell_level("electrical storm", spellpow);
    set_property("melee damage", ([ "cold" : 46 + (13 * pow), "unholy" : 46 + (13 * pow), "disruption" : 46 + (13 * pow)  ]));
return;
}
