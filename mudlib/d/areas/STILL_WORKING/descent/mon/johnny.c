#include "../descent.h"
inherit "/std/npc_shop";

void create() {
   ::create();
   set_name("johnny");
   set("id", ({"shopkeeper", "shop keeper", "johnny"}));
    add_money("gold", 3500);
   set_level(100);
   set_exp(5000);
   set_max_hp(10000000);
   set_hp(10000000);
   set_property("enhance criticals", -9);
   set_property("melee damage", ([ "crushing" : 99]));
   set("short","Johnny Applesbee, the proprietor of this fine establishment");
   set("long",
"Johnny Applesbee is a friendly dwarf who has a friendly smile and a good word for all who come by the shop, be it a Gnome or some other race.");
   set_gender("male");
   set_body_type("human");
   set("race", "gnome");
   set_skill("nexus lore", 350);
   set_skill("elementalism", 350);
   set_spell_level("elemental storm", 6);
   add_spell("elemental storm", "");
   set_combat_chance(150);
   set_skill("dodge", 500);
   set_skill("parry", 600);
   set_skill("ripost", 175);
   set_skill("martial arts", 600);
   set_skill("perception", 700);
   set_languages(({"common", "stormspeak", "elvish", "serra", "yin", "dwarvish",
                "drow", "pix", "treefolk", "vr'krr", "middle-english",
		"catfolk","undead-tongue", "hisaaa", "ogryn" }));
   set("storage room",ROOMS+"store");
   set_stats("dexterity", 150);
   set_stats("strength", 200);
   set("num rounds", 2);
   set("markup", 50);
}

void catch_tell(string str) {
    string tmp, tmp2;
    if(sscanf(str, "Your %s is severed!", tmp)) {
      call_out("new_body", 3);
    }
}
