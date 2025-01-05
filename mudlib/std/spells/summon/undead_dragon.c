inherit "/std/pet";

void create() {
  ::create();
  set_name("undead dragon");
  set_combat_chance(120);
  set_id(({ "undead dragon", "dragon", "undead"}));
  set("race", "undead dragon");
  set_body_type("humanoid");
  set_attack(1);
  set_can_change_aggr(1);
  //set_change_ownership(0);
  set_carry(0);
  set_save(1);
  set_property("magic resistance", 120);
  set_skill("resist stun", 375);
  set("see invis", 1);
  set_property("enhance criticals", -7);
  set_level(100);
  set_overall_ac(500);
  set_short("Dragon of the undead realm");
  set_long("This a a dragon that comes from the dead. It's scales are spattered with blood.");
  set_property("physical resistance", ([ "default" : 500]));
  set_property("magical resistance", ([ "default" : 500]));
  set_aggr_status(0);
 if(!present("dragon skin", this_object())) {
    new("/d/damned/guilds/necromancer/obj/dragon_skin")->move(this_object());
    }
  force_me("wear skin");
  return;
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
  set_property("power", pow);
  set_max_hp(pow * 5000 );
  set_hp(pow * 5000 );
  set_max_mp(5000 * pow);
  set_mp(5000 * pow);
  set_skill("melee", 85*pow);
  set_skill("dodge", 50*pow);
  set_skill("parry", 50*pow);
  set_skill("attack", 85*pow);
  set_stats("strength", 120 + (10 * pow));
  set_stats("intelligence", 120);
  set_skill("elementalism", 110+(15*pow));
  set_skill("black magic", 110+(15*pow));
  set_skill("paralysis magic", 110+(15*pow));
  set_spell_level("breathe fire", 6);
  add_spell("breathe fire", "$A");
  set_spell_level("syphon soul", 6);
  add_spell("syphon soul", "$A");
  add_spell("greater elemental strike", "$A");
  set_spell_level("greater elemental strike", 6);
  set_skill("concentrate", 500);
    force_me("use concentrate");
  return;
}
int ele = this_object()->query_element();
string query_element() { return ""+ele+""; }

void set_dur(int dur) {
  call_out("remove_servant", dur);
  return;
}

void die(object ob) {
  message("info", "%^GREEN%^%^BOLD%^A dragon returns to the nether world.",
	  environment());
::die();
   }


