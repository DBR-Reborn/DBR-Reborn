inherit "/std/pet";

void create() {
    ::create();
    set_name("blood hound");
    set("race", "dog");
    set_combat_chance(120);
    set_id(({ "dog", "hound", "drooling hound", "drooling blood hound", "blood hound", "undead" }));
    set_body_type("quadruped");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(10);
    set_property("enhance criticals", 0);
    set_property("nethermancer pet", 1);
    set_property("pet name", "blood hound");
    set_overall_ac(50);
    set_short("Drooling Blood Hound");
    set_property("pet short", "Drooling Blood Hound");
    call_out("nether_form_check", 0);
    set_long("Covered entirely with light red fur and possessing darker red eyes, this three foot tall hound appears in no way docile. Blood drips endlessly from its small fangs as it stands relatively still glancing with a cold stare."); 
    set_aggr_status(0);
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

    set_max_hp(325 + 42*pow);
    set_hp(325 + 42*pow);
    set_skill("attack", 14.5*pow);
    set_skill("melee", 14.5*pow);
    set_skill("dodge", 11*pow);
    set_skill("parry", 13*pow);
    set_property("melee damage", ([ "crushing" : 10 + (2 * pow) ]));
return;
}
