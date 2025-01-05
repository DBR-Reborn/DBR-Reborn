//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 1);
    set_property("night light", 1);
    set_property("indoors", 1);
    set("short", "Inside the Gnome Mines.");
    set("long", "In this part of the tunnel, the minerals have _not_ been fully mined out by a long shot. Glittering gold, sparkling gems, and other treasures are buried in the walls. You tug on one as you walk by, but they are firmly embedded, and you doubt you could get one out no matter what you did.");
set_items( (["gold" : "You pull and pull, and it doesn't come out. NOOOOO!",
"gems" : "You pull and pull, and they don't come out. NOOOOO!",
"walls" : "A treasure trove. Now, what made the Gnomes abandon ship?" ]) );
    add_exit(ROOMS+"mine5", "west");
    add_exit(ROOMS+"mine3", "south");
        if(!present("demon")) {
  new(MON+"demon.c")->move(this_object());
  new(MON+"demon.c")->move(this_object());
}
}
