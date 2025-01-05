//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set("short", "The Entrance to the Mines.");
    set("long", "You are right at the entrance to the large mining complex of the Gnomes. To the east is the path that you took from the entrance of the underground to get here. You can enter the mines by going west.");
set_items( (["entrance" : "Judging from the workmanship, you guess it won't collapse."]) );
    add_exit(ROOMS+"mine1", "west");
    add_exit(ROOMS+"path", "east");
        if(!present("demon"))
  new(MON+"demon.c")->move(this_object());
}
