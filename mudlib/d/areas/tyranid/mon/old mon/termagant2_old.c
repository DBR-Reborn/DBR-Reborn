#include "../a1.h"

// Wizard: Avatar
// Monster: Termagant
// /wizards/avatar/tyranid/mon/termagant2.c
// October 15th, 1996

inherit "/std/monster";

void create()
{
    object deathspitter;
    ::create();
    set_name("termangant");
    set("id",({"termagant","tyranid"}));
    set_level(17);
    set("aggressive",1);
    set("gang bang", 1);
    add_money("silver",random(20)+10);
    set("short","[17]Termagant");
    set("long",
      "This strange looking creature looks like a demonic hybred of dinosaur\n"
      +"and insect.  It walks upright in the manner of a Tyranosaurous, with two\n"
      +"sets of multijointed arms...one set tucked under its torso and the other\n"
      +"set brandishing an extremely ugly weapon!  The creature is covered in\n"
      +"chitinous scales, from the tip of its long slenter tail to the top of\n"
      +"its demonic head.  Its eyes glow with a maniacal hatred of all\n"
      +"nonTyranid life and its mouth is filled with dozens of needle sharp\n"
      +"teeth as it grins in your direction!\n");
    set("race","tyranid");
    set_gender("neuter");
    add_limb("head","FATAL",225,0,7);

    add_limb("torso","FATAL",375,0,7);
    add_limb("right arm","right grasping claw",125,0,7);
    add_limb("left arm","left grasping claw",125,0,7);
    add_limb("right scythe arm","right scythe claw",150,0,7);
    add_limb("left scythe arm","left scythe claw",150,0,7);
    add_limb("right leg","right walking talon",225,0,7);
    add_limb("left leg","left walking talon",225,0,7);
    add_limb("balancing tail","",175,0,7);
    add_limb("right grasping claw","",75,0,7);
    add_limb("left grasping claw","",75,0,7);
    add_limb("right scythe claw","",100,0,7);
    add_limb("left scythe claw","",100,0,7);
    add_limb("right walking talon","",100,0,7);
    add_limb("left walking talon","",100,0,7);
    set_overall_ac(170);
    set_melee_damage("cutting");
    set_wielding_limbs( ({ "right grasping claw", "left scythe claw" }));
    deathspitter = new(OBJ+"deathspitter");
    deathspitter->move(this_object());
    force_me("wield deathspitter in right grasping claw");
  //set_speed(100);
  //set_moving(1);
}
