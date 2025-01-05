#include "../a1.h"

// Wizard: Avatar
// Monster: Termagant
// /wizards/avatar/tyranid/mon/termagant1.c
// October 15th, 1996

inherit "/std/monster";

void create()
{
    ::create();
    set_name("termagant");
    set("id",({"termagant","tyranid"}));
    set_level(17);
    set("aggressive",1);
    set("gang bang", 1);
    add_money("silver",random(20)+10);
    set("short","[17]Termagant");
    set("long",
      "This strange looking creature looks like a demonic hybred of dinosaur\n"
      +"and insect.  It walks upright in the manner of a Tyranosaurous, with\n"
      +"two sets of multijointed arms tucked under its torso.  The creature is\n"
      +"covered in chitinous scales, from the tip of its long slender tail to\n"
      +"the top of its demonic head.  Its eyes glow with a maniacal hatred of\n"
      +"all nonTyranid life and its mouth is filled with dozens of needle sharp\n"
      +"teeth as it grins in your direction!\n");
    set("race","tyranid");
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
    set_overall_ac(170);
    set_melee_damage("cutting");
    set_wielding_limbs( ({ "right scythe claw", "left scythe claw" }));
  //set_speed(100);
  //set_moving(1);
}

void init()
{
    ::init();
    add_action("no","up");
    add_action("no","down");
}

int no()
{
   if(archp(this_player())) return 0;
   if(this_player()->query_ghost()) return 0;
    message("blocking",
      "The Termagant hisses and leaps in front of you, blocking your path.\n",
      this_player());
    message("blocking",
      "The Termagant blocks "+capitalize(this_player()->query_name())+"'s path.\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}
