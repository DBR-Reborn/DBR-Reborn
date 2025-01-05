#include <std.h>
#include "a1.h"

inherit "/std/guilds/spell_room_any";

void create() {
    ::create();
    set("short", "Global %^YELLOW%^BLADE%^RESET%^ spells");
  set("long", "This is a room that you can train Global %^YELLOW%^BLADE%^RESET%^ spells for all players. You need to join a guild to train spells for a specific guild to learn attack skills or spells.\n");
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no attack", 1); 
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("no cast", 1);
    set_join_room("/d/damned/guilds/join_rooms/child_join");

    add_exit(PATH+"spell_room_all", "up");
    add_exit(PATH+"spell_room_buff", "down");


add_spell("lesser elemental blade", 1);

add_spell("abyss blade", 1);
add_spell("stun blade", 1);
add_spell("stone blade", 1);
add_spell("soultaker blade", 1);
add_spell("sanctify blade", 1);
add_spell("lesser plasma blade", 1);
add_spell("lesser essential blade", 1);
add_spell("greater plasma blade", 1);
add_spell("greater essential blade", 1);
add_spell("greater elemental blade", 1);
add_spell("banshee blade", 1);
add_spell("essential blade", 1);
add_spell("elemental blade", 1);
add_spell("holy blade", 1);
add_spell("vampiric blade", 1);
add_spell("lifesteal blade", 1);


add_spell("lesser demon sword", 1);
add_spell("greater demon sword", 1);
add_spell("demon sword", 1);
add_spell("demon lord sword", 1);
add_spell("call spirit sword", 1);



add_spell("essence blade", 1);

add_spell("call blade of k'thach", 1);
add_spell("living weapon", 1);
//assassin blade spells
add_spell("assassination blade", 1);
add_spell("force blade", 1);
add_spell("pain blade", 1);
add_spell("edge of inertia", 1);


add_spell("war-hewn weapon", 1);
add_spell("poison weapon", 1);

add_spell("minor elemental weapon", 1);
add_spell("major elemental weapon", 1);
add_spell("extreme elemental weapon", 1);
add_spell("elemental weapon", 1);


    return;
}

