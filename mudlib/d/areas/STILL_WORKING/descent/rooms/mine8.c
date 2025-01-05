//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;

int pulled;

void create() {
    ::create();
    
    set_property("light", 0);
    set_property("indoors", 1);
    set("short", "Inside the Gnome Mines.");
    set("long", "You finally have found the source of all the evil - for before you is a demonic gate to somewhere... else. This is one of the ways the demons enter our dimension. The question is: who summoned them, and why?");
set_items( (["gate" : "No, you can't go into it. There's certainly a demonic army on the other side, waiting to rip you to shreds. And as legend says, there ain't no way to destroy a gate - you're going to kill the Demon Master who did this! You spy a small gem buried right under the portal.",
"gem" : "You bet you could pull this gem out with enough time." ]) );
    set_smell("default", "You smell death and fear in the air.");
    set_listen("default","The demon gate hums with power.");
    add_exit(ROOMS+"mine7", "south");
        if(!present("demon")) {
  new(MON+"demon.c")->move(this_object());
  new(MON+"demon.c")->move(this_object());
  new(MON+"demon_king.c")->move(this_object());
}
}
void init() {
    ::init();
    add_action("pull_func", "pull");
    pulled = 0;
}
int pull_func(string str) {
    if(!str || str != "gem") {
	notify_fail("Pull what?\n");
	return 0;
    }
    if(pulled==1) {
      write("What gem? It has already been pulled out!");
      return 0;
     }
    if(present("demon")) {
	write("You start pulling the gem out, but a demon slaps you over the head, and you stop.");
this_player()->add_hp(-50);
	return 0;
    }
    write("You pull out the gem - and everything explodes around you. Unfortunately, the demon gate remains standing.");
  call_out("damage_all", 200);
  new(OBJ+"gem")->move(this_object());
  pulled = 1;
    return 1;
}
