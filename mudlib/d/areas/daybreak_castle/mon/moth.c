#include <std.h>
#include <dirs.h>
#include "../a1.h"
inherit MONSTER;

void create() {
int zlevel;
   object money;
   ::create();
    zlevel = (3+random(1));
   set_level(zlevel);
   set_short("["+zlevel+"]Moth");
   set_overall_ac(zlevel+5);
    set_name("Moth");
    set_id( ({ "moth","moth" , "moth", "moth", "moth"}) );
    set("long", "This moth is overly large fo its common size and is all grey with sharp fine hairs on it's main body.");
    set_gender("male");
    set("race", "moth");
    set_alignment(5);
    //set_skill("two handed polearm", 210);
    //set_skill("two handed blunt", 210);
    set_wielding_limbs( ({"right hand","left hand"}) );
    set_body_type("human");
	
	set_melee_damage( (["crushing" : zlevel, "fire" : zlevel ]) );
    set_skill("melee", 6*zlevel);
    set_skill("attack", 6*zlevel);
    set_skill("defense", 6*zlevel);
    set_skill("dodge", 6*zlevel);
	
	set_max_hp(100);
    set_hp(100);
    set_max_mp(70);
    set_mp(70);
	
/*   
   switch(random(5)){
case 0:new(OBJ+"pick-axe.c")->move(this_object());
      force_me("wield pick in right hand and left hand");
      break;
case 1:new(OBJ+"pick.c")->move(this_object());
      force_me("wield pick in right hand and left hand");
      break;
case 2:new("/d/damned/virtual/war-hammer_6.weapon")->move(this_object());
      force_me("wield hammer in right hand and left hand");
      break;
case 3:new("/d/damned/virtual/great-axe_6.weapon")->move(this_object());
      force_me("wield axe in right hand and left hand");
      break;
case 4:new("/d/damned/virtual/battle-axe_6.weapon")->move(this_object());
      force_me("wield axe in right hand");
      break;
}
*/
    money=new("std/obj/coins");
    money->set_money("gold",(random(150)+50));
    money->move(this_object());
}
