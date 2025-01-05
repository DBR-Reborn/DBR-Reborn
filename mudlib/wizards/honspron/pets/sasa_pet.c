inherit "/std/pet_2";

object ob;

void create() {
    ::create();
    set_name("sasa");
    set("race", "thranx");
    set_combat_chance(120);
    set("id", ({ "sasa", "samoan"}));
    set_body_type("thranx");
    set_property("ambidextry", 1);
    set_attack(1);
    set_can_change_aggr(1);
    set_carry(0);
    set_save(1);
    add_limb("first arm", 0, 5000, 0, 4);
    add_limb("second arm", 0, 5000, 0, 4);
    add_limb("third arm", 0, 5000, 0, 4);
    add_limb("fourth arm", 0, 5000, 0, 4);
    add_limb("fifth arm", 0, 5000, 0, 4);
    set_level(120);
    set_property("enhance criticals", -50);
    set_overall_ac(1111);
    set_short("%^BOLD%^%^RED%^Sasa, %^BOLD%^%^WHITE%^the %^BOLD%^%^BLUE%^Dreadnaught%^RESET%^");
    set_long("As you behold Sasa, the only thing you can think about is running away... far enough to no get hit by da slippahs.");
    ob = new("/d/damned/guilds/nethermancer/misc/ed_shield.c");
    ob->move(this_object());
    ob = new("/wizards/honspron/obj/sasa_two_handed.c");
    ob->move(this_object());
    ob = new("/wizards/honspron/obj/sasa_two_handed.c");
    ob->move(this_object());
    ob->set_damage_allowed(05000);
    ob->set_shadow_name("eternal darkness shield");
    ob->start_shadow(this_object(), 2000000000, "");
    ob = new("/std/spells/shadows/ele_pres_shad");
    ob->set_power(5);
    ob->set_damage(({ "infernal", "aether" }));
    ob->set_shadow_name("eternal darkness presence");
    ob->start_shadow(this_object(), 2000000000, "");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    force_me("wield stick in first hand and second hand");
    force_me("wield stick 2 in third hand and fourth hand");
    set_aggr_status(0);
}

void set_owner(string who) {
  object ob;

  ob = find_player(who);
  if(!ob) {
    ::set_owner(who);
    return;
  }
  set_languages(({ "undead-tongue", "common", "elvish", "dwarvish", "serra", "yin", "treefolk",
		 (string)ob->query_primary_lang() }) );
  ::set_owner(who);
  return;
}

void set_up(int pow) {
set_max_hp(50000 + 5000*pow);
    set_hp(50000 + 5000*pow);
    set_max_mp(40000 + 4000*pow);
    set_mp(40000 + 4000*pow);
    set_skill("offhand training", 150*pow);
    set_skill("dual attack", 150*pow);
    set_skill("attack", 150*pow);
    set_skill("melee", 150*pow);
    set_skill("two handed blunt", 150*pow);
    set_skill("dodge", 100*pow);
    set_skill("parry", 120*pow);
    set_skill("warcasting", 111*pow);
    set_skill("assassin's magic", 111*pow);
    set_skill("spiritmancy", 111*pow);
    set_skill("necromancy", 111*pow);
    set_skill("elementalism", 111*pow);
    set_skill("nexus lore", 111*pow);
    add_spell("dark breath", "$A");
    set_spell_level("dark breath", 6);
    add_spell("decay", "$A");
    set_spell_level("decay", 6);
    add_spell("pain", "$A");
    set_spell_level("pain", 6);
    add_spell("greater elemental storm", "$A");
    set_spell_level("greater elemental storm", 6);
    add_spell("greater elemental strike", "$A");
    set_spell_level("greater elemental strike", 6);
    set_property("melee damage", ([ "nexus" : 75 + (20 * pow), "infernal" : 75 + (20 * pow), "time" : 75 + (20 * pow), "aether" : 75 + (20 * pow), "sonic" : 75 + (20 * pow) ]));
	set_property("gang bang", 1);
return;
}