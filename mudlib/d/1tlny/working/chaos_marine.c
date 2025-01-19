#include <std.h>

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

    zlevel = (60+random(5));
    lvl = 1;
    llvl = 2;
    zskill = 8;
    zskillx = 6;
    zskillac = 5;
    zspell = 7;

    set_level(zlevel);

   set_overall_ac(zlevel*zskillac);
   set_property("magic resistance", zlevel/2);
   set_skill("resist stun", zlevel*zskillx);
   set_property("enhance criticals",-llvl);

   set_melee_damage(([ "crushing" : zlevel, damage1 : zlevel, damage2 : zlevel ]));

   set_money("mithril", random(zlevel*lvl)+zlevel); 

set_name("Chaos Marine");
   set("id", ({"chaos", "marine", "chaos marine" }) );
   set("long",@ext Chaos Space Marines, also sometimes called Traitor Marines, Renegade Marines, or Heretic Astartes, are former Loyalist Space Marines of the Imperium of Man who have chosen to abandon the service of the Emperor of Mankind and dedicate themselves to the service of Chaos to achieve their own ends. 
ext);
   set_short("["+zlevel+"]Chaos Marine");    
  
   set("race", "human");
   set_body_type("human");
   set_gender("male");
   set_alignment(100);

   set("gang bang", 1);
   set("aggressive", 1);

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

/*
    set_skill("martial arts",zskillx*zlevel);
    set_skill("shield bash", zskillx*zlevel);
    set_skill("reverse stroke", zskillx*zlevel); 
    set_skill("defense", zskillx*zlevel);
    set("see invis", 1);



  set_skill("conjuration", zspell*zlevel);
   set_skill("prayer", zspell*zlevel);
    set_spell_level("explosive fireball", 6);
   set_spell_level("internal flame",6);
    add_spell("explosive fireball","$A");
   add_spell("internal flame", "$A");

   set_skill("illusionism", zspell*zlevel);
   set_skill("conjuration", zspell*zlevel);
   set_skill("necromancy", zspell*zlevel);
   set_skill("concentrate", zspell*zlevel);
   add_spell("curse", "$A");
   set_spell_level("curse", 6);
   add_spell("lightning bolt", "$A");
   set_spell_level("lightning bolt", 6);
*/

    set_skill("concentrate", zskillx*zlevel);
    force_me("use concentrate");

    set_skill("elementalism", zspell*zlevel);
    set_skill("electricity lore", zspell*zlevel);
    force_me("use electricity lore");
    set_spell_level("greater elemental bolt", 5);
    add_spell("greater elemental bolt", "$A");
    set_spell_level("greater elemental storm", 5);
    add_spell("greater elemental storm", "$A"); 

    set_property("handedness", "right hand");
 
