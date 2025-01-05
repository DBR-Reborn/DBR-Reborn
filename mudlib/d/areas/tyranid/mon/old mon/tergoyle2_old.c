#include "../a1.h"

// Wizard: Avatar
// Monster: Tergoyle
// /wizards/avatar/tyranid/mon/tergoyle2.c
// October 15th, 1996

inherit "/std/monster";

void create()
{
    object flamespitter;
    ::create();
    set_name("tergoyle");
    set("id",({"tergoyle","tyranid"}));
    set_level(20);
    set("aggressive",1);
    set("gang bang", 1);
    add_money("silver",random(20)+10);
    set("short","[20]Tergoyle");
    set("long",
      "This strange looking creature looks like a demonic hybred of dinosaur\n"
      +"and insect.  It bears a strong resemblance to the more common\n"
      +"Termagants, but with two frightening differences. First, one of its sets\n"
      +"of arms have been replaced with a pair of brightly scaled wings.\n"
      +"Second, the creature is holding some sort of weapon in its remaining\n"
      +"hands that apparently allows the horrid thing to breath fire!\n");
    set("race","tyranid");
    set_gender("neuter");
    add_limb("head","FATAL",350,0,7);
    add_limb("torso","FATAL",475,0,7);
    add_limb("right arm","right grasping claw",225,0,7);
    add_limb("left arm","left grasping claw",225,0,7);
    add_limb("right wing","",300,0,7);
    add_limb("left wing","",300,0,7);
    add_limb("lashing tail","",325,0,7);
    add_limb("right grasping claw","",100,0,7);
    add_limb("left grasping claw","",100,0,7);
    set_overall_ac(200);
    set_melee_damage("cutting");
    set_wielding_limbs( ({ "lashing tail" }));
    flamespitter = new(OBJ+"flamespitter");
    flamespitter->move(this_object());
    force_me("wear flamespitter");
    set_combat_chance(75);
    set_skill("elementalism",80);
    set_skill("fire lore",80);
    set_skill("concentrate",80);
    add_spell("elemental bolt","$A");
    set_spell_level("elemental bolt",2);
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
