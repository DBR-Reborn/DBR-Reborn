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
      case 0:quality="3";break;
      case 1:quality="4";break;
      case 2:quality="4";break;
      case 3:quality="4";break;
      case 4:quality="5";break;
      case 5:quality="5";break;
      case 6:quality="6";break;
      case 7:quality="6";break;
    }

//controls monsters level
    zlevel = (22+random(5));
//Controls Loot level and other fucntions do to raise to high multpies loot
    lvl = 2;
//Controls critical hit reduction and other such
    llvl = 1;
//controls skill levels 2 multipliers controlled indepdent of level
    zskill = 1;
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

   set_melee_damage(([ "cutting" : zlevel ]));
   //set_melee_damage(([ "cutting" : zlevel,damage1 : zlevel, damage2 : zlevel ]));

    //set_melee_damage("cutting");

   //set_money("mithril", random(zlevel*lvl)+zlevel);
   //set_money("gold", random(zlevel*lvl)+zlevel); 
   set_money("silver", random(zlevel*lvl)+zlevel);  
   //set_money("copper", random(zlevel*lvl)+zlevel); 

set_name("gene stealer");
    set("id",({"gene stealer","stealer","tyranid"}));
   set("long",@ext One of the more terrifying of the Tyranid aliens, the Gene stealers
at least vaguely resemble a huge human with two sets of arms.  One
set of razor-sharp scythe-like talons.  The chitinous plate armour is a
deep mightnight blue in colour, fading to a pale pink along the sinous
tale and the toothy maw.  Gene stealers are the most intelligent of the
Tyranid foot soldiers.  They sweep forward ahead of the main Tyranid
force, using their bliding speed and unending ferocity to cut down all
living creatures they encounter.  They then sample the genetic code of
their victim and incorporate it into their own...thereby becoming
faster, stronger and smarter with every kill!
ext);
   set_short("["+zlevel+"]Gene Stealer");    
  
   set("race", "tyranid");
    add_limb("head","FATAL",300,0,7);
    add_limb("torso","FATAL",450,0,7);
    add_limb("right arm","right grasping claw",200,0,7);
    add_limb("left arm","left grasping claw",200,0,7);
    add_limb("right scythe arm","right scythe claw",225,0,7);
    add_limb("left scythe arm","left scythe claw",225,0,7);
    add_limb("right grasping claw","",90,0,7);
    add_limb("left grasping claw","",90,0,7);
    add_limb("right scythe claw","",120,0,7);
    add_limb("left scythe claw","",120,0,7);
    add_limb("right leg","right walking talon",300,0,7);
    add_limb("left leg","left walking talon",300,0,7);
    add_limb("right walking talon","",120,0,7);
    add_limb("left walking talon","",120,0,7);

set_wielding_limbs( ({ "right grasping claw","left grasping claw","right scythe claw","left scythe claw" }));
    //set_speed(100);
    //set_moving(1);

   set("gang bang", 1);
   set("aggressive", 1);

    set_combat_chance(75);
    set_skill("elementalism",110);
    set_skill("fire lore",100);
    set_skill("concentrate",12);
    add_spell("elemental bolt","$A");
    set_spell_level("elemental bolt",6);
    force_me("use concentrate");
    force_me("use fire lore");


