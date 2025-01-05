#include <std.h>
#include "../keep.h"

/* This is the most powerful of the common monsters in the black keep. It is a level 65 mob, wearing a full suit of eight pieces of pitch black armour. The armour has 125 AC, which is slightly higher than a high merchants steel, making it likely the best armour suit for low levels players to wear, and at the same time it isnt real good defensively in the big picture. The shadow knights have high offense wielding a powerful mcgrail two handed sword, which serves as the 2h blade counterpart of buff mob weapons such as the undead monk's sidepiece of chemosh staff. The knights have relatively high defense, equivalent to low purple on player limbs, and have tens of thousands of hit points. They do not cast any attack spells, but they do cast magic that greatly boosts their combat abilities. As far as players who wish to face these powerful warriors, they should be hero level with decent gear and skills at a minimum. */

inherit MONSTER;

void create() {
object ob;
::create();
set_name("shadow knight");
set_level(65);
set_max_hp(35000);
set_hp(35000);
set_combat_chance(120);
set_property("gang bang", 1);
set("id", ({ "knight", "shadow knight" }));
set_short("[65]shadow knight");
set_long("Covered from head to toe in pitch black armour, carrying a large dark two handed sword in both hands, and possessing extremely dark red eyes, this imposing warrior emits an aura of truly pure evil. It knows no pity, remorse, or fear and it doesnt need to speak a single word to get this across to you.");
set("race", "demon");
set_gender("male");
set_body_type("humanoid");
set_alignment(-800);
set_skill("melee", 600);
set_skill("martial arts", 300);
set_skill("attack", 600);
set_skill("parry", 400);
set_skill("dodge", 400);
set_skill("perception", 500);
set_skill("two handed blade", 600);
set_skill("invisible dagger discipline", 550);
set_skill("magery", 550);
ob = new(WEAP+"dark_cleaver.c");
ob->move(this_object());
ob = new(ARMOUR+"black_greaves.c");
ob->move(this_object());
ob = new(ARMOUR+"black_boots.c");
ob->move(this_object());
ob = new(ARMOUR+"black_helm.c");
ob->move(this_object());
ob = new(ARMOUR+"black_plate.c");
ob->move(this_object());
ob = new("/d/damned/virtual/gauntlet.armour");
ob->set_name("black gauntlet");
ob->set("id", ({ "gauntlet", "black gauntlet", "pitch black gauntlet" }));
ob->set_short("A pitch black gauntlet");
ob->set_long("This is a relatively large gauntlet, fashioned of dark steel and completely black in color. It is very durable and allows good hand movement as well.");
ob->set_ac(125);
ob->set_material("dark steel");
ob->move(this_object());
ob = new("/d/damned/virtual/gauntlet.armour");
ob->set_name("black gauntlet");
ob->set("id", ({ "gauntlet", "black gauntlet", "pitch black gauntlet" }));
ob->set_short("A pitch black gauntlet");
ob->set_long("This is a relatively large gauntlet, fashioned of dark steel and completely black in color. It is very durable and allows good hand movement as well.");
ob->set_ac(125);
ob->set_material("dark steel");
ob->move(this_object());
ob = new("/d/damned/virtual/plate-bracer.armour");
ob->set_name("black bracer");
ob->set("id", ({ "bracer", "black bracer", "pitch black bracer" }));
ob->set_short("A pitch black bracer");
ob->set_long("This bracer, fashioned of dark steel and completely black in color, looks very powerful and capable of absorbing respectable damage.");
ob->set_ac(125);
ob->set_material("dark steel");
ob->move(this_object());
ob = new("/d/damned/virtual/plate-bracer.armour");
ob->set_name("black bracer");
ob->set("id", ({ "bracer", "black bracer", "pitch black bracer" }));
ob->set_short("A pitch black bracer");
ob->set_long("This bracer, fashioned of dark steel and completely black in color, looks very powerful and capable of absorbing respectable damage.");
ob->set_ac(125);
ob->set_material("dark steel");
ob->move(this_object());
add_spell("haste", "$(ME)");
set_spell_level("haste", 6);
add_spell("mad rage", "$(ME)");
set_spell_level("mad rage", 6);
add_spell("undeniable will", "$(ME)");
set_spell_level("undeniable will", 6);
add_spell("cloak of shadows", "$(ME)");
set_spell_level("cloak of shadows", 6);
force_me("equip");
force_me("use concentrate");
set_overall_ac(700);
//improve_weapon(300);
return;
}
