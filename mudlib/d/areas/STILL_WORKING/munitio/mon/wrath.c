// gate guard
// 

inherit "/std/monster";

void create() {
     ::create();
     set_name("Wrath");
     set("id", ({"wrath"}) );
     set_level(30);
     set("short", "A vile looking wrath");
     set("long", "This monstrosity has extremely long and lithe limbs. It moves with an almost sickening speed and agility. It's green skin looks extrordinarily tough as well. It guards the elder blacksmiths with a single-mindedness that's simply terrifying...");
     set("race", "undead");
     set_overall_ac(100);
     set_skill("melee", 250);
     set_skill("martial arts", 100);
     set_skill("dodge", 200);
     set_property("handedness", "left hand");
     set_body_type("humanoid");
     set_languages( ({ "common" }) );
set_lang_prof("common",10);
force_me("speak common");
     set_speech(1, "common", ({
          "I'll gut you like a fish..."
     }),0);
     set_achats(10, ({
          "The wrath lunges at you"
	}) );
}
