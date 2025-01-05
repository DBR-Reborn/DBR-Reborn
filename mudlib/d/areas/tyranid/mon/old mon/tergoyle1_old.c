#include "../a1.h"

// Wizard: Avatar
// Monster: Tergoyle
// /wizards/avatar/tyranid/mon/tergoyle1.c
// October 15th, 1996

inherit "/std/monster";

void create()
{
    object flamespitter;
    ::create();
    set_name("tergoyle");
    set("id",({"tergoyle","tyranid"}));
    set_level(18);
    set("aggressive",1);
    set("gang bang", 1);
    add_money("silver",random(20)+10);
    set("short","[18]Tergoyle");
    set("long",
      "This strange looking creature looks like a demonic hybred of dinosaur\n"
      +"and insect.  It bears a strong resemblance to the more common\n"
      +"Termagants, but with two frightening differences. First, one of its sets\n"
      +"of arms have been replaced with a pair of brightly scaled wings.\n"
      +"Second, the creature is holding some sort of weapon in its remaining\n"
      +"hands that apparently allows the horrid thing to breath fire!\n");
    set("race","tyranid");
    set_gender("neuter");
    add_limb("head","FATAL",275,0,7);
    add_limb("torso","FATAL",400,0,7);
    add_limb("right arm","right grasping claw",135,0,7);
    add_limb("left arm","left grasping claw",135,0,7);
    add_limb("right wing","",165,0,7);
    add_limb("left wing","",165,0,7);
    add_limb("lashing tail","",200,0,7);
    add_limb("right grasping claw","",75,0,7);
    add_limb("left grasping claw","",75,0,7);
    set_overall_ac(180);
    set_melee_damage("cutting");
    set_wielding_limbs( ({ "lashing tail" }));
    flamespitter = new(OBJ+"flamespitter");
    flamespitter->move(this_object());
    force_me("wear flamespitter");
    set_combat_chance(75);
    set_skill("elementalism",70);
    set_skill("fire lore",70);
    set_skill("concentrate",70);
    add_spell("elemental bolt","$A");
    set_spell_level("elemental bolt",1);
    force_me("use concentrate");
    force_me("use fire lore");
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
      "The Tergoyle hisses and leaps in front of you, blocking your path.\n",
      this_player());
    message("blocking",
      "The Tergoyle blocks "+capitalize(this_player()->query_name())+"'s path.\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}
