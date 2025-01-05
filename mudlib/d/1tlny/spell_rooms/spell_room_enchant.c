#include <std.h>
#include "a1.h"

inherit "/std/guilds/spell_room_any";

void create() {
    ::create();
    set("short", "Global %^YELLOW%^ENCHANT%^RESET%^ spells");
  set("long", "This is a room that you can train Global %^YELLOW%^ENCHANT%^RESET%^ spells for all players. You need to join a guild to train spells for a specific guild to learn attack skills or spells.\n");
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no attack", 1); 
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("no cast", 1);
    set_join_room("/d/damned/guilds/join_rooms/child_join");


    add_exit(PATH+"spell_room_all", "down");

//FIXED
//WEAPON
add_spell("true weapon", 1);
add_spell("dark weapon", 1);
add_spell("bless weapon", 1);
add_spell("flame blade", 1);
add_spell("icy weapon", 1);
add_spell("major puissance", 1);
add_spell("minor puissance", 1);
add_spell("major accuracy", 1);
add_spell("minor accuracy", 1);
//WEAPON LOCKS
add_spell("claimed weapon", 1);
add_spell("lock enchantment", 1);
//ARMOUR
add_spell("true armour", 1);
add_spell("bless armour", 1);
add_spell("major fortification", 1);
add_spell("minor fortification", 1);
//OTHER
add_spell("enchanter mark", 1);

//WORKING ON
add_spell("prepare spell", 1);
add_spell("prepare skill", 1);
add_spell("imbue spell", 1);
add_spell("imbue skill", 1);


    return;
}

