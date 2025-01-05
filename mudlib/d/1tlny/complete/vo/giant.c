//  Wizard:   TLNY2020 Made new
//  Monster:  giant
//  File:     giant.c

#include <std.h>

inherit MONSTER;

int query_kho_mon();
void slam_door();

void init() {
  string zstr;
  int i,lvl;
  object *inv;
   ::init();
  force_me("cast *6 explosive fireball");
  delayed_call("slam_door", 4);
  inv = all_inventory(environment(this_object()));
  i = sizeof(inv);
  while(i--) {
    if(living(inv[i])) {
      lvl = (int)inv[i]->query_level(); 
      if(inv[i] != this_object())
      write_file("/d/khojem/log/giant.log",
      "=== Init:  "+inv[i]->query_cap_name()+" "+lvl+"\t\t\t"+
        ctime(time())+"\n");
    }
  }
  return;
}
 
string mtlname;
string damage1;
string damage2;
int zlevel;
   object ob;

void create() {
   ::create();
    zlevel = (35+random(3));
switch(random(14)){
      case 0:mtlname="iron";break;
      case 1:mtlname="steel";break;
      case 2:mtlname="boernerine";break;
      case 3:mtlname="mcgrail";break;
      case 4:mtlname="neorolite";break;
      case 5:mtlname="catoetine";break;
      case 6:mtlname="raysorite";break;
      case 7:mtlname="inniculmoid";break;
      case 8:mtlname="elrodnite";break;
      case 9:mtlname="mithril";break;
      case 10:mtlname="platnite";break;
      case 11:mtlname="mabril";break;
      case 12:mtlname="iysaughton";break;
      case 13:mtlname="laen";break;
    }
    switch(random(11)){
      case 0:damage1="crushing";break;
      case 1:damage1="cutting";break;
      case 2:damage1="impaling";break;
      case 3:damage1="impact";break;
      case 4:damage1="stress";break;
      case 5:damage1="fire";break;
      case 6:damage1="cold";break;
      case 7:damage1="vacuum";break;
      case 8:damage1="electricity";break;
      case 9:damage1="disruption";break;
      case 10:damage1="plasma";break;
    }
    switch(random(11)){
      case 0:damage2="crushing";break;
      case 1:damage2="cutting";break;
      case 2:damage2="impaling";break;
      case 3:damage2="impact";break;
      case 4:damage2="stress";break;
      case 5:damage2="fire";break;
      case 6:damage2="cold";break;
      case 7:damage2="vacuum";break;
      case 8:damage2="electricity";break;
      case 9:damage2="disruption";break;
      case 10:damage2="plasma";break;
    }
   set_name("huge giant");
   set("id", ({"giant", "huge giant", "huge", "kho_mob"}) );
   set_level(zlevel);
   set_short("["+zlevel+"]huge giant");
       set_long("The huge, massive hill-giant does not like the fact that you "+
      "have disturbed his solitude."
      );
   set_hp(zlevel*350 + zlevel*2);
   set_max_hp(zlevel*350 + zlevel*2);
   //set_exp(800000);
   set("race", "huge-giant");
   set_gender("male");
   set_body_type("human");
   set_skill("conjuration", 150);
   set_skill("concentrate", 100);
   set_languages( ({"common"}) );
  set_melee_damage( (["crushing" : 40, "cutting" : 20, "electricity" : 30 ]) );
  set_property("magic resistance",99);
  set_skill("martial arts",30);
  set_skill("resist stun",99);
  set_combat_chance(110);
  set_property("enhance criticals",-3);
  set_overall_ac(160);
  //set_property("weakness","water");
  //set_property("weakness","ice");
  add_spell("explosive fireball", "$A");
  set_spell_level("explosive fireball", 6);
  set_emotes(5, ({
         "The giant grins broadly and his eyes narrow.",
         "The giant grins broadly and his eyes narrow.",
         "The giant rotates his girth in the room and suddenly, "
           "playfully takes a swing at you with one arm.",
         "Smoke fumes from the giant's broad nostrils.",
         "Smoke fumes from the giant's broad nostrils.",
         "The giant's eyes narrow and glow a bright red  "
           "as he gauges your abilities",
         "The giant's eyes narrow and glow a bright red "
           "as he gauges your abilities",
  }),0);
   force_me("use concentrate");

add_money("gold", zlevel + random(100)*zlevel);
   set_property("enhance criticals",-4);
   set_property("magic resistance", zlevel/2);
   set_overall_ac(zlevel*5);

   set_stats("strength", zlevel*10 + random(20));
   set_stats("dexterity", zlevel*10 + random(20));
   set_stats("constitution", zlevel*10 + random(20));
   set_stats("wisdom", zlevel*10);
   set_stats("intelligence", zlevel*10);
   set_stats("charisma", zlevel*10);

   set_skill("melee", zlevel*11);
   set_skill("attack", zlevel*11);
   set_skill("defense", zlevel*11);
   set_skill("dodge", zlevel*11);
   set_skill("reverse stroke", zlevel*11);
   set_skill("martial arts",zlevel*11);
   set_skill("concentrate", zlevel*11);
   set_skill("perception", zlevel*11);
   set("concentrate", 1);
    set_skill("resist stun", zlevel*11);

}

