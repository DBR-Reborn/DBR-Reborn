
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 1);
set_property("indoors", 0);
add_exit(ROOMS+"basement18.c", "south");
add_exit(ROOMS+"basement16.c", "north");
set("short", "The Basement Of An Ancient House");
set("day long", "The Basement Of An Ancient House. This walls around you
are filled with cracks and chipped paint. The cieling is falling apart and
has alot of holes in it. There seems to be just enough light coming throw
the holes in the ceiling to let you see. You are standing in a small
passage. The passage way continues north and south.");

set("night long", "The Basement Of An Ancient House. This walls around you
are filled with cracks and chipped paint. The cieling is falling apart and
has alot of holes in it. You are standing in a small passage. The passage
way continues north and south.");
set_smell("default", "The smell of rat guano fills your nostrils");
set_listen("default", "The sound of rats fills the room"); 
}
void reset() {
::reset();
 if(!present("rat"))
new(MON+"rat-man_warrior.c")->move(this_object());
new(MON+"rat-man_warrior.c")->move(this_object());
new(MON+"rat-man_warrior.c")->move(this_object());
new(MON+"rat-man_warrior.c")->move(this_object());
new(MON+"rat-man_warrior.c")->move(this_object());
}
