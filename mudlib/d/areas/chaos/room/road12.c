#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "Intersection of Rockfish road and Queens street.");
	set("long", "This is the intersection of Rockfish road and Queens street, to the south you can seen the magnificent palace of Kislev.  Buildings burn hard with flames jumping out everywhere.");
	set_smell("default", "The smell of cinders and burn wood invade your nostrils.");
	set_property("light", 3);
	set_listen("default", "You can hear sounds of battle to the south, towards the palace.");
	set_property("indoors", 2);
	set_exits( ({
	"road11.c",
	//"gates2.c",
	"road13.c"}),
	({"east", 
//"south", 
"west"}));
}
void reset() {
	::reset();
	if(!present("beastman")) {
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
    }
}
