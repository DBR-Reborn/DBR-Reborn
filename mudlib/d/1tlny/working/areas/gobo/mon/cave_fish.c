// This is the cavefish for Amel and Arctic's gobo area.
#include <std.h>

inherit MONSTER;

create() {
  ::create();
  set_name("cave fish");
  set_id( ({ "cave fish","fish"}) );
  set_short("A Cave Fish");
  set_long("The light reflects off the scales of this large silvery "
           "fish.  The head is marked with whiskers glowing eyes "
           "and a large gaping mouth.");
  set_body_type("serpent");
  set_gender("female");
  set_level(2);
  set_stats("intelligence", 20);
  set_property("melee damage", ([ "impaling" : 10]));
  set_skill("melee", 30);
  set_skill("dodge", 10);
  set_skill("parry", 5);
  set_stats("dexterity", 80);
  set_max_hp(75);
  set_hp(75);
  set_speed(60);
  set_emotes(10, ({"The fish splashes in the shallow water",
        "The fish swims towards you",
      "The fish darts through the water back and forth."}) ,1);
}
