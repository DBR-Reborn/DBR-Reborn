#include <std.h>
#include "../zoo.h"

inherit MONSTER;

object ob;

void create() {
    ::create();
    set_name("sasa");
    set("race", "samoan");
    set_combat_chance(120);
    set("id", ({ "sasa", "samoan"}));
    set_body_type("human");
    set_level(100);
    set_property("enhance criticals", -20);
    set_overall_ac(1111);
    set_short("[100]%^BOLD%^%^RED%^Sasa, %^BOLD%^%^WHITE%^the %^BOLD%^%^BLUE%^Behemoth%^RESET%^");
    set_long("As you behold Sasa, the only thing you can think about is running away... far enough to no get hit by da slippahs.");
    ob = new(OBJ+"sasa_stick.c");
    ob->move(this_object());
    ob = new(OBJ+"sasa_stick.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/ed_shield.c");
    ob->move(this_object());
    ob->set_damage_allowed(25000);
    ob->set_shadow_name("eternal darkness shield");
    ob->start_shadow(this_object(), 2000000000, "");
    /*ob = new("/std/spells/shadows/ele_pres_shad");
    ob->set_power(5);
    ob->set_damage(({ "infernal", "aether" }));
    ob->set_shadow_name("eternal darkness presence");
    ob->start_shadow(this_object(), 2000000000, "");*/
    set_skill("concentrate", 500);
    force_me("use concentrate");
    force_me("equip");
    set_max_hp(50000 + 5000*6);
    set_hp(50000 + 5000*6);
    set_max_mp(40000 + 4000*6);
    set_mp(40000 + 4000*6);
    set_skill("offhand training", 150*6);
    set_skill("dual attack", 150*6);
    set_skill("attack", 150*6);
    set_skill("melee", 150*6);
    set_skill("blunt", 145*6);
    set_skill("dodge", 100*6);
    set_skill("parry", 120*6);
    set_skill("black magic", 111*6);
    set_skill("elementalism", 111*6);
    set_skill("nexus lore", 111*6);
    force_me("use nexus lore");
    add_spell("decay", "$A");
    set_spell_level("decay", 6);
    add_spell("syphon soul", "$A");
    set_spell_level("syphon soul", 6);
    add_spell("greater elemental storm", "$A");
    set_spell_level("greater elemental storm", 6);
    add_spell("greater elemental strike", "$A");
    set_spell_level("greater elemental strike", 6);
	set_property("melee damage", ([ "cold" : 100 + (10 * 6), "unholy" : 100 + (10 * 6), "infernal" : 100 + (10 * 6), "disruption" : 100 + (10 * 6) ]) );
	set_property("gang bang", 1);
    set_money("gold", 1000);
    set_money("mithril", 1000);
return;
}
