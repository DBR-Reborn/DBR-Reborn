#include <std.h>
inherit "/std/monster";

void create() {
   ::create();
   set_name("cat");
   set("id", ({"cat"}));
   set_level(3);
   set("short","A small black cat.");
   set("long", "It is a small black cat which looks at you with intelligence");
   set("race", "cat");
   set_body_type("quadruped");
   set_achats(30, ({
      "The cat stares at you.",
      "The cat hisses at you.",
      "The cat arches it's back and spits it's fury at you.",
      }) );
}




