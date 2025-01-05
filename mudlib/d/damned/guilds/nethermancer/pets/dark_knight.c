inherit "/std/pet";

void create() {
    object ob;
    ::create();
    set_name("dark knight");
    set("race", "undead");
    set_combat_chance(120);
    set_id(({ "knight", "dark knight", "dark knight of the abyss", "knight of the abyss", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(200);
    set_save(1);
    set_level(45);
    set_property("enhance criticals", -1);
    set_property("pet name", "dark knight");
    set_property("nethermancer pet", 1);
    set_overall_ac(300);
    set_short("Dark Knight of the Abyss");
    set_property("pet short", "Dark Knight of the Abyss");
    call_out("nether_form_check", 0);
    set_long("This is a powerful looking knight that appears to be a living suit of darkened steel armour, with no visible body parts through its extremely small cracks. A large sword and shield are present in its hands, both of which could pass as equipment of choice for even a seasoned warrior.");
    set_aggr_status(0);
    ob = new("/d/damned/guilds/nethermancer/misc/black_sword.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/black_shield.c");
    ob->move(this_object());
    force_me("wield sword in right hand");
    force_me("wear shield on left hand");
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

    set_max_hp(5000 + 500*pow);
    set_hp(5000 + 500*pow);
    set_max_mp(4100 + 410*pow);
    set_mp(4100 + 410*pow);
    set_skill("attack", 44*pow);
    set_skill("melee", 44*pow);
    set_skill("blade", 44*pow);
    set_skill("dodge", 33*pow);
    set_skill("block", 35*pow);
    set_skill("parry", 38*pow);
    set_skill("offhand training", 50*pow);
    set_skill("necromancy", 40*pow);
    set_skill("owedquar's will", 40*pow);
    add_spell("lifesteal", "$A");
    set_spell_level("lifesteal", spellpow);
    add_spell("owedquar's might", "$A");
    set_spell_level("owedquar's might", spellpow);
    set_property("melee damage", ([ "crushing" : 35 + (10 * pow), "cold" : 35 + (10 * pow)  ]));
return;
}
