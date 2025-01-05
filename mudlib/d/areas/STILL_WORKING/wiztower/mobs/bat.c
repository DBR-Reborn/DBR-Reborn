#include <std.h>
inherit "/std/monster";

void create() {
   ::create();
   set_name("bat");
   set("id", ({"bat"}));
  set_level(2);
   set("short","A small black bat.");
   set("long", "It is a small black bat.");
   set("race", "bat");
   set_body_type("fowl");
   set_achats(30, ({
      "The bat swoops at you.",
      "The bat circles looking for an opening in your defense",
      "The bat darts forward on silent wings.",
      }) );
}


