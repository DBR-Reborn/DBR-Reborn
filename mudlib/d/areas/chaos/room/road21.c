#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set_short("Along West Road.");
	set_long("You are standing along west road, the buildings here are burning with an unearthly flame from the depths of chaos.  The buildings and roads are changed with magicks and perversion.  Strange creatures scurry along the ground running away from everything they see.");
	set_property("indoors", 2);
	set_property("light", 3);
	set_exits( ({
	"road22.c",
	"road20.c"}),
	({"east", "west"}));
}
void reset(){
	::reset();
	if(!present("warrior")) {
	new(MON+"twarrior.c")->move(this_object());
	new(MON+"twarrior.c")->move(this_object());
	new(MON+"twarrior.c")->move(this_object());
	new(MON+"twarrior.c")->move(this_object());
	new(MON+"twarrior.c")->move(this_object());
    }
}
