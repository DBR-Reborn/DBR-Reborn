//          Wizard: Delsius
//          bat
//          June 97

#include <std.h>
#include <daemons.h>
inherit MONSTER;

create () {
   string var;
   ::create();
   set_name("vampire bat");
   set_id( ({"vampire bat","bat"}) );
   set("race","bat");
   set_short("A vampire bat");
   set_long("Trying to hide from the lethal sunlight from the outside "
            "world, this flying varmint lives in the tunnel system.  "
            "Since it IS a vampire bat, it's slightly larger than your "
            "typical one, and it's more deadly.");
   set_level(15 + random (2));
   set_max_hp(1000);
   set_hp(1000);
   set_max_mp(1250);
   set_mp(1250);
   set("gang bang", 0);
   set_skill("melee",75);
   set_skill("dodge",75);
   add_money("gold",5 + random(3));
   set_property("base mp regen",50);
   switch(random(2)) {
     case 0: var = "female"; break;
     case 1: var = "male"; break;
}
   set_gender(var);
   set_body_type("bat");
   set_moving(1);
   set_speed(120);
   set_property("melee damage", (["cutting" : 20]));
   set_emotes(5, ({"The bat swoops by your head.",
                   "The bat flutters around your face.",
                   "The bat makes some squeaking noises."}));
}
   void remove() {
   MOB_TRACK_D->mob_minus("vampire bat");
   ::remove();
}
