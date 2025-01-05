#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"
inherit "/std/npc_shop";

void create() {
  ::create();
   set_name("rob");
   set("id", ({"shopkeeper", "shop keeper", "rob"}) );
   set_level(12);
   set_property("enhance criticals", -10);
   set("storage room",TARAROOMS+"sp1_store");
   add_money("gold", 1000);
   set_max_hp(50000);
   set_hp(50000);
   set("short","Rob, the General Store shopkeep");
   set("long", @ROB
Rob is a middle aged halfling, he runs a general store
during the daylight hours in the town of Tara.  Like most
shopkeepers need to be, he is very strong and would not be
smart to mess with.  He smiles at you kindly, and inquires
on what you would like to buy or sell.
ROB
);
   set_gender("male");
   set_body_type("human");
   set("race", "halfling");
  set_languages(({"common", "stormspeak", "elvish", 
"serra", "yin", "dwarvish", "drow", "pix", "treefolk", 
"vr'krr", "middle-english", "catfolk", "undead-tongue",
"hisaaa", "ogryn" }) );
   set("num rounds", 2);
   set("markup", 50);
   set_skill("perception", 100);
   set_skill("elementalism", 80);
   set_spell_level("elemental storm", 6);
   add_spell("elemental storm", "");
   set_combat_chance(80);
   set_skill("concentrate", 100);
   force_me("use concentrate");
   set_skill("martial arts", 50);
   set_property("melee damage", ([ "crushing" : 99]));
}

string query_element() { return "wind"; }
