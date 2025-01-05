#include "../a1.h"

// Wizard: Avatar
// Monster: Tyranid Warrior
// /wizards/avatar/tyranid/mon/tyranid1.c
// October 15th, 1996

inherit "/std/monster";

void create()
{
    object bonesword;
    ::create();
    set_name("tyranid warrior");
    set("id",({"warrior","tyranid"}));
    set_level(25);
   // set_exp(358826);
    set("aggressive",1);
    set("gang bang", 1);
    add_money("silver",random(20)+10);
    set("short","[25]Tyranid Warrior");
    set("long",
      "A mighty creature, the Tyranid warrior stands almost ten feet high,\n"
      +"thickly muscled, encased in heavily plated chitin armour and not even\n"
      +"vaguely humanoid.  This is one of the most advanced of the Tyranid\n"
      +"biowarriors.  Its design incorporates two powerful arms ending in human-\n"
      +"like hands holding strange swords with blades of living bone and humming\n"
      +"with psionic power.  Another set of limbs ends in huge striking claws\n"
      +"that remind you vaguely of bear paws.  The tail of lesser Tyranids has\n"
      +"been replaced by a bone tipped stinger...you shudder at the thought of\n"
      +"the unearthly diseases or venom it must deliver.  Worst of all, Tyranid\n"
      +"warriors such as this one act as nodes for the Tyranid hive\n"
      +"consciousness.  The vast intellect and will of the collective is able to\n"
      +"manifest thorugh this horrid creature, making it a general in the\n"
      +"Tyranid army.\n");
    set("race","tyranid");
    set_gender("neuter");
    add_limb("head","FATAL",375,0,7);
    add_limb("torso","FATAL",525,0,7);
    add_limb("right arm","right grasping claw",275,0,7);
    add_limb("left arm","left grasping claw",275,0,7);
    add_limb("right striking arm","right striking claw",325,0,7);
    add_limb("left striking arm","left striking claw",325,0,7);
    add_limb("right leg","right walking talon",400,0,7);
    add_limb("left leg","left walking talon",400,0,7);
    add_limb("stingered tail","",350,0,7);
    add_limb("right grasping claw","",125,0,7);
    add_limb("left grasping claw","",125,0,7);
    add_limb("right striking claw","",165,0,7);
    add_limb("left striking claw","",165,0,7);
    add_limb("right walking talon","",165,0,7);
    add_limb("left walking talon","",165,0,7);
    set_overall_ac(250);
    set_melee_damage("cutting");
    set_wielding_limbs( ({"right grasping claw", "left striking claw",
	"stingered tail"}));
    bonesword = new(OBJ+"bonesword");
    bonesword->move(this_object());
    force_me("wield sword in right grasping claw");
}

void init()
{
    ::init();
    add_action("no","out");
    add_action("no","hole");
}

int no()
{
   if(archp(this_player())) return 0;
   if(this_player()->query_ghost()) return 0;
    message("blocking",
      "The Tyranid Warrior hisses and leaps in front of you, blocking your path.\n",
      this_player());
    message("blocking",
      "The Tyranid Warrior blocks "+capitalize(this_player()->query_name())+"'s path.\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}
