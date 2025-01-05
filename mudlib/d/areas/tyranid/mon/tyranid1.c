#include "../a1.h"

//TLNY2020 Example of basic creatures
 
#include <std.h>

inherit MONSTER;
string woodname;
string mtlname;
string damage1;
string damage2;
string quality;
int zlevel, lvl, llvl, zskill, zskillx, zskillac, zspell;
    mixed desc;
 
void create() {
    object bonesword;
   ::create();

    switch(random(7)){
      case 1:woodname="pine";break;
      case 2:woodname="willow";break;
      case 3:woodname="walnut";break;
      case 4:woodname="oak";break;
      case 5:woodname="maple";break;
      case 6:woodname="mahogany";break;
    }

    switch(random(11)){
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
    }
    switch(random(7)){
      case 0:damage1="crushing";break;
      case 1:damage1="cutting";break;
      case 2:damage1="impaling";break;
      case 3:damage1="impact";break;
      case 4:damage1="stress";break;
      case 5:damage1="fire";break;
      case 6:damage1="cold";break;
    }
    switch(random(7)){
      case 0:damage2="crushing";break;
      case 1:damage2="cutting";break;
      case 2:damage2="impaling";break;
      case 3:damage2="impact";break;
      case 4:damage2="stress";break;
      case 5:damage2="fire";break;
      case 6:damage2="cold";break;
    }
switch(random(8)){
      case 0:quality="4";break;
      case 1:quality="4";break;
      case 2:quality="5";break;
      case 3:quality="5";break;
      case 4:quality="5";break;
      case 5:quality="6";break;
      case 6:quality="6";break;
      case 7:quality="6";break;
    }

//controls monsters level
    zlevel = (27+random(5));
//Controls Loot level and other fucntions do to raise to high multpies loot
    lvl = 2;
//Controls critical hit reduction and other such
    llvl = 1;
//controls skill levels 2 multipliers controlled indepdent of level
    zskill = 7;
//controls stats level like str,con
    zskillx = 2;
//controlls skill% spell level
    zspell = 1;
//controls ac * level
    zskillac = 7;

    set_level(zlevel);

   set_overall_ac(zlevel*zskillac);
   set_property("magic resistance", zlevel/1);
   set_skill("resist stun", zlevel*zskillac);
   set_property("enhance criticals",-llvl);

   set_melee_damage(([ "cutting" : zlevel ]));
   //set_melee_damage(([ "cutting" : zlevel,damage1 : zlevel, damage2 : zlevel ]));

    //set_melee_damage("cutting");

   //set_money("mithril", random(zlevel*lvl)+zlevel);
   set_money("gold", random(zlevel*lvl)+zlevel); 
   //set_money("silver", random(zlevel*lvl)+zlevel);  
   //set_money("copper", random(zlevel*lvl)+zlevel); 

set_name("tyranid warrior");
    set("id",({"warrior","tyranid"}));
   set("long",@ext A mighty creature, the Tyranid warrior stands almost ten feet high
thickly muscled, encased in heavily plated chitin armour and not even
vaguely humanoid.  This is one of the most advanced of the Tyranid
biowarriors.  Its design incorporates two powerful arms ending in human-like hands holding strange swords with blades of living bone and humming
with psionic power.  Another set of limbs ends in huge striking claws
that remind you vaguely of bear paws.  The tail of lesser Tyranids has
been replaced by a bone tipped stinger...you shudder at the thought of
the unearthly diseases or venom it must deliver.  Worst of all, Tyranid
warriors such as this one act as nodes for the Tyranid hive
consciousness.  The vast intellect and will of the collective is able to
manifest thorugh this horrid creature, making it a general in the
Tyranid army.
ext);
   set_short("["+zlevel+"]Tyranid Warrior");    
  
   set("race", "tyranid");
    add_limb("head","FATAL",375,0,7);
    add_limb("torso","FATAL",525,0,7);
    add_limb("right arm","right grasping claw",275,0,7);
    add_limb("left arm","left grasping claw",275,0,7);
    add_limb("right striking arm","right striking claw",325,0,7);
    add_limb("left striking arm","left striking claw",325,0,7);
    add_limb("right leg","right walking talon",400,0,7);
    add_limb("left leg","left walking talon",400,0,7);
    add_limb("stingered tail","",350,0,7);
    add_limb("right grasping claw","",125,0,7);
    add_limb("left grasping claw","",125,0,7);
    add_limb("right striking claw","",165,0,7);
    add_limb("left striking claw","",165,0,7);
    add_limb("right walking talon","",165,0,7);
    add_limb("left walking talon","",165,0,7);

    set_wielding_limbs( ({"right grasping claw", "left striking claw",
	"stingered tail"}));
    bonesword = new(OBJ+"bonesword");
    bonesword->move(this_object());
    force_me("wield sword in right grasping claw");

    //set_speed(100);
    //set_moving(1);

   set("gang bang", 1);
   set("aggressive", 1);
}

