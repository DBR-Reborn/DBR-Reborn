#include <std.h>
#include <shao.h>

inherit VAULT;
void init(){
    ::init();
    add_action("kick_wall", "kick");
}

void create() {
    ::create();
    set_property("light", 2);
    set("short", "back room");
set("long",
"For the back room of a shop this room is very strange.\n"
"The floors are pure black marble, and the walls are "
"made from mithril. The furnature isn't what you'd expect."
"You see an odd looking 'rack' as well as a large bed "
"on one side of the room, on the east side you see a "
"large oak cabinet.  hanging from the walls and cieling "
"you see numerious chains and leather collars, and shackles.\n"
"An iron door is on the south wall...");
set_items( ([
({"door","doors"}):
"There is a north door, a south door and a northeast door.",
({"north door","northeast door"}):
"The heavy iron door looks very, very sturdy.",
({"south door"}):
"The heavy wood door doesn't appeer to have a visible lock.",
({"medium building","stone building","medium stone building"}):
"They both look very sturdy, a heavy iron door is "
"on the one to the north.\n"
]) );
add_exit(PATH+"al2","south");
add_exit(PATH+"leather_shop","north");
add_invis_exit("south");
set_door("iron door",PATH+"al2","south","master key");
set_open("iron door",0);
set_locked("iron door",1);

set_smell("default","The smell of well oiled leather lingers"
" in the air.\n");
}
