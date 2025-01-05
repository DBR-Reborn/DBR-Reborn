#include <std.h>
#include "../keep.h"

/* The Necromancer is a very powerful boss, at level 90 possessing nearly 50,000 hit points. It is encountered several non-combat times during the black keep quest in various rooms to add to the roleplay, but the player only has to fight it when it is encountered at the second floor stairway after the forging of the Legend Key late in the quest. The Necromancer has several types of undead magic, including shatter soul, disease bone rot, instill fear, black curse, and a powerful single target spell called hell blast causing disruption and infernal damage. During the battle, he is accompanied by two pulsing energy masses similar to the one in the jail room that summon monsters endlessly to help him out. At times during the battle, the Necromancer will make himself immaterial and become unhittable for several rounds. Despite all the advantages this powerful undead wizard has, he has virtually no AC protection, and 50,000 hp isnt that much with protection that low. When defeated, the masses will die as well */

inherit MONSTER;

int a;
int b;

void create() {
object ob;
::create();
set_name("necromancer");
set_level(90);
set_max_hp(50000);
set_hp(50000);
set_max_mp(80000);
set_mp(80000);
set_property("aggressive", 1);
set_property("gang bang", 1);
set_property("see invis", 1);
set_casting_chance(120);
set_combat_chance(120);
set_property("enhance criticals", -5);
set("id", ({ "necromancer", "undead", "undead wizard", "wizard" }));
set_short("[90]undead wizard");
set_long("With shimmering energy coarsing throughout his hands and his grey robe blowing in many directions due to the mist surrounding his entire body, this wizard is indeed a sight to see. He is a legendarily powerful Necromancer, a summoner and manipulator of the undead. Unlike most of his kind however, he is an almost impossible combination of both dead and living, partially undead like the very things he controls. Whoever created this powerful cross of realm divided bodies must indeed be comparable to a god.");
set("race", "undead");
set_gender("male");
set_body_type("humanoid");
set_alignment(-1000);
set_skill("parry", 700);
set_skill("dodge", 700);
set_skill("perception", 900);
set_skill("reverse stroke", 900);
set_skill("chaos magic", 600);
set_skill("spiritmancy", 600);
set_skill("necromancy", 600);
set_skill("curse lore", 600);
set_skill("concentrate", 200);
add_spell("instill fear", "$A");
set_spell_level("instill fear", 6);
add_spell("disease bone rot", "$A");
set_spell_level("disease bone rot", 6);
add_spell("black curse", "$A");
set_spell_level("black curse", 6);
add_spell("shatter soul", "$A");
set_spell_level("shatter soul", 6);
add_spell("hell blast", "$A");
set_spell_level("hell blast", 6);
ob = new(ARMOUR+"grey_pants.c");
ob->move(this_object());
ob = new(ARMOUR+"grey_shirt.c");
ob->move(this_object());
ob = new(ARMOUR+"grey_crown.c");
ob->move(this_object());
ob = new(ARMOUR+"grey_robe.c");
ob->move(this_object());
force_me("equip");
force_me("use concentrate");
a = 0;
return;
}

void heart_beat() {
::heart_beat();
b = random(100);
if(b<10 && a<1) {
tell_room(environment(this_object()), "%^BOLD%^%^WHITE%^The Necromancer shimmers and becomes immaterial!%^RESET%^");
set_skill("dodge", 10000);
a++;
return;
}
if(b<10 && a>0) {
tell_room(environment(this_object()), "%^BOLD%^%^WHITE%^The Necromancer shimmers and is no longer immaterial.%^RESET%^");
set_skill("dodge", 700);
a = 0;
return;
}
}

void die() {
tell_room(environment(this_object()), "Necromancer says in Common: %^MAGENTA%^You may have defeated me, but you are no match for the master. There is no way that you will ever defeat him.");
tell_room(environment(this_object()), "");
tell_room(environment(this_object()), "The energy masses dissipate as the Necromancer falls to the floor.");
present("energy mass")->remove();
present("energy mass")->remove();
::die();
}
