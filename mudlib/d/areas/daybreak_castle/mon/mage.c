#include "../a1.h"

// Wizard: Eos
// Monster: Mages
// July 19th, 2020

inherit "/std/monster";


void create()
{
	
int zlevel,roll;
	
    ::create();
    set_name("mage");
    set("id",({"mage"}) );
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
    add_money("silver",random(50)+20);
    set("short","[20]Mage");
    set("long",
      "This strange looking mage as he looks like he had lived in this hall all his life\n");
    set("race","mage");
    set_gender("neuter");
    add_limb("head","FATAL",200,0,6);
    add_limb("torso","FATAL",325,0,6);
    add_limb("right arm","right grasping claw",100,0,6);
    add_limb("left arm","left grasping claw",100,0,6);
    add_limb("right scythe arm","right scythe claw",125,0,6);
    add_limb("left scythe arm","left scythe claw",125,0,6);
    add_limb("right leg","right walking talon",200,0,6);
    add_limb("left leg","left walking talon",200,0,6);
    add_limb("balancing tail","",150,0,6);
    add_limb("right grasping claw","",50,0,6);
    add_limb("left grasping claw","",50,0,6);
    add_limb("right scythe claw","",75,0,6);
    add_limb("left scythe claw","",75,0,6);
    add_limb("right walking talon","",75,0,6);
    add_limb("left walking talon","",75,0,6);
    set_overall_ac(40);
    set_melee_damage("cutting");
    set_wielding_limbs( ({ "right scythe claw", "left scythe claw" }));
  set_speed(0);
  set_moving(0);
}

