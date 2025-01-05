#include "../newshards.h"
inherit "/std/npc_shop";

void create() {
    ::create();
    set_name("blackwind");
    set("id", ({"shopkeeper", "shop keeper", "blackwind", "blackwind raddix", "raddix"}));
    set_level(30);
    add_money("gold", "30000");
    set("restock", 6000);
    set_exp(5000);
    set_max_hp(10000000);
    set_hp(10000000);
    set_property("enhance criticals", -10);
    set_property("melee damage", ([ "crushing" : 99]));
    set("short","Blackwind Raddix, the shopkeeper");
    set("long", "Blackwind Raddix must have been a soldier at one point in his life, because he looks like the buffest guy you've ever seen..");
    set_gender("male");
    set_body_type("human");
    set("race", "high-man");
    set_skill("elementalism", 75);
    set_spell_level("elemental storm", 6);
    add_spell("elemental storm", "");
    set_combat_chance(100);
    set_skill("dodge", 70);
    set_skill("parry", 80);
    set_skill("martial arts", 50);
    set_skill("perception", 95);
    set_languages(({"common", "stormspeak", "elvish", "serra", "yin", "dwarvish",
	"drow", "pix", "treefolk", "vr'krr", "middle-english",
	"catfolk","undead-tongue", "hisaaa", "ogryn" }));
    set("storage room",ROOMS+"shop1_store");
    set_stats("dexterity", 150);
    set_stats("strength", 200);
    set("num rounds", 2);
    set("markup", 50);
}
void die(){
    set_money("gold", 0);
    ::die();
}

