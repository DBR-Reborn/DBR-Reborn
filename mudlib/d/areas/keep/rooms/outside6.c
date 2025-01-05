#include <std.h>
#include "../keep.h"

/* This is the northwest room of the periphery surrounding the black keep. Now in the rear area, going east will lead directly behind the keep, and going south will go to the keep's west side. Present in this room are three zombies, which opt to give the player a slightly better challenge than the rooms with two zombies. The zombies are roughly equivalent to a thief from the den in difficulty. */ 

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", 1);
set_property("indoors", 0);
set_short("A misty field");
set_long(@ext Standing still, you see the dead grass move swiftly as if someone or something is watching you. Shrouded in mist, you cannot tell. You can only see the polluted moat and what you think is a large black keep to your southeast.

    @--0
    |
    0
ext);
set_smell("default", "The air smells of death.");
set_listen("default", "You hear very faint sounds of movement.");
add_exit(ROOMS+"outside4", "south");
add_exit(ROOMS+"outside7", "east");
ob = new(MON+"zombie.c");
ob->move(this_object());
ob = new(MON+"zombie.c");
ob->move(this_object());
ob = new(MON+"zombie.c");
ob->move(this_object());
set_items(([
({ "water" }) : "The water in the moat is horribly polluted. It appears light grey through the mist.",
({ "mist" }) : "The mist is incredibly thick, so much so that you can barely make out your own hands.",
({ "moat" }) : "The moat, filled with old and heavily polluted water, gives off a grey hue.",
({ "grass" }) : "The grass is dead without the slighest trace of green.",
({ "keep" }) : "From what you can make out, the keep appears to be black without a single light shining.",
]));
}
