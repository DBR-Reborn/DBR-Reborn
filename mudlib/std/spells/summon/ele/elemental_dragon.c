inherit "/std/pet";

string element;
string *elems;
int power;
int zlevel, lvl, llvl, zskill, zskillx, zskillac, zspell;

void create() {
    ::create();

    zlevel = (20+random(5));
//Controls Loot level and other fucntions do to raise to high multpies loot
    lvl = 1;
//Controls critical hit reduction and other such
    llvl = 2;
    zskill = 8;
    zskillx = 6;
    zskillac = 5;
    zspell = 7;

    set_level(zlevel);

   set_overall_ac((int)this_object()->query_level()*4);
   set_property("magic resistance", this_object()->query_level()*4);
   set_skill("resist stun", this_object()->query_level()*4);
   set_property("enhance criticals",-llvl);
   //set_property("physical resistance", ([ "default" : this_object()->query_level()]));
   //set_property("magical resistance", ([ "default" : 500]));
   //set("see invis", 1);

    set_save(1);
    //set_change_ownership(1);
    set_attack(1);
    set_can_change_aggr(1);

    set_carry(0);              //also linked to equip
    set_bodyguard(1);
    set_bodyblocking(1);
    set_learning_spells(1);     //can learn spells??
    set_intelligent(1);         //can tell it to cast spells
    set_short("["+this_object()->query_level()+"] "+this_object()->query_element()+" Elemental Dragon");
    set_id(({ "elemental", "dragon", "elemental dragon" }));
    set("race", "elemental");
    set_body_type("winged-humanoid");
    set_name("elemental");
    //set_short("Dragon");

    set_long("This majestic elemental dragon shimmers with a radiant glow, reflecting the unique energy of the caster’s chosen element. Its wings stir the atmosphere, unleashing storms in its wake, while its fierce roar echoes like thunder. As a guardian of elemental mastery, it unleashes devastating power upon its foes, ready to protect its summoner in battle.");

    return;
}

//ADD
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
//END

int query_flying() { return 1; }

void restore_stuff() {
    ::restore_stuff();
    if(elems && power && element)
	this_object()->set_up(power, elems, element);
    return;
}
/*
void restore_locker(string file) {
  ::restore_locker(file);
  if(elems && power && element)
  this_object()->set_up(power, elems, element);
  return;
}
*/
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

/*
  //set_level(19+pow/2);
  //set_exp(400000);
  //set_max_hp(1400 + 120*pow);
  //set_hp(1400 + 120*pow);
  //set_property("base hp regen", 22 + 5*pow);
  set_skill("melee", 80 + pow * 5);
  set_skill("parry", 75 + pow * 5);
  set_skill("dodge", 70 + pow * 5);
*/

  set_max_mp(4000);
  set_mp(4000);
  set_property("base mp regen", 25 + 4 * pow);

//ADD
  set_skill("body block", (this_object()->query_level()) * 4+(pow*pow*4));
  set_skill("elementalism", (this_object()->query_level()) * 4+(pow*pow*4));
  set_skill(element+" lore", (this_object()->query_level()) * 4+(pow*pow*4));

if (pow >= 6){ pow=6; }
 set_spell_level("lesser elemental bolt",pow);
add_spell("lesser elemental bolt", "$A");
 //set_spell_level("body of elements",6);
//add_spell("body of elements", "$(ME)");
 set_spell_level("elemental shield",pow);
add_spell("elemental shield", "$(ME)");
 
  set_spell_level("elemental bolt",pow);
add_spell("elemental bolt", "$A");

  set_spell_level("lesser elemental strike",pow);
add_spell("lesser elemental strike", "$A");
 
  set_spell_level("elemental curse",pow);
add_spell("elemental curse", "$A");
 
  set_spell_level("lesser elemental storm",pow);
add_spell("lesser elemental storm", "", pow);
 
  set_spell_level("elemental strike",pow);
add_spell("elemental strike", "$A");
 set_spell_level("greater elemental bolt",pow);
add_spell("greater elemental bolt", "$A");
 set_spell_level("elemental barrier",pow);
add_spell("elemental barrier", "$(ME)");
 
  set_spell_level("elemental presence",pow);
add_spell("elemental presence", "$(ME)");
 
  set_spell_level("elemental storm",pow);
add_spell("elemental storm", "", pow);
 
  set_spell_level("elemental bane",pow);
add_spell("elemental bane", "$A");
 
  set_spell_level("elemental aegis",pow);
add_spell("elemental aegis", "$(ME)");
 set_spell_level("elemental transformation",pow);
add_spell("elemental transformation", "$(ME)");
 
  set_spell_level("greater elemental storm",pow);
add_spell("greater elemental storm", "", pow);
 
  set_spell_level("greater elemental strike",pow);
add_spell("greater elemental strike", "$A");

  set_combat_chance(100);

//END
/*
  set_spell_level("lesser elemental bolt", 6);
  add_spell("lesser elemental bolt", "$A");
  set_spell_level("elemental bolt", 6);
  add_spell("elemental bolt", "$A");
  set_spell_level("lesser elemental strike", 6);
  add_spell("lesser elemental strike", "$A");
  set_spell_level("greater elemental storm", 1+pow/5);
  add_spell("greater elemental storm", "", 1);
  add_spell("greater elemental bolt", 6);
  add_spell("greater elemental bolt", "$A");
  set_spell_level("elemental strike", 3+pow/2);
  set_spell_level("elemental storm", 6);
  add_spell("elemental storm", "", 1);
  set_spell_level("elemental strike", 6);
  add_spell("elemental strike", "$A");
*/
  return;
}
