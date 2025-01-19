#include <std.h>

inherit MONSTER;
string mtlname;
string damage1;
string damage2;
int zlevel, lvl, llvl, zskill, zskillx, zskillac, zspell;
    mixed desc;
 
void init() {
    :: init();
    add_action("no","north");
    add_action("no","west");
    add_action("no","east");
    add_action("no","south");
    add_action("no","southeast");
    add_action("no","southwest");
    add_action("no","northwest");
    add_action("no","northeast");
}

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

    zlevel = (100+random(51));
//Controls Loot level and other fucntions do to raise to high multpies loot
    lvl = 4;
//Controls critical hit reduction and other such
    llvl = 20;
    zskill = 12;
    zskillx = 10;
    zskillac = 9;
    zspell = 11;


    set_level(zlevel);

   set_overall_ac(zlevel*zskillac+random(zlevel)*2);
   set_property("magic resistance", zlevel/2);
   set_skill("resist stun", zlevel*zskillx);
   set_property("enhance criticals",-llvl*2);


   set_melee_damage(([ "crushing" : zlevel*zskill*lvl*llvl*2, damage1 : zlevel*zskill*lvl*llvl*2, damage2 : zlevel*zskill*lvl*llvl*2 ]));

   set_money("mithril", random(zlevel*lvl)+zlevel); 

set_name("Shadowflame Templar");
set("id", ({ "templar", "shadowflame templar", "shadow flame templar", "shadow and flame templar", "armoured templar", "armoured templar covered in shadow and flame", "undead" }));
   set("long",@ext 
This armoured behemoth has to be one of the most imposing warriors you have ever laid eyes upon. Equipped from top to bottom in dark purple gear and also with a shimmering halberd, it appears blatantly evident that it was given life for the purpose of nothing less than the most extreme of combat. A thin and barely visible aura of darkness and flame emanates from the entirety of the armour. suggesting that something more than just hearing a clang would happen to aggressor if it was struck by weapons.
ext);

switch(random(4)){
	case 0:set_short("["+zlevel+"]Armoured Templar Covered in %^BLUE%^Shadow%^BOLD%^%^RED%^ and %^ORANGE%^Flame%^BOLD%^%^RED%^%^RESET%^");    
	break;
	case 1:set_short("["+zlevel+"]Armoured Templar Covered in %^RED%^Blood%^BOLD%^%^RED%^ and %^YELLOW%^Gore%^BOLD%^%^RED%^%^RESET%^");
	break;
	case 2:set_short("["+zlevel+"]Armoured Templar Covered in %^CYAN%^Dark%^BOLD%^%^RED%^ and %^WHITE%^Light%^BOLD%^%^RED%^%^RESET%^");
	break;
	case 3:set_short("["+zlevel+"]Armoured Templar Covered in %^BOLD%^%^BLACK%^Hate%^BOLD%^%^RED%^ and %^MAGENTA%^Blaze%^BOLD%^%^RED%^%^RESET%^");
}  
  
   set("race", "undead");
   set_body_type("humanoid");
   set_gender("male");
   set_alignment(100);

   set("gang bang", 1);
   set("aggressive", 1);

   set_hp(zlevel*550 + zlevel*2);
   set_max_hp(zlevel*550 + zlevel*2);
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

    //set_skill("parry", zskillx*zlevel);
    //set_skill("dodge", zskillx*zlevel);
    //set_skill("block", zskillx*zlevel);

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

    set_skill("concentrate", zskillx*zlevel);
    force_me("use concentrate");

    set_skill("necromancy", zspell*zlevel);
    add_spell("curse", "$A");
    set_spell_level("curse", 6);
    add_spell("lifesteal", "$A");
    set_spell_level("lifesteal", 6);
    add_spell("decay", "$A");
    set_spell_level("decay", 6);
