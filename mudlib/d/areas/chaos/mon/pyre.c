#include "../chaos.h"

inherit "/std/npc_shop";


void create() {
   ::create();
	set_name("pyre");
	set("id", ({"shopkeeper", "shop keeper", "pyre"}));
    add_money("gold", 1000);
	set_level(32);
	set("short", "[32]Pyre, the Equipment Store owner");
	set_long("Pyre, the Equipment Store owner.  Pyre is a bright faced, red hair shopkeeper.  Always Jovial, and happy to help you out if you need something. Although his pot belly keeps him from doing certain things.");
	set_gender("male");
   set_body_type("human");
	set("race", "high-man");
	set_property("melee damage", ([ "impact" :30]));
	//set_skill("melee", 60);
	//set_skill("attack", 50);
	//set_skill("dodge", 60);
	//set_skill("perception", 80);
	set_stats("charisma", 150);
   set_languages(({"common", "stormspeak", "elvish", "serra", "yin",
     "dwarvish", "drow", "middle-english", "mountainspeak" }));
   set_lang_prof("stormspeak",8);
   set_lang_prof("elvish",10);
   set_lang_prof("serra",8);
   set_lang_prof("yin",8);
   set_lang_prof("dwarvish",9);
   set_lang_prof("drow",10);
   set_lang_prof("middle-english",7);
   set_lang_prof("mountainspeak",8);
	set("storage room", PATH+"pyre_shop");
	set("markup", 150);
}
