#include <std.h>

inherit "/std/locker_room";

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    add_exit("/d/damned/guilds/nethermancer/skill_room", "east");
    set_short("The Nethermancer Chamber of Storage");
    set_long("This is a very large chamber with enormous amounts of empty space for there is nothing present hanging from any of the walls or from the ceiling. It is within this room that a Nethermancer is permitted to store the belongings of his or her choice, whether they be on the floor or in chests or lockers. If lockers are used here, it is imperative that they be closed at all times when not being used, or there is a possibility that their contents can be lost.");

if (!present("rune")) {
	new ("/std/diewarzau/obj/misc/h_rune") ->move(this_object());
	 }

	    return;

}
