// Wizard: Gellor
// Schtel the Shopkeeper
// schtel.c
inherit "/std/npc_shop";
void create() {
   ::create();
   set_name("schtel");
   set("id", ({"shopkeeper", "shop keeper", "schtel"}));
   add_money("gold", 3500);
   set_level(10);
   set_exp(5000);
   set_max_hp(10000000);
   set_hp(10000000);
   set_property("enhance criticals", -10);
   set_property("melee damage", ([ "crushing" : 99]));
   set("short","Schtel the shopkeeper");
   set("long","Schtel is a short, stout, tough looking dwarf. His "
   			  "graying hair is well trimmed as is his like colored "
                "beard and mustache. His wide brown eyes are attentive, "
              "always looking for some detail to take note of or "
              "an item to profit from. He winks and smiles at you as "
              "you look around.");
   set_gender("male");
   set_body_type("human");
   set("race", "dwarf");
   set_skill("dodge", 70);
   set_skill("parry", 80);
   set_skill("martial arts", 50);
   set_skill("perception", 95);
   set_languages(({"common", "stormspeak", "elvish", "serra", "yin",
                   "dwarvish", "drow", "pix", "treefolk", "vr'krr", 
                   "middle-english", "catfolk","undead-tongue",
                   "hisaaa", "ogryn" }));
   set("storage room","/wizards/gellor/newfirn/shops/schtel_storage.c");
   set_stats("dexterity", 150);
   set_stats("strength", 200);
   set("num rounds", 2);
   set("markup", 50);
}
