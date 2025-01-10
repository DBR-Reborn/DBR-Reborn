#include "/adm/include/std.h"

inherit "/std/save_room";

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);

    set_property("no scry", 1);
    set_property("no summon", 1);
	set_property("no teleport",1);
    set_property("no attack", 1);
    set_property("no cast", 1);

    set("short", "The workroom of a new immortal");
set( "day long", @EndText
It is %^YELLOW%^DAY%^RESET%^ outside.

You are here because TLNY summoned you here you better talk to him

EndText);

set( "night long", @EndText
It is %^BOLD%^BLUE%^NIGHT%^RESET%^ outside.

You are here because TLNY summoned you here you better talk to him

EndText);
/*
    add_exit("/std/obj/workroom.c", "main");
    add_exit("/d/daybreak/room/N1", "portal");


    add_exit("/wizards/tlny/workroom.c", "south");

    add_exit("/d/damned/guilds/join_rooms/arch-mage_join", "arch-mage");
    add_exit("/d/damned/guilds/join_rooms/chaotic-lord_join", "chaotic-lord");
    add_exit("/d/damned/guilds/join_rooms/cleric_join", "cleric");
    add_exit("/d/damned/guilds/join_rooms/dark-paladin_join", "dark-paladin");
    add_exit("/d/damned/guilds/join_rooms/elementalist_join", "elementalist");
    add_exit("/d/damned/guilds/join_rooms/enchanter_join", "enchanter");
    add_exit("/d/damned/guilds/join_rooms/fighter_join", "fighter");
    add_exit("/d/damned/guilds/join_rooms/necromancer_join", "necromancer");
    add_exit("/d/damned/guilds/join_rooms/nightblade_join", "nightblade");
    add_exit("/d/damned/guilds/join_rooms/paladin_join", "paladin");
    add_exit("/d/damned/guilds/join_rooms/sword-mage_join", "sword-mage");
    add_exit("/d/damned/guilds/join_rooms/tinker_join", "tinker");
    add_exit("/d/damned/guilds/join_rooms/war-priest_join", "war-priest");

    add_exit("/d/damned/guilds/join_rooms/theif_join", "theif");

    add_exit("/d/damned/guilds/join_rooms/elemental-mage_join", "elemental-mage");
    add_exit("/d/damned/guilds/join_rooms/mercenary_join", "mercenary");
    add_exit("/d/damned/guilds/join_rooms/nethermancer_join", "nethermancer");
    add_exit("/d/damned/guilds/join_rooms/shaman_join", "shaman");
    add_exit("/d/damned/guilds/join_rooms/assassin_join", "assassin");
    add_exit("/d/damned/guilds/join_rooms/alchemist_join", "alchemist");
*/
        add_exit("/d/daybreak/room/db_square", "daybreak");
        set_invis_exits(({ "daybreak" }));


}
