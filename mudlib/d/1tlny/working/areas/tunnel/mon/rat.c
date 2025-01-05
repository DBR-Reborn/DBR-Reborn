//          Wizard: Delsius
//          rat
//          June 97

#include <std.h>
#include <daemons.h>
inherit MONSTER;

create () {
   string var;
   ::create();
   set_name("rat");
   set_id(({"rodent","rat","filthy rat","tunnel rat","pesty rat"}));
   set("race","rodent");
   set_level(15 + random (3));
   switch(random(2)) {
     case 0: var = "female"; break;
     case 1: var = "male"; break;
}
   set_gender(var);
   switch(random(3)) {
      case 0: var = "A tunnel rat"; break;
      case 1: var = "A filthy looking rat"; break;
      case 2: var = "A pesty rat"; break;
}
   set("short", var);
   set_moving(1);
   set_speed(120);
   set_long("Scurrying about the tunnel system are numerous of these "
            "large rats.  Their diet mainly consists of rotted pieces "
            "of flesh and sometimes the feces of other creatures.  "
            "Ugh... these things are disgusting.");
   set_emotes(5, ({"The rat scurries about the tunnel.",
                    "The rat begins to gnaw at your leg.",
                    "The rat wallows in it's on feces."}));
}
   void remove() {
   MOB_TRACK_D->mob_minus("tunnel rat");
   ::remove();
}