switch(random(4)){
case 0:ob = new("/d/damned/virtual/battle-axe_6.weapon");
    ob -> set("long", @EndText
A Power Axe is a Power Weapon taking the form of a single or double-edged battle axe. Power Axes vary in length and design, and have been known to be crafted from one of any number of different materials, though usually Adamantium. As with all Power Weapons, when its power field is activated, usually by operating a control located on the hilt, the blade is sheathed in a lethal corona of disruptive energy. This energy field allows the blade to carve through flesh, bone and most forms of armour plate alike, making a Power Axe a highly effective close combat weapon.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Power%^RESET%^ Axe");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Power%^RESET%^ Axe
EndText);
    ob->set_wc(zlevel+zlevel ,"plasma");
    ob->set_wc(zlevel , damage1);
    ob->set_wc(zlevel , damage2);
    ob->set_wc(zlevel+zlevel ,"impact");
    ob -> set_material("metal/"+mtlname);
    ob->move(this_object());
ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set("long", @EndText
A Storm Shield is a Power Shield that is used by the Space Marines and sometimes by Inquisitors of the Ordo Malleus to provide an extreme form of protection from ranged weapons fire and potent melee strikes.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Storm%^RESET%^ shield");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Storm%^RESET%^ shield
EndText);
    ob -> set_material("metal/laen");    
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("wear shield on left hand");
	break;
	case 1:ob = new("/d/damned/virtual/broad-sword_6.weapon");
    ob -> set("long", @EndText
Power Swords are used by all members of the Imperial armed forces, including the troops of the Astra Militarum and the Space Marines of the Adeptus Astartes, as well as their Chaos counterparts among the Lost and the Damned and the Chaos Space Marines. Xenos species such as the Aeldari, their evil kin the Drukhari and the Necrons are also known to make use of such weapons.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Power%^RESET%^ Sword");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Power%^RESET%^ Sword
EndText);
    ob->set_wc(zlevel+zlevel ,"plasma");
    ob->set_wc(zlevel , damage1);
    ob->set_wc(zlevel , damage2);
    ob->set_wc(zlevel+zlevel ,"impact");
    ob -> set_material("metal/"+mtlname);
    ob->move(this_object());
ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set("long", @EndText
A Storm Shield is a Power Shield that is used by the Space Marines and sometimes by Inquisitors of the Ordo Malleus to provide an extreme form of protection from ranged weapons fire and potent melee strikes.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Storm%^RESET%^ shield");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Storm%^RESET%^ shield
EndText);
    ob -> set_material("metal/laen");    
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("wear shield on left hand");
	break;
	case 2:ob = new("/d/damned/virtual/knife_6.weapon");
    ob -> set("long", @EndText
A Combat Knife is the ubiquitous back-up melee weapon for warriors all across the Imperium of Man, be they lowly hive city scum or the elite soldiers of a Planetary Governor. 
EndText);
    ob -> set_property("new desc", "%^BOLD%^Combat%^RESET%^ Knife");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Combat%^RESET%^ Knife
EndText);
    ob->set_wc(zlevel+zlevel ,"plasma");
    ob->set_wc(zlevel , damage1);
    ob->set_wc(zlevel , damage2);
    ob->set_wc(zlevel+zlevel ,"impact");
    ob -> set_material("metal/"+mtlname);
    ob->move(this_object());
ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set("long", @EndText
A Storm Shield is a Power Shield that is used by the Space Marines and sometimes by Inquisitors of the Ordo Malleus to provide an extreme form of protection from ranged weapons fire and potent melee strikes.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Storm%^RESET%^ shield");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Storm%^RESET%^ shield
EndText);
    ob -> set_material("metal/laen");    
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("wear shield on left hand");
	break;
	case 3:ob = new("/d/damned/virtual/hammer_6.weapon");
    ob -> set("long", @EndText
Many Battle-Brothers balance the clumsy nature of attempting to parry with a Thunder Hammer by pairing it with a Storm Shield which is surrounded by a glowing blue field of protective energy which emits crackling lightning when the Space Marine parries the blow. 
EndText);
    ob -> set_property("new desc", "%^BOLD%^Thunder%^RESET%^ Hammer");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Thunder%^RESET%^ Hammer
EndText);
    ob->set_wc(zlevel+zlevel ,"plasma");
    ob->set_wc(zlevel , damage1);
    ob->set_wc(zlevel , damage2);
    ob->set_wc(zlevel+zlevel ,"impact");
    ob -> set_material("metal/"+mtlname);
    ob->move(this_object());
ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set("long", @EndText
A Storm Shield is a Power Shield that is used by the Space Marines and sometimes by Inquisitors of the Ordo Malleus to provide an extreme form of protection from ranged weapons fire and potent melee strikes.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Storm%^RESET%^ shield");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Storm%^RESET%^ shield
EndText);
    ob -> set_material("metal/laen");    
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("wear shield on left hand");
	break;
}    

    ob = new("/d/damned/virtual/power-armour.armour");
    ob -> set_property("new desc", "%^BOLD%^Power%^RESET%^ armour");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Power%^RESET%^ armour
EndText);
    ob -> set_material("metal/laen");
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());

    ob = new("/d/damned/virtual/great-helm.armour");
    ob -> set_property("new desc", "%^BOLD%^Power%^RESET%^ helm");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Power%^RESET%^ helm
EndText);
    ob -> set("long", "The armoured reinforced headgear that protects an Astartes head.");
    ob -> set_material("metal/laen");
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("equip");
}

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


void die(object ob) {

switch(random(16)){

	case 0:
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
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
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
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
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
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
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
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
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
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
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
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
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
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
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());   
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
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
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
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
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
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object()); 
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
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
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
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
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
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/damned/virtual/great-axe_6.weapon");
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
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());	
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
message("info","%^B_YELLOW%^Somthing drops on the corpse you should probably LOOK at corpse%^RESET%^", environment(this_object()), this_object());
 ob = new("/std/diewarzau/obj/misc/ingot");
    ob->set_material("metal/"+mtlname);
   ob->move(this_object());
break;
    }


switch(random(100)){
    case 50:
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
