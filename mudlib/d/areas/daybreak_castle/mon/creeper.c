#include "../a1.h"

// Wizard: Eos
// Monster: creeper
// July 19th, 2020

inherit "/std/monster";

void create()
{
	
	int zlevel,roll;
	
    ::create();
    set_name("creeper");
    set("id",({"creeper"}));
	roll=random(10);
	
	switch(roll){
	case 0:zlevel=15;break;
	case 1:zlevel=16;break;
	case 2:zlevel=17;break;
	case 3:zlevel=18;break;
	case 4:zlevel=19;break;
	case 5:zlevel=20;break;
	case 6:zlevel=21;break;
	case 7:zlevel=22;break;
	case 8:zlevel=23;break;
	case 9:zlevel=24;break;
}
   
   
    set("aggressive",0);
    set("gang bang", 0);
    add_money("gold",random(10)+10);
    set("short","[17]Creeper");
    set("long",
      "One of the local mages who spends most of his time creeping around the pathways of the castle\n");
    set("race","mage");
    set_gender("neuter");
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
    set_overall_ac(45);
    set_melee_damage("cutting");
    set_wielding_limbs( ({ "right grasping claw","left grasping claw","right scythe claw","left scythe claw" }));

}
