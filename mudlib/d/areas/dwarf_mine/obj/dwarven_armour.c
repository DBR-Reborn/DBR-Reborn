#include <clock.h>
#include <def.h>
#include "../a1.h"

inherit "/std/armour";   
string mtlname;

void create() {
   ::create();
   set_name("dwarven mail");
   set("id",({"mail","dwarven mail",}));
   set("short","%^ORANGE%^Dwarven Mail%^RESET%^");
   set("long","This Dwarven armour with finely crafted links on every"
     " part of the armour.");
   set_type("metal torso");
 switch(random(3)){
      case 0:mtlname="mithril";break;
      case 1:mtlname="elrodnite";break;
      case 2:mtlname="platnite";break;
    }
   set_material("metal/"+mtlname);
   set_ac(65);
   set_limbs( ({"torso","right arm","left arm","right leg","left leg"}) );
   set_weight(110);
   set_value(800);
}

