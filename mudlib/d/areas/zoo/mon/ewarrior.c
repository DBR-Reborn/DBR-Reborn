#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("essence warrior");
    set("race", "spirit");
    set_combat_chance(120);
    set_id(({ "warrior", "essence warrior", "shimmering warrior", "shimmering essence warrior", "undead" }));
    set_body_type("human");
    set_level(51);
    set_property("enhance criticals", -1);
    set_property("pet name", "essence warrior");
    set_overall_ac(350);
    set_short("[51]Shimmering Essence Warrior");
    set_property("pet short", "Shimmering Essence Warrior");
    call_out("nether_form_check", 0);
    set_long("Comprised entirely of a staggeringly dense mist from head to toe, this nearly nine foot tall warrior looks both considerably imposing and amazing. Massive immaterial armour appears to cover every one of its limbs, including a truly menacing mask resembling that of a truly ferocious demon lord. A very large and fully material skull sword seems to float in its hands, miraculously serving as its weapon despite the fact that the concept itself breaks natural laws."); 
    ob = new("/d/damned/guilds/nethermancer/misc/huge_sword.c");
    ob->move(this_object());
    set_skill("concentrate", 200);
    force_me("wield sword in right hand and left hand");
    force_me("use concentrate");
    set_max_hp(7000 + 700*6);
    set_hp(7000 + 700*6);
    set_max_mp(6100 + 610*6);
    set_mp(6100 + 610*6);
    set_skill("attack", 52*6);
    set_skill("melee", 52*6);
    set_skill("two handed blade", 52*6);
    set_skill("dodge", 38*6);
    set_skill("parry", 45*6);
    set_skill("owedquar's will", 47*6);
    set_skill("shadow lore", 47*6);
    add_spell("unholy rage", "$(ME)");
    set_spell_level("unholy rage", 6);
    add_spell("devour soul", "$A");
    set_spell_level("devour soul", 6);
    set_property("melee damage", ([ "crushing" : 40 + (11 * 6), "cold" : 40 + (11 * 6), "unholy" : 40 + (11 * 6)  ]));
    set_property("gang bang", 1);
    set_money("gold", random(200)*6);
    set("aggressive",1);
return;
}