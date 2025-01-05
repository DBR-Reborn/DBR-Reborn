#include <std.h>
#include "../keep.h"

/* This is a very unique mob, as it is one that cannot be killed in combat. It can be found in only one place in the keep, in the jail room located in the basement only accessible by finding the secret entrance in the west wing of the first floor. It serves the sole purpose of summoning mobs to constantly assault players inside the jail. This is intended to keep high pressure on players while they attempt to open the chests with a thief searching for the arcane gem required for one of the three arcane orbs. Because of the constant summoning, the players generally only have one shot at conquering the room before it gets too overcrowded. It summons a monster anywhere from once every round to once every ten rounds randomly, and the frequencies of what is summoned are as follows: Vampiric Demon (40%), Death Soldier (30%), Shadow Knight (20%), Warlock (10%). */

inherit MONSTER;

int b;
int c;

void create() {
::create();
set_name("energy mass");
set_level(1);
set_max_hp(10000000);
set_hp(10000000);
set("id", ({ "mass", "energy mass", "pulsing energy mass", "mass of pulsing energy", "mass of energy", "pulsing mass", "pulsing mass of energy", "pulsing energy mass", "energy" })); 
set_short("%^RESET%^%^MAGENTA%^A pulsing mass of energy%^BOLD%^%^RED%^");
set_long("This is an extremely compact mass of high density energy. It glows bright purple and constantly expands and contracts in random intervals, seemingly opening interdimensional gateways at times while doing so.");
set("race", "energy");
set_gender("neuter");
set_body_type("humanoid");
set_property("no kill", 1);
set_property("no kill msg", "The mass of energy is immaterial and far too active to control, thus is impossible to hamper.");
b = 0;
c = (random(10) + 1);
}

void heart_beat() {
int a;
object ob;
::heart_beat();
b++;
if(b==c) {
a = random(100);
if(a<40) {
ob = new(MON+"vampiric_demon.c");
ob->set("aggressive", 1);
ob->set_property("see invis", 1);
ob->set_experience(0);
ob->move(environment(this_object()));
}
if(a>39 && a<70) {
ob = new(MON+"death_soldier.c");
ob->set("aggressive", 1);
ob->set_property("see invis", 1);
ob->set_experience(0);
ob->move(environment(this_object()));
}
if(a>69 && a<90) {
ob = new(MON+"shadow_knight.c");
ob->set("aggressive", 1);
ob->set_property("see invis", 1);
ob->set_experience(0);
ob->move(environment(this_object()));
}
if(a>90) {
ob = new(MON+"warlock.c");
ob->set("aggressive", 1);
ob->set_property("see invis", 1);
ob->set_experience(0);
ob->move(environment(this_object()));
}
tell_room(environment(this_object()), "%^RED%^The energy mass expands outward. Before very quickly contracting inward a gateway is created which warps in a vicious creature.");
b = 0;
c = (random(10) + 1);
}
else
return;
}
