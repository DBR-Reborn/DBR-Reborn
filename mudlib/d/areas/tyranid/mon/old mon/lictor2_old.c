#include "../a1.h"

// Wizard: Avatar
// Monster: Lictor
// /wizards/avatar/tyranid/mon/lictor2.c
// October 15th, 1996

inherit "/std/monster";

int hide_in_shadows,in_stealth,shadowing;

void init() {
    :: init();
    if(!this_player()->is_player()) { return; }
    if(this_player()->query_invis()) { return; }
    if(hide_in_shadows==0) {
	force_me("use hide in shadows");
	hide_in_shadows = 1;
    }
    if(in_stealth==0) {
	force_me("use stealth");
	in_stealth = 1;
    }
    if (shadowing==0) {
	force_me("use shadow at "+(string)this_player()->query_name());
	delayed_call("bs",random(6)+2,this_player());
	shadowing = 1;
    }
    return;
}

void create()
{
    ::create();
    set_name("lictor");
    set("id",({"lictor","tyranid"}));
    set_level(23);
    //set_exp(222725);
    set("aggressive",0);
    set("gang bang", 0);
    add_money("silver",random(20)+10);
    set("short","[23]Lictor");
    set("long",
      "This terrifying creature is a Lictor, the ninja/commandos of the\n"
      +"Tyranids.  Like most Tyranids, they have 2 sets of arms.  The first set\n"
      +"is almost perfectly humanoid.  The second set however are huge\n"
      +"structures of chitin and bone that almost perfectly resemble a pair of\n"
      +"scythes!  The Lictor's armour plate is covered with special chamelionic\n"
      +"scales, capable of blending in almost perfectly in any environment.\n"
      +"This, combined with its blinding speed and inhuman cunning, enables the\n"
      +"Lictor to penetrate deep into even an alert enemy's territory to gather\n"
      +"intelligence.  The four slender tenticles that ring its mandible-like\n"
      +"mouth, are capable of extracting the brains from many life forms, from\n"
      +"which the Lictor is able to derive an appaling amount of information\n"
      +"as well as the victim's genetic code which the Lictor uses to improve\n"
      +"itself.\n");
    set("race","tyranid");
    set_gender("neuter");
    add_limb("head","FATAL",425,0,7);
    add_limb("torso","FATAL",600,0,7);
    add_limb("right arm","right grasping claw",325,0,7);
    add_limb("left arm","left grasping claw",325,0,7);
    add_limb("right scythe arm","right scythe claw",350,0,7);
    add_limb("left scythe arm","left scythe claw",350,0,7);
    add_limb("right grasping claw","",175,0,7);
    add_limb("left grasping claw","",175,0,7);
    add_limb("right scythe claw","",400,0,7);
    add_limb("left scythe claw","",400,0,7);
    add_limb("right leg","right walking talon",400,0,7);
    add_limb("left leg","left walking talon",400,0,7);
    add_limb("right walking talon","",200,0,7);
    add_limb("left walking talon","",200,0,7);
    set_overall_ac(230);
    set_melee_damage("impailing");
    set_wielding_limbs( ({ "right grasping claw","left grasping claw","right scythe claw","left scythe claw" }));
    set_skill("back stab",120);
    set_skill("hide in shadows",120);
    set_skill("stealth",120);
    set_skill("shadow",120);
    set_skill("perception",120);
}

void bs(object tp){
    if(!tp || !present(tp, environment())) { return; }
    message("combat","A terrifying shape flashes out of the shadows and attacks with blinding speed!\n",all_inventory(environment()));
    tp->kill_ob(this_object(), 0);
    tp->do_damage((string)tp->return_target_limb(),2*(random(6)+6));
    do_critical(this_object(),tp,"impaling C");
    do_critical(this_object(),tp,"speed C");
    hide_in_shadows = 0;
    in_stealth = 0;
    shadowing = 0;
    return;
}
