#include <std.h>
#include "../a1.h"

inherit MONSTER;
string mtlname;
string damage1;
string damage2;
string elelore;
int zlevel, lvl, llvl, zskill, zskillx, zskillac, zspell;
 
void create() {
   //object ob;
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

    zlevel = (60+random(5));
    lvl = 1;
    llvl = 2;
    zskill = 8;
    zskillx = 6;
    zskillac = 5;
    zspell = 7;

    set_level(zlevel);

   set_overall_ac(zlevel*zskillac+random(zlevel));
   set_property("magic resistance", zlevel*zskillx+random(zlevel));
   set_skill("resist stun", zlevel*zskillx+random(zlevel));
   set_property("enhance criticals",-llvl);

   set_melee_damage(([ "crushing" : zlevel, damage1 : zlevel, damage2 : zlevel ]));

   set_money("mithril", random(zlevel*lvl)+zlevel); 


set_name("dragon");
   set("id", ({ "dragon", "Dragon", "mithril dragon", "ancient dragon", "ancient", "mithril" }));
   set("long",
	"Scales ripple as powerful muscles move beneath the skin of this large "+
	"dragon.  The heat that ripples from his body gives evidence to the fire "+
	"contained within.  Massive large claws as long as swords and sharp teeth "+
	"only serve to add to this creatures powerful arsenal.");
   set_short("["+zlevel+"]Ancient %^RESET%^%^COLOR231%^%^B_RED%^Mithril%^RESET%^ Dragon");
  
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
   set_alignment(100);

   set("gang bang", 1);
   set("aggressive", 1);

   set_hp(zlevel*350 + zlevel*2);
   set_max_hp(zlevel*350 + zlevel*2);
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

    set_skill("parry", zskillx*zlevel+random(zlevel));
    set_skill("dodge", zskillx*zlevel+random(zlevel));
    set_skill("block", zskillx*zlevel+random(zlevel));

    set_skill("combo", zskillx*zlevel+random(zlevel));
    set_skill("reverse stroke", zskillx*zlevel+random(zlevel));
    set_skill("perception", zskillx*zlevel+random(zlevel));

    set_combat_chance(100);


    set_skill("martial arts",zskillx*zlevel+random(zlevel));
    set_skill("shield bash", zskillx*zlevel+random(zlevel));
    set_skill("reverse stroke", zskillx*zlevel+random(zlevel)); 
    set_skill("defense", zskillx*zlevel+random(zlevel));
    set("see invis", 1);

    set_skill("concentrate", zskillx*zlevel+random(zlevel));
    force_me("use concentrate");
/*
    set_skill("conjuration", zspell*zlevel+random(zlevel));
    set_skill("prayer", zspell*zlevel+random(zlevel));
    set_spell_level("explosive fireball", 6);
    set_spell_level("internal flame",6);
    add_spell("explosive fireball","$A");
    add_spell("internal flame", "$A");
*/
/*
   set_skill("illusionism", zspell*zlevel+random(zlevel));
   set_skill("conjuration", zspell*zlevel+random(zlevel));
   set_skill("necromancy", zspell*zlevel+random(zlevel));
   set_skill("concentrate", zspell*zlevel+random(zlevel));
   add_spell("curse", "$A");
   set_spell_level("curse", 6);
   add_spell("lightning bolt", "$A");
   set_spell_level("lightning bolt", 6);
*/
    switch(random(7)){
      case 0:elelore="electricity lore";break;
      case 1:elelore="inertia lore";break;
      case 2:elelore="plasma lore";break;
      case 3:elelore="vacid lore";break;
      case 4:elelore="chaos lore";break;
      case 5:elelore="aether lore";break;
      case 6:elelore="nexus lore";break;
    }
    set_skill("elementalism", zspell*zlevel);
    set_skill(elelore, zspell*zlevel);
    force_me("use "+ elelore); 

    set_spell_level("greater elemental strike", 6);
    add_spell("greater elemental strike", "$A");
    set_spell_level("greater elemental storm", 6);
    add_spell("greater elemental storm", "$A");

    set_spell_level("whelp summon", 6);
    add_spell("whelp summon", "$A");

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
      force_me("cast *5 greater elemental bolt at
"+(string)plyr->query_name());
    }
    return;
  }
  if(str == "YOU CAN MOVE AGAIN!!!" && !query_casting() &&
(inv=query_attackers())) {
    if(sizeof(inv) >= 3)
      force_me("cast *5 greater elemental storm");
    else if(sizeof(inv))
      force_me("cast *5 greater elemental bolt at "+
        (string)inv[0]->query_name());
  }
  return;
}
*/