void init()
{
    ::init();
    add_action("no","out");
    add_action("no","hole");
}

int no()
{
   if(archp(this_player())) { return 0; }
   if(this_player()->query_ghost()) { this_player()->stop_hunting(); return 0; }
    message("blocking",
      "The Tyranid Warrior hisses and leaps in front of you, blocking your path.\n",
      this_player());
    message("blocking",
      "The Tyranid Warrior blocks "+capitalize(this_player()->query_name())+"'s path.\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}


void die(object ob) {

switch(random(110)){

	case 0:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
   ob = new("/d/damned/virtual/great-helm.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Great Helm of "+damage1+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Great Helm of "+damage1+" protection");
    ob->set_ac(zlevel*lvl+random(zlevel), damage1); 
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());  
	break;
	case 1:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/breast-plate.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Breast Plate of "+damage1+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Breast Plate of "+damage1+" protection");
    ob->set_ac(zlevel*lvl+random(zlevel), damage1);    
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());  
	break;
	case 2: 
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
ob = new("/d/damned/virtual/plate-bracer.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Plate Bracer of "+damage1+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Plate Bracer of "+damage1+" protection");
    ob->set_ac(zlevel*lvl+random(zlevel), damage1);    
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());  
	break;
	case 3:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/gauntlet.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Gauntlet of "+damage1+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Gauntlet of "+damage1+" protection");
    ob->set_ac(zlevel*lvl+random(zlevel), damage1);   
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());  
	break;
	case 4:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/plate-greaves.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Plate Greaves of "+damage1+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Plate Greaves of "+damage1+" protection");
    ob->set_ac(zlevel*lvl+random(zlevel), damage1);    
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());  
	break;
	case 5:  
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
     ob = new("/d/damned/virtual/metal-boots.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Metal Boots of "+damage1+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Metal Boots of "+damage1+" protection");
    ob->set_ac(zlevel*lvl+random(zlevel), damage1); 
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());  
	break;
	case 6:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/buckler-shield.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Buckler Shield of "+damage1+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Buckler Shield of "+damage1+" protection");
    ob->set_ac(zlevel*lvl+random(zlevel), damage1);  
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());  
	break;
	case 7:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object()); 
    ob = new("/d/damned/virtual/battle-axe_"+quality+".weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Battle Axe of "+damage1);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Battle Axe of "+damage1);
    ob->set_wc(zlevel*lvl+random(zlevel), damage1);  
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());  
	break;
	case 8:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());   
    ob = new("/d/damned/virtual/broad-sword_"+quality+".weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Broad Sword of "+damage1);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Broad Sword of "+damage1);
    ob->set_wc(zlevel*lvl+random(zlevel), damage1);    
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());  
	break;
	case 9:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/footman's-mace_"+quality+".weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Footman's Mace of "+damage1);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Footman's Mace of "+damage1);
    ob->set_wc(zlevel*lvl+random(zlevel), damage1);  
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());  
	break;
	case 10: 
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/knife_"+quality+".weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Knife of "+damage1);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Knife of "+damage1);
    ob->set_wc(zlevel*lvl+random(zlevel), damage1); 
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());  
	break;
	case 11:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/brass-knuckles_"+quality+".weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Brass Knuckles of "+damage1);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Brass Knuckles of "+damage1);
    ob->set_wc(zlevel*lvl+random(zlevel), damage1); 
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());
	break;
	case 12:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/two-handed-sword_"+quality+".weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Two Handed Sword of "+damage1);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Two Handed Sword of "+damage1);
    ob->set_wc(zlevel*lvl+random(zlevel), damage1); 
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());
	break;
	case 13:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/war-hammer_"+quality+".weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" War Hammer of "+damage1);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" War Hammer of "+damage1);
    ob->set_wc(zlevel*lvl+random(zlevel), damage1);
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());
	break;
	case 14:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/footman's-flail_"+quality+".weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Footman's Flail of "+damage1);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Footman's Flail of "+damage1);
    ob->set_wc(zlevel*lvl+random(zlevel), damage1);
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());
	break;
	case 15:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());	
    ob = new("/d/damned/virtual/halberd_"+quality+".weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Halberd of "+damage1);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Halberd of "+damage1);
    ob->set_wc(zlevel*lvl+random(zlevel), damage1);
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());
	break;
	case 16:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());	
    ob = new("/d/damned/virtual/shod-staff_"+quality+".weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Shod Staff of "+damage1);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Shod Staff of "+damage1);
    ob->set_wc(zlevel*lvl+random(zlevel), damage1);
    ob->set_material("metal/"+mtlname);
    ob->move(this_object());
	break;
    }
   ::die();
}
