#include <std.h>
#include <dirs.h>
#include "../a1.h"
inherit MONSTER;

void create() {
int zlevel;
   object money;
   ::create();
    zlevel = (16+random(5));
   set_level(zlevel);
   set_short("["+zlevel+"]Dwarven Worker");
   set_overall_ac(zlevel+15);
    set_name("worker");
    set_id( ({ "worker","dwarf" }) );
    set("long", "This dwarf is hard at work here in the quarry.");
    set_gender("male");
    set("race", "dwarf");
    set_alignment(0);
    set_skill("two handed polearm", 130);
    set_skill("two handed blunt", 130);
    set_wielding_limbs( ({"right hand","left hand"}) );
    set_body_type("human");
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
    money=new("std/obj/coins");
    money->set_money("gold",(random(50)+50));
    money->move(this_object());
}
