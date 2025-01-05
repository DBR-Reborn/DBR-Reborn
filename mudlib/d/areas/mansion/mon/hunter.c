// hunter

#include "mansion.h"
inherit MONSTER;

void create() {
   string var;
   ::create();
    set_money("gold", 1+random(18));
   set_name("a hunter");
   set("id", ({"hunter", "frogman"}) );
   set_level(18);
   set("short", "[18]dark green frogman");
   set("long",
   "You see a large biped walking towards you.  Upon closer "
   "inspection you notice that it resembles a large frog, only "
   "with long claws and very sharp looking teeth."
   );
   set("race", "amphibion");
   set_gender("neuter");
   set_body_type("human");
   set("aggressive", 1);
}
