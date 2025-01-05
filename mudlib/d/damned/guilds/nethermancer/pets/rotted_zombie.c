inherit "/std/pet";

void create() {
    ::create();
    set_name("rotted zombie");
    set("race", "zombie");
    set_combat_chance(120);
    set_id(({ "zombie", "rotted zombie", "filthy rotted zombie", "filthy zombie", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(6);
    set_property("enhance criticals", 0);
    set_property("nethermancer pet", 1);
    set_property("pet name", "rotted zombie");
    set_overall_ac(0);
    set_short("Filthy Rotted Zombie");
    set_property("pet short", "Filthy Rotted Zombie");
    call_out("nether_form_check", 0);
    set_long("This creature is a zombie covered from head to toe in filth from severely noticeable rot. Disturbing moans emanate from its mouth at an almost endless rate as it stumbles forward during its walking motions.");
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
    set_max_hp(200 + 30*pow);
    set_hp(200 + 30*pow);
    set_skill("attack", 11*pow);
    set_skill("melee", 11*pow);
    set_skill("dodge", 8*pow);
    set_skill("parry", 9*pow);
    set_property("melee damage", ([ "crushing" : 7 + (2 * pow) ]));
return;
}
