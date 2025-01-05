#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("A downward passage");
    set_long("With light still emanating from the library not far above you, you can somewhat make out the features of this room. Not a single ornament of decoration is present on the thick stone walls, and the floor and ceiling are both completely diagonal leading up and down.");
    set_smell("default", "The air smells of death.");
    set_listen("default", "You hear the disturbing sounds of wailing souls.");
    add_exit("/wizards/cythug/nethermancer/rooms/down2", "down");
    add_exit("/d/areas/keep/rooms/insidelibrary", "up");
}
