#include <shao.h>
inherit "/std/npc_shop";

void init(){
::init();
add_action("check_out","check");
add_action("ask_room","ask about");
}

void create() {
  object ob;

   ::create();
set_name("christina");
set("id",({"christina","owner","boutique owner","perky","shopkeeper"}));
   add_money("gold", 5000);
   set_level(40);
//She's young, and probably shouldn't be level 40, but 
//she's a shop keeper, and I want to make sure it will
//be DAM hard for a player to kill her.
set_exp(100);
//Low Exp -How much should someone learn
//from slaughtering an inocent, next_to helpless
//female ?
   set_property("enhance criticals", -10);
   set_hp(200000);
   set_max_hp(200000);
set("short","Christina the boutique owner");
   set("long",
"Sabrina is a young female human.\n"
"Her soothing blue eyes, and long flowing blond hair "
"only complement her attractive smile and appealing "
"curves.  Every inch of her 5'1 body is firm and toned, "
"you wish you could check out every inch of her, but you "
"suspect that skinning corpses and crafting leather isn't "
"the only thing her hands are capable of, so you don't "
"want to offend her.\n");
   set_gender("female");
   set_body_type("human");
   set("race", "human");
   set_property("melee damage", ([ "crushing" : 99]));
   set_combat_chance(80);
set_skill("knife",300);
//High knife skill due to fact she is a leather
//crafter and has been useing them since a very young
//age... 
set_property("ambidextry",1);
set_stats("dexterity",250);
set_skill("dual attack",150);
   set_languages(({"common", "stormspeak", "elvish", "serra", "yin", "dwarvish",
                "drow", "pix", "treefolk", "vr'krr", "middle-english",
		            "catfolk", "ogryn" }));
set("storage room",PATH+"leather_store");
   set("markup", 60);
set_wielding_limbs( ({"right hand", "left hand"}) );
   set("no sell", 1);
ob = new(ARMOR_PATH+"l_bra");
   ob->move(this_object());
   ob = new("d/damned/virtual/studded-leather-glove.armour");
   ob->move(this_object());
   ob = new("d/damned/virtual/studded-leather-glove.armour");
   ob->move(this_object());
ob = new(ARMOR_PATH+"l_thong");
   ob->move(this_object());
ob = new(ARMOR_PATH+"l_boot");
ob->move(this_object());
ob = new(ARMOR_PATH+"l_boot");
ob->move(this_object());
force_me("wear boot on right foot");
force_me("wear boot 2 on left foot");
ob = new(WEAP_PATH+"juggler_knife");
ob->move(this_object());
ob = new(WEAP_PATH+"juggler_knife");
ob->move(this_object());
force_me("wield knife in left hand");
force_me("wield knife 2 in right hand");
force_me("wear bra");
   force_me("wear glove on left hand");
   force_me("wear glove 2 on right hand");
force_me("wear thong");
}

int query_num_rounds() { return 3; }

string query_element() { return "vacid"; }
