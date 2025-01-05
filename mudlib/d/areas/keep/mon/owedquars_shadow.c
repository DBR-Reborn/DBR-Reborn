#include <std.h>
#include "../keep.h"

/* This level 100 master of darkness is the ruler of the Black Keep, and by FAR the most powerful mob in the area. He is the shadow of the dark god Owedquar, who controls it from a distant realm. It is located on the second floor, and a long quest is required to reach it. It contains similar powers to that of the dark god, but of far less intensity. He casts seven different spells during the fight, and in the end it is totally luck as to what he is going to use. His spells are storm of ages (disruption, infernal, stress area spell), rot (decay on entire room), wrath of the magus (time, plasma, acid attack on one target), dark empowerment (heals 1-100000 hp), penetrating dagger (casts on his weapon), death (instantly kills one target), grand summon (summons two silver dragons to help him). This mob is designed to be impossible to defeat solo, and a diverse party of different guilds is required to have any chance. A full description on this boss is included in the main area directory. */

inherit MONSTER;

int b;
int c;
int d;
int e;
int f;
int g;

void create() {
object ob;
::create();
b = 0;
e = 0;
f = 0;
g = 0;
d = c;
set_name("owedquar's shadow");
set_level(100);
add_money("mithril", 2500);
add_money("gold", 10000);
set_hp(65535);
set_max_hp(65535);
set_mp(99999);
set_max_mp(99999);
set_combat_chance(120);
set("id", ({ "shadow", "owedquar", "owedquar's shadow", "shadow of owedquar" }));
set_short("[100]%^BLUE%^Owedquar's Shadow%^RESET%^");
set_long("As you gaze upon this being, you gain the long awaited confirmation that the legends were true, the dark god Owedquar indeed does have a shadow of himself living in this realm. Covered in a dark black and blue robe and wielding a menacing spear like staff in his hands, the master of the black keep stands somewhat relaxed in the center of the room, giving you the impression he is horrifyingly confident of his power and its potential to destroy trespassers. A voice seems to echo in your head as you look closer, saying '%^CYAN%^Your life ends now mortal%^RESET%^'.");
set("race", "ancient");
set_gender("male");
set_body_type("humanoid");
set_alignment(-1000);
set_property("enhance criticals", -10);
set_property("see invis", 1);
set_property("gang bang", 1);
set_stats("wisdom", 1000);
set_skill("two handed polearm", 800);
set_skill("attack", 800);
set_skill("perception", 1000);
set_skill("reverse stroke", 1000);
set_skill("invisible dagger discipline", 600);
set_skill("owedquar's will", 600);
set_skill("conjuration", 600);
set_skill("necromancy", 600);
set_skill("warcasting", 600);
set_skill("magery", 600);
set_skill("dodge", 700);
set_skill("parry", 700);
set_skill("concentrate", 1000);
set_skill("fast casting", 1000);
add_spell("storm of ages", "$A");
set_spell_level("storm of ages", 6);
add_spell("wrath of the magus", "$A");
set_spell_level("wrath of the magus", 6);
add_spell("death", "$A");
set_spell_level("death", 6);
add_spell("grand summon", "$A");
set_spell_level("grand summon", 6);
add_spell("dark empowerment", "$(ME)");
set_spell_level("dark empowerment", 6);
add_spell("rot", "$A");
set_spell_level("rot", 6);
add_spell("penetrating dagger", "$(ME)");
set_spell_level("penetrating dagger", 6);
ob = new(WEAP+"ultima_umbra.c");
ob->move(this_object());
ob = new(ARMOUR+"shimmering_robe.c");
ob->move(this_object());
ob = new(ARMOUR+"hades_amulet.c");
ob->move(this_object());
force_me("equip");
force_me("use concentrate");
set_overall_ac(1000);
improve_weapon(500);
return;
}

void init() {
::init();
if(c<1 && d<1) {
tell_room(environment(this_object()), "A mysterious voice says in Common: %^CYAN%^Welcome mortals. I commend you for making it this far, but i am afraid it is time for your life to end.%^RESET%^");
force_me("use fast casting");
force_me("cast *6 storm of ages");
c = 1;
}
else
return;
}