int query_kho_mon() { return 1;}

void slam_door() {
  message("info","The giant reaches an arm out "
    "towards the door.",environment(this_object()));
  force_me("close translusent door");
  return;
}

/*
void catch_tell(string str) {
  string who, b;
  
  if(sscanf(str, "%s drops dead before %s", who, b) == 2 ) {
    force_me("grin");
    write_file("/d/khojem/log/demi-dragon.log",
      "*** Player Kill:  "+who+"\t\t"+ctime(time())+"\n");
  }
  if(sscanf(str, "%s dies a horrible %s", who, b) == 2 ) {
    force_me("grin");
    write_file("/d/khojem/log/demi-dragon.log",
      "*** Player Kill:  "+who+"\t\t\t"+ctime(time())+"\n");
  }
  return;
}
*/

/*
void die() {
  write_file("/d/khojem/log/demi-dragon.log",
    ">>> Demi-Dragon died \t\t\t"+ctime(time())+"\n");
   ::die();
}
*/
//TLNY2020 added in
int loot;

void die(object ob) {
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
loot=(1+random(18));

if (loot == 1){ 
    ob = new("/d/damned/virtual/great-helm.armour");
   ob->move(this_object());
    ob -> set("short", mtlname+" helm of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else 
if (loot == 2) { 
    ob = new("/d/damned/virtual/gauntlet.armour");
   ob->move(this_object());
    ob -> set("short", mtlname+" gauntlet of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 3) {   
    ob = new("/d/damned/virtual/chain-mail.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" mail of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 4) {  
    ob = new("/d/damned/virtual/metal-boots.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" boots of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 5) {  
    ob = new("/d/damned/virtual/large-shield.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" shield of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 6) {    
    ob = new("/d/damned/virtual/plate-greaves.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" greaves of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 7) {   
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" bracer of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 8) {   
    ob = new("/d/damned/virtual/broad-sword_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" broad-sword of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 9) {   
    ob = new("/d/damned/virtual/knife_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" knife of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 10) {   
    ob = new("/d/damned/virtual/footman's-mace_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" footman's-mace of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 11) {   
    ob = new("/d/damned/virtual/battle-axe_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" battle-axe of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 12) {   
    ob = new("/d/damned/virtual/two-handed-sword_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" two-handed-sword of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 13) {   
    ob = new("/d/damned/virtual/war-hammer_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" war-hammer of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 14) {   
    ob = new("/d/damned/virtual/great-axe_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" great-axe of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 15) {   
    ob = new("/d/damned/virtual/shod-staff_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" shod-staff of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel, damage1);
    ob -> set_wc(zlevel, damage2);
    ob->set_material("metal/"+mtlname);
}

else
if (loot == 16) {  
//special GEAR DROP can cast mad rage
    ob = new("/d/1tlny/loot/orb_rage.c");
    ob->move(this_object());  
}
else {
 ob = new("/std/diewarzau/obj/misc/ingot");
    ob->set_material("metal/"+mtlname);
   ob->move(this_object());
}
 
   ::die();
}
