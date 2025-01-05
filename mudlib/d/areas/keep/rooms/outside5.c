#include <std.h>
#include "../keep.h"

/* This is the eastern room of the misty field area surrounding the black keep. The north and south exits from this room lead to the northeast and southeast corners of the field repectively. Present in this room are two zombies, both of which are roughly the strength of thieves from the den. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", 1);
set_property("indoors", 0);
set_short("A misty field");
set_long(@ext With burns in your eyes, you look to the west across very thick mists to see both a moat and an entire side of what seems to be a black keep. As you gaze upon the sights, you feel as if the dead grass surrounding your feet is moving ever so swiftly, suggesting others may be present here.
    0   
    |   
    @
    |
    0
ext);
set_smell("default", "The air smells of death.");
set_listen("default", "You hear very faint sounds of movement.");
add_exit(ROOMS+"outside8", "north");
add_exit(ROOMS+"outside3", "south");
ob = new(MON+"zombie.c");
ob->move(this_object());
ob = new(MON+"zombie.c");
ob->move(this_object());
set_items(([
({ "water" }) : "The water in the moat is horribly polluted. It appears light grey through the mist.",
({ "side" }) : "The side of the keep you can see appears to be pitch black, with no illumination.",
({ "sights" }) : "The sights you can see through the mist include a grey polluted moat and what seems to be a pitch black keep.",
({ "mist" }) : "The mist is incredibly thick, so much so that you can barely make out your own hands.",
({ "moat" }) : "The moat, filled with old and heavily polluted water, gives off a grey hue.",
({ "grass" }) : "The grass is dead without the slighest trace of green.",
({ "keep" }) : "From what you can make out, the keep appears to be black without a single light shining.",
]));
}
