#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "South end of Market Street.");
	set("long", "This is the south end of Market Street, many of the buildings are somewhat warped and distorted by the powers of chaos.  The buildings here burn with an unearthly blue-green flame.  This area seems quite psychadelic.");
	set_smell("default", "It smells strange here, almost invigorating.");
	set_property("light", 3);
	set_listen("default", "Sounds of manicaly laughter and sorrow are heard here.");
	set_property("indoors", 2);
	set_exits( ({
	"road18.c",
	"road20.c"}),
	({"north", "south"}));
}
void reset() {
	::reset();
	if(!present("warrior")) {
	new(MON+"twarrior.c")->move(this_object());
	new(MON+"twarrior.c")->move(this_object());
	new(MON+"twarrior.c")->move(this_object());
    }
}
