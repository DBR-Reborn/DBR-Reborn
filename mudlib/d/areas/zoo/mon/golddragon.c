#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
::create();
set_name("gold dragon");
set_level(100);
set_max_mp(50000);
set_mp(50000);
set_combat_chance(100);
set("id", ({ "dragon", "gold dragon", "beautiful dragon", "beautiful gold dragon" }));
set_short("[100] beautiful gold dragon");
set_long("You stand in awe as you look over this beast, Its entire body is fashioned of pure gold and shines endlessly, producing perhaps the most beautiful creature you have ever seen. The air surrounding it becomes an unusually bitter cold as it surveys you, and as frostbiting winds swirl about its mouth.");
set("race", "dragon");
set_gender("neuter");
set_body_type("humanoid");
set_alignment(-200);
set_skill("owedquar's will", 500);
set_skill("melee", 600);
set_skill("martial arts", 600);
set_skill("attack", 800);
set_skill("conjuration", 500);
set_skill("parry", 500);
set_skill("dodge", 700);
set_skill("perception", 1000);
set_skill("concentrate", 500);
set_stats("wisdom", 1000);
add_spell("violent blaze", "$A");
set_spell_level("violent blaze", 6);
set_property("enhance criticals", -50);
force_me("use concentrate");
set_overall_ac(1500);
set_money("gold", 1000);
set_money("mithril", 500); 
set_property("gang bang", 1);
//set("aggressive",1);
return;
}
