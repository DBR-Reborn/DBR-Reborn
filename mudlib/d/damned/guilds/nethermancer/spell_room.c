#include <std.h>

inherit "/std/guilds/spell_room";

void create() {
    ::create();
    set_short("The Nethermancer Chamber of Spell Training");
    set_long("This room compared to most others in the guild is extremely small, barely large enough to hold out an average persons arms horizontally. However, it is here that by using the glowing glyph on the floor that members of the Nethermancer Guild can harness the powers needed to educate themselves in various types of magic. Once the magic is trained, it can be utilized either with soul orbs or with nexuses of varying sizes depending on the power of the spell.\n");
    set_property("light", 2);
    set_property("indoors", 1);
    set_join_room("/d/damned/guilds/join_rooms/nethermancer_join");
    add_exit("/d/damned/guilds/nethermancer/skill_room", "south");
    add_spell("bone man infusion", 1);
    add_spell("minor orb finalization", 1);
    add_spell("minor orb sacrifice", 1);
    add_spell("minor undead creation", 1);
    add_spell("rotted zombie infusion", 3);
    add_spell("minor soul union", 4);
    add_spell("blood hound infusion", 7);
    add_spell("mold nether staff", 10);
    add_spell("mold nether robe", 10);
    add_spell("ghost infusion", 12);
    add_spell("nether gate", 15);
    add_spell("blood fiend infusion", 20);
    add_spell("orb finalization", 20);
    add_spell("orb sacrifice", 20);
    add_spell("undead creation", 20);
    add_spell("soul union", 21);
    add_spell("orb stabilization", 24);
    add_spell("induce nether form", 28);
    add_spell("dark knight infusion", 30);
    add_spell("soul duplication", 32);
    add_spell("chaos shadow infusion", 35);
    add_spell("major orb finalization", 35);
    add_spell("major orb sacrifice", 35);
    add_spell("major undead creation", 35);
    add_spell("major soul union", 38);
    add_spell("soul release", 40);
    add_spell("soul transference", 42);
    add_spell("undead restoration", 46);
    add_spell("elite orb finalization", 48);
    add_spell("elite soul union", 48);
    add_spell("elite undead creation", 48);
    add_spell("elite orb sacrifice", 48);
    add_spell("forbidden soul union", 58);
    add_spell("forbidden orb finalization", 59);
    add_spell("forbidden undead creation", 60);
    return;
}

