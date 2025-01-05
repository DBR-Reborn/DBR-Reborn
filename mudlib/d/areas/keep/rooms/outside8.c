#include <std.h>
#include "../keep.h"

/* This is the misty fields' northeast room, a rear corner of the black keep periphery. Here in the rear of the keep, moving along to the west will lead to the keeps complete back side, while going to the south will end up at the keeps complete east side. In this room three zombies await the player. They provide a slightly higher challenge than two zombies, all of the zombies which are equivalent in power roughly to a thief from the thieves den. */

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", 1);
set_property("indoors", 0);
set_short("A misty field");
set_long(@ext Feeling cold from the relentless shrouds of mist, you look at the dead grass and you see parts of it blow near you. Perhaps there is another being of some sort here with you. To your southwest you can make out a medium sized moat of polluted water, plus two sides of what appears to be an ancient keep.
  
 0--@
    |
    0
ext); 
set_smell("default", "The air smells of death.");
set_listen("default", "You hear very faint sounds of movement.");
add_exit(ROOMS+"outside5", "south");
add_exit(ROOMS+"outside7", "west");
ob = new(MON+"zombie.c");
ob->move(this_object());
ob = new(MON+"zombie.c");
ob->move(this_object());
ob = new(MON+"zombie.c");
ob->move(this_object());
set_items(([
({ "water" }) : "The water in the moat is horribly polluted. It appears light grey through the mist.",
({ "sides" }) : "The sides of the keep you can see appears to be pitch black, with no illumination.",
({ "mist" }) : "The mist is incredibly thick, so much so that you can barely make out your own hands.",
({ "moat" }) : "The moat, filled with old and heavily polluted water, gives off a grey hue.",
({ "grass" }) : "The grass is dead without the slighest trace of green.",
({ "keep" }) : "From what you can make out, the keep appears to be black without a single light shining.",
]));
}
