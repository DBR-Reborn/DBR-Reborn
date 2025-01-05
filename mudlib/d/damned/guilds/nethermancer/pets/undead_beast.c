inherit "/std/pet";

void create() {
    ::create();
    set_name("undead beast");
    set("race", "beast");
    set_combat_chance(120);
    set_id(({ "beast", "slavering beast", "slavering undead beast", "undead beast", "undead" }));
    set_body_type("quadruped");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(18);
    set_property("enhance criticals", 0);
    set_property("nethermancer pet", 1);
    set_property("pet name", "undead beast");
    set_overall_ac(150);
    set_short("Slavering Undead Beast");
    set_property("pet short", "Slavering Undead Beast");
    call_out("nether_form_check", 0);
    set_long("A sick mixture of rotting flesh and a bloodthirsty hound, this ugly but vicious looking undead creature seems to be somewhat of a decent adversary. Its claws extend over two inches on all four of its legs but oddly enough it has no teeth. However in place of them the creature has a pulsing red glow in its mouth that looks as if it generates magic.");
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

    set_max_hp(800 + 80*pow);
    set_hp(800 + 80*pow);
    set_max_mp(600 + 60*pow);
    set_mp(600 + 60*pow);
    set_skill("attack", 21*pow);
    set_skill("melee", 21*pow);
    set_skill("dodge", 15*pow);
    set_skill("parry", 18*pow);
    set_skill("black magic", 17*pow);
    set_skill("owedquar's will", 17*pow);
    add_spell("cold blast", "$A");
    set_spell_level("cold blast", spellpow);
    add_spell("dark assault", "$A");
    set_spell_level("dark assault", spellpow);
    set_property("melee damage", ([ "crushing" : 16 + (5 * pow) ]));
return;
}
