//          Wizard: Delsius
//          ghost
//          May 97

#include <std.h>
inherit MONSTER;

create () {
   string var;
   ::create();
   set_name("ghost");
   set_id(({"ghost","spirit","entity","apparition"}));
   set("race", "undead");
   switch(random(3)) {
      case 0: var = "A ghastly spirit"; break;
      case 1: var = "The ghost of a tunnel worker"; break;
      case 2: var = "A hovering entity"; break;
}
   set("short", var);
   set_long("This apparition was once a hard-working tunnel worker "
            "who met his demise at the hands of something within "
            "the tunnel system.  It stares at you with empty eyes "
            "sending cold chills up your spine.");
   set_body_type("human");
   set_level(16 + random(3));
   set_hp(1500);
   set_max_hp(1500);
   set_property("physical resistance", (["default": 25]));
   set_overall_ac(20);
   set_property("melee damage", (["vacuum":25]));
   set_skill("melee",100);
   set_skill("dodge",75);
   set_skill("parry",25);
   set_stats("strength",100);
   set_stats("dexterity",100);
   set("gang bang", 0);
   set_emotes(5, ({"The apparition moans in agony.",
                   "The apparition floats slowly past you.",
                   "The apparition stares at you with it's cold gaze."}));
}
