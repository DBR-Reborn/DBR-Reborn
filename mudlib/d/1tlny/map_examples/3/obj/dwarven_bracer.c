#include <clock.h>
#include <def.h>
#include "../a1.h"

inherit "/std/armour";   
string mtlname;

void create() {
   ::create();
   set_name("dwarven bracer");
   set("id",({"bracer","dwarven bracer" }));
   set("short","%^ORANGE%^Dwarven Bracer%^RESET%^");
   set("long","This Dwarven Bracer fits smoothly on your arm.");
   set_type("metal arm");
 switch(random(3)){
      case 0:mtlname="mithril";break;
      case 1:mtlname="elrodnite";break;
      case 2:mtlname="platnite";break;
    }
   set_material("metal/"+mtlname);
   set_ac(60);
   set_limbs( ({ ({ "right arm", "left arm" }) }) );
   set_weight(110);
   set_value(800);
}

