#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("A tight hallway");
    set_long("A small amount of light from the south gives this room enough illumination to make out its features rather effectively, and from what you can see those features are relatively signnificant as compared to other rooms you have seen within this keep. The entire west and east walls of the room are covered by a very large and identical art design that depicts storms, shadows, and damned souls surrounding a dark robed mage. The walls, floor, and the ceiling are all extremely flat and smooth, with ceiling also containing a design. That design is simplistic however, it being only a few dark clouds. To the north you can see the upwards passage leading back towards the library, but following the light to the south you can see this passage widening itself into a full sized chamber.");
    set_smell("default", "The air smells of death.");
    set_listen("default", "You hear extremely loud and very disturbing sounds of wailing souls.");
    add_exit("/d/damned/guilds/nethermancer/down2", "north");
    add_exit("/d/damned/guilds/join_rooms/nethermancer_join", "south");
}
