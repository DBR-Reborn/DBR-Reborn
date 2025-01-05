#include "giants_paths.h"
inherit "/std/npc_shop";

void create() {
  object ob;

   ::create();
   set_name("conrad");
   set("id", ({"conrad", "shopkeeper", "conrad stormbeard", "stormbeard",
"shop keeper"}));
   add_money("gold", 5000);
   set_level(25);
   set_exp(13000000);
   set_property("enhance criticals", -10);
   set_hp(2000000);
   set_max_hp(2000000);
   set("short","Conrad Stormbeard, the shopkeeper");
   set("long", @EndText
Conrad Stormbeard is a massive storm giant.
His body is muscular and torn from endless
years at the forge.
EndText
);
   set_gender("male");
   set_body_type("human");
   set("race", "storm-giant");
   set_property("melee damage", ([ "crushing" : 99, "electricity" : 99]));
   set_skill("elementalism", 120);
   set_spell_level("elemental storm", 6);
   add_spell("elemental storm", "");
   set_combat_chance(80);
   set_stats("strength", 175);
   set_skill("dodge", 170);
   set_skill("parry", 180);
   set_skill("martial arts", 150);
   set_skill("perception", 190);
   set_languages(({"common", "stormspeak", "elvish", "serra", "yin",
"dwarvish",
                "drow", "pix", "treefolk", "vr'krr", "middle-english",
                           "catfolk", "ogryn" }));
   set("storage room",ROOMS_PATH+"gen_storage.c");
   set("markup", 60);
   set_property("handedness", "right hand");
   set("no sell", 1);
   ob = new("/d/damned/virtual/breast-plate.armour");
   ob->move(this_object());
   ob = new("d/damned/virtual/plate-greaves.armour");
   ob->move(this_object());
   ob = new("d/damned/virtual/metal-bracer.armour");
   ob->move(this_object());
   ob = new("d/damned/virtual/metal-bracer.armour");
   ob->move(this_object());
   force_me("wear breast plate");
   force_me("wear bracer on left arm");
   force_me("wear bracer 2 on right arm");
   force_me("wear greaves");
}

int query_num_rounds() { return 3; }

string query_element() { return "ice"; }

