#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set_short("The burning city of Kislev");
	set_long("
	This was once the magnificent city of Kislev, now being attacked by the maurauding warriors of Chaos.  Dead bodies are seated everywhere with wounds so viscous that they make your skin crawl and shudder at the sight of it.  The walls are blackened by constant siege and war, while chaotic daemons rampage throughout the city.
");
	set_property("indoors", 2);
	set_property("light", 3);
	set_exits( ({
	"plains3.c",
	"xroads.c"}),
	({"south", "north"}));
}
void reset() {
	::reset();
	if(!present("body")) {
new(OBJ+"body")->move(this_object());
new(OBJ+"body")->move(this_object());
    }
}
