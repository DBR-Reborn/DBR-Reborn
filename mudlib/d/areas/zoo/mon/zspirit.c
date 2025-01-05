#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    ::create();
    set_name("zombie spirit");
    set("race", "spirit");
    set_combat_chance(120);
    set_id(({ "spirit", "zombie", "zombie spirit", "undead" }));
    set_body_type("human");
    set_level(25);
    set_property("enhance criticals", 0);
    set_property("pet name", "zombie spirit");
    set_overall_ac(175);
    set_short("[25]Zombie Spirit");
    set_property("pet short", "Zombie Spirit");
    call_out("nether_form_check", 0);
    set_long("Constructed of thick and bright white mist, this amalgamation of a zombie and a ghost seems to move about in the same annoying manners as a zombie would and does not hover about like a typical spirit. However, judging by the density and activity of the mist combined with the deafening screams of the creature you can safely assume that this monster is more powerful than either of the undead comprising it.");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    set_max_hp(1100 + 110*6);
    set_hp(1100 + 110*6);
    set_skill("attack", 24*6);
    set_skill("melee", 24*6);
    set_skill("dodge", 18*6);
    set_skill("parry", 21*6);
    set_skill("assassin's magic", 23*6);
    add_spell("mind freeze", "$A");
    set_spell_level("mind freeze", 6);
    set_property("melee damage", ([ "cutting" : 23 + (7 * 6), "crushing" : 23 + (7 * 6) ]));
	set_property("gang bang", 1);
    set_money("gold", random(200)*6);
return;
}
