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
   object ob;
   ::create();

    switch(random(17)){
      case 1:woodname="pine";break;
      case 2:woodname="willow";break;
      case 3:woodname="walnut";break;
      case 4:woodname="oak";break;
      case 5:woodname="maple";break;
      case 6:woodname="mahogany";break;
      case 7:woodname="limba";break;
      case 8:woodname="ironwood";break;
      case 9:woodname="gum";break;
      case 10:woodname="elm";break;
      case 11:woodname="dogwood";break;
      case 12:woodname="coachwood";break;
      case 13:woodname="buckeye";break;
      case 14:woodname="birch";break;
      case 15:woodname="aspen";break;
      case 16:woodname="abachi";break;
    }

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
    switch(random(13)){
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
      case 11:damage1="holy";break;
      case 12:damage1="infernal";break;
    }
    switch(random(13)){
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
      case 11:damage2="unholy";break;
      case 12:damage2="aether";break;
    }

    switch(random(6)){
      case 0:quality="1";break;
      case 1:quality="2";break;
      case 2:quality="3";break;
      case 3:quality="4";break;
      case 4:quality="5";break;
      case 5:quality="6";break;
    }

//controls monsters level
    zlevel = (50+random(10));
//Controls Loot level and other fucntions do to raise to high multpies loot
    lvl = 2;
//Controls critical hit reduction and other such
    llvl = 2;
//controls skill levels 2 multipliers controlled indepdent of level
    zskill = 8;
//controls stats like STR, CON
    zskillx = 6;
//controlls skill% spell level
    zspell = 7;
//controls ac * level
    zskillac = 5;


    set_level(zlevel);

set_name("Troll King");
   set("id", ({"troll king", "troll", "king" }) );
   set("long",@ext This is a Troll King!
ext);
   set_short("["+zlevel+"]Troll King");    
  
   set("race", "human");
   set_body_type("humanoid");
   set_gender("male");

   set_alignment(-100);

   set_overall_ac(zlevel*zskillac);
   set_property("magic resistance", zlevel/2);
   set_skill("resist stun", zlevel*zskillac);
   set_property("enhance criticals",-llvl);


   set_melee_damage(([ "crushing" : zlevel, damage1 : zlevel, damage2 : zlevel ]));

   set_money("mithril", random(zlevel*lvl)+zlevel);
   //set_money("gold", random(zlevel*lvl)+zlevel); 
   //set_money("silver", random(zlevel*lvl)+zlevel);  
   //set_money("copper", random(zlevel*lvl)+zlevel); 

   set("gang bang", 1);
   set("aggressive", 1);

    set_casting_chance(10);
    set_combat_chance(200);



   set_hp(zlevel*250 + zlevel*2);
   set_max_hp(zlevel*250 + zlevel*2);
    //set_hp(100);
    //set_max_hp(100);
    //set_max_mp(7000);
    //set_mp(7000);

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
/* 
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
    set_property("handedness", "right hand");

    //ob = new("/d/damned/virtual/battle-axe_6.weapon");
    //ob = new("/d/damned/virtual/broad-sword_6.weapon");
    //ob = new("/d/damned/virtual/war-hammer_6.weapon");


    //ob->move(this_object());
/*
    ob->set_ac(200);
    ob->set_name("sasa stick");
    ob->set("id", ({ "stick", "sasa stick"}));
    ob->set_short("%^BLUE%^Sasa Stick%^RESET%^");
    ob->set_long("This is a large stick that Sasa uses to beat you with.");
    ob->set_quality(6);
    ob->set_type("blunt");
    ob->set_weight(10);
    ob->set_material("metal/eog");
    ob->set_value(10000);
*/
/*
    ob->set_wc(10 ,"aether");
    ob->set_wc(10 ,"infernal");
    ob->set_wc(10 ,"unholy");
    ob->set_wc(10 ,"holy");
    ob->set_wc(10 ,"plasma");
    ob->set_wc(10 ,"disruption");
    ob->set_wc(10 ,"electricity");

    ob->set_wc(25 ,"vacuum");
    ob->set_wc(25 ,"cold");
    ob->set_wc(25 ,"fire");
    ob->set_wc(25 ,"stress");
    ob->set_wc(25 ,"impact");
    ob->set_wc(25 ,"strike");
    ob->set_wc(25 ,"impaling");
    ob->set_wc(25 ,"cutting");
    ob->set_wc(25 ,"crushing");
*/
/*

    ob->set_enh_critical(100);
    ob->set_property("hit bonus", 100);
*/
/*
ob->set_property("auto critical", ([ "crushing A" : 50,"crushing B" : 50,"fire A" : 100, ]));
*/
/*
	//ob->set_property("no decay",1);
    //ob->set_decay_rate(10000);
    //ob->set_property("brittle", 200);
    //ob->set_verb("beat");
*/

