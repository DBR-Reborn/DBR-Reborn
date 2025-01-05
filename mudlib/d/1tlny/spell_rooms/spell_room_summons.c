#include <std.h>
#include "a1.h"

inherit "/std/guilds/spell_room_any";

void create() {
    ::create();
    set("short", "Global %^YELLOW%^SUMMONS%^RESET%^ spells");
  set("long", "This is a room that you can train Global %^YELLOW%^SUMMONS%^RESET%^ spells for all players. You need to join a guild to train spells for a specific guild to learn attack skills or spells.\n");
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no attack", 1); 
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("no cast", 1);
    set_join_room("/d/damned/guilds/join_rooms/child_join");


    add_exit(PATH+"spell_room_elemental", "up");
    add_exit(PATH+"spell_room_other", "down");


//NEW
  add_spell("summon demon prince", 1);

add_spell("summon black weapon", 1);
add_spell("summon holy bane", 1);
add_spell("summon woodland familiar", 1);
add_spell("summon rune", 1);
add_spell("summon lesser elemental", 1);
add_spell("summon lesser demon", 1);
add_spell("summon illusionary guardian", 1);
add_spell("summon guardian angel", 1);
add_spell("summon greater familiar", 1);
add_spell("summon greater elemental", 1);
add_spell("summon greater demon", 1);
add_spell("summon familiar", 1);
add_spell("stabilize familiar", 1);
add_spell("summon ethereal entity", 1);
add_spell("summon elemental dragon", 1);
add_spell("summon elemental", 1);
add_spell("summon elder seraph", 1);
add_spell("summon desert spirit", 1);
add_spell("summon demon lord", 1);
add_spell("summon demon", 1);
add_spell("summon arch angel", 1);
add_spell("summon aerial servant", 1);
add_spell("fashion statue", 1);
add_spell("fashion golem", 1);
add_spell("fashion dragon engine", 1);
add_spell("improve statue", 1);
add_spell("improve golem", 1);
add_spell("improve dragon engine", 1);

//NECROMANCER summon stuff
add_spell("animate zombie", 1);
add_spell("animate wood", 1);
add_spell("animate vampire", 1);
add_spell("animate skeleton", 1);
add_spell("animate lich", 1);
add_spell("animate ghoul", 1);
add_spell("animate ghast", 1);
add_spell("animate death knight", 1);
add_spell("undead dimension", 1);
add_spell("transport undead", 1);
add_spell("animate demilich", 1);
add_spell("animate dracolich", 1);
add_spell("animate abomination", 1);
add_spell("animate nethergeist", 1);

add_spell("bind lesser demon", 1);
add_spell("bind greater demon", 1);
add_spell("bind drizzt", 1);
add_spell("bind demon-lord", 1);
add_spell("bind demon lord", 1);
add_spell("bind demon", 1);
add_spell("demonic rebirth", 1);

add_spell("summon extreme mass", 1);
add_spell("summon ultimate mass", 1);
add_spell("summon greater mass", 1);
add_spell("summon mass", 1);
add_spell("summon lesser mass", 1);
add_spell("create elemental overlord", 1);
add_spell("create elemental dragon", 1);
add_spell("create elemental demon", 1);
add_spell("create elemental warrior", 1);
add_spell("create elemental fighter", 1);
add_spell("greater mass immersion", 1);
add_spell("extreme mass immersion", 1);
add_spell("mass immersion", 1);
add_spell("lesser mass immersion", 1);
add_spell("bind greater mass", 1);
add_spell("bind extreme mass", 1);
add_spell("bind mass", 1);
add_spell("bind lesser mass", 1);
add_spell("mass diffusion", 1);

add_spell("mold nether staff", 1);
add_spell("mold nether robe", 1);
add_spell("undead creation", 1);
add_spell("major undead creation", 1);
add_spell("forbidden undead creation", 1);
add_spell("elite undead creation", 1);
add_spell("minor undead creation", 1);
add_spell("elite soul union", 1);
add_spell("soul union", 1);
add_spell("major soul union", 1);
add_spell("minor soul union", 1);
add_spell("dark knight infusion", 1);
add_spell("chaos shadow infusion", 1);
add_spell("blood fiend infusion", 1);
add_spell("ghost infusion", 1);
add_spell("rotted zombie infusion", 1);
add_spell("blood hound infusion", 1);
add_spell("bone man infusion", 1);
add_spell("forbidden soul union", 1);
add_spell("forbidden orb finalization", 1);
add_spell("major orb finalization", 1);
add_spell("elite orb finalization", 1);
add_spell("orb finalization", 1);
add_spell("minor orb finalization", 1);
add_spell("minor orb sacrifice", 1);
add_spell("major orb sacrifice", 1);
add_spell("orb stabilization", 1);
add_spell("orb sacrifice", 1);
add_spell("elite orb sacrifice", 1);
add_spell("soul duplication", 1);
add_spell("soul transference", 1);
add_spell("soul release", 1);

    return;
}

