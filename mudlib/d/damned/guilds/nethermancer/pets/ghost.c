inherit "/std/pet";

void create() {
    ::create();
    set_name("ghost");
    set("race", "spirit");
    set_combat_chance(120);
    set_id(({ "ghost", "transparent ghost", "transparent", "spirit", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(17);
    set_property("enhance criticals", 0);
    set_property("nethermancer pet", 1);
    set_property("pet name", "ghost");
    set_overall_ac(125);
    set_short("Transparent Ghost");
    set_property("pet short", "Transparent Ghost");
    call_out("nether_form_check", 0);
    set_long("What hovers approximately one foot above the ground before you can only be described as a full fledged ghost. It is completely white and appears extremely hazy, but nonetheless transparent allowing notable vision beyond its body."); 
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

    set_max_hp(700 + 55*pow);
    set_hp(700 + 55*pow);
    set_skill("attack", 20*pow);
    set_skill("melee", 20*pow);
    set_skill("dodge", 14.5*pow);
    set_skill("parry", 18.5*pow);
    set_property("melee damage", ([ "cutting" : 18 + (5 * pow) ]));
return;
}
