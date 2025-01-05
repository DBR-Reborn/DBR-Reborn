#include <std.h>

inherit MONSTER;

create() {
  int x;
  object ob;
  ::create();
  set_name("guard");
  set_id(({ "royal-infantry guard", "guard", "infantry", "mob" }));
  set_short("Royal-Infantry Guard");
  set("race", "human");
  set_long("Disciplined, tall, and strong-looking, this member of the Royal-Infantry has been tasked to guard the camp, and will do so at any cost, including to their life.");
  set_body_type("human");
  set_level(20);
  x = random(2);
  if(x==0) set_gender("male");
  else set_gender("female");
  set_stats("dexterity", 110);
  set_stats("strength", 100);
  set_stats("constitution", 100);
  set_skill("attack", 205);
  set_property("handedness", "right hand");
  set_property("ambidexterity", 1);
  x = random(4);
  switch(x){
    case 0:
      set_skill("blade", 220);
      set_skill("block", 190);
      ob = new("/d/damned/virtual/short-sword_6.weapon");
      ob->move(this_object());
      ob = new("/d/damned/virtual/large-shield.armour");
      ob->move(this_object());
      force_me("wield sword in left hand");
      force_me("wear shield on right hand");
      break;
    case 1:
      set_skill("axe", 220);
      set_skill("block", 190);
      ob = new("/d/damned/virtual/battle-axe_6.weapon");
      ob->move(this_object());
      ob = new("/d/damned/virtual/large-shield.armour");
      ob->move(this_object());
      force_me("wield axe in left hand");
      force_me("wear shield on right hand");
      break;
    case 2:
      set_skill("blunt", 220);
      set_skill("block", 190);
      ob = new("/d/damned/virtual/hammer_6.weapon");
      ob->move(this_object());
      ob = new("/d/damned/virtual/large-shield.armour");
      ob->move(this_object());
      force_me("wield hammer in left hand");
      force_me("wear shield on right hand");
      break;
    case 3:
      set_skill("flail", 220);
      set_skill("block", 190);
      ob = new("/d/damned/virtual/morning-star_6.weapon");
      ob->move(this_object());
      ob = new("/d/damned/virtual/large-shield.armour");
      ob->move(this_object());
      force_me("wield star in left hand");
      force_me("wear shield on right hand");
      break;
    case 4:
      set_skill("knife", 220);
      set_skill("block", 190);
      ob = new("/d/damned/virtual/spiked-gauntlet_6.weapon");
      ob->move(this_object());
      ob = new("/d/damned/virtual/large-shield.armour");

      ob->move(this_object());
      force_me("wield knife in left hand");
      force_me("wear shield on right hand");
      break;
  }
  set_skill("parry", 130);
  set_skill("dodge", 125);
  set_skill("resist stun", 100);
  set_skill("perception", 110);
  set_skill("reverse stroke", 110);
  set_skill("melee", 50);
  set_skill("shield bash", 100);
  set_skill("cleave", 100);
  set_skill("arrest", 100);
  set_property("magic resistance", 20);

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

void do_salute(string str){
//   force_me("salute "+str);
  return;
}

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
    if(ob1->query_name() != "guardian") {
      force_me("kill "+a);
    }
  }
  if(sscanf(str, "%s enters.", a) == 1) {
    a = lower_case(a);
    call_out("do_salute", 1, a);
  }
  if(sscanf(str, "%s just tried to pick %s's pockets.", a, b) == 2){
    a = lower_case(a);
    b = lower_case(b);
    ob1 = present(a, environment(this_object()));
    ob2 = present(b, environment(this_object()));
    if(!ob1 || !ob2) return;
    if(ob1->query_name() != "guardian") {
      force_me("kill "+a);
    }
  }

  return;
}

void heart_beat(){
  string name;
  ::heart_beat();
  if(this_object()->query_attackers() != ({ })) {
    name =this_object()->query_attackers()[0]->query_name();
    if((time() - (int)this_object()->query_last_use("shield bash")) > 5){
      force_me("use shield bash at "+name+" with shield");
    }
    if((time() - (int)this_object()->query_last_use("cleave")) > 10){
      force_me("use cleave at "+name);
    }
    if((time() - (int)this_object()->query_last_use("arrest")) > 4){
      force_me("speak common");
      force_me("say You are under arrest for attacking an officer of the law!");
      force_me("use arrest at "+name);
    }

  return;
  }
}