*/
/*
    set_skill("chaos magic", zspell*zlevel);
    add_spell("chaos storm", "$A");
    set_spell_level("chaos storm", 6);
*/
/*

   set_skill("prayer", zspell*zlevel);
    add_spell("wrath of god", "$A");
    set_spell_level("wrath of god", 6);
    add_spell("holy condemnation", "$A");
    set_spell_level("holy condemnation", 6);
    add_spell("mass heal", "$A");
    set_spell_level("mass heal", 6);
    set_skill("lay on hands", zskill*zlevel);

   set_skill("magery", zspell*zlevel);
    add_spell("slow", "$A");
    set_spell_level("slow", 6);

   set_skill("conjuration", zspell*zlevel);
    add_spell("magic missile", "$A");
    set_spell_level("magic missile", 6);
    add_spell("lightning bolt", "$A");
    set_spell_level("lightning bolt", 6);
    add_spell("explosive fireball", "$A");
    set_spell_level("explosive fireball", 6);
    add_spell("internal flame", "$A");
    set_spell_level("internal flame", 6);
    add_spell("blizzard", "$A");
    set_spell_level("blizzard", 6);
    add_spell("meteor storm", "$A");
    set_spell_level("meteor storm", 6);

   set_skill("illusionism", zspell*zlevel);
*/
/*
string elelore;

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

    set_spell_level("greater elemental bolt", 6);
    add_spell("greater elemental bolt", "$A");
    set_spell_level("greater elemental strike", 6);
    add_spell("greater elemental strike", "$A");
    set_spell_level("greater elemental storm", 6);
    add_spell("greater elemental storm", "$A"); 
*/
/*
switch(random(8)){
	case 0:ob = new("/std/spells/shadows/ele_pres_shad");
    ob->set_power(1);
    ob->set_damage(({ "unholy", "fire" }));
    ob->set_shadow_name("shadowflame Presence");
    ob->start_shadow(this_object(), 2000000000, "");
	break;
	case 1:ob = new("/d/areas/beholders/spells/shadow_shield.c");
    ob->set_damage_allowed(25000);
    ob->set_shadow_name("Templar shield");
    ob->start_shadow(this_object(), 2000000000, "");
	break;
	case 2:ob = new("/d/areas/beholders/spells/shadow_shield.c");
    ob->set_damage_allowed(25000);
    ob->set_shadow_name("Templar shield");
    ob->start_shadow(this_object(), 2000000000, "");
	break;
	case 3:ob = new("/std/spells/shadows/ele_pres_shad");
    ob->set_power(4);
    ob->set_damage(({ damage1, damage2 }));
    ob->set_shadow_name("shadowflame Presence");
    ob->start_shadow(this_object(), 2000000000, "");
}
*/
/*
switch(random(10)){
	case 5:ob = new("/d/areas/beholders/spells/shadow_shield.c");
    ob->set_damage_allowed(25000);
    ob->set_shadow_name("Templar shield");
    ob->start_shadow(this_object(), 2000000000, "");
}
*/





    set_property("handedness", "right hand");

