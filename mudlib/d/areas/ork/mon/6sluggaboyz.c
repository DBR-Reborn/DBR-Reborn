#include <std.h>
#include "../a1.h"

inherit MONSTER;
string mtlname;
string damage1;
string damage2;
int zlevel, lvl, llvl, zskill, zskillx, zskillac, zspell;
 
void create() {
   object ob;
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

    zlevel = (92+random(10));
    lvl = 4;
    llvl = 5;
    zskill = 11;
    zskillx = 9;
    zskillac = 8;
    zspell = 10;

    set_level(zlevel);

   set_overall_ac(zlevel*zskillac+random(zlevel));
   set_property("magic resistance", zlevel/2);
   set_skill("resist stun", zlevel*zskillx+random(zlevel));
   set_property("enhance criticals",-llvl);

   set_melee_damage(([ "crushing" : zlevel*zskill*lvl*llvl*2, damage1 : zlevel*zskill*lvl*llvl*2, damage2 : zlevel*zskill*lvl*llvl*2 ]));

   set_money("gold", random(zlevel*lvl)+zlevel); 

set_name("Slugga Boyz");
   set("id", ({ "slugga boyz", "orc", "ork", "sluggas", "choppas", "sluggaboyz", "slugga" }));

 set("long",@ext Slugga Boyz are the most common and typical Ork warriors, and represent what the average Imperial human thinks of when they imagine an Ork. Slugga Boyz are anarchic brutes who love nothing more than a good fight, often leaving a horrific mess of whatever they attack on the battlefield.
ext);

    switch(random(2)){
      case 0:set_short("["+zlevel+"]Slugga Boyz");break;
      case 1:set_short("["+zlevel+"]Sluggas");break;
      case 1:set_short("["+zlevel+"]Choppas");break;
}

  
   set("race", "ork");
   set_body_type("human");
   set_gender("neuter");
   set_alignment(100);

   set("gang bang", 1);
   set("aggressive", 1);

   set_hp(zlevel*250 + zlevel*2);
   set_max_hp(zlevel*250 + zlevel*2);
 //set_hp(100);
 //set_max_hp(100);
    //set_max_mp(7000);
    //set_mp(7000);

    set_stats("strength", zskillx*zlevel+random(zlevel));
    set_stats("dexterity", zskillx*zlevel+random(zlevel));
    set_stats("constitution", zskillx*zlevel+random(zlevel));
    set_stats("wisdom", zskillx*zlevel+random(zlevel));
    set_stats("intelligence", zskillx*zlevel+random(zlevel));
    set_stats("charisma", zskillx*zlevel+random(zlevel));
    
    set_skill("attack", zskill*zlevel+random(zlevel));
    set_skill("two handed blade", zskill*zlevel+random(zlevel));
    set_skill("two handed blunt",  zskill*zlevel+random(zlevel));
    set_skill("two handed flail", zskill*zlevel+random(zlevel));
    set_skill("two handed polearm", zskill*zlevel+random(zlevel));
    set_skill("two handed staff", zskill*zlevel+random(zlevel));
    set_skill("axe", zskill*zlevel+random(zlevel));
    set_skill("blade", zskill*zlevel+random(zlevel));
    set_skill("blunt", zskill*zlevel+random(zlevel));
    set_skill("knife",  zskill*zlevel+random(zlevel));
    set_skill("flail", zskill*zlevel+random(zlevel));
    set_skill("melee", zskillx*zlevel+random(zlevel));

    //set_skill("parry", zskillx*zlevel+random(zlevel));
    //set_skill("dodge", zskillx*zlevel+random(zlevel));
    //set_skill("block", zskillx*zlevel+random(zlevel));

    set_skill("combo", zskillx*zlevel+random(zlevel));
    set_skill("reverse stroke", zskillx*zlevel+random(zlevel));
    set_skill("perception", zskillx*zlevel+random(zlevel));

    set_combat_chance(100);

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

    set_skill("chaos magic", zspell*zlevel);
    add_spell("disruption bolt ", "$A");
    set_spell_level("disruption bolt", 6);
    add_spell("chaos ball", "$A");
    set_spell_level("chaos ball", 6);
    add_spell("chaos storm", "$A");
    set_spell_level("chaos storm", 6);

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
*/
/*

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
    ob = new("/d/areas/ork/obj/choppa");
    //ob->set_enh_critical(8+random(6));
    ob->set_enh_critical(2+random(6));
    ob->set_wc(zlevel*zskill*lvl*llvl, "cutting");
    ob->set_wc(zlevel*zskill*lvl*llvl, damage1);
    ob->set_wc(zlevel*zskill*lvl*llvl, damage2);
    ob->set_property("auto critical", ([ "cutting A" : zlevel/2 ]));
    ob->move(this_object());
    force_me("equip");

    set_property("handedness", "right hand");
 

}
/*
string query_element() { return "electricity"; }

void catch_tell(string str) {
  string who;
  object plyr, *inv;

  str = eliminate_colour(str);
  if(!this_object()->query_casting() && sscanf(str, "%s begins casting a
spell.", who)) {
    if(who == "Someone") {
      inv = all_inventory(environment());
      inv = filter_array(inv, (: call_other :), "is_player");
      inv = filter_array(inv, (: call_other :), "query_invis");
      inv = filter_array(inv, (: call_other :), "query_casting");
      if(!sizeof(inv)) {
        return;
      }
      plyr = inv[0];
    }
    else
      plyr = present(lower_case(who), environment());
    if(!plyr) {
      return;
    }
    if(plyr->is_player() && (int)plyr->query_level() > 15) {
      force_me("cast *6 greater elemental strike at
"+(string)plyr->query_name());
    }
    return;
  }
  if(str == "YOU CAN MOVE AGAIN!!!" && !query_casting() &&
(inv=query_attackers())) {
    if(sizeof(inv) >= 3)
      force_me("cast *6 greater elemental storm");
    else if(sizeof(inv))
      force_me("cast *6 greater elemental strike at "+
        (string)inv[0]->query_name());
  }
  return;
}
*/

void die(object ob) {

   map_array(all_inventory(this_object()), (: call_other :), "remove");

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
    }

switch(random(100)){
    case 44:
message("info","%^COLOR222%^A ingot drops on the corpse you should probably LOOK at corpse and get it%^RESET%^", environment(this_object()), this_object());
 ob = new("/std/diewarzau/obj/misc/ingot");
    ob->set_material("metal/"+mtlname);
    ob->set_value((2*zlevel)+random(zlevel));
    ob->set_weight((2*zlevel)+random(zlevel));
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

   ::die();
}


