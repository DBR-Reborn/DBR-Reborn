
#include "../ruins.h"
#include <std.h>
inherit "std/room";
void create() {
::create() ;
set_property("light", 1);
set_property("indoors", 0);
add_exit(ROOMS+"basement11.c", "west");
add_exit(ROOMS+"basement13.c", "south");
set("short", "The Basement Of An Ancient House");
set("day long", "The Basement Of An Ancient House. This walls around you
are filled with cracks and chipped paint. The cieling is falling apart and
has alot of holes in it. There seems to be just enough light coming throw
the holes in the ceiling to let you see. You are standing in a small
passage. The passage way continues south.");
set("night long", "The Basement Of An Ancient House. This walls around you
are filled with cracks and chipped paint. The cieling is falling apart and
has alot of holes in it. You are standing in a small passage. The passage
way continues south.");
set_smell("default", "The smell of rat guano fills your nostrils");
set_listen("default", "The sound of rats fills the room"); 
set_listen("default", "The sound of rats fills the room. There is a sound
of pick axes coming from the west.");
}
void reset() {
::reset();
if(!present("rat"))
new(MON+"smallratchild_spear.c")->move(this_object());
new(MON+"smallratchild_spear.c")->move(this_object());
new(MON+"smallratchild_spear.c")->move(this_object());
new(MON+"smallratchild_spear.c")->move(this_object());
}
