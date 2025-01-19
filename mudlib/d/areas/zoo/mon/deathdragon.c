#include <std.h>
#include "../zoo.h"

inherit MONSTER;

object ob;

void create() {
    ::create();
    set_name("death dragon");
    set("race", "dragon");
    set("id", ({ "dragon", "undead dragon", "death dragon", "great dragon", "great undead dragon", "great death dragon", "dragon of death", "undead" }));
    set_body_type("dragon");
    set_level(77);
    set_property("enhance criticals", -3);
    set_property("pet name", "death dragon");
    set_overall_ac(750);
    set_short("[77]%^MAGENTA%^Great Undead Dragon%^BOLD%^%^RED%^");
    set_property("pet short", "%^MAGENTA%^Great Undead Dragon%^BOLD%^%^RED%^");
    call_out("nether_form_check", 0);
    set_long("What can only be described as the largest and most ferocious looking dragon you have ever seen now stands on four legs before your eyes. Its red and purple scales look as if they could serve as knives in their own right, and the footlong claws on its feet could probably shred through stainless steel. The entirety of its ten foot tall body is glowing with a bright cyan aura which serves as a powerful energy shield to help ward off even the nastiest of offensive assaults. Judging from the shield and the numerous souls endlessly floating throughout its mouth, this towering creature is unquestionably the product of absolutely incredible magic.");
    ob = new("/d/damned/guilds/nethermancer/misc/shield_shadow");
    ob->set_damage_allowed(10000);
    ob->set_shadow_name("death dragon shield");
    ob->start_shadow(this_object(), 2000000000, "");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    set_money("mithril", random(200)+77); 
    set_combat_chance(120);
	set_property("gang bang", 1);
	set_max_hp(17000 + 1700*6);
    set_hp(17000 + 1700*6);
    set_max_mp(15750 + 1575*6);
    set_mp(15750 + 1575*6);
    set_skill("attack", 85*6);
    set_skill("melee", 85*6);
    set_skill("dodge", 64*6);
    set_skill("parry", 73*6);
    set_skill("necromancy", 77*6);
    add_spell("dark breath", "$A");
    set_spell_level("dark breath", 6);
    set_property("melee damage", ([ "crushing" : 60 + (16 * 6), "cutting" : 60 + (16 * 6), "acid" : 60 + (16 * 6), "infernal" : 60 + (16 * 6) ]));
    set("aggressive",1);
    return;
}

void shield_func() {
    ob->heal_damage();
    call_out("shield_func", 60);
}
