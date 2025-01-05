//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "Inside the Gnome Mines.");
    set("long", "Evil. That's all you can feel - a tremendous evil to the north. What is going on here? The utter darkness makes you even more worried.");
    set_smell("default", "You smell death and fear in the air.");
    set_listen("default","There's some sort of whirring noise to the north.");
    add_exit(ROOMS+"mine6", "south");
    add_exit(ROOMS+"mine8", "north");
        if(!present("demon")) {
  new(MON+"demon.c")->move(this_object());
  new(MON+"demon.c")->move(this_object());
  new(MON+"demon.c")->move(this_object());
}
}
