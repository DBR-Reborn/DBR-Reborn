#include "../a1.h"

// Wizard: Avatar
// Monster: Ripper Swarm
// /wizards/avatar/tyranid/mon/ripper.c
// October 15th, 1996


inherit "/std/monster";


void create()
{
    ::create();
    set_name("ripper swarm");
    set("id",({"ripper","swarm","tyranid"}));
    set_level(15);
    set("aggressive",1);
    set("gang bang", 1);
    add_money("silver",random(20)+10);
    set("short","[15]Ripper swarm");
    set("long",
      "This horrible creature resembles a two foot long insect larva. Its\n"
      +"rope-like muscular body is covered in thick chitinous armour plates\n"
      +"and itsbear trap-like snapping jaws are festooned with gore!  Millions\n"
      +"of these creatures are released to devour every living thing on a\n"
      +"world, from trees to animals and even fish.  The ripper swarms then\n"
      +"return to thehive, carrying their load of genetic and building\n"
      +"material where they are reabsorbed into the Tyranid collective and\n"
      +"used to create new and even more deadly Tyranids!");
    set("race","tyranid");
    set_gender("neuter");
    add_limb("head","FATAL",185,0,5);
    add_limb("body","FATAL",185,0,5);
    set_overall_ac(150);
    set_melee_damage("cutting");
    add_wielding_limb("head");
  set_speed(100);
  set_moving(1);
}

