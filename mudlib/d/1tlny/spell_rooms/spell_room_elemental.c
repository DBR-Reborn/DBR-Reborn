#include <std.h>
#include "a1.h"

inherit "/std/guilds/spell_room_any";

void create() {
    ::create();
    set("short", "Global %^YELLOW%^ELEMENTAL%^RESET%^ spells");
  set("long", "This is a room that you can train Global %^YELLOW%^ELEMENTAL%^RESET%^ spells for all players. You need to join a guild to train spells for a specific guild to learn attack skills or spells.\n");
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no attack", 1); 
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("no cast", 1);
    set_join_room("/d/damned/guilds/join_rooms/child_join");


    add_exit(PATH+"spell_room_buff", "up");
    add_exit(PATH+"spell_room_summons", "down");



add_spell("elemental transformation", 1);
add_spell("body of elements", 1);
add_spell("lesser elemental strike", 1);
add_spell("lesser elemental storm", 1);
add_spell("lesser elemental bolt", 1);
add_spell("greater elemental strike", 1);
add_spell("greater elemental storm", 1);
add_spell("greater elemental bolt", 1);
add_spell("elemental strike", 1);
add_spell("elemental storm", 1);
add_spell("elemental shield", 1);
add_spell("elemental presence", 1);
add_spell("elemental curse", 1);
add_spell("elemental bolt", 1);
add_spell("elemental barrier", 1);
add_spell("elemental bane", 1);
add_spell("elemental aegis", 1);

add_spell("elemental breath", 1);
add_spell("final elemental magic", 1);
add_spell("elemental onslaught", 1);
add_spell("elemental fatality", 1);
add_spell("elemental disaster", 1);
add_spell("elemental force", 1);
add_spell("ultimate elemental burst", 1);
add_spell("extreme elemental burst", 1);
add_spell("major elemental burst", 1);
add_spell("elemental burst", 1);
add_spell("minor elemental burst", 1);
add_spell("ultimate elemental blast", 1);
add_spell("major elemental blast", 1);
add_spell("minor elemental blast", 1);
add_spell("extreme elemental blast", 1);
add_spell("elemental blast", 1);


    return;
}

