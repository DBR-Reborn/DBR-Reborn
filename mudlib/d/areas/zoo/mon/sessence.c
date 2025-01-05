#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    ::create();
    set_name("skeletal essence");
    set("race", "spirit");
    set_combat_chance(120);
    set_id(({ "essence", "skeleton", "skeletal essence", "misty essence", "misty skeleton", "misty skeletal essence", "undead" }));
    set_body_type("human");
    set_level(28);
    set_property("enhance criticals", 0);
    set_property("nethermancer pet", 1);
    set_property("pet name", "skeletal essence");
    set_overall_ac(200);
    set_short("[28]Misty Skeletal Essence");
    set_property("pet short", "Misty Skeletal Essence");
    call_out("nether_form_check", 0);
    set_long("This rather shrouded creature appears to be made up of such dense mist that one could say it looks real and not immaterial. It has the makeup of a very complex skeleton with rather sharp toes and fingers as well as glowing holes in its palms for releasing magical energy. No sounds are heard in any of its movements, not even those of slight drafts from the mist in motion.");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    set_max_hp(1500 + 150*6);
    set_hp(1500 + 150*6);
    set_skill("attack", 28*6);
    set_skill("melee", 28*6);
    set_skill("dodge", 21*6);
    set_skill("parry", 24*6);
    set_skill("assassin's magic", 25*6);
    set_skill("warcasting", 25*6);
    add_spell("mind freeze", "$A");
    set_spell_level("mind freeze", 6);
    add_spell("electrocute", "$A");
    set_spell_level("electrocute", 6);
    set_property("melee damage", ([ "cutting" : 24 + (7 * 6), "crushing" : 24 + (7 * 6) ]));
	set_property("gang bang", 1);
    set_money("gold", random(200)*6);
return;
}
