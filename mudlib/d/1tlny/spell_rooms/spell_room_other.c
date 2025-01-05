#include <std.h>
#include "a1.h"

inherit "/std/guilds/spell_room_any";

void create() {
    ::create();
    set("short", "Global %^YELLOW%^OTHER%^RESET%^ spells");
  set("long", "This is a room that you can train Global %^YELLOW%^OTHER%^RESET%^ spells for all players. You need to join a guild to train spells for a specific guild to learn attack skills or spells.\n");
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no attack", 1); 
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("no cast", 1);
    set_join_room("/d/damned/guilds/join_rooms/child_join");


    add_exit(PATH+"spell_room_summons", "up");

//MONSTER ONLY
/*
/home/bob/DarkeLIB-master/mudlib/d/areas/keep/spells/absorption.c     <-- Could be DP spell
/home/bob/DarkeLIB-master/mudlib/d/areas/keep/spells/dark_empowerment.c
/home/bob/DarkeLIB-master/mudlib/d/areas/keep/spells/death.c
/home/bob/DarkeLIB-master/mudlib/d/areas/keep/spells/fire_breath.c
/home/bob/DarkeLIB-master/mudlib/d/areas/keep/spells/grand_summon.c
/home/bob/DarkeLIB-master/mudlib/d/areas/keep/spells/hell_blast.c
/home/bob/DarkeLIB-master/mudlib/d/areas/keep/spells/ice_breath.c
/home/bob/DarkeLIB-master/mudlib/d/areas/keep/spells/icefire_breath.c
/home/bob/DarkeLIB-master/mudlib/d/areas/keep/spells/storm_of_ages.c  <-- Could be DP spell
/home/bob/DarkeLIB-master/mudlib/d/areas/keep/spells/violent_blaze.c
whelp_summon
*/

//NEW
//add_spell("summon shadow weapon", 1); //DP spell xavier
//add_spell("shadow edge"); //DP spell xavier
add_spell("call_weapon_of_kthach.c", 1);
add_spell("call_weapon_of_faith.c", 1);
add_spell("call_spirit_weapon.c", 1);
add_spell("unholy will", 1);

//damage spell
add_spell("chilling touch", 1);
add_spell("burning hands", 1);
add_spell("call lightning", 1);
add_spell("wind of death", 1);
add_spell("vacuum bolt", 1);
//AOE DAMAGE
add_spell("wrath of god", 1);
//curses
add_spell("curse vision", 1);
add_spell("distance poison", 1);
//nethermancer
add_spell("nether gate", 1);
//dark-paladin
add_spell("soul crush", 1);
add_spell("power of darkness", 1);
add_spell("lesser shadow field", 1);
add_spell("owedquar's fury", 1);
add_spell("owedquar's might", 1);
add_spell("black fire", 1);
add_spell("black edge", 1);
add_spell("dark pact", 1);
add_spell("shadow field", 1);
add_spell("cause weakness", 1);
add_spell("abyss blast", 1);
add_spell("absorption", 1);
add_spell("greater shadow field", 1);
add_spell("storm of ages", 1);
add_spell("owedquar's wrath", 1);
add_spell("shadow bolt", 1);
add_spell("dark assault", 1);
add_spell("black shroud", 1);
//enchantment

//preserve corpse
add_spell("embalm corpse", 1);
//create food item
add_spell("create food", 1);
//posion
add_spell("body disruption", 1);
add_spell("area poison", 1);
//steal items
add_spell("apportation", 1);
//BROKEN?
add_spell("wor shad", 1);
add_spell("weaken", 1);
//teleportation
add_spell("word of recall", 1);
//res spell
add_spell("warrior's interment", 1);
//heal spell
add_spell("true heal", 1);

add_spell("transport rune", 1);
add_spell("transport beacon", 1);
add_spell("transport", 1);
add_spell("transmutation", 1);
add_spell("teleport", 1);
add_spell("summon", 1);
add_spell("suggestion", 1);
add_spell("store spell", 1);
add_spell("soul gate", 1);
add_spell("smite", 1);
add_spell("slow", 1);
add_spell("silent walk", 1);
//broken spell
add_spell("shadow form", 1);
add_spell("sense aura", 1);
add_spell("self power", 1);
add_spell("scry", 1);
add_spell("scribe scroll", 1);
add_spell("satisfy thirst", 1);
add_spell("satisfy hunger", 1);
add_spell("sanctuary", 1);
add_spell("sanctify", 1);
add_spell("rot", 1);
//add_spell("ritual generic", 1);
//add_spell("ritualdud", 1);
add_spell("revitalization", 1);
add_spell("resurrect", 1);
add_spell("remove poison", 1);
add_spell("rejuvination", 1);
add_spell("regeneration", 1);
add_spell("regenerate", 1);
add_spell("rain of spears", 1);
add_spell("preserve rune", 1);
add_spell("preserve corpse", 1);

add_spell("poison rune", 1);

add_spell("meteor storm", 1);
add_spell("mass heal", 1);
add_spell("mass barrier", 1);
add_spell("mana vortex", 1);
add_spell("mana drain", 1);

add_spell("magic missile", 1);

add_spell("link", 1);
add_spell("light of day", 1);
add_spell("lightning bolt", 1);
add_spell("light", 1);
add_spell("lifesteal", 1);
add_spell("levitation", 1);
add_spell("lamp of night", 1);
add_spell("killing cloud", 1);
add_spell("intoxication", 1);
add_spell("internal flame", 1);
add_spell("instill poison", 1);
add_spell("infravision", 1);
add_spell("indomitable spirit", 1);
add_spell("implosion", 1);

add_spell("ice dagger", 1);
add_spell("holy word", 1);
add_spell("holy strike", 1);
add_spell("holy light", 1);
add_spell("holy lamp", 1);
add_spell("holy condemnation", 1);
add_spell("hex", 1);
add_spell("healing rune", 1);
add_spell("heal", 1);
add_spell("harm2", 1);
add_spell("harm", 1);
add_spell("hand of the divine", 1);
add_spell("hand of light", 1);
add_spell("hammer of k'thach", 1);
add_spell("hammer of god", 1);
add_spell("gate rune", 1);
add_spell("gate hellion", 1);
add_spell("gaseous form", 1);
add_spell("garguth's pounding fist", 1);
add_spell("garguth's open palm", 1);
add_spell("garguth's grasping hand", 1);
add_spell("fireball", 1);
add_spell("faerie fire", 1);
add_spell("explosive fireball", 1);
add_spell("exploding rune", 1);
add_spell("entangle", 1);
add_spell("drizzt strike", 1);
add_spell("drain life", 1);
add_spell("divine punishment", 1);
add_spell("distance healing", 1);
add_spell("distance harming", 1);
add_spell("disruption bolt", 1);
add_spell("dispel rune", 1);
add_spell("dispel magic", 1);
add_spell("delay rune", 1);
add_spell("delay", 1);
//Curse slow
add_spell("decrease metabolism", 1);
add_spell("curse", 1);
add_spell("decay", 1);
add_spell("dark of night", 1);
add_spell("darkness", 1);
add_spell("dagger storm", 1);
add_spell("cure serious wounds", 1);
add_spell("cure light wounds", 1);
add_spell("cure critical wounds", 1);
add_spell("create teleport beacon", 1);
add_spell("create elixir of healing", 1);
add_spell("create alabaster potion", 1);
add_spell("counter spell", 1);
add_spell("cold blast", 1);
add_spell("clairvoyance", 1);
add_spell("claim activate", 1);
add_spell("chaos storm", 1);
add_spell("chaos bane", 1);
add_spell("chaos ball", 1);
add_spell("cause serious wounds", 1);
add_spell("cause light wounds", 1);
add_spell("cause critical wounds", 1);
add_spell("call holy staff", 1);
add_spell("call hammer of faith", 1);
add_spell("call divine plate", 1);
add_spell("bolt of righteousness", 1);
add_spell("blizzard", 1);
add_spell("alter visage", 1);
add_spell("activate powerstone", 1);
add_spell("induce nether form", 1);
add_spell("dark breath", 1);
add_spell("undead restoration", 1);
add_spell("time leap", 1);
add_spell("pain", 1);
add_spell("fade", 1);
add_spell("blackout", 1);
add_spell("teleportation", 1);
add_spell("striking point", 1);
add_spell("mental lock", 1);
add_spell("stun blast", 1);
add_spell("enemy vision", 1);
add_spell("keen detection", 1);
add_spell("mind freeze", 1);
add_spell("eye seal", 1);
add_spell("energize dragon jewel", 1);
add_spell("planar wrath", 1);
add_spell("energy sphere", 1);
add_spell("mass enhancement", 1);
add_spell("owedquar's eyes", 1);
add_spell("mist cloud", 1);
add_spell("anger charge", 1);


    return;
}

