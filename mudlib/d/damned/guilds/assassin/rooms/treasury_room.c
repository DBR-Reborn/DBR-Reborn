inherit "/std/locker_room";

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_short("The Assassin Guild Treasury Room");
    set_long("This is a very small room almost entirely bare of decoration, almost as if it is a minature prison without bars. It is here however that all members of the potent Assassin's Guild are permitted to store their various belongings for safekeeping. All members using this storage facility must be aware however that any member is permitted to access anything located here in either lockers, chests, or from the floor. Be certain that all opened storage items are closed when no one is present in this room, or everything may be lost.");
    add_exit("/d/damned/guilds/assassin/rooms/foyer_room.c", "south");
 
if (!present("rune")) {
	new ("/std/diewarzau/obj/misc/h_rune") ->move(this_object());
	 }
if (!present("locker")) {
	new("/std/diewarzau/obj/misc/storage_locker")->move(this_object());
	}
    return;
}