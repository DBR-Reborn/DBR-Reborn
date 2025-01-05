#include <std.h>
#include "../keep.h"

/* This level 55 monster is a medium to high monster for the black keep. It can be found on the first floor mainly, and in some instances on the deadly second floor. They wear the blood red robes that are also worn by the slightly lesser vampiric demons, and they dual wield two powerful elemental swords. The elemental the swords are is totally random, and there is an extremely small chance the weapon may be one of the keeps many secret items, the aether blade which is the one handed blade super weapon of the keep. As far as magic, the death soldiers love to cast decay and curse spells frequently, and occassionally use a devastating black curse spell to terribly lower its targets AC, giving them a massive advantage and providing a risk and challenge for even the toughest players. Before fighting death soldiers on a regular basis, the player should have high end defense because of the monsters offense and to stand a chance if he lands black curse. He/she should also have a high end weapon to dispost of them in a reasonable amount of time */

inherit MONSTER;

void create() {
int a;
object ob;
::create();
a=(20000+random(10000));
set_name("death soldier");
set_level(55);
set_max_hp(a);
set_hp(a);
set_combat_chance(120);
set_property("gang bang", 1);
set("id", ({ "soldier", "death soldier" }));
set_short("[55]death soldier");
set_long("With no color coming from the eye sockets of this demonic creatures skull, you do not know if it sees you or not. What you do know is that this six foot tall skeleton, with extremely thick and very well constructed dark blue bones partially covered by a red robe, is a creature specifically designed for combat in the darkest of wars.");
set("race", "undead");
set_gender("neuter");
set_body_type("humanoid");
set_alignment(-800);
set_skill("dual attack", 400);
set_skill("offhand training", 400);
set_skill("blade", 550);
set_skill("attack", 500);
set_skill("parry", 400);
set_skill("dodge", 400);
set_skill("perception", 450);
set_skill("necromancy", 450);
set_skill("concentrate", 200);
set_skill("curse lore", 450);
ob = new(WEAP+"elemental_sword.c");
ob->move(this_object());
ob = new(WEAP+"elemental_sword.c");
ob->move(this_object());
ob = new(ARMOUR+"red_robe.c");
ob->move(this_object());
add_spell("black curse", "$A");
set_spell_level("black curse", 6);
add_spell("decay", "$A");
set_spell_level("decay", 6);
add_spell("curse", "$A");
set_spell_level("curse", 6);
force_me("equip");
force_me("use concentrate");
set_overall_ac(500);
//improve_weapon(300);
}
