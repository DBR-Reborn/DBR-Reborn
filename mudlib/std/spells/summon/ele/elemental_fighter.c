inherit "/std/pet";

string element;
string *elems;
int power;

void create() {
    ::create();
    set_name("elemental fighter");
    set_id(({ "fighter", "elemental fighter", "smug fighter", "smug elemental fighter", "elemental" }));
    set("race", "elemental");
    set_body_type("human");
    set_attack(1);
    set_carry(0);
    set_save(0);
set_property("no save", 1);
    set_property("no save", 1); 

    set_bodyguard(1);
    set_bodyblocking(1);

    //set_level(40);
    set_short("A smug elemental fighter");
    set_long("This is a well built humanoid shaped elemental, completely obedient to its master summoner. Its entire body shimmers faintly with power and moves very quickly, as it is well versed in hand to hand combat.");
    set_can_change_aggr(0);

   set_overall_ac((int)this_object()->query_level()*4);
   set_property("magic resistance", this_object()->query_level()*4);
   set_skill("resist stun", this_object()->query_level()*4);
   set_property("enhance criticals",-1);
   set_property("physical resistance", ([ "default" : this_object()->query_level()]));
   set_property("magical resistance", ([ "default" : this_object()->query_level()]));
   //set("see invis", 1);

    return;
}

void restore_stuff() {
    ::restore_stuff();
    if(elems && power && element)
	this_object()->set_up(power, elems, element);
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

string query_element() { return element; }

int id(string str) {
  if(::id(str)) return 1;
  if(!element) return 0;
  return ::id(replace_string(str, element + " ", ""));
}

set_up(int pow, string *ele, string name) {
  int i;
  mapping tmp;
  
  element = name;
  elems = ele;
  power = pow;
  tmp = ([]);
  i = sizeof(ele);
  while(i--) tmp += ([ ele[i] : 38 + 5*pow+(this_object()->query_level()*2) ]);
  set_melee_damage(tmp);

  set_skill("body block", (this_object()->query_level()) * 4+(pow*pow*4));
  set_skill("elementalism", (this_object()->query_level()) * 4+(pow*pow*4));
  set_skill(element+" lore", (this_object()->query_level()) * 4+(pow*pow*4));

  set_skill("martial arts", (this_object()->query_level()) * 2);
  set_skill("melee", (this_object()->query_level()) * 6+(pow*pow*4));

  set_skill("parry", (this_object()->query_level()) * 4+(pow*pow*4));
  set_skill("dodge", (this_object()->query_level()) * 4+(pow*pow*4));
  set_skill("block", (this_object()->query_level()) * 4+(pow*pow*4));
 
if (pow >= 6){ pow=6; }
    set_spell_level("elemental transformation",pow);
    add_spell("elemental transformation", "$(ME)", pow);
    set_combat_chance(50);
}
/*
void set_up(int pow) {
    set_max_hp(pow * 300);
    set_hp(pow * 300);
    set_stats("strength", 50 + 25*pow);
    set_skill("attack", 50 + 15*pow);
    set_skill("melee", 50 + 15*pow);
    return;
}
*/


void set_dur(int dur) {
    call_out("remove_pet", dur);
    return;
}

void remove_pet() {
    this_object()->force_me("drop all");
    message("info", "%^BLUE%^The Elemental Fighter slowly begins to fade away, and before long is completely erased from existence.%^RESET%^", environment(this_object()));
    remove();
    return;
}
