#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    ::create();
    set_name("red ghoul");
    set("race", "undead");
    set_combat_chance(120);
    set_id(({ "ghoul", "red ghoul", "blood red ghoul", "blood ghoul", "undead" }));
    set_body_type("human");
    set_level(42);
    set_property("enhance criticals", -1);
    set_property("pet name", "red ghoul");
    set_overall_ac(300);
    set_short("[42]Blood Red Ghoul");
    set_property("pet short", "Blood Red Ghoul");
    call_out("nether_form_check", 0);
    set_long("This undead with its skin colored as red as the brightest blood stands nearly seven feet tall and looks as muscular as the bulkiest of barbarians. In addition to those muscles it also possesses claws reminicent of knives and teeth that despite being small appear sharp enough to bite directly through steel.");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    set_max_hp(3900 + 390*6);
    set_hp(3900 + 390*6);
    set_max_mp(3300 + 330*6);
    set_mp(3300 + 330*6);
    set_skill("attack", 40*6);
    set_skill("melee", 40*6);
    set_skill("dodge", 30*6);
    set_skill("parry", 34*6);
    set_property("melee damage", ([ "cutting" : 35 + (10 * 6), "crushing" : 35 + (10 * 6), "impaling" : 35 + (10 * 6)  ]));
	set_property("gang bang", 1);
    set_money("gold", random(200)*6);
    set("aggressive",1);
return;
}
