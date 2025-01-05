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
    set("long", "As you progress deeper into the mines, it becomes darker and darker. There's still a bit of light streaming in from the entrance of the tunnel, though, so it's not pitch black. This part of the shaft was probably exhausted of minerals, but you swear you can see a glitter on the walls, even in the faint light.");
set_items( (["glitter" : "Fool's gold, you can tell, under closer inspection."]) );
    add_exit(ROOMS+"mine4", "north");
    add_exit(ROOMS+"mine2", "northeast");
        if(!present("demon")) {
  new(MON+"demon.c")->move(this_object());
  new(MON+"demon.c")->move(this_object());
}
}
