#include <std.h>
#include "../keep.h"

/* This is the entrance room of the field surrounding the main area, and is also the first room a player enters from the world map. No monsters are present here. The north exit leads to the keep gates, west and east go around the keeps periphery, and leave goes back to the world map. */

inherit ROOM;

void create() {
::create();
set_property("light", 1);
set_property("indoors", 0);
set_short("A misty field");
set_long(@ext As you stand still in this field, you are shrouded in thick mist. The grass beneath your feet is dead, and all you can make out is a rotting draw bridge above what seems to be a moat, and an imposing black structure to your direct north beyond it.");
set_smell("default", "The air smells of death.
    0   
    |   
 0--@--0
        leave
ext);
set_listen("default", "You dont hear a sound.");
add_exit(ROOMS+"outside2", "west");
add_exit(ROOMS+"outside3", "east");
add_exit(ROOMS+"outsidegate", "north");
add_exit("/d/damned/virtual/room_24_6.world", "leave");
set_items(([
({ "water" }) : "The water in the moat is horribly polluted. It appears light grey through the mist.",
({ "water" }) : "The water in the moat is horribly polluted. It appears light grey through the mist.",
({ "field" }) : "The field is covered with dead grass and enshrouded in thick mist.",
({ "mist" }) : "The mist is incredibly thick, so much so that you can barely make out your own hands.",
({ "bridge" }) : "Rotting unsturdy wood appearing to be decades old comprises the draw bridge.",
({ "moat" }) : "The moat beneath the bridge surrounding the keep is filled with extremely old and polluted water, which gives off a grey hue.",
({ "grass" }) : "The grass is dead without the slightest trace of green.",
({ "keep" }) : "From what you can make out, the keep appears to be black without a single light shining.",
({ "structure" }) : "From what you can make out, the structure appears to be black without a single light shining.",
]));
add_pre_exit_function("north", "go_north");
}

int go_north() {
write("You cross the draw bridge, despite nearly falling into the moat from some of the rotting wood buckling beneath your feet.");
return 1;
}
