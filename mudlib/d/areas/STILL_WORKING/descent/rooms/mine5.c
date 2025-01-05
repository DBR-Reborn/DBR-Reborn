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
    set("long", "Even with such faint light, the reflections of the gems and gold embedded in the walls nearly blinds you. It is no wonder the Gnomes are mining, despite their propensity for hilly lands - you'd drag your entire family down here for such a mother lode! It is pitch black to the north.");
set_items( (["gold" : "You pull and pull, and it doesn't come out. NOOOOO!",
"gems" : "You pull and pull, and they don't come out. NOOOOO!",
"walls" : "If this place wasn't claimed, you would sell your wife to a brothel to get this place. Theoretically." ]) );
    add_exit(ROOMS+"mine4", "east");
    add_exit(ROOMS+"mine6", "north");
        if(!present("demon")) {
  new(MON+"demon.c")->move(this_object());
  new(MON+"demon.c")->move(this_object());
}
}
