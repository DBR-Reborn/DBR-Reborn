#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("blood knight");
    set("race", "undead");
    set_combat_chance(120);
    set_id(({ "knight", "blood knight", "large knight", "stained knight", "blood stained knight", "large stained knight", "large blood stained knight", "undead" }));
    set_body_type("human");
    set_level(48);
    set_property("enhance criticals", -1);
    set_property("pet name", "blood knight");
    set_overall_ac(350);
    set_short("[48]Large Blood Stained Knight");
    set_property("pet short", "Large Blood Stained Knight");
    call_out("nether_form_check", 0);
    set_long("Towering high at approximately eight feet tall, this heavily armoured and horribly blood stained warrior at first glance looks to be a very imposing figure. No body parts of any kind appear within any of the armour cracks, indicating this being is a product of highly potent magic. Average sized swords are carried in each hand of the knight, likely daggers in the eyes of something its size but apparently proud weapons of choice judging from the fluency of their movement.");
    ob = new("/d/damned/guilds/nethermancer/misc/stained_sword.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/stained_sword.c");
    ob->move(this_object());
    force_me("wield sword in right hand");
    force_me("wield sword 2 in left hand");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    set_max_hp(6000 + 600*6);
    set_hp(6000 + 600*6);
    set_max_mp(4800 + 480*6);
    set_mp(4800 + 480*6);
    set_skill("attack", 48*6);
    set_skill("melee", 48*6);
    set_skill("blade", 48*6);
    set_skill("dodge", 35*6);
    set_skill("parry", 41*6);
    set_skill("offhand training", 55*6);
    set_skill("dual attack", 55*6);
    set_skill("owedquar's will", 44*6);
    add_spell("unholy rage", "$(ME)");
    set_spell_level("unholy rage", 6);
    add_spell("owedquar's might", "$A");
    set_spell_level("owedquar's might", 6);
    set_property("melee damage", ([ "crushing" : 37 + (11 * 6), "cold" : 37 + (11 * 6)  ]));
    set_money("gold", random(200)*6); 
	set_property("gang bang", 1);
	set("aggressive",1);
    return;
}

