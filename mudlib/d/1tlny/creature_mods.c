    set_body_type("human");
    set("race", "human");
    set_gender("male");
    set_alignment(-100);

    set("aggressive", 1);
    set("chase",1);

	set_melee_damage( (["crushing" : 40 ]) );
    set_property("enhance criticals",-5);
    set_property("magic resistance", 120);
   set_property("physical resistance", ([ "default" : 500]));
   set_property("magical resistance", ([ "default" : 500]));

    set_skill("resist stun", 175);
    set_overall_ac(100);
    set("see invis", 1);
    
    set_stats("strength", 120 + random(30));
    set_stats("dexterity", 120 + random(30));
    set_stats("constitution", 120 + random(20));
    set_stats("wisdom", 50 + random(20));
    set_stats("intelligence", 50 + random(20));
    set_stats("charisma", 80);
   
    set_max_hp(10000);
    set_hp(10000);
    set_property("base hp regen", 22 + 5*6);

    set_max_mp(7000);
    set_mp(7000);
    set_property("base mp regen", 25 + 4*6);

    set_skill("melee", 110);
    set_skill("attack", 110);
    set_skill("defense", 110);
    set_skill("dodge", 110);
    set_skill("reverse stroke", 110);
    set_skill("martial arts",110);
    set_skill("perception", 110);
    set_skill("concentrate", 110);
    set("concentrate", 1);
    force_me("use concentrate");

    set_skill("shield bash", 110);
    set_skill("head butt", 110);
    set_skill("kick", 110);
    set_skill("reverse punch", 110);
    set_skill("sweep", 110);



    set_max_mp(150 + 70*pow);
    set_mp(150 + 70*pow);
    set_property("base mp regen", 25 + 4 * pow);

	set_casting_chance(0);
    set_combat_chance(80);
    add_spell("blur","$ME");
    set_spell_level("blur",4);
    set_skill("illusionism",90);
/*
   set_skill("conjuration", 140);
   set_skill("prayer", 100);
    set_spell_level("explosive fireball", 6);
   set_spell_level("internal flame",6);
    add_spell("explosive fireball","$A");
   add_spell("internal flame", "$A");

   set_skill("illusionism", 175);
   set_skill("conjuration", 175);
   set_skill("necromancy", 175);
   set_skill("concentrate", 175);
   add_spell("curse", "$A");
   set_spell_level("curse", 6);
   add_spell("lightning bolt", "$A");
   set_spell_level("lightning bolt", 6);
*/

