#include <std.h>

inherit MONSTER;

void create() {
  ::create();
    set_name("grim");
    set_id( ({ "grim", "mine builder" }) );
    set_short("Grim Oredigger, the Mine Builder");
    set("race", "human");
    set_long(
    "Grim Irondigger is an experienced mine builder who will help you get everything going right.");
    set_gender("male");
    set_body_type("human");
    set_level(14);
    set_hp(200000);
   set_property("enhance criticals", -10);
    set_max_hp(200000);
    set_property("melee damage", ([ "crushing" : 99]));
    set_skill("melee", 185);
    set_skill("elementalism", 175);
    set_spell_level("elemental storm", 6);
    add_spell("elemental storm", "");
    set_skill("dodge", 60);
    set_skill("parry", 75);
    set_stats("dexterity", 90);
    set_skill("conjuration", 70);
    set_spell_level("ice dagger", 4);
    add_spell("ice dagger", "$A");
    set_combat_chance(80);
}
int query_num_rounds() { return 3; }

string query_element() { return "vacid"; }
