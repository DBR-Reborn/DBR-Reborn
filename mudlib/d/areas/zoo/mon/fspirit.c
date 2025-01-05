#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    ::create();
    set_name("fanged spirit");
    set("race", "spirit");
    set_combat_chance(120);
    set_id(({ "spirit", "fanged spirit", "ghost", "undead" }));
    set_body_type("human");
    set_level(33);
    set_property("enhance criticals", -1);
    set_property("pet name", "fanged spirit");
    set_overall_ac(250);
    set_short("[33]Fanged Spirit");
    set_property("pet short", "Fanged Spirit");
    call_out("nether_form_check", 0);
    set_long("This is a rather peculiar ghostly being, for it appears to have both immaterial and material aspects. The entire main body of the spirit is blood red mist, butseveral three inch teeth hang down from the mouth area thatm are actually real and look as if they can do serious damage to even a well armoured warrior. Coupled along with this anomaly are wails so high pitched that even the most patient person would strongly consider running for cover from.");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    set_max_hp(2600 + 260*6);
    set_hp(2600 + 260*6);
    set_max_hp(2300 + 230*6);
    set_mp(2300 + 230*6);
    set_skill("attack", 32*6);
    set_skill("melee", 32*6);
    set_skill("dodge", 24*6);
    set_skill("parry", 28*6);
    set_skill("necromancy", 30*6);
    set_skill("spiritmancy", 30*6);
    add_spell("curse", "$A");
    set_spell_level("curse", 6);
    add_spell("devour soul", "$A");
    set_spell_level("devour soul", 6);
    set_property("melee damage", ([ "cutting" : 29 + (8 * 6), "crushing" : 29 + (8 * 6), "impaling" : 29 + (8 * 6)  ]));
    set_property("gang bang", 1);
    set_money("gold", random(200)*6);
return;
}