void init()
{
    ::init();
    add_action("no","north");
    add_action("no","south");
    //add_action("no","east");
    //add_action("no","west");
    //add_action("no","enter");
    //add_action("no","northeast");
    //add_action("no","northwest");
}

int no()
{
    if(wizardp(this_player())) return 0;
   if(this_player()->query_ghost()) return 0;
else
    message("blocking",
      "The Ancient Dragon roars at you, and quickly jumps in front of you blocking your path.\n",
      this_player());
    message("blocking",
      "The Ancient Dragon roars blocking "+capitalize(this_player()->query_name())+"'s path.\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}


void die(object ob) {

switch(random(75)){

	case 0:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/great-helm.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" helm of "+damage1+" and "+damage2+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" helm of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 1:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/gauntlet.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" gauntlet of "+damage1+" and "+damage2+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" gauntlet of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 2: 
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/chain-mail.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" mail of "+damage1+" and "+damage2+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" mail of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 3:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/metal-boots.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" boots of "+damage1+" and "+damage2+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" boots of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 4:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" shield of "+damage1+" and "+damage2+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" shield of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 5:  
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/plate-greaves.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" greaves of "+damage1+" and "+damage2+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" greaves of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 6:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" bracer of "+damage1+" and "+damage2+" protection");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" bracer of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 7:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());  
    ob = new("/d/damned/virtual/broad-sword_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" broad-sword of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" broad-sword of "+damage1+" and "+damage2);
    ob->move(this_object());
    ob->set_wc(zlevel+random(zlevel*lvl));      
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 8:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/knife_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" knife of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" knife of "+damage1+" and "+damage2);
    ob->move(this_object());
    ob->set_wc(zlevel+random(zlevel*lvl));      
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 9:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/footman's-mace_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" footman's-mace of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" footman's-mace of "+damage1+" and "+damage2);
    ob->move(this_object());
    ob->set_wc(zlevel+random(zlevel*lvl));      
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 10: 
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/battle-axe_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" battle-axe of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" battle-axe of "+damage1+" and "+damage2);
    ob->move(this_object());
    ob->set_wc(zlevel+random(zlevel*lvl));      
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 11:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/two-handed-sword_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" two-handed-sword of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" two-handed-sword of "+damage1+" and "+damage2);
    ob->move(this_object());
    ob->set_wc(zlevel+random(zlevel*lvl));      
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 12:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/war-hammer_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" war-hammer of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" war-hammer of "+damage1+" and "+damage2);
    ob->move(this_object());
    ob->set_wc(zlevel+random(zlevel*lvl));      
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 13:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/greate-axe_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" great-axe of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" great-axe of "+damage1+" and "+damage2);
    ob->move(this_object());
    ob->set_wc(zlevel+random(zlevel*lvl));      
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 14:
message("info","%^BLACK%^%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/shod-staff_6.weapon");
    ob -> set_property("new desc", "level["+zlevel+"] "+mtlname+" shod-staff of "+damage1+" and "+damage2);
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" shod-staff of "+damage1+" and "+damage2);
    ob->move(this_object());     
    ob->set_wc(zlevel+random(zlevel*lvl));
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage1);
    ob -> set_wc(zlevel+random(zlevel*lvl)+random(llvl+lvl+(llvl*llvl)), damage2);
    ob->set_material("metal/"+mtlname);
	break;
	case 15:
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
}
   ::die();
}
