#include <std.h>
#include <dirs.h>
#include "../a1.h"
inherit MONSTER;

void create() {
int zlevel;
   object money;
   ::create();
    zlevel = (25+random(4));
   set_level(zlevel);
   set_short("["+zlevel+"]Dwarven Trainee");
   set_overall_ac(zlevel+10);
    set_name("trainee");
    set("gang bang", 1);
    set_id( ({ "trainee","dwarf" }) );
    set_gender("male");
    set("race", "dwarf");
    set_alignment(0);
   set("long", "This young dwarf is learning the ways of the quarry from the older, more experienced dwarves.  Essentially though, he is just a slave.  He is carrying metal between the dwarves in the mines and the dwarves taking the metal out of the quarry."); 
    set_skill("axe", zlevel*8);
    set_skill("blunt", zlevel*8);
    set_wielding_limbs( ({"right hand","left hand"}) );
    set_body_type("human");
    switch(random(3)){
case 0:new("/d/damned/virtual/battle-axe_5.weapon")->move(this_object());
      force_me("wield axe in right hand");
     //new(OBJ+"misc/metal")->move(this_object());
      break;
case 1:new("/d/damned/virtual/hammer_5.weapon")->move(this_object());
      force_me("wield hammer in right hand");
      break;
case 2:new("/d/damned/virtual/hand-axe_5.weapon")->move(this_object());
      force_me("wield axe in right hand");
    //new(OBJ+"metal")->move(this_object());
    //new(OBJ+"metal")->move(this_object());
      move(this_object());
      break;
}
    money=new("std/obj/coins");
    money->set_money("gold",(random(10)+10));
    money->move(this_object());
}
