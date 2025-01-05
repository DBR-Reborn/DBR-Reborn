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

object *vics;
int flag,i;

 
void create() {
   object spinefist;
   object ob;

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
    zlevel = (35+random(5));
//Controls Loot level and other fucntions do to raise to high multpies loot
    lvl = 3;
//Controls critical hit reduction and other such
    llvl = 2;
//controls skill levels 2 multipliers controlled indepdent of level
    zskill = 7;
//controls stats level like str,con
    zskillx = 2;
//controlls skill% spell level
    zspell = 7;
//controls ac * level
    zskillac = 13;

    set_level(zlevel);

set_name("Hive Tyrant");
    set("id",({"tyrant","Tyrant","hive tyrant","tyranid"}));
   set_short("["+zlevel+"]Hive Tyrant"); 

   set("long",@ext This monstrous Tyranid is the central node for their collective
consciousness in this hive.  Its appearence is almost classically
demonic...hugely muscled, goat-like legs complete with chitinous hooves,
a skull-like head and horn-like protrusions.  The differences end there
though, as the bifercated lashing tail resembles a double stingered
scorpion tail and four claws arms are beyond even demons.  As it turns
to face you, you are overcome by a wave of emotion radiating from the
creature.  Its eyes flare with a combination of hate and lust as it
ponders the uses to which it could put your body and mind...
ext);
   
   set("race", "tyranid");
    add_limb("head","FATAL",550,0,7);
    add_limb("torso","FATAL",800,0,7);
    add_limb("upper right arm","upper right grasping claw",325,0,7);
    add_limb("upper left arm","upper left grasping claw",325,0,7);
    add_limb("lower right arm","lower right grasping claw",325,0,7);
    add_limb("lower left arm","lower left grasping claw",325,0,7);
    add_limb("right leg","right hoof",400,0,7);
    add_limb("left leg","left hoof",400,0,7);
    add_limb("upper right grasping claw","",200,0,7);
    add_limb("upper left grasping claw","",200,0,7);
    add_limb("lower right grasping claw","",200,0,7);
    add_limb("lower left grasping claw","",200,0,7);
    add_limb("right hoof","",200,0,7);
    add_limb("left hoof","",200,0,7);
    add_limb("constricting tail","stinger",350,0,7);

    set_wielding_limbs(({"upper right grasping claw","upper left grasping claw","lower right grasping claw","lower left grasping claw"}));

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

    set_skill("perception",zskill*zlevel);
    ob = new(OBJ+"spinefist");
    ob->set_wc(zlevel*lvl ,"disruption");
    ob->set_wc(zlevel*lvl ,"impaling");
    ob->set_wc(zlevel*lvl ,"cutting");
    ob->move(this_object());
    force_me("wield spinefist in upper right grasping claw");

    ob = new(OBJ+"bonesword");
    ob->set_wc(zlevel*lvl ,"fire");
    ob->set_wc(zlevel*lvl ,"cold");
    ob->set_wc(zlevel*lvl ,"cutting");
    ob->move(this_object());
    force_me("wield sword in upper left grasping claw");

    set_skill("black magic", zspell*zlevel);
    set_spell_level("lich form", 6);
    add_spell("lich form", "$(ME)");
    add_spell("syphon soul", "$A");
    set_spell_level("syphon soul", 6);
    add_spell("decay", "$A");
    set_spell_level("decay", 6);
}


heart_beat()
{
    ::heart_beat();
    catch(flash());
}

flash()
{
    object ob;
    int n;
    if (flag > 0) {
	flag--;
	return;
    }
    n = random(4);
    switch(n)
    {
    case 0: 
	message("combat",
	  "The Hive Tyrant calls upon the power of the Tyranid Hive consciousness\n"
	  +"and releases a devastating wave of disruption force that washes over you!\n",
	  all_inventory(environment()));
	vics = all_inventory(environment());
	i = sizeof(vics);
	while(i--)
	{
	    if (vics[i]!= this_object()) {
		vics[i]->kill_ob(this_object(), 0);
		vics[i]->do_damage((string)vics[i]->return_target_limb(),random(20)+25);
		do_critical(this_object(),vics[i],"disruption C");
	    }
	}
	flag = 3+random(4);
	break;
    case 1:
	ob = this_object()->query_current_attacker();
	if (!ob) {
	    flag = 1;
	    break;
	}
	message("combat",
	  "Needle-sharp lances of barbed bone explode from the Hive Tyrant's chest!\n"
	  +"They steak through the air trailing bloody cords of ligament and muscle\n"
	  +"and imbed themselves in "+capitalize(ob->query_name())+"'s body!\n",
	  all_inventory(environment()),
	  ob);
	message("combat",
	  "Needle-sharp lances of barbed bone explode from the Hive Tyrant's chest!\n"
	  +"They streak through the air trailing bloody cords of ligament and muscle\n"
	  +"and imbed themselves deeply in your body!\n",
	  ob);
	ob->kill_ob(this_object(), 0);
	ob->do_damage((string)ob->return_target_limb(),3 * random(10)+2);
	do_critical(this_object(),ob,"impaling D");
	/*
//don't have this code
		new("/wizards/avatar/tyranid/obj/flesh_hook")->move(ob);
	*/
	break;
    case 2:
	ob = this_object()->query_current_attacker();
	if (!ob) {
	    flag = 1;
	    break;
	}
	message("combat",
	  "With a lightning fast motion, the Hive Tyrant's serpentine tail\n"
	  +"lashes forward, wraping around "+capitalize(ob->query_name())+"!\n",
	  all_inventory(environment()),
	  ob);
	message("combat",
	  "With a light fast motion, the Hive Tyrant's serpentine tail\n"
	  +"lashes forward, wrapping around you and squeezing!\n",
	  ob);
	ob->kill_ob(this_object(), 0);
	ob->do_damage((string)ob->return_target_limb(),3 * random(10)+2);
	do_critical(this_object(),ob,"stress D");
	flag = 3 + random(4);
	break;
    case 3:
	ob = this_object()->query_current_attacker();
	if (!ob) {
	    flag = 1;
	    break;
	}
	message("combat",
	  "With a lightning fast motion, the Hive Tyrant's serpentine tail\n"
	  +"lashes forward, its venomous stinger striking "+capitalize(ob->query_name())+"!\n",
	  all_inventory(environment()),
	  ob);
	message("combat",
	  "With a light fast motion, the Hive Tyrant's serpentine tail\n"
	  +"lashes forward, its venomous stinger striking you!\n",
	  ob);
	ob->kill_ob(this_object(), 0);
	ob->add_poisoning(20+random(20));
	do_critical(this_object(),ob,"impaling A");
	flag = 3 + random(4);
	break;
    }
    return;
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
      "The Hive Tyrant hisses and leaps in front of you, blocking your path.\n",
      this_player());
    message("blocking",
      "The Hive Tyrant blocks "+capitalize(this_player()->query_name())+"'s path.\n",
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
