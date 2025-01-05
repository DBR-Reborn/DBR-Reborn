#include <std.h>
#include "../chaos.h"


inherit ROOM;

void create() {
	::create();
	set("short", "An information center.");
	set("long", "This used to be a beautiful information center, but now it is burnt and charred.  The beautiful attendant is still standing here, trying to salvage whatever she has left to sell.  The booth is decorated with many gifts and souvenirs.");
	set_property("indoors", 2);
	set_property("light", 3);
	set_exits( ({
	"road7.c",
}),
	({"east"}));
	set_smell("default", "The air is permeated by soot and the smell of charcoal.");
}
void reset(){
::reset();
if(!present("shaia")) {
	new(MON+"shaia.c")->move(this_object());
    }
}
