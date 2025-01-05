#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "The north end of Livingstone");
	set("long", "This is the north end of Livingstone street, there is something aluring about this part of the street, something you can't quite put your hand on.  The buildings here smell burnt but with a scent of perfume.  Strange music is heard to the north of here.");
	set_property("indoors", 2);
	set_property("light", 3);
	set_smell("default", "It smells like burnt perfume here.");
	set_listen("default", "Sounds of aluring music is heard here.");
	set_exits( ({
	"road9.c",
	//"house3.c",
	"road7.c"}),
	({"north", 
//"east", 
"south"}));
}
void reset() {
	::reset();
	if(!present("beastman")) {
	new(MON+"beastman.c")->move(this_object());
	new(MON+"swarrior.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
    }
}
