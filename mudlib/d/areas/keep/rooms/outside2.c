#include <std.h>
#include "../keep.h"

inherit ROOM;

/* This is the southwest corner of the field surrounding the keep. The north exit leads toward the rear keep periphery, and the east exit goes back to the entrance of the field, where the draw bridge of the keep awaits. Present in this room are two zombies, which are equivalent in strength to that of a thief from the thieves den. */

void create() {
object ob;
::create();
set_property("light", 1);
set_property("indoors", 0);
set_short("A misty field");
set_long(@ext Mist flows throughout this dead field, making you feel sick. You see the dead grass covering the ground move swiftly, suggesting you are not alone. You can see nothing but mist, what seems to be a moat, and the faint black walls of a keep to the northeast.");
set_smell("default", "The air smells of death.
    0   
    |   
    @--0
ext);
set_listen("default", "You hear very faint sounds of movement.");
add_exit(ROOMS+"outside4", "north");
add_exit(ROOMS+"outside1", "east");
ob = new(MON+"zombie.c");
ob->move(this_object());
ob = new(MON+"zombie.c");
ob->move(this_object());
set_items(([
({ "water" }) : "The water in the moat is horribly polluted. It appears light grey through the mist.",
({ "walls" }) : "The walls of the keep appear to be pitch black, with no illumination.",
({ "field" }) : "The field is covered with dead grass and enshrouded in thick mist.",
({ "ground" }) : "Endless shreds of dead grass covers the entirety of the ground.",
({ "mist" }) : "The mist is incredibly thick, so much so that you can barely make out your own hands.",
({ "moat" }) : "The moat, filled with old and heavily polluted water, gives off a grey hue.",
({ "grass" }) : "The grass is dead without the slighest trace of green.",
({ "keep" }) : "From what you can make out, the keep appears to be black without a single light shining.",
]));
}
