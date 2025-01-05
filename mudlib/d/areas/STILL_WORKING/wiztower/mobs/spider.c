#include <std.h>
inherit "/std/monster";

void create() {
   ::create();
   set_name("spider");
   set("id", ({"spider"}));
   set_level(1+random(3));
   set("short","A spider");
   set("long", "It is a hairy spider with sharp mandibles.");
   set("race", "spider");
   set_body_type("arachnid");
}



