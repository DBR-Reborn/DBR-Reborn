#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("dark knight");
    set("race", "undead");
    set_id(({ "knight", "dark knight", "dark knight of the abyss", "knight of the abyss", "undead" }));
    set_body_type("human");
    set_level(45);
    set_property("enhance criticals", -1);
    set_property("pet name", "dark knight");
    set_overall_ac(300);
    set_short("[45]Dark Knight of the Abyss");
    set_property("pet short", "Dark Knight of the Abyss");
    call_out("nether_form_check", 0);
    set_long("This is a powerful looking knight that appears to be a living suit of darkened steel armour, with no visible body parts through its extremely small cracks. A large sword and shield are present in its hands, both of which could pass as equipment of choice for even a seasoned warrior.");
    ob = new("/d/damned/guilds/nethermancer/misc/black_sword.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/black_shield.c");
    ob->move(this_object());
    force_me("wield sword in right hand");
    force_me("wear shield on left hand");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    set_max_hp(5000 + 500*6);
    set_hp(5000 + 500*6);
    set_max_mp(4100 + 410*6);
    set_mp(4100 + 410*6);
    set_skill("attack", 44*6);
    set_skill("melee", 44*6);
    set_skill("blade", 44*6);
    set_skill("dodge", 33*6);
    set_skill("block", 35*6);
    set_skill("parry", 38*6);
    set_skill("offhand training", 50*6);
    set_skill("necromancy", 40*6);
    set_skill("owedquar's will", 40*6);
    add_spell("lifesteal", "$A");
    set_spell_level("lifesteal", 6);
    add_spell("owedquar's might", "$A");
    set_spell_level("owedquar's might", 6);
    set_property("melee damage", ([ "crushing" : 35 + (10 * 6), "cold" : 35 + (10 * 6)  ]));
    set_money("gold", random(200)*6); 
	set_property("gang bang", 1);
	set("aggressive",1);
    return;
}
