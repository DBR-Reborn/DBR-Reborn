#include <std.h>
#include "../keep.h"

/* This is a level 60 mob, and is one of the higher end mobs of the black keep. They can be found on both the first and second floors of the keep, and in most cases they are aggro to players. Warlocks are not very strong in physical combat, but magically they can cast some extremely powerful spells that will drop unprepared players fast. He has four spells at his disposal, electrocute, which causes low level electricity damage, mutate for mid level entropy damage, and age for high level time damage, the latter of which is lethal even to high players. They can also cast a confuse spell that stuns a single opponent. The Warlock also has a unique ability that will really force players to come prepared while facing them, they can summon vampiric demons to aid them at a 10% chance per round! Defeating Warlocks requires extreme offense over defense, because if the player cannot kill them quick enough combat becomes horribly difficult even for hero levels to survive for long. */

inherit MONSTER;

void create() {
object ob;
::create();
set_name("warlock");
set_level(60);
set_combat_chance(120);
set_property("gang bang", 1);
set_property("aggressive", 1);
set("id", ({ "warlock", "dark warlock", "robed warlock", "dark robed warlock" }));
set_short("[60]dark robed warlock");
set_long("A old and horribly grim face, greatly dimmed from the loose black hood covering it, stares at you showing no emotion. Below that face is a wrinkled robe with a metallic skull hanging across the chest, done so by a dark steel chain worn around the neck above it. Powerful energy flows through the small staff grasped in two aged hands as this demonic creature prepares to annihilate all standing in his path that swears the slightest opposition to his lord and master.");
set("race", "demon");
set_gender("male");
set_body_type("humanoid");
set_alignment(-900);
set_skill("two handed staff", 500);
set_skill("attack", 400);
set_skill("parry", 350);
set_skill("dodge", 350);
set_skill("perception", 500);
set_skill("warcasting", 500);
set_skill("mentalism", 500);
set_skill("concentrate", 200);
ob = new(WEAP+"energy_staff.c");
ob->move(this_object());
ob = new(ARMOUR+"necklace.c");
ob->move(this_object());
ob = new(ARMOUR+"dark_robe.c");
ob->move(this_object());
ob = new(ARMOUR+"black_hood.c");
ob->move(this_object());
add_spell("age", "$A");
set_spell_level("age", 6);
add_spell("mutate", "$A");
set_spell_level("mutate", 6);
add_spell("confuse", "$A");
set_spell_level("confuse", 6);
add_spell("electrocute", "$A");
set_spell_level("electrocute", 6);
force_me("equip");
force_me("use concentrate");
set_overall_ac(300);
//improve_weapon(200);
}

void heart_beat(object to) {
int a;
object ob;
::heart_beat();
seteuid(getuid());
a=(random(100));
if(a<10 && sizeof(this_object()->query_attackers()) > 0) {
tell_room(environment(this_object()), "%^BLUE%^The Warlock takes one hand off his staff and raises it above his head, gathering massive energy which he then blasts at your feet. Two vicious Vampiric Demons rise from the blast and instantly attack!%^RESET%^");
ob = new(MON+"vampiric_demon.c");
ob->set_property("aggressive", 1);
ob->move(environment(this_object()));
ob->force_me("kill "+this_object()->query_current_attacker()->query_name());
ob = new(MON+"vampiric_demon.c");
ob->set_property("aggressive", 1);
ob->move(environment(this_object()));
ob->force_me("kill "+this_object()->query_current_attacker()->query_name());
}
else
return;
}
