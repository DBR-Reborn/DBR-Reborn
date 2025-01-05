//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set("short", "The Cave.");
    set("long", "This little cave was used at one point by some poor soul trying to defend himself from the giant rats inhabiting this tunnel. He lost the fight, and his (or her, you can't tell) destroyed skeleton lies in shards on the ground. Bits of flesh lie about, and pieces of cloth are abundant. Not a pleasant way to go.");
set_items( (["skeleton" : "Judging from all the broken pieces, the rats must have had a good time after his death. It's a gnome-size skeleton, unsuprisingly.",
"flesh" : "It's pretty gross.",
"cloth" : "Standard clothing. The moron wasn't even wearing armour." ]) );
    add_exit(ROOMS+"lair4", "east");
        if(!present("rat"))
  new(MON+"giant_rat.c")->move(this_object());
}
