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
    set("long", "While Gnomes are not widely known as miners, anyone who knows them can tell you that their only match are the Dwarves. The mine shaft is very well-built and standing strong, and you can tell that this vein was dug out a while back, too. The shaft runs southeast and southwest.");
set_items( (["vein" : "You're not getting freebies in a high level area. Get over it."]) );
    add_exit(ROOMS+"mine3", "southwest");
    add_exit(ROOMS+"mine1", "southeast");
        if(!present("demon")) {
  new(MON+"demon.c")->move(this_object());
  new(MON+"demon.c")->move(this_object());
}
}
