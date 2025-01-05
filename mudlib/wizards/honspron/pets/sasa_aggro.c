#include <std.h>
//#include "../zoo.h"

inherit MONSTER;

object ob;

void create() {
    ::create();
    set_name("sasa");
    set("race", "thranx");
    set_combat_chance(120);
    set("id", ({ "sasa", "samoan"}));
    set_body_type("thranx");
    set_property("ambidextry", 1);
    add_limb("first arm", 0, 1000, 0, 4);
    add_limb("second arm", 0, 1000, 0, 4);
    add_limb("third arm", 0, 1000, 0, 4);
    add_limb("fourth arm", 0, 1000, 0, 4);
    add_limb("fifth arm", 0, 1000, 0, 4);
    set_level(100);
    set_property("enhance criticals", -20);
    set_overall_ac(1111);
    set_short("[100]%^BOLD%^%^RED%^Sasa, %^BOLD%^%^WHITE%^the %^BOLD%^%^BLUE%^Behemoth%^RESET%^");
    set_long("As you behold Sasa, the only thing you can think about is running away... far enough to no get hit by da slippahs.");
    ob = new("/d/damned/guilds/nethermancer/misc/ed_shield.c");
    ob->move(this_object());
    ob = new("/wizards/honspron/obj/sasa_two_handed.c");
    ob->move(this_object());
    ob = new("/wizards/honspron/obj/sasa_two_handed.c");
    ob->move(this_object());
    ob->set_damage_allowed(25000);
    ob->set_shadow_name("eternal darkness shield");
    ob->start_shadow(this_object(), 2000000000, "");
    ob = new("/std/spells/shadows/ele_pres_shad");
    ob->set_power(5);
    ob->set_damage(({ "infernal", "aether" }));
    ob->set_shadow_name("eternal darkness presence");
    ob->start_shadow(this_object(), 2000000000, "");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    force_me("wield stick in first hand and second hand");
    force_me("wield stick 2 in third hand and fourth hand");
    set_max_hp(50000 + 5000*6);
    set_hp(50000 + 5000*6);
    set_max_mp(40000 + 4000*6);
    set_mp(40000 + 4000*6);
    set_skill("offhand training", 150*6);
    set_skill("dual attack", 150*6);
    set_skill("attack", 150*6);
    set_skill("melee", 150*6);
    set_skill("two handed blunt", 145*6);
    set_skill("dodge", 100*6);
    set_skill("parry", 120*6);
    set_skill("warcasting", 111*6);
    set_skill("assassin's magic", 111*6);
    set_skill("spiritmancy", 111*6);
    set_skill("necromancy", 111*6);
    set_skill("elementalism", 111*6);
    set_skill("chaos lore", 111*6);
    add_spell("dark breath", "$A");
    set_spell_level("dark breath", 6);
    add_spell("decay", "$A");
    set_spell_level("decay", 6);
    add_spell("pain", "$A");
    set_spell_level("pain", 6);
    set_property("melee damage", ([ "nexus" : 75 + (20 * 6), "infernal" : 75 + (20 * 6), "time" : 75 + (20 * 6), "aether" : 75 + (20 * 6), "sonic" : 75 + (20 * 6) ]));
	set_property("gang bang", 1);
    set_money("gold", 1000000);
    set_money("mithril", 1000000);
    set("aggressive",1);
return;
}