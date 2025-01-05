#include <std.h>
#include "../keep.h"

/* This is the room directly behind the black keep, and the furthest outside room from the entrance. Both of the two exits of this room lead to the rear two corners of the misty field respectively. This room is also designed to be a challenge room for a character, as it contains two zombies and two large snakes. The zombies are comparable to a thief from the thieves den, while the snakes are comparable to a shard demon. If a player can survive this room, they are ready to brave entering the black keep without high risk. */ 

inherit ROOM;

void create() {
object ob;
::create();
set_property("light", 1);
set_property("indoors", 0);
set_short("A misty field");
set_long(@ext Looking to the south through horrid mist, you know see you are directly behind what seems to be a large black keep, protected by a grey polluted moat. There is a great deal of sound coming from the area, some of which sounds like faint footsteps and some what seems like slithering cutting across the dead grass. You definitely know you are not alone.
  
 0--@--0
ext);
set_smell("default", "The air smells of death.");
set_listen("default", "You hear a great deal of movement.");
add_exit(ROOMS+"outside8", "east");
add_exit(ROOMS+"outside6", "west");
ob = new(MON+"zombie.c");
ob->move(this_object());
ob = new(MON+"zombie.c");
ob->move(this_object());
ob = new(MON+"snake.c");
ob->move(this_object());
ob = new(MON+"snake.c");
ob->move(this_object());
set_items(([
({ "water" }) : "The water in the moat is horribly polluted. It appears light grey through the mist.",
({ "area" }) : "The area surrounding you consists mostly of thick mist, with dead grass covering the ground and a moat plus what you think is a black keep to your south.",
({ "mist" }) : "The mist is incredibly thick, so much so that you can barely make out your own hands.",
({ "moat" }) : "The moat, filled with old and heavily polluted water, gives off a grey hue.",
({ "grass" }) : "The grass is dead without the slighest trace of green.",
({ "keep" }) : "From what you can make out, the keep appears to be black without a single light shining.",
]));
}
