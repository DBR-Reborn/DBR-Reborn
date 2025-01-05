#include <std.h>
inherit "/std/monster";

void create() {
   ::create();
   set_name("Fairy dragon");
   set("id", ({"dragon","fairy dragon"}));
   set_level(4+random(3));
   set("short","A fairy dragon");
   set("long", "You see before you a rare and beautiful creature.");
   set("race", "dragon");
   set_body_type("dragon");
   set_money("gold", random(50)+random(10));
   set_achats(30, ({
      "The dragon spits a small cloud at you.",
      "The dragon hisses his wrath",
      "Claws menacingly at you.",
      }) );
}