switch(random(4)){
case 0:ob = new("d/areas/beholders/obj/axe");
    ob -> set("long", @EndText
The blade has a large, warped cross-guard, adding just enough weight to make sure the blade sits firmly in the owner's hand and protecting those same hands as well. The cross-guard has a jeweled cross on each side, a clear sign this weapon belongs to a champion.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Templar%^RESET%^ Axe");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Templar%^RESET%^ Axe
EndText);
    ob->set_enh_critical(11+random(6));
    ob->set_wc(zlevel*zskill*lvl*llvl, "cutting");
    ob->set_wc(zlevel*zskill*lvl*llvl ,"impact");
    ob->set_wc(zlevel*zskill*lvl*llvl, damage1);
    ob->set_wc(zlevel*zskill*lvl*llvl, damage2);
    ob->set_property("auto critical", ([ "cutting A" : zlevel/2 ]));
    ob -> set_material("metal/"+mtlname);
    ob->move(this_object());
ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set("long", @EndText
This tenacious Greek-style shield, made from ebonsteel, offers a stable barricade, especially against lunging attacks and coordinated attacks.
This isn't a mere fluke, as this shield was forged by enigma goblins in a storm workshop.

The shield's edges are reinforced with a thick metal lining and have been decorated with a scaly texture.
Its center is garnished with several gem stones and painted symbols.

It's clear this shield is naive to the ways of war. As if carefully looked after, who knows if this shield will ever know the glory of victory, but one this is for sure: glory shall come to this shield in one way or another.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Templar%^RESET%^ shield");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Templar%^RESET%^ shield
EndText);
    ob -> set_material("metal/laen");    
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("wear shield on left hand");
	break;
	case 1:ob = new("d/areas/beholders/obj/sword");
    ob -> set("long", @EndText
A fairly small, thick, smooth blade made of ivory is held by a grip wrapped in fairly common, dark brown deerskin.
With just one razor-sharp edge this weapon is the perfect choice for slicing and dicing while also offering you a way to effectively block attacks.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Templar%^RESET%^ Sword");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Templar%^RESET%^ Sword
EndText);
    ob->set_enh_critical(11+random(6));
    ob->set_wc(zlevel*zskill*lvl*llvl, "cutting");
    ob->set_wc(zlevel*zskill*lvl*llvl ,"impact");
    ob->set_wc(zlevel*zskill*lvl*llvl, damage1);
    ob->set_wc(zlevel*zskill*lvl*llvl, damage2);
    ob->set_property("auto critical", ([ "cutting A" : zlevel/2 ]));
    ob -> set_material("metal/"+mtlname);
    ob->move(this_object());
ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set("long", @EndText
This tenacious Greek-style shield, made from ebonsteel, offers a stable barricade, especially against lunging attacks and coordinated attacks.
This isn't a mere fluke, as this shield was forged by enigma goblins in a storm workshop.

The shield's edges are reinforced with a thick metal lining and have been decorated with a scaly texture.
Its center is garnished with several gem stones and painted symbols.

It's clear this shield is naive to the ways of war. As if carefully looked after, who knows if this shield will ever know the glory of victory, but one this is for sure: glory shall come to this shield in one way or another.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Templar%^RESET%^ shield");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Templar%^RESET%^ shield
EndText);
    ob -> set_material("metal/laen");    
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("wear shield on left hand");
	break;
	case 2:ob = new("d/areas/beholders/obj/knife");
    ob -> set("long", @EndText
A Templar Knife is a scary weapon
EndText);
    ob -> set_property("new desc", "%^BOLD%^Templar%^RESET%^ Knife");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Templar%^RESET%^ Knife
EndText);
    ob->set_enh_critical(11+random(6));
    ob->set_wc(zlevel*zskill*lvl*llvl, "cutting");
    ob->set_wc(zlevel*zskill*lvl*llvl ,"impaling");
    ob->set_wc(zlevel*zskill*lvl*llvl, damage1);
    ob->set_wc(zlevel*zskill*lvl*llvl, damage2);
    ob->set_property("auto critical", ([ "impaling A" : zlevel/2 ]));
    ob -> set_material("metal/"+mtlname);
    ob->move(this_object());
ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set("long", @EndText
This tenacious Greek-style shield, made from ebonsteel, offers a stable barricade, especially against lunging attacks and coordinated attacks.
This isn't a mere fluke, as this shield was forged by enigma goblins in a storm workshop.

The shield's edges are reinforced with a thick metal lining and have been decorated with a scaly texture.
Its center is garnished with several gem stones and painted symbols.

It's clear this shield is naive to the ways of war. As if carefully looked after, who knows if this shield will ever know the glory of victory, but one this is for sure: glory shall come to this shield in one way or another.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Templar%^RESET%^ shield");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Templar%^RESET%^ shield
EndText);
    ob -> set_material("metal/laen");    
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("wear shield on left hand");
	break;
	case 3:ob = new("d/areas/beholders/obj/hammer");
    ob -> set("long", @EndText
Many Battle-Brothers balance the clumsy nature of attempting to parry with a Thunder Hammer by pairing it with a Storm Shield which is surrounded by a glowing blue field of protective energy which emits crackling lightning when the Space Marine parries the blow. 
EndText);
    ob -> set_property("new desc", "%^BOLD%^Templar%^RESET%^ Hammer");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Templar%^RESET%^ Hammer
