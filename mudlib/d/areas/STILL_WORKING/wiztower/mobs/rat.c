#include <std.h>
inherit "/std/monster";

void create() {
   ::create();
   set_name("rat");
   set("id", ({"rat"}));
   set_level(3);
   set("short","A small brown rat");
   set("long", "It is a small brown rat with beady little eyes.");
   set("race", "rat");
   set_body_type("quadruped");
   set_achats(30, ({
      "The rat eyes you.",
      "The rat darts at you.",
      "The rat bares it's disease coated teeth at you.",
      }) );
}