/*
   set_hp(zlevel*250 + zlevel*2);
   set_max_hp(zlevel*250 + zlevel*2);
//set_hp(100);
//set_max_hp(100);
    //set_max_mp(100);
    //set_mp(100);

    set_stats("strength", zskillx*zlevel);
    set_stats("dexterity", zskillx*zlevel);
    set_stats("constitution", zskillx*zlevel);
    set_stats("wisdom", zskillx*zlevel);
    set_stats("intelligence", zskillx*zlevel);
    set_stats("charisma", zskillx*zlevel);
    
    set_skill("attack", zskill*zlevel);
    set_skill("two handed blade", zskill*zlevel);
    set_skill("two handed blunt",  zskill*zlevel);
    set_skill("two handed flail", zskill*zlevel);
    set_skill("two handed polearm", zskill*zlevel);
    set_skill("two handed staff", zskill*zlevel);
    set_skill("axe", zskill*zlevel);
    set_skill("blade", zskill*zlevel);
    set_skill("blunt", zskill*zlevel);
    set_skill("knife",  zskill*zlevel);
    set_skill("flail", zskill*zlevel);
    set_skill("melee", zskill*zlevel);

    set_skill("parry", zskillx*zlevel);
    set_skill("dodge", zskillx*zlevel);
    set_skill("block", zskillx*zlevel);

    set_skill("combo", zskillx*zlevel);
    set_skill("reverse stroke", zskillx*zlevel);
    set_skill("perception", zskillx*zlevel);

    set_combat_chance(100);
*/
/*
    set_skill("martial arts",zskillx*zlevel);
    set_skill("shield bash", zskillx*zlevel);
    set_skill("kick", zskillx*zlevel);
    set_skill("head butt", zskillx*zlevel);
    set_skill("reverse punch", zskillx*zlevel);
    set_skill("sweep", zskillx*zlevel);
    set_skill("reverse stroke", zskillx*zlevel); 
    set_skill("defense", zskillx*zlevel);
    set("see invis", 1);

    set_skill("concentrate", zskillx*zlevel);
    force_me("use concentrate");

    set_skill("necromancy", zspell*zlevel);

    set_skill("black magic", zspell*zlevel);
    set_spell_level("lich form", 6);
    add_spell("lich form", "$(ME)");
    add_spell("curse", "$A");
    set_spell_level("curse", 6);
    add_spell("drain life", "$A");
    set_spell_level("drain life", 6);
    add_spell("lifesteal", "$A");
    set_spell_level("lifesteal", 6);
    add_spell("syphon soul", "$A");
    set_spell_level("syphon soul", 6);
    add_spell("decay", "$A");
    set_spell_level("decay", 6);
    add_spell("rot", "$A");
    set_spell_level("rot", 6);

    add_spell("cold blast", "$A");
    set_spell_level("cold blast", 6);
    add_spell("wind of death", "$A");
    set_spell_level("wind of death", 6);

*/
/*
    set_skill("chaos magic", zspell*zlevel);
    add_spell("disruption bolt ", "$A");
    set_spell_level("disruption bolt", 6);
    add_spell("chaos ball", "$A");
    set_spell_level("chaos ball", 6);
    add_spell("chaos storm", "$A");
    set_spell_level("chaos storm", 6);
*/
/*
   set_skill("body alteration", zspell*zlevel);
    add_spell("decrease metabolism", "$A");
    set_spell_level("decrease metabolism", 6);
    set_spell_level("divine transformation", 6);
    add_spell("divine transformation", "$(ME)");

   set_skill("prayer", zspell*zlevel);
    add_spell("harm", "$A");
    set_spell_level("harm", 6);
    add_spell("smite", "$A");
    set_spell_level("smite", 6);
    add_spell("holy condemnation", "$A");
    set_spell_level("holy condemnation", 6);

    add_spell("mass heal", "$R");
    set_spell_level("mass heal", 6);
    set_spell_level("cure serious wounds", 6);
    add_spell("cure serious wounds", "$(ME)");
    set_spell_level("heal", 6);
    add_spell("heal", "$(ME)");
    set_spell_level("true heal", 6);
    add_spell("true heal", "$(ME)");
    set_skill("lay on hands", zskill*zlevel);

   set_skill("worship of k'thach", zspell*zlevel);
    add_spell("wrath of god", "$A");
    set_spell_level("wrath of god", 6);


   set_skill("sorcery", zspell*zlevel);

   set_skill("illusionism", zspell*zlevel);
    add_spell("faerie fire ", "$A");
    set_spell_level("faerie fire ", 6);

   set_skill("magery", zspell*zlevel);
    add_spell("slow", "$A");
    set_spell_level("slow", 6);

   set_skill("conjuration", zspell*zlevel);
    add_spell("magic missile", "$A");
    set_spell_level("magic missile", 6);
    add_spell("fireball", "$A");
    set_spell_level("fireball", 6);
    add_spell("ice dagger", "$A");
    set_spell_level("ice dagger", 6);
    add_spell("lightning bolt", "$A");
    set_spell_level("lightning bolt", 6);
    add_spell("killing cloud", "$A");
    set_spell_level("killing cloud", 6);
    add_spell("explosive fireball", "$A");
    set_spell_level("explosive fireball", 6);
    add_spell("vacuum bolt", "$A");
    set_spell_level("vacuum bolt", 6);
    add_spell("blizzard", "$A");
    set_spell_level("blizzard", 6);
    add_spell("internal flame", "$A");
    set_spell_level("internal flame", 6);
    add_spell("meteor storm", "$A");
    set_spell_level("meteor storm", 6);
*/
/*
string elelore;

    switch(random(14)){
      case 0:elelore="air lore";break;
      case 1:elelore="water lore";break;
      case 2:elelore="earth lore";break;
      case 3:elelore="fire lore";break;
      case 4:elelore="cold lore";break;
      case 5:elelore="wind lore";break;
      case 6:elelore="ice lore";break;
      case 7:elelore="electricity lore";break;
      case 8:elelore="inertia lore";break;
      case 9:elelore="plasma lore";break;
      case 10:elelore="vacid lore";break;
      case 11:elelore="chaos lore";break;
      case 12:elelore="aether lore";break;
      case 13:elelore="nexus lore";break;
    }
    set_skill("elementalism", zspell*zlevel);
    set_skill(elelore, zspell*zlevel);
    force_me("use "+ elelore); 

    set_spell_level("lesser elemental bolt", 6);
    add_spell("lesser elemental bolt", "$A");
    set_spell_level("elemental bolt", 6);
    add_spell("elemental bolt", "$A");
    set_spell_level("lesser elemental strike", 6);
    add_spell("lesser elemental strike", "$A");
    set_spell_level("lesser elemental storm", 6);
    add_spell("lesser elemental storm", "$A");
    set_spell_level("elemental strike", 6);
    add_spell("elemental strike", "$A");
    set_spell_level("greater elemental bolt", 6);
    add_spell("greater elemental bolt", "$A");
    set_spell_level("elemental storm", 6);
    add_spell("elemental storm", "$A"); 
    set_spell_level("greater elemental storm", 6);
    add_spell("greater elemental storm", "$A"); 
    set_spell_level("greater elemental strike", 6);
    add_spell("greater elemental strike", "$A");

    set_spell_level("body of elements", 6);
    add_spell("body of elements", "$(ME)"); 
    set_spell_level("elemental shield", 6);
    add_spell("elemental shield", "$(ME)"); 
    set_spell_level("elemental barrior", 6);
    add_spell("elemental barrior", "$(ME)");
    set_spell_level("elemental pressence", 6);
    add_spell("elemental pressence", "$(ME)"); 
    set_spell_level("elemental aegis", 6);
    add_spell("elemental aegis", "$(ME)"); 
    set_spell_level("elemental transformation", 6);
    add_spell("elemental transformation", "$(ME)"); 

*/
    //set_property("handedness", "right hand");

    //ob = new("/d/damned/virtual/battle-axe_6.weapon");
    //ob = new("/d/damned/virtual/broad-sword_6.weapon");
    //ob = new("/d/damned/virtual/footman's-mace-axe_6.weapon");
    //ob = new("/d/damned/virtual/morning-star_6.weapon");
    //ob = new("/d/damned/virtual/knife_6.weapon");
    //ob = new("/d/damned/virtual/brass-knuckles_6.weapon");

    //ob = new("/d/damned/virtual/two-handed-sword_6.weapon");
    //ob = new("/d/damned/virtual/war-hammer_6.weapon");
    //ob = new("/d/damned/virtual/footman's-flail_6.weapon");
    //ob = new("/d/damned/virtual/halberd_6.weapon");

    //ob->move(this_object());
    force_me("equip");
}

void init()
{
    ::init();
    add_action("no","up");
    add_action("no","down");
}

int no()
{
   if(archp(this_player())) { return 0; }
   if(this_player()->query_ghost()) { this_player()->stop_hunting(); return 0; }
    message("blocking",
      "The Gene Stealer hisses and leaps in front of you, blocking your path.\n",
      this_player());
    message("blocking",
      "The Gene Stealer blocks "+capitalize(this_player()->query_name())+"'s path.\n",
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
