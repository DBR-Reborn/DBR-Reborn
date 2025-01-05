inherit ROOM;

void create() {
    object ob;
    ::create();
    set_short("The Assassin's Foyer");
    set_long("Looking about as you enter this room you notice it to be considerably cold and dark, with three different exits in sight. To the north you see the narrow path to the Assassin Guild Treasury, and to the south you see the slightly brighter guild join room. The eastern part of the room contains a stairway leading down into the Inner Sanctum, the forbidden area where all Assassins hone their deadly talents.");
    set_property("light", 1);
    set_property("indoors", 1);
    ob = new("/d/damned/guilds/assassin/misc/kyoki_statue.c");
    ob->move(this_object());
    ob = new("/d/damned/guilds/assassin/t_guard.c");
    ob->move(this_object());
    add_exit("/d/damned/guilds/join_rooms/assassin_join.c", "south");
    add_exit("/d/damned/guilds/assassin/rooms/treasury_room.c", "north");
    add_exit("/d/damned/guilds/assassin/rooms/skill_room_1.c", "down");
    add_pre_exit_function("north", "go_north");
    return;
}

int go_north() {
    if(this_player()->query_class() == "assassin") {
	write("The Death Artist looks you over and deems you fit to proceed.");
	return 1;
    }
    if(!present("death artist")) {
	return 1;
    }
    if(this_player()->query_class() != "assassin") {
	write("The Death Artist eyes you with an piercing glare and forbids your entry.");
	return 0;
    }
}

