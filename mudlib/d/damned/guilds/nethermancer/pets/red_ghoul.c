inherit "/std/pet";

void create() {
    ::create();
    set_name("red ghoul");
    set("race", "undead");
    set_combat_chance(120);
    set_id(({ "ghoul", "red ghoul", "blood red ghoul", "blood ghoul", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(42);
    set_property("enhance criticals", -1);
    set_property("nethermancer pet", 1);
    set_property("pet name", "red ghoul");
    set_overall_ac(300);
    set_short("Blood Red Ghoul");
    set_property("pet short", "Blood Red Ghoul");
    call_out("nether_form_check", 0);
    set_long("This undead with its skin colored as red as the brightest blood stands nearly seven feet tall and looks as muscular as the bulkiest of barbarians. In addition to those muscles it also possesses claws reminicent of knives and teeth that despite being small appear sharp enough to bite directly through steel.");
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

    set_max_hp(3900 + 390*pow);
    set_hp(3900 + 390*pow);
    set_max_mp(3300 + 330*pow);
    set_mp(3300 + 330*pow);
    set_skill("attack", 40*pow);
    set_skill("melee", 40*pow);
    set_skill("dodge", 30*pow);
    set_skill("parry", 34*pow);
    set_property("melee damage", ([ "cutting" : 35 + (10 * pow), "crushing" : 35 + (10 * pow), "impaling" : 35 + (10 * pow)  ]));
return;
}
