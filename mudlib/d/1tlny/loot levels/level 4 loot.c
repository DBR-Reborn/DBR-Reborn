//#include "../a1.h"

//TLNY2020 Example of basic creatures
 
#include <std.h>

inherit MONSTER;
string mtlname;
string damage1;
string damage2;
string quality;
int zlevel;

 
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
switch(random(7)){
      case 0:quality="6";break;
      case 1:quality="6";break;
      case 2:quality="6";break;
      case 3:quality="6";break;
      case 4:quality="6";break;
      case 5:quality="6";break;
      case 6:quality="6";break;
      case 7:quality="6";break;
    }

    zlevel = (25+random(6));

    set_level(zlevel);

   set_overall_ac(zlevel*2);
   set_property("magic resistance", zlevel/2);
   set_skill("resist stun", zlevel*3);
   set_property("enhance criticals",-1);

   set_melee_damage(([ "crushing" : zlevel,damage1 : zlevel, damage2 : zlevel ]));

   set_money("silver", random(100)+5*zlevel); 

   set_name("dragon");
   set("id", ({ "dragon", "Dragon", "gold dragon", "large dragon" }));
   set("long",
	"Scales ripple as powerful muscles move beneath the skin of this large "+
	"dragon.  The heat that ripples from his body gives evidence to the fire "+
	"contained within.  Massive large claws as long as swords and sharp teeth "+
	"only serve to add to this creatures powerful arsenal.");
   set_short("["+zlevel+"]Large %^RESET%^%^YELLOW%^Gold%^RESET%^ Dragon");
  
   set("race", "dragon");
   set_body_type("dragon");
    switch(random(2)){
    case 0:
    set_gender("male");
    break;
    case 1:
    set_gender("female");
    break;
    }
   set_alignment(-100);

   set("gang bang", 1);
   set("aggressive", 1);

   set_hp(zlevel*200 + zlevel*2);
   set_max_hp(zlevel*200 + zlevel*2);
 //set_hp(100);
 //set_max_hp(100);
    //set_max_mp(7000);
    //set_mp(7000);

    set_stats("strength", 9*zlevel +random(zlevel));
    set_stats("dexterity", 9*zlevel +random(zlevel));
    set_stats("constitution", 9*zlevel +random(zlevel));
    set_stats("wisdom", 9*zlevel +random(zlevel));
    set_stats("intelligence", 9*zlevel +random(zlevel));
    set_stats("charisma", 9*zlevel +random(zlevel));
    
    set_skill("attack", 9*zlevel +random(zlevel));
    set_skill("two handed blade", 9*zlevel +random(zlevel));;
    set_skill("two handed blunt",  9*zlevel +random(zlevel));
    set_skill("two handed flail", 9*zlevel +random(zlevel));
    set_skill("two handed polearm", 9*zlevel +random(zlevel));
    set_skill("two handed staff", 9*zlevel +random(zlevel));
    set_skill("axe", 9*zlevel +random(zlevel));
    set_skill("blade", 9*zlevel +random(zlevel));
    set_skill("blunt", 9*zlevel +random(zlevel));
    set_skill("knife",  9*zlevel +random(zlevel));
    set_skill("flail", 9*zlevel +random(zlevel));
    set_skill("melee", 9*zlevel +random(zlevel));

    set_skill("parry", 9*zlevel +random(zlevel));
    set_skill("dodge", 9*zlevel +random(zlevel));
    set_skill("block", 9*zlevel +random(zlevel));
/*
    set_skill("whirlwind attack", 9*zlevel +random(zlevel));
    set_skill("reverse stroke", 9*zlevel +random(zlevel));
    set_skill("perception", 9*zlevel +random(zlevel));

    set_combat_chance(100);

    set_skill("martial arts",9*zlevel +random(zlevel));
    set_skill("shield bash", 9*zlevel +random(zlevel));
    set_skill("reverse stroke", 9*zlevel +random(zlevel)); 
    set_skill("defense", 9*zlevel +random(zlevel));
    set("see invis", 1);

    set_skill("concentrate", 9*zlevel +random(zlevel));
    force_me("use concentrate");

    set_skill("conjuration", 8*zlevel +random(zlevel));
    set_skill("prayer",  8*zlevel +random(zlevel));
    set_spell_level("explosive fireball", 6);
    set_spell_level("internal flame",6);
    add_spell("explosive fireball","$A");
    add_spell("internal flame", "$A");

   set_skill("illusionism",  8*zlevel +random(zlevel));
   set_skill("conjuration",  8*zlevel +random(zlevel));
   set_skill("necromancy",  8*zlevel +random(zlevel));
   set_skill("concentrate",  8*zlevel +random(zlevel));
   add_spell("curse", "$A");
   set_spell_level("curse", 6);
   add_spell("lightning bolt", "$A");
   set_spell_level("lightning bolt", 6);

    set_skill("elementalism",  8*zlevel +random(zlevel));
    set_skill("electricity lore",  8*zlevel +random(zlevel));
    force_me("use electricity lore");
    set_spell_level("greater elemental bolt", 5);
    add_spell("greater elemental bolt", "$A");
    set_spell_level("greater elemental storm", 5);
    add_spell("greater elemental storm", "$A"); 
*/
    set_property("handedness", "right hand");
}

void die(object ob) {

switch(random(16)){

	case 0:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/great-helm.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" helm of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 1:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/gauntlet.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" gauntlet of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 2: 
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/chain-mail.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" mail of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 3:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/metal-boots.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" boots of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 4:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/large-shield.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" shield of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 5:  
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/plate-greaves.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" greaves of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 6:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob->move(this_object());
    ob -> set("short", mtlname+" bracer of "+damage1+" and "+damage2+" protection");      
    ob->set_ac(zlevel);
    ob -> set_ac(zlevel*3, damage1);
    ob -> set_ac(zlevel*3, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 7:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());   
    ob = new("/d/damned/virtual/broad-sword_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" broad-sword of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 8:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/knife_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" knife of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 9:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/footman's-mace_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" footman's-mace of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 10: 
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object()); 
    ob = new("/d/damned/virtual/battle-axe_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" battle-axe of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 11:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/two-handed-sword_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" two-handed-sword of "+damage1);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 12:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/war-hammer_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" war-hammer of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 13:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/great-axe_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" great-axe of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 14:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());	
    ob = new("/d/damned/virtual/shod-staff_"+quality+".weapon");
    ob->move(this_object());
    ob -> set("short", mtlname+" shod-staff of "+damage1+" and "+damage2);      
    ob->set_wc(zlevel);
    ob -> set_wc(zlevel*2, damage1);
    ob -> set_wc(zlevel*2, damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 15:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/std/diewarzau/obj/misc/ingot");
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());
break;
    }
   ::die();
}
