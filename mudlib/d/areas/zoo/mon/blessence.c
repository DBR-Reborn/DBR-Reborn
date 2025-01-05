#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    ::create();
    set_name("black essence");
    set("race", "spirit");
    set_combat_chance(120);
    set_id(({ "essence", "black essence", "shrouded essence", "shrouded black essence", "spirit", "undead" }));
    set_body_type("human");
    set_level(38);
    set_property("enhance criticals", -1);
    set_property("pet name", "black essence");
    set_overall_ac(250);
    set_short("[38]Shrouded Black Essence");
    set_property("pet short", "Shrouded Black Essence");
    call_out("nether_form_check", 0);
    set_long("As black as the night and as frightening in appearance as any material creature, this immaterial being truly appears to be a force to be reckoned with. Its entire body hovers about a foot above the ground and it shimmers at a seemingly never ending rate, giving impressions that it never has a period of rest and is always primed for inflicting harm at its most potent potential."); 
    set_skill("concentrate", 200);
    force_me("use concentrate");
    set_max_hp(3300 + 330*6);
    set_hp(3300 + 330*6);
    set_max_hp(3000 + 300*6);
    set_mp(3000 + 230*6);
    set_skill("attack", 35*6);
    set_skill("melee", 35*6);
    set_skill("dodge", 27*6);
    set_skill("parry", 31*6);
    set_skill("necromancy", 34*6);
    set_skill("owedquar's will", 34*6);
    add_spell("decay", "$A");
    set_spell_level("decay", 6);
    add_spell("black fire", "$A");
    set_spell_level("black fire", 6);
    set_property("melee damage", ([ "cutting" : 30 + (8 * 6), "crushing" : 30 + (8 * 6), "impaling" : 30 + (8 * 6)  ]));
    set_money("gold", random(200)*6);
    set_property("gang bang", 1);
    return;
}