/*
    ob = new("/d/damned/virtual/robe.armour");
    //ob = new("/d/1tlny/loot/hooded_robe");
    ob->set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg", "right foot", "left foot", "head", "left hand", "right hand"  }));
    ob->set_enh_critical(-2);
    ob->move(this_object());    
    ob->set_ac(100);


    ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" shield of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());    
    ob->set_ac(100);
*/
    ob = new("/d/damned/virtual/chain-mail.armour");
    ob->move(this_object());    
    ob->set_ac(zlevel*zskill);
    ob = new("/d/damned/virtual/plate-greaves.armour");
    ob->move(this_object());    
    ob->set_ac(zlevel*zskill);
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob->move(this_object());    
    ob->set_ac(zlevel*zskill);
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob->move(this_object());    
    ob->set_ac(zlevel*zskill);
    ob = new("/d/damned/virtual/great-helm.armour");
    ob->move(this_object());    
    ob->set_ac(zlevel*zskill);
    ob = new("/d/damned/virtual/metal-boots.armour");
    ob->move(this_object());    
    ob->set_ac(zlevel*zskill);
    ob = new("/d/damned/virtual/gauntlet.armour");
    ob->move(this_object());    
    ob->set_ac(zlevel*zskill);
    ob = new("/d/damned/virtual/gauntlet.armour");
    ob->move(this_object());    
    ob->set_ac(zlevel*zskill);
    force_me("equip");
}


void die(object ob) {

switch(random(100)){

	case 0:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/great-helm.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Helm of "+damage1+" and "+damage2+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Helm of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 1:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/gauntlet.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Gauntlet of "+damage1+" and "+damage2+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Gauntlet of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 2: 
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/chain-mail.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Mail of "+damage1+" and "+damage2+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Mail of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 3:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/metal-boots.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Boots of "+damage1+" and "+damage2+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Boots of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 4:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Shield of "+damage1+" and "+damage2+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Shield of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 5:  
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/plate-greaves.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Greaves of "+damage1+" and "+damage2+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Greaves of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 6:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Bracer of "+damage1+" and "+damage2+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Bracer of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 7:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());  
    ob = new("/d/damned/virtual/broad-sword_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Broad Sword of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Broad Sword of "+damage1+" and "+damage2);
    ob->move(this_object());
    ob->set_wc(zlevel+random(zlevel*lvl));      
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 8:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/footman's-mace_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Footman's Mace of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Footman's Mace of "+damage1+" and "+damage2);
    ob->move(this_object());
    ob->set_wc(zlevel+random(zlevel*lvl));      
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 9: 
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/battle-axe_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Battle Axe of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Battle Axe of "+damage1+" and "+damage2);
    ob->move(this_object());
    ob->set_wc(zlevel+random(zlevel*lvl));      
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 10:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/knife_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Knife of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Knife of "+damage1+" and "+damage2);
    ob->move(this_object());     
    ob->set_wc(zlevel+random(zlevel*lvl));
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 11:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/brass-knuckles_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Brass Knuckles of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Brass Knuckles of "+damage1+" and "+damage2);
    ob->move(this_object());     
    ob->set_wc(zlevel+random(zlevel*lvl));
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 12:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/two-handed-sword_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Two Handed Sword of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Two Handed Sword of "+damage1+" and "+damage2);
    ob->move(this_object());     
    ob->set_wc(zlevel+random(zlevel*lvl));
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 13:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/war-hammer_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" War Hammer of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" War Hammer of "+damage1+" and "+damage2);
    ob->move(this_object());     
    ob->set_wc(zlevel+random(zlevel*lvl));
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 14:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/footman's-flail_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Footman's Flail of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Footman's Flail of "+damage1+" and "+damage2);
    ob->move(this_object());     
    ob->set_wc(zlevel+random(zlevel*lvl));
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 15:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/halberd_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Halberd of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Halberd of "+damage1+" and "+damage2);
    ob->move(this_object());     
    ob->set_wc(zlevel+random(zlevel*lvl));
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 16:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/shod-staff_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" Shod-Staff of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" Shod-Staff of "+damage1+" and "+damage2);
    ob->move(this_object());     
    ob->set_wc(zlevel+random(zlevel*lvl));
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 17:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
 ob = new("/std/diewarzau/obj/misc/ingot");
    ob->set_material("metal/"+mtlname);
   ob->move(this_object());
break;
    }

switch(random(10)){
    case 1:
message("info","%^COLOR222%^A extra ingot drops on the corpse you should probably LOOK at corpse and get it%^RESET%^", environment(this_object()), this_object());
 ob = new("/std/diewarzau/obj/misc/ingot");
    ob->set_material("metal/"+mtlname);
   ob->move(this_object());
}
switch(random(100)){
    case 99:
message("info","%^COLOR200%^Very Rare loot drops on the corpse you should probably LOOK at corpse and get it%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/1tlny/loot/hooded_robe");
    ob -> set_property("new desc", "level["+zlevel+"] Rare Robe of "+damage1+" and "+damage2+" protection");
    ob -> set_property("extra long", "level["+zlevel+"] Rare Robe of "+damage1+" and "+damage2+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);  
    ob->move(this_object());
//new code to move to room instead of on corpse
    //ob->move(environment(this_object()));  
}


switch(random(110)){
    case 88:
message("info","%^COLOR200%^Very Rare loot drops on the corpse you should probably LOOK at corpse and get it%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/1tlny/loot/ring_troll_king");
    ob -> set_property("new desc", "level["+zlevel+"] Rare Ring of "+damage1+" and "+damage2+" protection");
    ob -> set_property("extra long", "level["+zlevel+"] Rare Ring of "+damage1+" and "+damage2+" protection");
    ob -> set_property("znum", lvl*2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);  
    ob->move(this_object());  
}

   ::die();
}


