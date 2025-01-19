inherit "/std/save_room.c";

void create()
{
    ::create();
    set_property("light", 5);
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set_property("indoors",1);
    set_property("indoors", 0);
     set("short", "The workroom of a new immortal");
    set("long", "This inherits from /std/vault_locker_room.c");
    set("night long", "It is night outside.\nA new immortal works here.\n");
    set("day long", "It is day outside.\nA new immortal works here.\n");
    add_exit ( "/wizards/honspron/workroom.c", "north");
    add_exit ("/d/damned/guilds/join_rooms/arch-mage_join.c", "am");
    add_exit ("/d/damned/guilds/join_rooms/assassin_join.c", "assassin");
    add_exit ("/d/damned/guilds/join_rooms/chaotic-lord_join.c", "cl");
    add_exit ("/d/damned/guilds/join_rooms/cleric_join.c", "cleric");
    add_exit ("/d/damned/guilds/join_rooms/dark-paladin_join.c", "dp");
    add_exit ("/d/damned/guilds/join_rooms/elemental-mage_join.c", "elemage");
    add_exit ("/d/damned/guilds/join_rooms/elementalist_join.c", "ele");
    add_exit ("/d/damned/guilds/join_rooms/enchanter_join.c", "chanter");
    add_exit ("/d/damned/guilds/join_rooms/fighter_join.c", "fighter");
    add_exit ("/d/damned/guilds/join_rooms/necromancer_join.c", "necro");
    add_exit ("/d/damned/guilds/join_rooms/nethermancer_join.c", "nether");
    add_exit ("/d/damned/guilds/join_rooms/nightblade_join.c", "nb");
    add_exit ("/d/damned/guilds/join_rooms/sword-mage_join.c", "sm");
	add_exit ("/d/damned/guilds/join_rooms/thief_join.c", "thief");
	add_exit ("/d/damned/guilds/join_rooms/tinker_join.c", "tinker");
	add_exit ("/d/damned/guilds/join_rooms/war-priest_join.c", "wp");


	   /*if (!present("rune")) {
	new ("/std/diewarzau/obj/misc/h_rune") ->move(this_object());
	 }*/
}

/*void reset()
{
    ::reset();
}*/
