#include <std.h>
inherit "/std/monster";
string mtlname;
string damage1;
string damage2;
string quality;
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
switch(random(7)){
      case 0:quality="5";break;
      case 1:quality="5";break;
      case 2:quality="6";break;
      case 3:quality="6";break;
      case 4:quality="6";break;
      case 5:quality="6";break;
      case 6:quality="6";break;
      case 7:quality="6";break;
    }

   set_level(zlevel);
   set_name("Monk");
   set("id", ({ "monk", "Monk", "nine dot monk", "nine monk" }));
   set_short("["+zlevel+"]nine dot Monk");
   set("long",
	"A very strong and focused monk that has nine dots on his head stands here");


  // set_exp(6432454);

   set_property("enhance criticals",-2);
    set_property("magic resistance", zlevel/2);
   set_overall_ac(zlevel*4);
   set_body_type("human");
   set_alignment(-100);
   set("race", "human");
   set_gender("male");
add_money("gold", zlevel + random(100));

   set("aggressive", 1);
  set("chase",1);

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

/*
   set_skill("conjuration", 140);
   set_skill("prayer", 100);
    set_spell_level("explosive fireball", 6);
   set_spell_level("internal flame",6);
    add_spell("explosive fireball","$A");
   add_spell("internal flame", "$A");
*/
   set_combat_chance(100);
add_action("block_exit", "south");

 
set_property("melee damage", ([
	"crushing" : zlevel,
	"cutting" : zlevel,
	"fire" : zlevel ]) );

   set_hp(zlevel*400 + zlevel*2);
   set_max_hp(zlevel*400 + zlevel*2);
/*
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
    ob -> set("short", mtlname+" helm");      
    ob->set_ac(zlevel);
    ob->set_material("metal/"+mtlname);
}
else 
if (loot == 2) { 
    ob = new("/d/damned/virtual/gauntlet.armour");
   ob->move(this_object());
    ob -> set("short", mtlname+" gauntlet");      
    ob->set_ac(zlevel);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 3) {   
    ob = new("/d/damned/virtual/chain-mail.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" mail");      
    ob->set_ac(zlevel);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 4) {  
    ob = new("/d/damned/virtual/metal-boots.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" boots");      
    ob->set_ac(zlevel);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 5) {  
    ob = new("/d/damned/virtual/large-shield.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" shield");      
    ob->set_ac(zlevel);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 6) {    
    ob = new("/d/damned/virtual/plate-greaves.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" greaves");      
    ob->set_ac(zlevel);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 7) {   
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" bracer");      
    ob->set_ac(zlevel);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 8) {   
    ob = new("/d/damned/virtual/broad-sword_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" broad-sword");      
    ob->set_wc(zlevel);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 9) {   
    ob = new("/d/damned/virtual/knife_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" knife");      
    ob->set_wc(zlevel);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 10) {   
    ob = new("/d/damned/virtual/footman's-mace_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" footman's-mace");      
    ob->set_wc(zlevel);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 11) {   
    ob = new("/d/damned/virtual/battle-axe_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" battle-axe");      
    ob->set_wc(zlevel);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 12) {   
    ob = new("/d/damned/virtual/two-handed-sword_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" two-handed-sword");      
    ob->set_wc(zlevel);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 13) {   
    ob = new("/d/damned/virtual/war-hammer_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" war-hammer");      
    ob->set_wc(zlevel);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 14) {   
    ob = new("/d/damned/virtual/great-axe_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" great-axe");      
    ob->set_wc(zlevel);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 15) {   
    ob = new("/d/damned/virtual/shod-staff_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" shod-staff");      
    ob->set_wc(zlevel);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 16) {  
//special GEAR DROP can cast holy fury 
    ob = new("/d/1tlny/loot/orb_fury2");
    ob->move(this_object()); 
}	
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

