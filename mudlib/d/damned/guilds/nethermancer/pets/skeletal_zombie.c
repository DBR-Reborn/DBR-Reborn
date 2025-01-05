inherit "/std/pet";

void create() {
    ::create();
    set_name("skeletal zombie");
    set("race", "zombie");
    set_combat_chance(120);
    set_id(({ "skeletal zombie", "zombie", "skeleton zombie", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(10);
    set_property("enhance criticals", 0);
    set_property("nethermancer pet", 1);
    set_property("pet name", "skeletal zombie");
    set_overall_ac(0);
    set_short("Skeletal Zombie");
    set_property("pet short", "Skeletal Zombie");
    call_out("nether_form_check", 0);
    set_long("This is a rather curious combination of both a skeleton and a zombie into a single undead creature. Numerous white bones protrude from a disgusting and odor plagued body, while both moaning and bone creaking sounds generate from the monster as it moves.");
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

    set_max_hp(300 + 40*pow);
    set_hp(300 + 40*pow);
    set_skill("attack", 14*pow);
    set_skill("melee", 14*pow);
    set_skill("dodge", 10*pow);
    set_skill("parry", 12*pow);
    set_property("melee damage", ([ "crushing" : 10 + (2 * pow) ]));
return;
}
