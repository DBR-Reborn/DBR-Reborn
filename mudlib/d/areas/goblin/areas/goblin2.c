#include <std.h>
#include "../goblin.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 3);
	set_property("clean", 1);
	set("short", "A hut built in a cave");
	set("long", "The hut on the west side is a large hut made crudely out of wood and rocks, mushrooms litter the room from start to end.  Some furniture lay idly around the room.  There are some goblins here doing odd things, practicing, eating, drinking and the like.\n   0\n   | \n   @--0\n     \n    \n");
set_exits( ({(ROOMS+"goblin4"), (ROOMS+"settlement")}), ({"north", "east"}));
}

void reset() {
	::reset();
	if(!present("goblin")) {
new(MON+"goblin_spear.c")->move(this_object());
new(MON+"goblin_spear.c")->move(this_object());
new(MON+"goblin_spear.c")->move(this_object());
new(MON+"goblin_spear.c")->move(this_object());
new(MON+"goblin_spear.c")->move(this_object());
new(MON+"goblin_spear.c")->move(this_object());
new(MON+"goblin_spear.c")->move(this_object());
new(MON+"goblin_spear.c")->move(this_object());
new(MON+"goblin_spear.c")->move(this_object());
new(MON+"goblin_spear.c")->move(this_object());
new(MON+"goblin_spear.c")->move(this_object());
new(MON+"goblin.c")->move(this_object());
new(MON+"goblin.c")->move(this_object());
new(MON+"goblin.c")->move(this_object());
new(MON+"goblin.c")->move(this_object());
new(MON+"goblin.c")->move(this_object());
new(MON+"goblin.c")->move(this_object());
new(MON+"goblin.c")->move(this_object());
new(MON+"goblin.c")->move(this_object());
new(MON+"goblin.c")->move(this_object());
new(MON+"goblin.c")->move(this_object());
new(MON+"goblin.c")->move(this_object());
}
}

void init() {
  ::init();
  call_out("reset",10,!present("goblin"));
  return;
}

