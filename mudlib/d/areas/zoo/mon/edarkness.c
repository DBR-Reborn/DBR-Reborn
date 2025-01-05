#include <std.h>
#include "../zoo.h"

inherit MONSTER;

object ob;

void create() {
    ::create();
    set_name("eternal darkness");
    set("race", "undead");
    set_combat_chance(120);
    set("id", ({ "darkness", "eternal darkness", "darkness of the netherworld", "eternal darkness of the netherworld", "undead" }));
    set_body_type("human");
    set_level(100);
    set_property("enhance criticals", -5);
    //set_property("nethermancer pet", 1);
    set_property("pet name", "eternal darkness");
    set_overall_ac(1111);
    set_short("[100]%^BOLD%^%^RED%^Eternal Darkness of the Netherworld%^BOLD%^%^RED%^");
    set_long("Before you floating slightly above the ground is the most feared undead creation known to the minds of the universe, the legendary eternal darkness of the netherworld. Comprised of pure darkness and the most damned of damned souls, it looks as it only a truly chosen master of the most elite of nether arts could possibly have binded everything together to create the creature. As it moves, its body expands outwards and the souls become more visible as they orbit the main body at an electrifying speed. Ear splitting wails emanate from all the souls simultaneously along with a tremendous roar from its main face, educating you that it desperately seeks more and more souls and will likely stop at nothing to slay whatever it can to obtain them. With this creature present in front of you, it can only be a matter of time before the netherworld itself breaks open and the world is overrun by everlasting death.");
    ob = new("/d/damned/guilds/nethermancer/misc/krieger_of_sin.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/nethermancer/misc/ed_shield.c");
    ob->set_damage_allowed(25000);
    ob->set_shadow_name("eternal darkness shield");
    ob->start_shadow(this_object(), 2000000000, "");
    ob = new("/std/spells/shadows/ele_pres_shad");
    ob->set_power(5);
    ob->set_damage(({ "infernal", "aether" }));
    ob->set_shadow_name("eternal darkness presence");
    ob->start_shadow(this_object(), 2000000000, "");
    set_skill("concentrate", 200);
    force_me("use concentrate");
    force_me("equip");
    set_max_hp(50000 + 5000*6);
    set_hp(50000 + 5000*6);
    set_max_mp(40000 + 4000*6);
    set_mp(40000 + 4000*6);
    set_skill("attack", 150*6);
    set_skill("melee", 150*6);
    set_skill("blade", 145*6);
    set_skill("knife", 145*6);
    set_skill("dodge", 100*6);
    set_skill("parry", 120*6);
    set_skill("warcasting", 111*6);
    set_skill("assassin's magic", 111*6);
    set_skill("spiritmancy", 111*6);
    set_skill("necromancy", 111*6);
    set_skill("elementalism", 111*6);
    set_skill("chaos lore", 111*6);
    add_spell("dark breath", "$A");
    set_spell_level("dark breath", 6);
    add_spell("decay", "$A");
    set_spell_level("decay", 6);
    add_spell("greater elemental storm", "$A");
    set_spell_level("greater elemental storm", 6);
    add_spell("pain", "$A");
    set_spell_level("pain", 6);
    set_property("melee damage", ([ "reflection" : 75 + (20 * 6), "infernal" : 75 + (20 * 6), "time" : 75 + (20 * 6), "aether" : 75 + (20 * 6), "sonic" : 75 + (20 * 6) ]));
	set_property("gang bang", 1);
    set_money("gold", 1000);
    set_money("mithril", 500);
return;
}
