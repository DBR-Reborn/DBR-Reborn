//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set("short", "Inside the Gnome Mines.");
    set("long", "You have stepped into the entrance of the Gnomish mines. Torches light the spacious mine shaft. The walls appear to be quite smooth, and you can tell that this vein was dug out a long time ago. The exit to the mines is east, and you can continue to the northwest.");
set_items( (["vein" : "Nothing here, sucker.",
"torches" : "You need to look at torches? Man, you're a loser." ]) );
    add_exit(ROOMS+"mine2", "northwest");
    add_exit(ROOMS+"mine-enter", "east");
        if(!present("demon")) {
  new(MON+"demon.c")->move(this_object());
  new(MON+"demon.c")->move(this_object());
}
}
