#include <clock.h>
#include <def.h>
#include "../a1.h"

inherit "/std/armour";   
string mtlname;

void create() {
   ::create();
   set_name("dwarven shield");
   set("id",({"shield","dwarven shield", "helm"}));
   set("short","%^ORANGE%^Dwarven Shield%^RESET%^");
   set("long","This Dwarven shield fits smoothly on your hand.");
   set_type("shield");
 switch(random(3)){
      case 0:mtlname="mithril";break;
      case 1:mtlname="elrodnite";break;
      case 2:mtlname="platnite";break;
    }
   set_material("metal/"+mtlname);
   set_ac(60);
   set_limbs( ({ ({ "right hand", "left hand" }) }) );
   set_weight(110);
   set_value(800);
}

