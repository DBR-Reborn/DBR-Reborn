#include "../a1.h"

// Wizard: Avatar
// Monster: Hive Tyrant
// /wizards/avatar/tyranid/mon/tyrant1.c
// October 15th, 1996

inherit "/std/monster";

object *vics;
int flag,i;

void create()
{
    object spinefist;
    ::create();
    set_name("Hive Tyrant");
    set("id",({"tyrant","Tyrant","hive tyrant","tyranid"}));
    set_level(30);
    //set_exp(835846);
    set("aggressive",1);
    set("gang bang", 0);
    add_money("silver",random(20)+10);
    set("short","[30]Hive Tyrant");
    set("long",
      "This monstrous Tyranid is the central node for their collective\n"
      +"consciousness in this hive.  Its appearence is almost classically\n"
      +"demonic...hugely muscled, goat-like legs complete with chitinous hooves,\n"
      +"a skull-like head and horn-like protrusions.  The differences end there\n"
      +"though, as the bifercated lashing tail resembles a double stingered\n"
      +"scorpion tail and four claws arms are beyond even demons.  As it turns\n"
      +"to face you, you are overcome by a wave of emotion radiating from the\n"
      +"creature.  Its eyes flare with a combination of hate and lust as it\n"
      +"ponders the uses to which it could put your body and mind...\n");
    set("race","tyranid");
    set_gender("neuter");
    add_limb("head","FATAL",550,0,7);
    add_limb("torso","FATAL",800,0,7);
    add_limb("upper right arm","upper right grasping claw",325,0,7);
    add_limb("upper left arm","upper left grasping claw",325,0,7);
    add_limb("lower right arm","lower right grasping claw",325,0,7);
    add_limb("lower left arm","lower left grasping claw",325,0,7);
    add_limb("right leg","right hoof",400,0,7);
    add_limb("left leg","left hoof",400,0,7);
    add_limb("upper right grasping claw","",200,0,7);
    add_limb("upper left grasping claw","",200,0,7);
    add_limb("lower right grasping claw","",200,0,7);
    add_limb("lower left grasping claw","",200,0,7);
    add_limb("right hoof","",200,0,7);
    add_limb("left hoof","",200,0,7);
    add_limb("constricting tail","stinger",350,0,7);
    set_overall_ac(1000);
    set_wielding_limbs(({"upper right grasping claw","upper left grasping claw","lower right grasping claw","lower left grasping claw"}));
    set_melee_damage("cutting");
    set_skill("perception",120);
    spinefist = new(OBJ+"spinefist");
    spinefist->move(this_object());
    force_me("wield spinefist in upper right grasping claw");
    new(OBJ+"bonesword")->move(this_object());
    force_me("wield sword in upper left grasping claw");
}

heart_beat()
{
    ::heart_beat();
    catch(flash());
}

flash()
{
    object ob;
    int n;
    if (flag > 0) {
	flag--;
	return;
    }
    n = random(4);
    switch(n)
    {
    case 0: 
	message("combat",
	  "The Hive Tyrant calls upon the power of the Tyranid Hive consciousness\n"
	  +"and releases a devastating wave of disruption force that washes over you!\n",
	  all_inventory(environment()));
	vics = all_inventory(environment());
	i = sizeof(vics);
	while(i--)
	{
	    if (vics[i]!= this_object()) {
		vics[i]->kill_ob(this_object(), 0);
		vics[i]->do_damage((string)vics[i]->return_target_limb(),random(20)+25);
		do_critical(this_object(),vics[i],"disruption C");
	    }
	}
	flag = 3+random(4);
	break;
    case 1:
	ob = this_object()->query_current_attacker();
	if (!ob) {
	    flag = 1;
	    break;
	}
	message("combat",
	  "Needle-sharp lances of barbed bone explode from the Hive Tyrant's chest!\n"
	  +"They steak through the air trailing bloody cords of ligament and muscle\n"
	  +"and imbed themselves in "+capitalize(ob->query_name())+"'s body!\n",
	  all_inventory(environment()),
	  ob);
	message("combat",
	  "Needle-sharp lances of barbed bone explode from the Hive Tyrant's chest!\n"
	  +"They streak through the air trailing bloody cords of ligament and muscle\n"
	  +"and imbed themselves deeply in your body!\n",
	  ob);
	ob->kill_ob(this_object(), 0);
	ob->do_damage((string)ob->return_target_limb(),3 * random(10)+2);
	do_critical(this_object(),ob,"impaling D");
	/*
//don't have this code
		new("/wizards/avatar/tyranid/obj/flesh_hook")->move(ob);
	*/
	break;
    case 2:
	ob = this_object()->query_current_attacker();
	if (!ob) {
	    flag = 1;
	    break;
	}
	message("combat",
	  "With a lightning fast motion, the Hive Tyrant's serpentine tail\n"
	  +"lashes forward, wraping around "+capitalize(ob->query_name())+"!\n",
	  all_inventory(environment()),
	  ob);
	message("combat",
	  "With a light fast motion, the Hive Tyrant's serpentine tail\n"
	  +"lashes forward, wrapping around you and squeezing!\n",
	  ob);
	ob->kill_ob(this_object(), 0);
	ob->do_damage((string)ob->return_target_limb(),3 * random(10)+2);
	do_critical(this_object(),ob,"stress D");
	flag = 3 + random(4);
	break;
    case 3:
	ob = this_object()->query_current_attacker();
	if (!ob) {
	    flag = 1;
	    break;
	}
	message("combat",
	  "With a lightning fast motion, the Hive Tyrant's serpentine tail\n"
	  +"lashes forward, its venomous stinger striking "+capitalize(ob->query_name())+"!\n",
	  all_inventory(environment()),
	  ob);
	message("combat",
	  "With a light fast motion, the Hive Tyrant's serpentine tail\n"
	  +"lashes forward, its venomous stinger striking you!\n",
	  ob);
	ob->kill_ob(this_object(), 0);
	ob->add_poisoning(20+random(20));
	do_critical(this_object(),ob,"impaling A");
	flag = 3 + random(4);
	break;
    }
    return;
}
