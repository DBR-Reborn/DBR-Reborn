#include <clock.h>
#include <def.h>
#include "../a1.h"

inherit "/std/armour";   
string mtlname;

void create() {
   ::create();
   set_name("dwarven greaves");
   set("id",({"greaves","dwarven greaves"}));
   set("short","%^ORANGE%^Dwarven Greaves%^RESET%^");
   set("long","These Dwarven Greaves fits snugly on your legs.");
   set_type("metal legs");
 switch(random(3)){
      case 0:mtlname="mithril";break;
      case 1:mtlname="elrodnite";break;
      case 2:mtlname="platnite";break;
    }
   set_material("metal/"+mtlname);
   set_ac(60);
   set_limbs( ({"left leg", "right leg"}) );
   set_weight(110);
   set_value(800);
}

