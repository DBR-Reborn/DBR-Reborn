// Wizard: Gellor
// Faelana the Herbalist
// faelana.c
inherit "/std/npc_shop";
void create() {
   ::create();
   set_name("faelana");
   set("id", ({"shopkeeper", "shop keeper", "faelana"}));
   add_money("gold", 1000);
   set_level(15);
   set_max_hp(10000000);
   set_hp(10000000);
   set_property("enhance criticals", -10);
   set_property("melee damage", ([ "crushing" : 99]));
   set("short","Faelana the herbalist");
   set("long","Not many female beings have the appearance of Faelana. "
   			  "She is about six feet tall, and has blond hair which "
              "is wavy and shoulder length. Her thin body is muscular, "
              "although not so much so that she looks grotesque, and "
              "tan making her quite attractive. She looks at you and "
              "smiles revealing her bright white teeth and beautiful "
              "mouth surrounded by thin lips. Her nose is small and "
              "rounded while her deep blue eyes are big and wide. ");
   set_gender("female");
   set_body_type("human");
   set("race", "wood-elf");
   set_skill("dodge", 70);
   set_skill("parry", 80);
   set_skill("martial arts", 50);
   set_skill("perception", 95);
   set_languages(({"common", "stormspeak", "elvish", "serra", "yin",
                   "dwarvish", "drow", "pix", "treefolk", "vr'krr", 
                   "middle-english", "catfolk","undead-tongue",
                   "hisaaa", "ogryn" }));
   set("storage room","/wizards/gellor/newfirn/shops/faelana_storage.c");
   set_stats("dexterity", 150);
   set_stats("strength", 200);
   set("num rounds", 2);
   set("markup", 50);
}
