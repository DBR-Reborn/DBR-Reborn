#include <clock.h>
#include <def.h>
#include "../a1.h"

inherit "/std/armour";   
string mtlname;

void create() {
   ::create();
   set_name("dwarven helmet");
   set("id",({"helmet","dwarven helmet", "helm"}));
   set("short","%^ORANGE%^Dwarven Helmet%^RESET%^");
   set("long","This Dwarven helmet fits smoothly on your head.");
   set_type("metal head");
 switch(random(3)){
      case 0:mtlname="mithril";break;
      case 1:mtlname="elrodnite";break;
      case 2:mtlname="platnite";break;
    }
   set_material("metal/"+mtlname);
   set_ac(60);
   set_limbs( ({"head"}) );
   set_weight(110);
   set_value(800);
}

