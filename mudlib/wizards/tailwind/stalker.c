#include <std.h>

inherit MONSTER;

create() {
  int x;
  object ob;
  ::create();
  set_name("stalker");
  set_id(({ "stalker", "mob" }));
  set_short("The Stalker");
  set("race", "human");
  set_long("He wants to duel you. Attack and die.");
  set_body_type("human");
  set_level(20);
  set_gender("male");
  set_stats("dexterity", 200);
  set_stats("strength", 200);
  set_stats("constitution", 200);
  set_skill("attack", 400);
  set_property("handedness", "left hand");
  set_property("ambidexterity", 1);
  x = random(4);
  switch(x){
    case 0:
      set_skill("blade", 400);
      set_skill("dual attack", 400);
      ob = new("/d/damned/virtual/short-sword_6.weapon");
      ob->move(this_object());
      ob = new("/d/damned/virtual/short-sword_6.weapon");
      ob->move(this_object());
      force_me("wield sword in left hand");
      force_me("wield sword 2 in right hand");
      break;
    case 1:
      set_skill("axe", 400);
      set_skill("dual attack", 400);
      ob = new("/d/damned/virtual/battle-axe_6.weapon");
      ob->move(this_object());
      ob = new("/d/damned/virtual/battle-axe_6.weapon");
      ob->move(this_object());
      force_me("wield axe in left hand");
      force_me("wield axe 2 in right hand");
      break;
    case 2:
      set_skill("blunt", 400);
      set_skill("dual attack", 400);
      ob = new("/d/damned/virtual/hammer_6.weapon");
      ob->move(this_object());
      ob = new("/d/damned/virtual/hammer_6.weapon");
      ob->move(this_object());
      force_me("wield hammer in left hand");
      force_me("wield hammer 2 in right hand");
      break;
    case 3:
      set_skill("flail", 400);
      set_skill("dual attack", 400);
      ob = new("/d/damned/virtual/morning-star_6.weapon");
      ob->move(this_object());
      ob = new("/d/damned/virtual/morning-star_6.weapon");
      ob->move(this_object());
      force_me("wield star in left hand");
      force_me("wield star 2 in right hand");
      break;
    case 4:
      set_skill("knife", 400);
      set_skill("dual attack", 400);
      ob = new("/d/damned/virtual/spiked-gauntlet_6.weapon");
      ob->move(this_object());
      ob = new("/d/damned/virtual/spiked-gauntlet_6.weapon");
      ob->move(this_object());
      force_me("wield knife in left hand");
      force_me("wield knife 2 in right hand");
      break;
  }
  set_skill("parry", 400);
  set_skill("dodge", 400);
  set_skill("resist stun", 400);
  set_skill("perception", 400);
  set_skill("reverse stroke", 400);
  set_skill("melee", 400);
  set_skill("stalk", 400);
set_skill("shadow",400);
set_skill("jugular slash", 400);
  set_skill("limb breaker", 400);
  set_skill("backhand smash", 400);
  set_skill("knee", 400);
  set_property("magic resistance", 90);

  ob = new("/d/damned/virtual/breast-plate.armour");
  ob->move(this_object());
  ob = new("/d/damned/virtual/plate-greaves.armour");
  ob->move(this_object());
  ob = new("/d/damned/virtual/plate-bracer.armour");
  ob->move(this_object());
  ob = new("/d/damned/virtual/plate-bracer.armour");
  ob->move(this_object());
  ob = new("/d/damned/virtual/taces.armour");
  ob->move(this_object());
  ob = new("/d/damned/virtual/metal-boots.armour");
  ob->move(this_object());
  ob = new("/d/damned/virtual/gauntlet.armour");
  ob->move(this_object());
  ob = new("/d/damned/virtual/gauntlet.armour");
  ob->move(this_object());  
  ob = new("/d/damned/virtual/metal-visor.armour");
  ob->move(this_object());
  ob = new("/d/damned/virtual/robe.armour");
  ob->set_material("cloth");
  ob->move(this_object());
  ob = new("/d/damned/virtual/tabard.armour");
  ob->set_material("leather");
  ob->move(this_object());
  force_me("equip");

}

int query_num_rounds() {return 3;}

void catch_tell(string str) {
  string a,b;
  object ob1;
  object ob2;
  if(sscanf(str, "%s attacks %s!", a, b) ==2){
    a = lower_case(a);
    b = lower_case(b);
    ob1 = present(a, environment(this_object()));
    ob2 = present(b, environment(this_object()));
    if(!ob1 || !ob2) return;
    if(ob1->query_npc() == 0) {
      force_me("kill "+a);
    }
    if(ob2->query_npc() == 0) {
      force_me("kill "+b);
    }
  }
  
    if(sscanf(str, "%s enters.",a) ==1){
    a = lower_case(a);
    ob1 = present(a, environment(this_object()));
    if(ob1->query_npc() == 0) {
      force_me("use shadow at "+a);
    }
  }
  
  return;
}

void heart_beat(){
  string name;
  ::heart_beat();
  if(this_object()->query_attackers() != ({ })) {
    name =this_object()->query_attackers()[0]->query_name();
    if((time() - (int)this_object()->query_last_use("limb breaker")) > 6){
      force_me("use limb breaker at "+name);
    }
    if((time() - (int)this_object()->query_last_use("backhand smash")) > 2){
      force_me("use backhand smash at "+name);
    }
    if((time() - (int)this_object()->query_last_use("knee")) > 4){
      force_me("use knee at "+name);
    }

if((time()-(int)this_object()->query_last_use("jugular slash")) > 10){
force_me("use jugular slash at "+name);
}



  return;
  }
}

int query_invis(){return 1;}
