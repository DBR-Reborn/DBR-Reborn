//  Made by Tailwind for the Invisible-Dagger Area.
#include "../newshards.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "The Room of the Bed.");
    set("long", "This is a secret whorehouse in the town! You wonder why they made it so secret. The only thing in this room is a large bed, probably for... business. You can exit by taking the stairs back up to the surface.");

set_items( (["bed": "It looks really comfortable and bouncy." ]) );
    add_exit(ROOMS+"street4", "up");
}

void reset() {
     ::reset();
if(!present("whore")) {
new(MON+"girl.c")->move(this_object());
}
}
