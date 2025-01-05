// Wizard: Gellor
// Jesip the Shopkeeper
// jesip.c
inherit "/std/npc_shop";
void create() {
   ::create();
   set_name("jesip");
   set("id", ({"shopkeeper", "shop keeper", "jesip"}));
   add_money("gold", 7000);
   set_level(10);
   set_exp(5000);
   set_max_hp(10000000);
   set_hp(10000000);
   set_property("enhance criticals", -10);
   set_property("melee damage", ([ "crushing" : 99]));
   set("short","Jesip the shopkeeper");
   set("long","Jesip is about six and a half feet tall and is "
   			  "annoyingly skinny. His looks at you from his black "
              "eyes planted in a long, thin face. The top of his "
              "head is covered with thick black hair which makes "
              "his white-ish skin appear even more pale. A natural "
              "aura of warmth and charisma surrounds him making "
              "you feel more comfortable dealing with him.");
   set_gender("male");
   set_body_type("human");
   set("race", "drow-elf");
   set_skill("dodge", 70);
   set_skill("parry", 80);
   set_skill("martial arts", 50);
   set_skill("perception", 95);
   set_languages(({"common", "stormspeak", "elvish", "serra", "yin",
                   "dwarvish", "drow", "pix", "treefolk", "vr'krr", 
                   "middle-english", "catfolk","undead-tongue",
                   "hisaaa", "ogryn" }));
   set("storage room","/wizards/gellor/newfirn/shops/jesip_storage.c");
   set_stats("dexterity", 150);
   set_stats("strength", 200);
   set("num rounds", 2);
   set("markup", 50);
}
