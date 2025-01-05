#include <std.h>
#include "../keep.h"

/* This is the southeast corner of the field surrounding the keep. The north exit leads toward the rear keep periphery, and the west exit goes back to the entrance of the field, where the draw bridge of the keep awaits. There are no monsters in this room. */

inherit ROOM;

void create() {
::create();
set_property("light", 1);
set_property("indoors", 0);
set_short("A misty field");
set_long(@ext You begin to feel dizzy as you walk through the relentless mist. Feeling the dead grass with your feet you stand to look around, seeing only a moat and what appears to be a keep to the northwest.
    0   
    |   
 0--@
ext);
set_smell("default", "The air smells of death");
set_listen("default", "You dont hear a sound");
add_exit(ROOMS+"outside5", "north");
add_exit(ROOMS+"outside1", "west");
set_items(([
({ "water" }) : "The water in the moat is horribly polluted. It appears light grey through the mist.",
({ "mist" }) : "The mist is incredibly thick, so much so that you can barely make out your own hands.",
({ "moat" }) : "The moat, filled with old and heavily polluted water, gives off a grey hue.",
({ "grass" }) : "The grass is dead without the slightest trace of green.",
({ "keep" }) : "From what you can make out, the keep appears to be black without a single light shining.",
]));
}
