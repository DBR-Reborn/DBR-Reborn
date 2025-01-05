inherit "/std/pet";

void create() {
    object ob;
    ::create();
    set_name("blood knight");
    set("race", "undead");
    set_combat_chance(120);
    set_id(({ "knight", "blood knight", "large knight", "stained knight", "blood stained knight", "large stained knight", "large blood stained knight", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(200);
    set_save(1);
    set_level(48);
    set_property("enhance criticals", -1);
    set_property("pet name", "blood knight");
    set_property("nethermancer pet", 1);
    set_overall_ac(350);
    set_short("Large Blood Stained Knight");
    set_property("pet short", "Large Blood Stained Knight");
    call_out("nether_form_check", 0);
    set_long("Towering high at approximately eight feet tall, this heavily armoured and horribly blood stained warrior at first glance looks to be a very imposing figure. No body parts of any kind appear within any of the armour cracks, indicating this being is a product of highly potent magic. Average sized swords are carried in each hand of the knight, likely daggers in the eyes of something its size but apparently proud weapons of choice judging from the fluency of their movement.");
    set_aggr_status(0);
    ob = new("/d/damned/guilds/nethermancer/misc/stained_sword.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/stained_sword.c");
    ob->move(this_object());
    force_me("wield sword in right hand");
    force_me("wield sword 2 in left hand");
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

    set_max_hp(6000 + 600*pow);
    set_hp(6000 + 600*pow);
    set_max_mp(4800 + 480*pow);
    set_mp(4800 + 480*pow);
    set_skill("attack", 48*pow);
    set_skill("melee", 48*pow);
    set_skill("blade", 48*pow);
    set_skill("dodge", 35*pow);
    set_skill("parry", 41*pow);
    set_skill("offhand training", 55*pow);
    set_skill("dual attack", 55*pow);
    set_skill("owedquar's will", 44*pow);
    add_spell("unholy rage", "$(ME)");
    set_spell_level("unholy rage", spellpow);
    add_spell("owedquar's might", "$A");
    set_spell_level("owedquar's might", spellpow);
    set_property("melee damage", ([ "crushing" : 37 + (11 * pow), "cold" : 37 + (11 * pow)  ]));
return;
}
