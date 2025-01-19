#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "East Rockfish road and Ice Port pier.");
	set("long", "East Rockfish road and Ice Port pier.  To the north is Ice Port pier, usually a bustling busy port except during the incursions of Chaos.  The ports to the north stretch out as far as you can see.");
	set_smell("default", "It smells like burnt fish and perfume here, almost enough to make you heave.");
	set_property("light", 3);
	set_listen("default", "You can't hear the seaguls that are usually associated with ports.");
	set_property("indoors", 2);
	set_exits( ({
	//"portroad.c",
	"road9.c",
	"road11.c"}),
	({
//"north", 
"east", "west"}));
}
void reset(){
	::reset();
	if(!present("warrior")) {
	new(MON+"swarrior.c")->move(this_object());
	new(MON+"swarrior.c")->move(this_object());
	new(MON+"swarrior.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
	new(OBJ+"body.c")->move(this_object());
    }
}
