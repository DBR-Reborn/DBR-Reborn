inherit "/std/pet";

void create() {
    object ob;
    ::create();
    set_name("deathmage");
    set("race", "undead");
    set_combat_chance(120);
    set_id(({ "mage", "deathmage", "death mage", "mage of death", "robed mage", "robed deathmage", "robed death mage", "robed mage of death", "undead" }));
    set_body_type("human");
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(500);
    set_save(1);
    set_level(65);
    set_property("enhance criticals", -2);
    set_property("nethermancer pet", 1);
    set_property("pet name", "deathmage");
    set_overall_ac(500);
    set_short("Robed Mage of Death");
    set_property("pet short", "Robed Mage of Death");
    call_out("nether_form_check", 0);
    set_long("Before your eyes stands a relatively small being at only five feet tall, but one that appears to be extraordinarily menacing. Nearly all of its body is covered in a neat purple and black robe with its head covered just as well by a hood of the same colors. Virtually nothing can be seen through where the face is supposed to be except two extremely dark red eyes that never seem to blink for any reason, not even when it moves its head or its body. As the mage moves closer and closer to you you can hear extremely scary sounds of breathing.");
    set_aggr_status(0);
    ob = new("/d/damned/guilds/nethermancer/misc/mage_robe.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/mage_hood.c");
    ob->move(this_object());
    set_skill("concentrate", 200);
    force_me("use concentrate");
    force_me("equip");
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

    set_max_hp(11500 + 1150*pow);
    set_hp(11500 + 1150*pow);
    set_max_mp(9999 + 999*pow);
    set_mp(9999 + 999*pow);
    set_skill("attack", 69*pow);
    set_skill("melee", 69*pow);
    set_skill("dodge", 51*pow);
    set_skill("parry", 62*pow);
    set_skill("owedquar's will", 63*pow);
    set_skill("warcasting", 63*pow);
    set_skill("paralysis magic", 63*pow);
    add_spell("mutate", "$A");
    set_spell_level("mutate", spellpow);
    add_spell("abyss blast", "$A");
    set_spell_level("abyss blast", spellpow);
    add_spell("stun blast", "$A");
    set_spell_level("stun blast", spellpow);
    set_property("melee damage", ([ "cold" : 48 + (13 * pow), "unholy" : 48 + (13 * pow), "disruption" : 48 + (13 * pow), "reflection" : 48 + (13 *pow)  ]));
return;
}