EndText);
    ob->set_enh_critical(11+random(6));
    ob->set_wc(zlevel*zskill*lvl*llvl, "crushing");
    ob->set_wc(zlevel*zskill*lvl*llvl ,"impact");
    ob->set_wc(zlevel*zskill*lvl*llvl, damage1);
    ob->set_wc(zlevel*zskill*lvl*llvl, damage2);
    ob->set_property("auto critical", ([ "crushing A" : zlevel/2 ]));
    ob -> set_material("metal/"+mtlname);
    ob->move(this_object());
ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set("long", @EndText
This tenacious Greek-style shield, made from ebonsteel, offers a stable barricade, especially against lunging attacks and coordinated attacks.
This isn't a mere fluke, as this shield was forged by enigma goblins in a storm workshop.

The shield's edges are reinforced with a thick metal lining and have been decorated with a scaly texture.
Its center is garnished with several gem stones and painted symbols.

It's clear this shield is naive to the ways of war. As if carefully looked after, who knows if this shield will ever know the glory of victory, but one this is for sure: glory shall come to this shield in one way or another.
EndText);
    ob -> set_property("new desc", "%^BOLD%^Templar%^RESET%^ shield");
    ob -> set_short((string)ob->query_property("new desc"));
    ob -> set_property("extra long", @EndText
%^BOLD%^Templar%^RESET%^ shield
EndText);
    ob -> set_material("metal/laen");    
    ob->set_ac(zlevel+zlevel);
    ob->move(this_object());
    force_me("wear shield on left hand");
	break;
}    


    ob = new("/d/damned/virtual/chain-mail.armour");
    ob -> set_material("metal/"+mtlname);
    ob->set_enh_critical(-1*(random(4)+1)); 
    ob->move(this_object());    
    ob->set_ac(zlevel+zlevel);
    ob = new("/d/damned/virtual/plate-greaves.armour");
    ob -> set_material("metal/"+mtlname);
    ob->set_enh_critical(-1*(random(4)+1)); 
    ob->move(this_object());    
    ob->set_ac(zlevel+zlevel);
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob -> set_material("metal/"+mtlname);
    ob->set_enh_critical(-1*(random(4)+1)); 
    ob->move(this_object());    
    ob->set_ac(zlevel+zlevel);
    ob = new("/d/damned/virtual/plate-bracer.armour");
    ob -> set_material("metal/"+mtlname);
    ob->set_enh_critical(-1*(random(4)+1)); 
    ob->move(this_object());    
    ob->set_ac(zlevel+zlevel);
    ob = new("/d/damned/virtual/great-helm.armour");
    ob -> set_material("metal/"+mtlname);
    ob->set_enh_critical(-1*(random(4)+1)); 
    ob->move(this_object());    
    ob->set_ac(zlevel+zlevel);
    ob = new("/d/damned/virtual/metal-boots.armour");
    ob -> set_material("metal/"+mtlname);
    ob->set_enh_critical(-1*(random(4)+1)); 
    ob->move(this_object());    
    ob->set_ac(zlevel+zlevel);
    ob = new("/d/damned/virtual/gauntlet.armour");
    ob -> set_material("metal/"+mtlname);
    ob->set_enh_critical(-1*(random(4)+1));
    ob->move(this_object());    
    ob->set_ac(zlevel+zlevel);
    ob = new("/d/damned/virtual/gauntlet.armour");
    ob -> set_material("metal/"+mtlname);
    ob->set_enh_critical(-1*(random(4)+1)); 
    ob->move(this_object());    
    ob->set_ac(zlevel+zlevel);
    ob = new("/d/1tlny/loot/hooded_robe");
    ob->set_enh_critical(-1*(random(4)+1)); 
    ob->move(this_object());    
    ob->set_ac(zlevel+zlevel);
    force_me("equip");

 


 
    //ob = new("/d/damned/virtual/brass-knuckles_6.weapon");
    //ob = new("/d/damned/virtual/bokken_6.weapon");
    //ob = new("/d/damned/virtual/military-pick_6.weapon");
    //ob = new("/d/damned/virtual/wooden-axe_6.weapon");
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

    ob->set_wc(555 ,"aether");
    ob->set_wc(555 ,"infernal");
    ob->set_wc(555 ,"unholy");
    ob->set_wc(555 ,"holy");
    ob->set_wc(555 ,"plasma");
    ob->set_wc(555 ,"disruption");
    ob->set_wc(555 ,"electricity");
    ob->set_wc(555 ,"vacuum");
    ob->set_wc(555 ,"cold");
    ob->set_wc(555 ,"fire");
    ob->set_wc(555 ,"stress");
    ob->set_wc(555 ,"impact");
    ob->set_wc(555 ,"strike");
    ob->set_wc(555 ,"impaling");
    ob->set_wc(555 ,"cutting");
    ob->set_wc(555 ,"crushing");

    ob->set_enh_critical(1000);
    ob->set_property("hit bonus", 300);
    ob->set_property("auto critical", ([ "a1 E" : 1000,"a1 D" : 1000,"a1 C" : 1000, ]));

	ob->set_auto_critical("a1 A");
	ob->set_auto_critical("a1 B");
