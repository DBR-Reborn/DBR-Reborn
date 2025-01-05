#include <clock.h>
#include <def.h>
#include "../a1.h"

inherit "/std/armour";   
string mtlname;

void create() {
   ::create();
   set_name("dwarven boots");
   set("id",({"boots","dwarven boots"}));
   set("short","%^ORANGE%^Dwarven Boots%^RESET%^");
   set("long","These Dwarven Boots fits snugly on your feet.");
   set_type("metal foots");
 switch(random(3)){
      case 0:mtlname="mithril";break;
      case 1:mtlname="elrodnite";break;
      case 2:mtlname="platnite";break;
    }
   set_material("metal/"+mtlname);
   set_ac(60);
   set_limbs( ({"left foot", "right foot"}) );
   set_weight(110);
   set_value(800);
}

