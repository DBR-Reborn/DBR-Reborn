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

int hide_in_shadows,in_stealth,shadowing;

void init() {
    :: init();
    add_action("no","up");
    add_action("no","down");
    if(!this_player()->is_player()) { return; }
    if(this_player()->query_invis()) { return; }
    if(hide_in_shadows==0) {
	force_me("use hide in shadows");
	hide_in_shadows = 1;
    }
    if(in_stealth==0) {
	force_me("use stealth");
	in_stealth = 1;
    }
    if (shadowing==0) {
	force_me("use shadow at "+(string)this_player()->query_name());
	delayed_call("bs",random(6)+2,this_player());
	shadowing = 1;
    }
    return;
}

 
void create() {

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
    zlevel = (26+random(5));
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
    zskillac = 6;

    set_level(zlevel);

   set_overall_ac(zlevel*zskillac);
   set_property("magic resistance", zlevel/1);
   set_skill("resist stun", zlevel*zskillac);
   set_property("enhance criticals",-llvl);

   //set_melee_damage(([ "cutting" : zlevel ]));
   //set_melee_damage(([ "cutting" : zlevel,damage1 : zlevel, damage2 : zlevel ]));

    set_melee_damage("impaling");

   //set_money("mithril", random(zlevel*lvl)+zlevel);
   set_money("gold", random(zlevel*lvl)+zlevel); 
   //set_money("silver", random(zlevel*lvl)+zlevel);  
   //set_money("copper", random(zlevel*lvl)+zlevel); 

set_name("lictor");
    set("id",({"lictor","tyranid"}));
   set("long",@ext This terrifying creature is a Lictor, the ninja/commandos of the
Tyranids.  Like most Tyranids, they have 2 sets of arms.  The first set
is almost perfectly humanoid.  The second set however are huge
structures of chitin and bone that almost perfectly resemble a pair of
scythes!  The Lictor's armour plate is covered with special chamelionic
scales, capable of blending in almost perfectly in any environment.
This, combined with its blinding speed and inhuman cunning, enables the
Lictor to penetrate deep into even an alert enemy's territory to gather
intelligence.  The four slender tenticles that ring its mandible-like
mouth, are capable of extracting the brains from many life forms, from
which the Lictor is able to derive an appaling amount of information
as well as the victim's genetic code which the Lictor uses to improve
itself.
ext);
   set_short("["+zlevel+"]Lictor");    
  
   set("race", "tyranid");
    add_limb("head","FATAL",425,0,7);
    add_limb("torso","FATAL",600,0,7);
    add_limb("right arm","right grasping claw",325,0,7);
    add_limb("left arm","left grasping claw",325,0,7);
    add_limb("right scythe arm","right scythe claw",350,0,7);
    add_limb("left scythe arm","left scythe claw",350,0,7);
    add_limb("right grasping claw","",175,0,7);
    add_limb("left grasping claw","",175,0,7);
    add_limb("right scythe claw","",400,0,7);
    add_limb("left scythe claw","",400,0,7);
    add_limb("right leg","right walking talon",400,0,7);
    add_limb("left leg","left walking talon",400,0,7);
    add_limb("right walking talon","",200,0,7);
    add_limb("left walking talon","",200,0,7);

    set_wielding_limbs( ({ "right grasping claw","left grasping claw","right scythe claw","left scythe claw" }));
    set_skill("back stab",zskill*zlevel);
    set_skill("hide in shadows",zskill*zlevel);
    set_skill("stealth",zskill*zlevel);
    set_skill("shadow",zskill*zlevel);
    set_skill("perception",zskill*zlevel);

    //set_speed(100);
    //set_moving(1);

   set("gang bang", 1);
   set("aggressive", 1);
}

void bs(object tp){
    if(!tp || !present(tp, environment())) { return; }
    message("combat","A terrifying shape flashes out of the shadows and attacks with blinding speed!\n",all_inventory(environment()));
    tp->kill_ob(this_object(), 0);
    tp->do_damage((string)tp->return_target_limb(),2*(random(6)+6));
    do_critical(this_object(),tp,"impaling C");
    do_critical(this_object(),tp,"speed C");
    hide_in_shadows = 0;
    in_stealth = 0;
    shadowing = 0;
    return;
}

int no()
{
   if(archp(this_player())) { return 0; }
   if(this_player()->query_ghost()) { this_player()->stop_hunting(); return 0; }
    message("blocking",
      "The Lictor hisses and leaps in front of you, blocking your path.\n",
      this_player());
    message("blocking",
      "The Lictor blocks "+capitalize(this_player()->query_name())+"'s path.\n",
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