void heart_beat() {
int a;
::heart_beat();
a = query_hp();
if(a<30000 && b<1) {
tell_room(environment(this_object()), "Owedquar's Shadow says in Common: %^CYAN%^Very resilient you mortals are. Now i will show you my true power, and with it i shall drag you into the abyss!%^RESET%^");
tell_room(environment(this_object()), "%^RED%^Owedquar's Shadow raises his weapon and prepares to imbue it with massive energy.%^RESET%^");
force_me("use fast casting");
force_me("cast *6 penetrating dagger at staff");
delete_spell("penetrating dagger");
b = 1;
}
if(a<50000 && e<1) {
tell_room(environment(this_object()), "Owedquar's Shadow says in Common: %^CYAN%^You call this an attack? How pathetic! My dear friends, this is what you would call an attack.%^RESET%^");
force_me("use fast casting");
force_me("cast *6 storm of ages");
e = 1;
}
if(a<40000 && f<1) {
tell_room(environment(this_object()), "Owedquar's Shadow says in Common: %^CYAN%^You are nothing to me but mere insects, and i shall now prove it. Come forth my servants, destroy these beings that are bold enough to call themselves warriors.%^RESET%^");
force_me("use fast casting");
force_me("cast *6 grand summon");
f = 1;
}
if(a<15000 && g<1) {
tell_room(environment(this_object()), "Owedquar's Shadow says in Common: %^CYAN%^Arrrrrgh!! Dont you pathetic mortal bastards ever die? Im through playing these childish games, for you have made me very angry. Breathe one last time, for my death spell within a split second will send the body i choose lifeless to the floor!%^RESET%^");
force_me("use fast casting");
force_me("cast *6 death at "+this_object()->query_current_attacker()->query_name());
g = 1;
}
else
return;
}

void die() {
object ob2;
tell_room(environment(this_object()), "Owedquar's Shadow says in Common: %^CYAN%^NOOOOOOOOOO!!!!!! This is IMPOSSIBLE!!!!!! You are MORTALS, how in all creation are you so powerful???? I solemly swear that one day i shall return to this realm and utterly shatter your miserable souls!%^RESET%^"); 
tell_room(environment(this_object()), "%^MAGENTA%^Massive amounts of energy begin to blast out of the body of Owedquar's Shadow. After a few moments, the blinding light created from the energy dies away, and the lifeless body of the dark master falls to the floor.%^RESET%^");
tell_room(environment(this_object()), "");
tell_room(environment(this_object()), "After a relatively brief calm, a menacing laugh echoes through your ears. A powerful screaming voice is then heard, sounding as if it coming from a terribly distant place.");
tell_room(environment(this_object()), "");
message("shout", "%^RED%^Owedquar's Shadow screams from afar:%^CYAN%^ Foolish mortals. You may have defeated me, but i shall not return to the realm of my true self without first bringing hell upon this one. Come my Death Soldiers, my Warlocks, my thirsty Vampiric Demons, destroy all in this world that emits the aura of life!%^RESET%^", users());
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/square"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/square"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/square"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/square"));
ob2 = new(MON+"warlock.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ridge3"));
ob2 = new(MON+"warlock.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ridge55"));
ob2 = new(MON+"warlock.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/lidfino1"));
ob2 = new(MON+"warlock.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ariel2"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ariel2"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ariel2"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ridge4"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ridge4"));
ob2 = new(MON+"warlock.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/lidfino3"));
ob2 = new(MON+"warlock.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/lidfino3"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/south_entrance"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/south_entrance"));
ob2 = new(MON+"vampiric_demon.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/south_entrance"));
ob2 = new(MON+"vampiric_demon.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/south_entrance"));
ob2 = new(MON+"vampiric_demon.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/south_entrance"));
ob2 = new(MON+"warlock.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/north_entrance"));
ob2 = new(MON+"warlock.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/north_entrance"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/north_entrance"));
ob2 = new(MON+"vampiric_demon.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ariel5"));
ob2 = new(MON+"vampiric_demon.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ariel5"));
ob2 = new(MON+"vampiric_demon.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ariel5"));
ob2 = new(MON+"vampiric_demon.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ariel5"));
ob2 = new(MON+"vampiric_demon.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ariel5"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ridge6"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ridge6"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ridge6"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ridge2"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ridge2"));
ob2 = new(MON+"warlock.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ariel4"));
ob2 = new(MON+"warlock.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ridge8"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/ridge8"));
ob2 = new(MON+"warlock.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/edge2"));
ob2 = new(MON+"warlock.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/edge3"));
ob2 = new(MON+"death_soldier.c");
ob2->set_moving(1);
ob2->set_speed(10);
ob2->move(find_object_or_load("/d/damned/daybreak/rooms/edge3"));
::die();
}
