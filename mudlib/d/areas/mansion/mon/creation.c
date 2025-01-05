// creation

#include "mansion.h"
inherit MONSTER;

void create() {
   string var;
   ::create();
    set_money("gold", 1+random(20));
   set_name("hideous creation");
   set("id", ({"creation"}) );
   set_level(20);
   set_short("[20]hideous creation");
   set("long",
   "You see a HUGE creature stomping around the room.  Most of its "+
   "vital organs appear to be on the outside of its body.  It seems "+
   "that the body was made up of parts from ogres, giants, and whatever "+
   "gave it that strange claw for a right hand.");
   set("race", "undead");
   set_gender("neuter");
   set_body_type("human");
   set_property("melee damage", (["cutting":150]));
   set_overall_ac(20);
   set_stats("strength", 200);
   set_stats("dexterity", 200);
   set_emotes(5, ({
                   "The creature snarls and stomps towards you.",
                   "The creature pauses for a deafening howl.",
                   }), 0);
   set("aggressive", 1);
}
