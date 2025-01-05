#include <std.h>
inherit "/std/monster";

void create() {
   ::create();
   set_name("elemental");
   set("id", ({"elemental","flame elemental"}));
   set_level(5+random(3));
   set("short","A elemental");
   set("long", "You see before you a pulsating humanoid creature made entirely of hot flame.");
   set("race", "elemental");
   set_body_type("human");
   set_wielding_limbs( ({ "right hand", "left hand" }) );
   set_money("gold", random(50)+10);
    set_property("aggressive", 1);
   set_achats(30, ({
      "The elemental spits flame in your direction.",
      "The elemental sizzles",
      "The elemental flares even brighter.",
      }) );
   force_me("wear ring on right hand");
}
