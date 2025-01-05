//      An example skill training room for the fighter's guild.
//
//      DarkeLIB 0.1
//      -Diewarzau 8/8/95
//
//      Edited by Tailwind
//
//      Blessed ReturnLIB
//      Tailwind 10/28/98

#include <std.h>

inherit "/std/guilds/spell_room";

void create() {
    ::create();
    set("short", "The Alchemists' Training Room");
    set("long", "This is the room where alchemists come to practice their
powerful spells.");
    //  "\n" important here, too.
    set_property("light", 2);
    set_property("indoors", 1);

    //  The following line is VERY, VERY important.
    set_join_room("/d/damned/guilds/join_rooms/alchemist_join");

    set_exits( ([ "east" : "/d/damned/guilds/alchemist/train_room",
        "north" : "/d/damned/guilds/alchemist/lab_room" ]));

    //  All the rest is adding the skills.  The add_skill lines are of the
    //  following form:
    //          add_skill(string skill, int level, int flag)
    //  skill           The name of the skill which is being added
    //  level           The level at which the player may begin
    //                  developing the skill.
    //  flag            (optional)  If a non-zero number is supplied,
    //                  the skill will be considered "secondary" to
    //                  the guild and cost double to develop.

    add_spell("cooking", 3);  
    add_spell("halt decay", 3);
    add_spell("minor life", 3);
    add_spell("color change", 4);
    add_spell("explosive geometry", 7);
    add_spell("ensnare spell", 9);
    add_spell("imbue potion", 13);
//Missing spell    //add_spell("etheral form", 10);  
    add_spell("activate stone", 11);
    add_spell("speed", 11);
    add_spell("magic leach", 12);
    add_spell("destroy pattern", 13);
    add_spell("major life", 14);
    add_spell("poison fumes", 14);
    add_spell("nuclear prism", 15);
    add_spell("aura flare", 13);
    add_spell("true life", 20);
//Broken Spell    //add_spell("condition weapon", 26);
//Missing code    //add_spell("mineral change", 30);

    return;
}

