#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("light", 1);
    set_property("indoors", 1);
    set_short("A tight darkened room");
    set_long("Hardly any light can be seen from the now far above library anymore, just barely enough to know that there is a very thin passage leading south away from this room and the diagonal floor leading up. The ceiling levels off with the flat floor here but does not provide very much room and requires anything of a notable height to indefinitely crouch. The two walls of this room each contain an art design painted into the very flat stone, the design of a nexus and numerous souls floating about its magical gateway.");
    set_smell("default", "The air smells of death.");
    set_listen("default", "You hear the disturbing sounds of wailing souls.");
    add_exit("/wizards/cythug/nethermancer/rooms/down1", "up");
    add_exit("/wizards/cythug/nethermancer/rooms/down3", "south");
}
