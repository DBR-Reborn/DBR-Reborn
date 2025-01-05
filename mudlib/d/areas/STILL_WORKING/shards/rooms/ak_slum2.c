#include "../shards.h"
inherit "std/room";

void reset() {
        ::reset();
        if(!present("demon"))
  new(MON+"demon")->move(this_object());
        }

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"ak_slum1", "north");
    set("short","Deep into dispair");
    set("long","As you proceed deeper into the slums, you are amazed at how badly the place has held up. Stone walls normally last a few hundred years. You would be surprised if these made it for ten. You walk carefully to avoid tripping over loose rubble. In the center of the street is a manhole.");
  set_items( ([
    "walls" : "Now they're stone _piles_.",
    "manhole" : "The thick iron manhole is in the center of the slum.",
	"people":"What people?"
  ]) );
  set_search("manhole","You notice several scratches along the edge. "
      "Something must have tried to move it.");
}

void init() {
	::init();
	add_action("open","open");
}

int open(string str) {
	if(str != "manhole") {
	notify_fail("Open what?\n");
	return 0;
}
write("It is welded shut!");
return 1
;
}
