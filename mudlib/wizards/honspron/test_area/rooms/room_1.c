#include <std.h>
#include "../test_area.h"

inherit ROOM;

void create() {
	::create();
	set_short("Honspron's Area");
	set_long("This is a test");
	set_property("light", 3);
	set_property("indoors", 2);
	set_smell("default", "Stinky Farts.");
	set_listen("default", "You hear ... gas?.");
	set_exits( ({
	"room_2.c",
	"room_3.c"}),
	({"east", "west"}));
}
void reset() {
	::reset();
	if(!present("pet 1")) {
		/*switch(random(3)){
			case 0:new(MON+"mon_1.c")->move(this_object());
			new(MON+"mon_1.c")->move(this_object());
			new(MON+"mon_1.c")->move(this_object());
			new(MON+"mon_1.c")->move(this_object());break;
			case 1:new(MON+"mon_1.c")->move(this_object());
			new(MON+"mon_1.c")->move(this_object());
			new(MON+"mon_1.c")->move(this_object());
			new(MON+"mon_1.c")->move(this_object());
			new(MON+"mon_1.c")->move(this_object());
			new(MON+"mon_1.c")->move(this_object());
			new(MON+"mon_1.c")->move(this_object());
			new(MON+"mon_1.c")->move(this_object());break;
			case 2:break;
		}*/
		new(MON+"mon_1.c")->move(this_object());
    }
}
