#include <std.h>
inherit "/std/monster";
string mtlname;
string damage1;
string damage2;
int zlevel;
   object ob;

void create() {
   ::create();
    zlevel = (15+random(3));
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

   set_level(zlevel);
   set_name("goblin");
   set("id", ({ "orc", "Orc", "gigantic orc" }));
   set_short("["+zlevel+"]Gigantic orc");
   set("long",
	"You see a mountain of a Orc before you what is that!!");


  // set_exp(6432454);

   set_property("enhance criticals",-3);
   set_property("magic resistance", 120);
   set_overall_ac(100);
   set_body_type("human");
   set_alignment(-100);
   set("race", "human");
   set_gender("male");

   set("aggressive", 1);
  set("chase",1);

   set_stats("strength", 1220 + random(30));
   set_stats("dexterity", 120 + random(30));
   set_stats("constitution", 120 + random(20));
   set_stats("wisdom", 50 + random(20));
   set_stats("intelligence", 50 + random(20));
   set_stats("charisma", 80);

   set_skill("melee", 110);
   set_skill("attack", 110);
   set_skill("defense", 110);
   set_skill("dodge", 110);
   set_skill("reverse stroke", 110);
   set_skill("martial arts",110);
   set_skill("concentrate", 110);
   set_skill("perception", 110);
   set("concentrate", 1);
    set_skill("resist stun", 175);

/*
   set_skill("conjuration", 140);
   set_skill("prayer", 100);
    set_spell_level("explosive fireball", 6);
   set_spell_level("internal flame",6);
    add_spell("explosive fireball","$A");
   add_spell("internal flame", "$A");
*/
   set_combat_chance(100);
add_action("block_exit", "west");

   
set_property("melee damage", ([
	"crushing" : zlevel,
	"cutting" : zlevel,
	"cold" : zlevel ]) );
/*
   set_hp(10000);
   set_max_hp(10000);
   set_max_mp(7000);
   set_mp(7000);
*/
}

int loot;

void die(object ob) {
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
loot=(1+random(19));

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
    ob = new("/d/damned/virtual/greate-axe_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" greate-axe of "+damage1+" and "+damage2);      
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
//special GEAR DROP can cast enlarge
    ob = new("/d/1tlny/loot/orb_enlarge");
    ob->move(this_object());  
else
if (loot == 17) {
//special GEAR DROP can cast hooded robe    
    ob = new("/d/1tlny/loot/hooded_robe");
    ob->move(this_object());    
}
else {
 ob = new("/std/diewarzau/obj/misc/ingot");
    ob->set_material("metal/"+mtlname);
   ob->move(this_object());
}
 
   ::die();
}


