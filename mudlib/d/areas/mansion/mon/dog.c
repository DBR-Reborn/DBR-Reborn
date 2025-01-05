// undead hound 

#include "mansion.h"
inherit MONSTER;

void create() {
   string var;
   ::create();
    set_money("gold", 1+random(10));
   set_name("undead hound");
   set("id", ({"hound", "dog", "undead", "flesh"}) );
   set_level(10);
   switch(random(3)) {
           case 0: var = "hungry looking dog"; break;
           case 1: var = "disgusting pile of flesh"; break;
           case 2: var = "undead hound"; break;
   }
   this_object()->set("short", "[10]"+var);
   set("long",
   "You see the rotted remains of some sort of dog.  Bare ribs show "
   "through flapping lengths of decaying flesh and muscle."
   );
   set("race", "dog");
   set_gender("neuter");
   set_body_type("quadruped");
   set_emotes(5, ({
                   "The undead howls, sending chills down your spine.",
                   "The rotting dog lets out a low growl.",
                   }), 0);
   set("aggressive", 1);
   set_property("melee damage", (["cutting":20]));
}
