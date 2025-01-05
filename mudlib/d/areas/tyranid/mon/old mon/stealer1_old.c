#include "../a1.h"

// Wizard: Avatar
// Monster: Gene Stealer
// /wizards/avatar/tyranid/mon/stealer1.c
// October 15th, 1996

inherit "/std/monster";

void create()
{
    ::create();
    set_name("gene stealer");
    set("id",({"gene stealer","stealer","tyranid"}));
    set_level(19);
    set("aggressive",1);
    set("gang bang", 1);
    add_money("silver",random(20)+10);
    set("short","[19]Gene Stealer");
    set("long",
      "One of the more terrifying of the Tyranid aliens, the Gene stealers\n"
      +"at least vaguely resemble a huge human with two sets of arms.  One\n"
      +"set of razor-sharp scythe-like talons.  The chitinous plate armour is a\n"
      +"deep mightnight blue in colour, fading to a pale pink along the sinous\n"
      +"tale and the toothy maw.  Gene stealers are the most intelligent of the\n"
      +"Tyranid foot soldiers.  They sweep forward ahead of the main Tyranid\n"
      +"force, using their bliding speed and unending ferocity to cut down all\n"
      +"living creatures they encounter.  They then sample the genetic code of\n"
      +"their victim and incorporate it into their own...thereby becoming\n"
      +"faster, stronger and smarter with every kill!\n");
    set("race","tyranid");
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
    set_overall_ac(190);
    set_melee_damage("cutting");
    set_wielding_limbs( ({ "right grasping claw","left grasping claw","right scythe claw","left scythe claw" }));
  //set_speed(100);
  //set_moving(1);
}