*/
	  //ob->set_property("no decay",1);
    //ob->set_decay_rate(100000);
    //ob->set_property("brittle", 600);
    //ob->set_verb("beat");

/*
    ob = new("/d/damned/virtual/large-shield.armour");
    ob -> set_property("extra long","level["+zlevel+"] "+mtlname+" shield of "+damage1+" and "+damage2+" protection");
    ob->move(this_object());    
    ob->set_ac(59500);
*/    
    force_me("equip");
}

void die(object ob) {

   map_array(all_inventory(this_object()), (: call_other :), "remove");

switch(random(300)){

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
message("info","%^COLOR222%^A extra ingot drops on the corpse you should probably LOOK at corpse and get it%^RESET%^", environment(this_object()), this_object());
 ob = new("/std/diewarzau/obj/misc/ingot");
    ob->set_material("metal/"+mtlname);
    ob->set_value((2*zlevel)+random(zlevel));
    ob->set_weight((2*zlevel)+random(zlevel));
   ob->move(this_object());
break;
    }

switch(random(100)){
    case 1:
message("info","%^COLOR222%^A extra ingot drops on the corpse you should probably LOOK at corpse and get it%^RESET%^", environment(this_object()), this_object());
 ob = new("/std/diewarzau/obj/misc/ingot");
    ob->set_material("metal/"+mtlname);
   ob->move(this_object());
}
/*
switch(random(1000)){
    case 998:
message("info","%^COLOR200%^Very Rare loot drops on the corpse you should probably LOOK at corpse and get it%^RESET%^", environment(this_object()), this_object());
    ob = new("/d/1tlny/loot/multi_stat_ring");
    ob -> set_property("new desc", "level["+zlevel+"] Rare Ring of "+damage1+" and "+damage2+" protection");
    ob -> set_property("extra long", "level["+zlevel+"] Rare Ring of "+damage1+" and "+damage2+" protection");
    ob -> set_property("znum", 10);
    ob -> set_short((string)ob->query_property("new desc"));
    ob->set_ac(zlevel*lvl+random(zlevel*lvl));      
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage1);
    ob -> set_ac(zlevel*(llvl+lvl)+random(zlevel*lvl), damage2);  
    ob->move(this_object());  
}
*/
   ::die();
}

int no()
{
   if(archp(this_player())) return 0;
   if(this_player()->query_ghost()) return 0;
    message("blocking",
      "The Templar moves in front of you, blocking your path.\n",
      this_player());
    message("blocking",
      "The Templar blocks "+capitalize(this_player()->query_name())+"'s path.\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}