//example of a creature creation using zlevel as a int to switch up multiple properties
void create() {
int zlevel;
   ::create();
    zlevel = (5+random(5));
   set_level(zlevel);
   set_short("["+zlevel+"]name");
   set_overall_ac(zlevel+5);
  
    set_long("This elemental dragon glows with the energy of vacid");
    set_name("elemental");
    set_id(({ "elemental", "elemental dragon", "vacid elemental", "dragon" }));
    set("race", "elemental");
    set_body_type("winged-humanoid");

	set_melee_damage( (["cold" : zlevel, "stress" : zlevel, "impact" : zlevel ]) );	

//example how to set names with levels based on zlevel	
int zlevel;
   ::create();	
zlevel=(1+random(5));
if (zlevel == 1) set_short("[1]name");
else 
if (zlevel == 2) set_short("[2]name");
else
if (zlevel == 3) set_short("[3]name");
else
if (zlevel == 4) set_short("[4]name");
else
if (zlevel == 5) set_short("[5]name");
else
if (zlevel == 6) set_short("[6]name");
else 
if (zlevel == 7) set_short("[7]name");
else
if (zlevel == 8) set_short("[8]name");
else
if (zlevel == 9) set_short("[9]name");
else
if (zlevel == 10) set_short("[10]name");
else set_short("[0]name");	
	set_level(zlevel);

//Rnadom amount of silve ron ground or creature
amt = random(10)*20+40;
    money = new("std/obj/coins");
money->set_money("silver",amt);
    money->move(this_object());

//Add money to created
    set_money("gold", 1+random(18));

//Switch porperties of random damage types example 
set_up(int pow) {
  string tmp;
  power = pow;
  set_max_hp(450 + 70*pow);
  set_hp(450 + 70* pow);
  set_skill("melee", 75 + pow * 6);
  set_skill("parry", 55 + pow * 5);
  set_skill("dodge", 55 + pow * 5);

  set_max_mp(600 + 80* pow);
  switch(random(6)) {
    case 0:
      tmp = "electricity";
      break;
    case 1:
      tmp = "disruption";
      break;
    case 2:
      tmp = "plasma";
      break;
    case 3:
      tmp = "vacuum";
      break;
    case 4:
      tmp = "infernal";
      break;
    case 5:
      tmp = "unholy";
      break;
  }
  set_melee_damage(([ tmp:7+3*pow ]));



//Negate damage to 0 example
void do_damage(string str, int arg)
{
    if (random(100) < 25) {
	message("combat",
	  "Your blow rings harmlessly off the Carnifex's thick chitin armour!\n",
	  all_inventory(environment()));
	return;
    }
    ::do_damage(str,arg);
}

//Blocking code example to block multiple exits
void init()
{
    ::init();
    add_action("no","up");
    add_action("no","down");
}

int no()
{
    //if(archp(this_player())) return 0;
    if(this_player()->query_ghost()) return 0
else
    message("blocking",
      "The Carnifex hisses and leaps in front of you, blocking your path.\n",
      this_player());
    message("blocking",
      "The Carnifex blocks "+capitalize(this_player()->query_name())+"'s path.\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}



//item examples 
void create() {
   object ob;
    ob = new("/d/damned/virtual/long-sword_6.weapon");
    ob -> set("short", "%^BOLD%^shining%^RESET%^longsword");
    ob -> set("long",
"This weapon is extremely well made. The long, sharp blade is finely "
"balanced. Soft leather is wrapped around the pommel, making the sword "
"a pleasure to wield.");
    ob -> set_wc(50,"cutting");
    ob -> set_wc(20,"impaling");
    ob -> set_hit_bonus(40);
    ob -> set_parry_bonus(40);
    ob -> set_material("metal/iysaughton");
    ob -> set_auto_critical("disruption D");
    ob -> set_auto_critical("stun E");
    ob -> set_property("no decay",1);
    ob -> set_property("enchantment",40);
    ob -> set_enh_critical(7);
    ob -> set_("skill level", 160);
	set_weight( 95 );
	set_value( 5 );
      ob -> move(this_object());
ob = new("/d/damned/virtual/great-helm.armour");
    ob -> set_material("metal/laen");
    ob -> set_ac(125);
    ob ->set_ac(99, "aether");
    ob ->set_ac(99, "depression");
           ob ->set_ac(99, "acid");
           ob ->set_ac(99, "vacuum");
          ob -> set_ac(99, "fire");
           ob ->set_ac(99, "cold");
           ob ->set_ac(99, "impact");
           ob ->set_ac(99, "stress");
           ob ->set_ac(99, "strike");
           ob ->set_ac(99, "electricity");
          ob -> set_ac(99, "time");
          ob -> set_ac(99, "crushing");
          ob -> set_ac(99, "disruption");
          ob -> set_ac(99, "holy");
          ob -> set_ac(99, "plasma");
          ob -> set_ac(99, "infernal");
    ob -> set_enh_critical(-4);
     ob -> move(this_object());
force_me("equip");
  command("equip");

//Example if someone enters the room cast spell at person that enters
// you can also do messages or create items as well
void catch_tell(string str) {
   string a;
   object tp;


 if(sscanf(str, "%s enters.", a) == 1) {
      a = lower_case(a);
      tp = present(a, environment(this_object()));
      if(!tp) return;
      command("cast *6 lightning bolt at "+a);

    }
}


// Makes the creature use shield bash every round in combat
    set_skill("shield bash", 100);
// (though it will only happen every other round, cause
// thats how the skill limits it...) Thanks elfguardian-
// maker for the nice function :)
varargs void heart_beat(int flag) {
  if (query_current_attacker())
    force_me("use shield bash at "+(string)(query_current_attacker()->query_name()));
  
  ::heart_beat(flag);
  return;
}

//updated code from above yet to test
varargs void heart_beat(int flag) {
  if(query_current_attacker() && !random(4)) {
    force_me("use shield bash at
"+(string)(query_current_attacker()->query_name()));
  }
  ::heart_beat(flag);
  return;
}

//Aggressive code to only kill payers
set("aggressive", (: call_other, this_object(), "no_other_monsters" :));

int no_other_monsters(object who) {
  if(who->is_player()) {
    if(who->query_invis()) { return 0; }
    if(who->query_hiding() >= 70)  { return 0; }
    if(who->query_stealth() >= 80) { return 0; }
   this_object()->kill_ob(who,0);
    return 1;
  }
  else return 0;
}

//More kill creature or player code based on race
init() {
  if( this_player()->query_race() == "devil" ) {
    force_me("kill "+this_player()->query_name());
  }
}


//cool blocking code and other stuff:
    set_skill("elementalism", 110);
    set_skill("electricity lore", 110);
    force_me("use electricity lore");
    set_spell_level("greater elemental bolt", 5);
    add_spell("greater elemental bolt", "$A");
    set("see invis", 1);
    set_combat_chance(200);

string query_element() { return "electricity"; }


void catch_tell(string str) {
  string who;
  object plyr, *inv;

  str = eliminate_colour(str);
  if(!this_object()->query_casting() && sscanf(str, "%s begins casting a
spell.", who)) {
    if(who == "Someone") {
      inv = all_inventory(environment());
      inv = filter_array(inv, (: call_other :), "is_player");
      inv = filter_array(inv, (: call_other :), "query_invis");
      inv = filter_array(inv, (: call_other :), "query_casting");
      if(!sizeof(inv)) {
        return;
      }
      plyr = inv[0];
    }
    else
      plyr = present(lower_case(who), environment());
    if(!plyr) {
      return;
    }
    if(plyr->is_player() && (int)plyr->query_level() > 15) {
      force_me("cast *5 greater elemental bolt at
"+(string)plyr->query_name());
    }
    return;
  }
  if(str == "YOU CAN MOVE AGAIN!!!" && !query_casting() &&
(inv=query_attackers())) {
    if(sizeof(inv) >= 3)
      force_me("cast *6 elemental storm");
    else if(sizeof(inv))
      force_me("cast *6 greater elemental bolt at "+
        (string)inv[0]->query_name());
  }
  return;
}

void init() {
  ::init();
  add_action("block_exit", "north");
  if(this_player()->is_player() && (int)this_player()->query_level() > 15
&&
    this_player()->query_casting() && !query_casting()) {
    force_me("speak common");
    force_me("say How dare you try to come into my domain, spell already casting?!  "
       "Die, "+capitalize((string)this_player()->query_name())+"!");
    force_me("cast *5 greater elemental bolt at
"+(string)this_player()->query_name());
    kill_ob(this_player(), 1);
  }
  return;
}

int block_exit(string null) {
  string name = capitalize((string)this_player()->query_name());
  
  if(!this_player()->is_player()) return 0;
  if(wizardp(this_player())) return 0;
  if((int)this_player()->query_level() <= 15) return 0;
  force_me("speak common");
  if(!this_player()->query_invis()) {
    force_me("say I must not allow such powerful players as you, "+name+",
into "
        "the camp, for fear you would destroy it!");
  } else {
    write("To your great surprise, the elf guardian lays a hand on you invisible shoulder!");
    force_me("say I don't like such tom-foolery as invisibility.  You may not pass.");
  }
  return 1;
}


