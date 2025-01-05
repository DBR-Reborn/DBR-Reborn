#include <std.h>
//#include "../keep.h"

inherit "/std/pet";

/* The Silver Dragon, at level 80, is an excessively powerful monster. Luckily for the player they are very rare, and are not common monsters in the keep like death soldiers or warlocks are. They are only found when a player touches one of the three orbs placed in three seperate arcane rooms, when they descend to defend the treasure carried inside the orb. They can also be summoned by Owedquar's Shadow, the master of the keep, with his Grand Summon spell. The Silver Dragons carry no equipment on them, and boast an extreme melee/martial arts offense, more powerful than any other monster in the keep. They also have an insane attack they use 10% of the time called violent blaze, which requires the players facing the dragon to come prepared with MAJOR aegis against fire. Defensively, the dragon has a very high dodge skill, but as far as AC goes it is no tougher to damage than other high level monsters in the keep. However, the dragon is completely resistant to all attack magic, meaning the player must bring high offense with their defense to defeat it. */

//inherit MONSTER;

void create() {
::create();
set_name("gold dragon");
set_level(100);
set_max_mp(50000);
set_mp(50000);
set_combat_chance(100);

  set_attack(1);
  set_can_change_aggr(1);
  set_carry(1);
  set_save(0);
  set_aggr_status(0);

set("id", ({ "dragon", "gold dragon", "beautiful dragon", "beautiful gold dragon" }));
set_short("[1]beautiful gold dragon");
set_long("You stand in awe as you look over this beast, Its entire body is fashioned of pure gold and shines endlessly, producing perhaps the most beautiful creature you have ever seen. The air surrounding it becomes an unusually bitter cold as it surveys you, and as frostbiting winds swirl about its mouth.");
set("race", "dragon");
set_gender("neuter");
set_body_type("humanoid");
set_alignment(-200);
set_skill("owedquar's will", 500);
set_skill("melee", 600);
set_skill("martial arts", 600);
set_skill("attack", 800);
set_skill("conjuration", 500);
set_skill("parry", 500);
set_skill("dodge", 700);
set_skill("perception", 1000);
set_skill("concentrate", 500);
set_stats("wisdom", 1000);
add_spell("violent blaze", "$A");
set_spell_level("violent blaze", 6);
/*
add_spell("mega freeze", "$A");
set_spell_level("mega freeze", 6);
add_spell("deep chill", "$A");
set_spell_level("deep chill", 6);
*/
set_property("enhance criticals", -50);
force_me("use concentrate");
set_overall_ac(1500);
return;
}
/*
void heart_beat() {
int a;
::heart_beat();
a = (random(100));
if(a<10) {
tell_room(environment(this_object()), "%^BOLD%^%^BLUE%^The Gold Dragon plants its feet into the ground and begins to charge a frigid icy rage.%^RESET%^");
force_me("cast *6 mega freeze");
}
if(a >= 10 && a < 20) {
tell_room(environment(this_object()), "%^BOLD%^%^BLUE%^The Gold Dragon's mouth fills with nastily cold air as it inhales.%^RESET%^");
force_me("cast *6 deep chill");
}
else
return;
}
*/
