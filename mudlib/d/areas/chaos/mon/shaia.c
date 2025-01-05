#include "../chaos.h"

inherit "/std/npc_shop";

void create() {
   ::create();
	set_name("shaia");
	set("id", ({"shopkeeper", "shop keeper", "shaia"}));
    add_money("gold", 1000);
	set_level(32);
	set("short", "Shaia, the Information Booth attendant");
	set_long("Shaia, the Information Booth attendant is one of the most beautiful woman you have every seen in your life.");
	set_gender("female");
   set_body_type("human");
	set("race", "high-elf");
	set_property("melee damage", ([ "impact" :30]));
	//set_skill("melee", 60);
	//set_skill("attack", 50);
	//set_skill("dodge", 60);
	set_skill("perception", 80);
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
	set("storage room", PATH+"shaia_shop");
	set("markup", 150);
}
