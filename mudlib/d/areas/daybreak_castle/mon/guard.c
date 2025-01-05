/* Monster coded by Eos. */
 
#include "std.h"

inherit MONSTER;
 
void create()
{
    ::create();
    set_name("guard");
    set("id",({"guard"}));
    set_level(30);
    set("aggressive",0);
    set("gang bang", 1);
    add_money("silver",random(50)+20);
    set("short","[30]guard");
    set("long",
      "Castle Guard\n");
    set("race","guard");
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
    set_overall_ac(59);
    set_melee_damage("cutting");
    set_wielding_limbs( ({ "right grasping claw","left grasping claw","right scythe claw","left scythe claw" }));
}
