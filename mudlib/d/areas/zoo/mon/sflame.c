#include <std.h>
#include "../zoo.h"

inherit MONSTER;

void create() {
    object ob;
    ::create();
    set_name("shadowflame templar");
    set("race", "undead");
    set_combat_chance(120);
    set("id", ({ "templar", "shadowflame templar", "shadow flame templar", "shadow and flame templar", "armoured templar", "armoured templar covered in shadow and flame", "undead" }));
    set_body_type("human");
    set_level(74);
    set_property("enhance criticals", -3);
    set_property("pet name", "shadowflame templar");
    set_overall_ac(600);
    set_short("[74]Armoured Templar Covered in %^BLUE%^Shadow%^BOLD%^%^RED%^ and %^ORANGE%^Flame%^BOLD%^%^RED%^");
    set_property("pet short", "Armoured Templar Covered in %^BLUE%^Shadow%^BOLD%^%^RED%^ and %^ORANGE%^Flame%^BOLD%^%^RED%^");
    call_out("nether_form_check", 0);
    set_long("This armoured behemoth has to be one of the most imposing warriors you have ever laid eyes upon. Equipped from top to bottom in dark purple gear and also with a shimmering halberd, it appears blatantly evident that it was given life for the purpose of nothing less than the most extreme of combat. A thin and barely visible aura of darkness and flame emanates from the entirety of the armour. suggesting that something more than just hearing a clang would happen to aggressor if it was struck by weapons.");
    ob = new("/d/damned/guilds/nethermancer/misc/shimmering_halberd.c");
    ob->move(this_object());
    ob = new("/std/spells/shadows/ele_pres_shad");
    ob->set_power(3);
    ob->set_damage(({ "unholy", "fire" }));
    ob->set_shadow_name("shadowflame presence");
    ob->start_shadow(this_object(), 2000000000, "");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    force_me("equip");
    set_max_hp(15000 + 1500*6);
    set_hp(15000 + 1500*6);
    set_max_mp(13500 + 1350*6);
    set_mp(13500 + 1350*6);
    set_skill("attack", 80*6);
    set_skill("melee", 80*6);
    set_skill("dodge", 60*6);
    set_skill("parry", 69*6);
    set_skill("necromancy", 72*6);
    add_spell("decay", "$A");
    set_spell_level("decay", 6);
    set_property("melee damage", ([ "crushing" : 55 + (15 * 6), "unholy" : 55 + (14 * 6), "fire" : 55 + (15 * 6), "electricity" : 55 + (15 * 6) ]));
	set_property("gang bang", 1);
    set_money("gold", random(200)*6);
    set("aggressive",1);
return;
}
