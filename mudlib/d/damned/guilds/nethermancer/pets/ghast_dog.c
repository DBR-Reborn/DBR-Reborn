inherit "/std/pet";

void create() {
    ::create();
    set_name("ghast dog");
    set("race", "spirit");
    set_combat_chance(120);
    set_id(({ "dog", "ghast dog", "wailing dog", "wailing ghast dog", "undead" }));
    set_body_type("quadruped");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    set_level(22);
    set_property("enhance criticals", 0);
    set_property("nethermancer pet", 1);
    set_property("pet name", "ghast dog");
    set_overall_ac(150);
    set_short("Wailing Ghast Dog");
    set_property("pet short", "Wailing Ghast Dog");
    call_out("nether_form_check", 0);
    set_long("Standing with four paws on the ground yet immaterial in nature, this hound can only be described as unnatural. Unlike the common spirit however, this creature is made of very thick mist and cannot be seen through at all regardless of the administered stare. Wailing noises come from its mouth as it seems to freely move about in the same manner as a completely material being.");
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

    set_max_hp(900 + 90*pow);
    set_hp(900 + 90*pow);
    set_skill("attack", 24*pow);
    set_skill("melee", 24*pow);
    set_skill("dodge", 18*pow);
    set_skill("parry", 21*pow);
    set_property("melee damage", ([ "cutting" : 20 + (6 * pow), "crushing" : 20 + (6 * pow) ]));
return;
}
