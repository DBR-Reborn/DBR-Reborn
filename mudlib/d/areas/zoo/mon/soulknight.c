#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("soul knight");
    set("race", "shadow");
    set_combat_chance(120);
    set_id(({ "knight", "soul knight", "knight of souls", "damned soul", "soul", "souls", "damned soul knight", "damned knight of souls", "shadow", "undead" }));
    set_body_type("thranx");
    set_level(59);
    set_property("enhance criticals", -2);
    set_property("pet name", "soul knight");
    set_overall_ac(450);
    set_short("[59]Damned Knight of Souls");
    set_property("pet short", "Damned Knight of Souls");
    call_out("nether_form_check", 0);
    set_long("Standing tall and possessive of four thick arms and completely comprised of numerous highly active souls of the damned, this appears to be a creature brought forth to this realm by a truly great power for a very dire purpose. Each of its hands carries identical blinding white blades and they all seem to move in a truly frightening unison as the creature stares upon you, a potential foe.");
    ob = new("/d/damned/guilds/nethermancer/misc/pale_sword.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/pale_sword.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/pale_sword.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/pale_sword.c");
    ob->move(this_object());
    set_skill("offhand training", 500);
    set_skill("dual attack", 500);
    set_skill("concentrate", 200);
    force_me("wield sword in first hand");
    force_me("wield sword 2 in second hand");
    force_me("wield sword 3 in third hand");
    force_me("wield sword 4 in fourth hand");
    force_me("equip");
    force_me("use concentrate");
    set_max_hp(8500 + 850*6);
    set_hp(8500 + 850*6);
    set_max_mp(7700 + 770*6);
    set_mp(7700 + 770*6);
    set_skill("attack", 60*6);
    set_skill("melee", 60*6);
    set_skill("dodge", 43*6);
    set_skill("parry", 52*6);
    set_skill("blade", 60*6);
    set_skill("offhand training", 70*6);
    set_skill("dual attack", 70*6);
    set_skill("curse lore", 56*6);
    add_spell("fatigue", "$A");
    set_spell_level("fatigue", 6);
    set_property("melee damage", ([ "cold" : 44 + (12 * 6), "unholy" : 44 + (12 * 6), "disruption" : 44 + (12 * 6)  ]));
	set_property("gang bang", 1);
    set_money("gold", random(200)*6);
    set("aggressive",1);
return;
}