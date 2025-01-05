#include <clock.h>
#include <def.h>
#include "../a1.h"

inherit "/std/armour";   
string mtlname;

void create() {
   ::create();
   set_name("dwarven glove");
   set("id",({"glove","dwarven glove" }));
   set("short","%^ORANGE%^Dwarven Glove%^RESET%^");
   set("long","This Dwarven Glove fits smoothly on your hand.");
   set_type("metal hand");
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

