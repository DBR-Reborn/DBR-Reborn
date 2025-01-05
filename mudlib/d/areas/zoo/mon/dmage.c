#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("deathmage");
    set("race", "undead");
    set_combat_chance(120);
    set_id(({ "mage", "deathmage", "death mage", "mage of death", "robed mage", "robed deathmage", "robed death mage", "robed mage of death", "undead" }));
    set_body_type("human");
    set_level(65);
    set_property("enhance criticals", -2);
    set_property("pet name", "deathmage");
    set_overall_ac(500);
    set_short("[65]Robed Mage of Death");
    set_property("pet short", "Robed Mage of Death");
    call_out("nether_form_check", 0);
    set_long("Before your eyes stands a relatively small being at only five feet tall, but one that appears to be extraordinarily menacing. Nearly all of its body is covered in a neat purple and black robe with its head covered just as well by a hood of the same colors. Virtually nothing can be seen through where the face is supposed to be except two extremely dark red eyes that never seem to blink for any reason, not even when it moves its head or its body. As the mage moves closer and closer to you you can hear extremely scary sounds of breathing.");
    ob = new("/d/damned/guilds/nethermancer/misc/mage_robe.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/mage_hood.c");
    ob->move(this_object());
    set_skill("concentrate", 200);
    force_me("use concentrate");
    force_me("equip");
    set_max_hp(11500 + 1150*6);
    set_hp(11500 + 1150*6);
    set_max_mp(9999 + 999*6);
    set_mp(9999 + 999*6);
    set_skill("attack", 69*6);
    set_skill("melee", 69*6);
    set_skill("dodge", 51*6);
    set_skill("parry", 62*6);
    set_skill("owedquar's will", 63*6);
    set_skill("warcasting", 63*6);
    set_skill("paralysis magic", 63*6);
    add_spell("mutate", "$A");
    set_spell_level("mutate", 6);
    add_spell("abyss blast", "$A");
    set_spell_level("abyss blast", 6);
    add_spell("stun blast", "$A");
    set_spell_level("stun blast", 6);
    set_property("melee damage", ([ "cold" : 48 + (13 * 6), "unholy" : 48 + (13 * 6), "disruption" : 48 + (13 * 6), "reflection" : 48 + (13 *6)  ]));
	set_property("gang bang", 1);
  set_money("gold", random(200)*6);
  set("aggressive",1);
return;
}