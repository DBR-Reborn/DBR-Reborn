#include "../newshards.h"
inherit "/std/npc_shop";

void create() {
    object ob;

    ::create();
    set_name("tinkerfiddle");
    set("id", ({"tinkerfiddle", "shopkeeper", "shop keeper"}));
    set_level(30);
    add_money("gold", 15000);
    set("restock", 2000);
    set_exp(3000000);
    set_property("enhance criticals", -10);
    set_hp(200000);
    set_max_hp(200000);
    set("short","Tinkerfiddle, the shopkeeper");
    set("long",
      "Tinkerfiddle is a middle-aged gnome. He's typical of the race - short, and slightly plump. Yet, oddly, he doesn't wear the jovial expression that most gnomes have");
    set_gender("male");
    set_body_type("human");
    set("race", "rock-gnome");
    set_property("melee damage", ([ "crushing" : 99]));
    set_skill("elementalism", 120);
    set_spell_level("elemental storm", 6);
    add_spell("elemental storm", "");
    set_combat_chance(80);
    set_stats("strength", 105);
    set_stats("dexterity", 95);
    set_skill("two handed polearm", 90);
    set_skill("dodge", 70);
    set_skill("parry", 80);
    set_skill("martial arts", 50);
    set_skill("perception", 90);
    set_languages(({"common", "stormspeak", "elvish", "serra", "yin", "dwarvish",
	"drow", "pix", "treefolk", "vr'krr", "middle-english",
	"catfolk", "ogryn" }));
    set("storage room",ROOMS+"shop5_store");
    set("markup", 60);
    set_property("handedness", "right hand");
    set("no sell", 0);
    set("pre sell function", (: call_other, this_object(), "only_armour" :));
    ob = new("/d/damned/virtual/breast-plate.armour");
    ob->move(this_object());
    ob = new("d/damned/virtual/studded-leather-glove.armour");
    ob->move(this_object());
    ob = new("d/damned/virtual/studded-leather-glove.armour");
    ob->move(this_object());
    ob = new("d/damned/virtual/leather-pants.armour");
    ob->move(this_object());
    force_me("wear breast plate");
    force_me("wear glove on left hand");
    force_me("wear glove 2 on right hand");
    force_me("wear pants");
}

string only_armour(object item) {
    if(!item->is_armour()) return "I only buy armour.";
    return 0;
}
int query_num_rounds() { return 3; }

string query_element() { return "vacid"; }
void die(){
    set_money("gold", 0);
    ::die();
}

