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

int cd;
 
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
      case 7:damage1="vacuum";break;
      case 8:damage1="electricity";break;
      case 9:damage1="disruption";break;
      case 10:damage1="plasma";break;
    }
switch(random(8)){
      case 0:quality="5";break;
      case 1:quality="5";break;
      case 2:quality="5";break;
      case 3:quality="5";break;
      case 4:quality="6";break;
      case 5:quality="6";break;
      case 6:quality="6";break;
      case 7:quality="6";break;
    }

//controls monsters level
    zlevel = (30+random(5));
//Controls Loot level and other fucntions do to raise to high multpies loot
    lvl = 3;
//Controls critical hit reduction and other such
    llvl = 1;
//controls skill levels 2 multipliers controlled indepdent of level
    zskill = 7;
//controls stats level like str,con
    zskillx = 2;
//controlls skill% spell level
    zspell = 7;
//controls ac * level
    zskillac = 11;

    set_level(zlevel);

set_name("carnifex");
    set("id",({"carnifex","tyranid"}));
   set_short("["+zlevel+"]Carnifex"); 

   set("long",@ext This monstrous creature is an incredibly advanced biowarrior used by the
Tyranids as a combination tank and artillery piece.  Its huge body is
massively plated with chitin armour, bony plates and underneith it all
is heavy muscle.  Four heavily plated scythe-like arms lash around the
abomination, cutting apart anything foolish enough to get close to it.
A special opening, where its mouth would be if it was primitive enough
to have to eat, shines with ugly green plasma, which the Carnifex can
project apalling distances for use as a bombardment weapon.
ext);
   
   set("race", "tyranid");
    add_limb("head","FATAL",500,0,7);
    add_limb("torso","FATAL",700,0,7);
    add_limb("upper right striking arm","",400,0,7);
    add_limb("upper left striking arm","",400,0,7);
    add_limb("lower right striking arm","",400,0,7);
    add_limb("lower left striking arm","",400,0,7);
    add_limb("right leg","right hoof",600,0,7);
    add_limb("left leg","left hoof",600,0,7);
    add_limb("right hoof","",300,0,7);
    add_limb("left hoof","",300,0,7);

    set_wielding_limbs(({"upper right striking arm","upper left striking arm","lower right striking arm","lower left striking arm"}));

    //set_speed(100);
    //set_moving(1);

   set("gang bang", 1);
   set("aggressive", 1);

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

    cd = 3;

    set_skill("black magic", zspell*zlevel);
    set_spell_level("lich form", 6);
    add_spell("lich form", "$(ME)");
    add_spell("drain life", "$A");
    set_spell_level("drain life", 3);
}


void do_damage(string str, int arg)
{
    if (random(100) < 25) {
	message("combat",
	  "Your blow rings harmlessly off the Carnifex's thick chitin armour!\n",
	  all_inventory(environment()));
	return;
    }
    ::do_damage(str,arg);
}

void flash()
{
    int i;
    object *vic;
    if (cd > 0) {
	switch(cd) {
	case 5:
	    message(
	      "combat",
	      "Rasping plates on the Carnifex's torso begin to move against each other,\n"
	      +"emitting a metal-on-metal grinding sound.\n",
	      all_inventory(environment()));
	    break;
	case 4:
	    message(
	      "combat",
	      "The rasping plates more faster and faster, the grinding sound rising in\n"
	      +"pitch with every second.\n",
	      all_inventory(environment()));
	    break;
	case 3:
	    message(
	      "combat",
	      "The rasping plates on the Carnifex's chest are a near invisible blur and\n"
	      +"the earsplitting shriek causes the very air to shimmer.\n",
	      all_inventory(environment()));
	    break;
	case 2:
	    message(
	      "combat",
	      "The deafening shriek of the Carnifex's rasping plates fills the air as a\n"
	      +"faint emerald glow begins to fill the opening in its chest.\n",
	      all_inventory(environment()));
	    break;
	case 1:
	    message(
	      "combat",
	      "The Carnifex's unholy scream seems to fill your soul as a blinding green\n"
	      +"light glares from the opening in its chest, casting demonic shifting\n"
	      +"shadows behind you.\n",
	      all_inventory(environment()));
	    break;
	}
	cd--;
	return;
    }
    message(
      "combat",
      "With a clap of thunder that nearly blasts you from your feet, a star bright\n"
      +"sphere of emerald plasma vomits forth from the Carnifex to assault its\n"
      +"foes!\n",
      all_inventory(environment()));
    vic = all_inventory(environment());
    i = sizeof(vic);
    while(i--)
    {
	if (vic[i]->is_player()) {
	    vic[i]->kill_ob(this_object(),0);
	    vic[i]->do_damage((string)vic[i]->return_target_limb(),20+random(20));
	    do_critical(this_object(),vic[i],"plasma D");
	}
    }
    cd = 5;
    return;
}

heart_beat()
{
    ::heart_beat();
    catch(flash());
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
      "The Carnifex hisses and leaps in front of you, blocking your path.\n",
      this_player());
    message("blocking",
      "The Carnifex blocks "+capitalize(this_player()->query_name())+"'s path.\n",
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
