#include <std.h>
inherit "/std/monster";
string mtlname;
string damage1;
string damage2;
int zlevel;
   object ob;

void create() {
   ::create();

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
   zlevel = (30+random(3));

   set_level(zlevel);

   set_overall_ac(zlevel*2);
   set_property("magic resistance", zlevel);
   set_skill("resist stun", zlevel+zlevel+zlevel);
   set_melee_damage(([ damage1 : zlevel, damage2 : zlevel, "crushing" : zlevel ]));

   set_money("silver", random(100)+5*zlevel); 
   set_name("dragon");
   set("id", ({ "dragon", "Dragon", "white dragon" }));
   set("long",
	"Scales ripple as powerful muscles move beneath the skin of this large "+
	"dragon.  The heat that ripples from his body gives evidence to the fire "+
	"contained within.  Massive large claws as long as swords and sharp teeth "+
	"only serve to add to this creatures powerful arsenal.");
   set_short("["+zlevel+"]Huge%^WHITE%^White%^RESET%^Dragon");

  // set_exp(6432454);

   set("race", "dragon");
   set_body_type("dragon");
   set_gender("male");
   set_alignment(-100);

    set("aggressive", 1);
    set("chase",1);

    //set_max_hp(10);
    //set_hp(10);
    //set_max_mp(7000);
    //set_mp(7000);

   set_stats("strength", 160 + zlevel);
   set_stats("dexterity", 160 + zlevel);
   set_stats("constitution", 160 + zlevel);
   set_stats("wisdom", 110 + zlevel);
   set_stats("intelligence", 110 + zlevel);
   set_stats("charisma", 110 + zlevel);
/*    
    set_skill("axe", 150 + 1*zlevel);
    set_skill("two handed blade", 150 + 1*zlevel);
    set_skill("two handed blunt", 150 + 1*zlevel);
    set_skill("two handed flail", 150 + 1*zlevel);
    set_skill("two handed polearm", 150 + 1*zlevel);
    set_skill("two handed staff", 150 + 1*zlevel);
    set_skill("blade", 150 + 1*zlevel);
    set_skill("blunt", 150 + 1*zlevel);
    set_skill("knife", 150 + 1*zlevel);
    set_skill("flail", 150 + 1*zlevel);
*/
/*
    set_skill("shield bash", 50 + 1*zlevel);
    set_skill("reverse stroke", 50 + 1*zlevel);
    set_skill("combo", 50 + 1*zlevel); //Whirlwind
    set_skill("block", 50 + 1*zlevel);
    set_skill("parry", 50 + 1*zlevel);
    set_skill("melee", 50 + 1*zlevel);
    set_skill("attack", 50 + 1*zlevel);
    set_skill("defense", 50 + 1*zlevel);
    set_skill("dodge", 50 + 1*zlevel);
*/
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

    set_property("handedness", "right hand");

}

int loot;

void die(object ob) {
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
loot=(1+random(17));

if (loot == 1){ 
    ob = new("/d/damned/virtual/great-helm.armour");
   ob->move(this_object());
    ob -> set("short", mtlname+" helm of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel*2);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else 
if (loot == 2) { 
    ob = new("/d/damned/virtual/gauntlet.armour");
   ob->move(this_object());
    ob -> set("short", mtlname+" gauntlet of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel*2);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 3) {   
    ob = new("/d/damned/virtual/chain-mail.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" mail of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel*2);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 4) {  
    ob = new("/d/damned/virtual/metal-boots.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" boots of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel*2);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 5) {  
    ob = new("/d/damned/virtual/large-shield.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" shield of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel*2);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 6) {    
    ob = new("/d/damned/virtual/plate-greaves.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" greaves of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel*2);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 7) {   
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" bracer of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel*2);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 8) {   
    ob = new("/d/damned/virtual/broad-sword_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" broad-sword of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel*2);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 9) {   
    ob = new("/d/damned/virtual/knife_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" knife of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel*2);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 10) {   
    ob = new("/d/damned/virtual/footman's-mace_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" footman's-mace of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel*2);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 11) {   
    ob = new("/d/damned/virtual/battle-axe_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" battle-axe of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel*2);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 12) {   
    ob = new("/d/damned/virtual/two-handed-sword_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" two-handed-sword of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel*2);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 13) {   
    ob = new("/d/damned/virtual/war-hammer_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" war-hammer of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel*2);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 14) {   
    ob = new("/d/damned/virtual/greate-axe_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" greate-axe of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel*2);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
}
else
if (loot == 15) {   
    ob = new("/d/damned/virtual/shod-staff_6.weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" shod-staff of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel*2);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
}
else {
 ob = new("/std/diewarzau/obj/misc/ingot");
    ob->set_material("metal/"+mtlname);
   ob->move(this_object());
}
 
   ::die();
}
