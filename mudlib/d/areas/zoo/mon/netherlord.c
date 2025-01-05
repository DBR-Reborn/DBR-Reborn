#include <std.h>
#include "../zoo.h"

inherit MONSTER;

object ob;

void create() {
    ::create();
    set_name("nether lord");
    set("race", "undead");
    set_combat_chance(120);
    set("id", ({ "lord", "nether lord", "lord of the arts", "lord of the nether arts", "undead" }));
    set_body_type("human");
    set_level(80);
    set_property("enhance criticals", -3);
    set_property("pet name", "nether lord");
    set_overall_ac(800);
    set_short("[80]%^BLUE%^Lord of the Nether Arts%^BOLD%^%^RED%^");
    set_property("pet short", "%^BLUE%^Lord of the Nether Arts%^BOLD%^%^RED%^");
    set_long("Standing before you wearing a devilish red and black robe as well as a hood looking even more menacing, this indeed looks as if it may be a sorcerer of the highest magical order. Grasped by both hands is a glowing staff made of no wood you have ever seen nor heard of, its glow fiercely increasing the closer you get to the magus. Not a single thing can be seen through the area that the hood covers, not even the slightest trace of an eye. However you know as well as anyone that this master warlock can see you as clearly as it can see the sun on a bright summer day."); 
    ob = new("/d/damned/guilds/nethermancer/misc/ancient_staff.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/lord_robe.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/lord_hood.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/shield_shadow");
    ob->set_damage_allowed(10000);
    ob->set_shadow_name("death dragon shield");
    ob->start_shadow(this_object(), 2000000000, "");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    force_me("equip");
    set_max_hp(20000 + 2000*6);
    set_hp(20000 + 2000*6);
    set_max_mp(18000 + 1800*6);
    set_mp(18000 + 1800*6);
    set_skill("attack", 90*6);
    set_skill("two handed staff", 90*6);
    set_skill("melee", 90*6);
    set_skill("dodge", 68*6);
    set_skill("parry", 78*6);
    set_skill("owedquar's will", 81*6);
    set_skill("necromancy", 77*6);
    add_spell("dark breath", "$A");
    set_spell_level("dark breath", 6);
    add_spell("decay", "$A");
    set_spell_level("decay", 6);
    add_spell("storm of ages", "$A");
    set_spell_level("storm of ages", 6);
    /*set_skill("warcasting", 81*6);
    set_skill("channelling", 81*6);
    add_spell("fumble shield", "$(ME)");
    set_spell_level("fumble shield", 6);
    add_spell("age", "$A");
    set_spell_level("age", 6);*/
    set_property("melee damage", ([ "crushing" : 63 + (17 * 6), "infernal" : 63 + (17 * 6), "time" : 63 + (17 * 6), "sonic" : 63 + (17 * 6) ]));
    set_property("gang bang", 1);
    set_money("gold", 5000);
    set_money("mithril", 500);
    set("aggressive",1);
return;
}
