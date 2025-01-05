#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
::create();
set_name("silver dragon");
set_level(100);
set_max_mp(50000);
set_mp(50000);
set_combat_chance(100);
set("id", ({ "dragon", "silver dragon", "ferocious dragon", "ferocious silver dragon" }));
set_short("[100] ferocious silver dragon");
set_long("You shudder with fear as this eight foot dragon lands on the ground in front of you and lets out a truly deafening roar. Its tough silver skin shines brightly as it spreads its enormous wings and prepares to attack, with its grisly face showing no hesitation.");
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
set_overall_ac(700);
set_money("gold", 1000);
set_money("mithril", 500);
set_property("gang bang", 1);
//set("aggressive",1);
return;
}
