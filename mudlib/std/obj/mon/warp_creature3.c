// a warp monster
// updated by Xavier July2020

#include "/adm/include/std.h"

inherit MONSTER;

void create() {
  ::create();
    set_name("warp creature");
    set_id( ({ "creature", "warp creature" }) );
    set_short("A hideous Warp Creature");
    set("race", "warp creature");
    set_long(
"This creature is absolutely hideous!  It has several arms and legs, "
"and it regards you with hundreds of multicolored eyes.  It attacks "
"without hesitation!");
set("aggressive", (: this_object(), "no_other_monsters" :) );
    set_body_type("quadruped");
    add_limb("first arm", 0, 1000, 0, 4);
    add_limb("second arm", 0, 1000, 0, 4);
    add_limb("third arm", 0, 1000, 0, 4);
    add_limb("fourth arm", 0, 1000, 0, 4);
    add_limb("fifth arm", 0, 1000, 0, 4);
    add_limb("first leg", 0, 1000, 0, 4);
    add_limb("second leg", 0, 1000, 0, 4);
    add_limb("third leg", 0, 1000, 0, 4);
    add_limb("fourth leg", 0, 1000, 0, 4);
    add_limb("fifth leg", 0, 1000, 0, 4);
    add_limb("second head", "FATAL", 1000, 0, 4);
    set_level(55);
    set_stats("intelligence", 120);
    set_property("melee damage", ([ "crushing" : 125, "electricity" : 125,
          "vacuum" : 125, "stress" : 110, "aether" : 110, "unholy" : 110 ]));
    set_skill("melee", 595);
    set_skill("dodge", 525);
    set_skill("parry", 525);
    set_stats("dexterity", 120);
    set_property("enhance criticals", -4);
  set_skill("resist stun", 1375);
    set_overall_ac(225);
  set_property("physical resistance", ([ "default" : 500]));
  set_property("magical resistance", ([ "default" : 500]));
    //set_property("magic resistance", 1250);
    //set_property("physical resistance", 550);
         // ([ "default" : 1250]));
//",iron" : 97, "steel" : 97, "wood" : 80 
    set_max_hp(55000);
    set_hp(55000);
}

 
void die(object obi) {
	object tmp,ob;
    int dmg1;
	tmp = environment();
	ob = new("/wizards/excelsior/misc/portal");
	ob->move(tmp);
	ob->setup_color();
	call_out("dissolve_portal",500,ob);
	message("info","%^RED%^With the creature dead, the reality it was controlling "+
		"becomes unstable. A portal opens up in the nexus.",tmp);
	message("info","%^BLUE%^A portal opens! It will close as soon as reality "+
		"stabalizes.",tmp);
/*
dmg1= this_object()->query_attackers()[0]->query_level()+10+random(11);

message("info", "The creature dies and a stronger version appears",tmp);
 ob=new("/std/obj/mon/warp_creature3");
ob->set_level(dmg1);
ob->set_short("["+dmg1+"] Warp Creature");
ob->set_melee_damage(([ "crushing" : (125+dmg1)*5, "electricity" : (125+dmg1)*5, "vacuum" : (125+dmg1)*5, "stress" : (125+dmg1)*5, "aether" : (125+dmg1)*8, "unholy" : (125+dmg1)*5 ]));
ob->set_skill("melee", 14*dmg1);
ob->set_skill("martial arts", 10*dmg1);
ob->move(environment());
*/
	::die(obi);
}


