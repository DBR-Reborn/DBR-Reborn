#include <std.h>
#include "../chaos.h"

inherit ROOM;
int i;

void create() {
	::create();
	set_short("The east road");
	set_long("This is the east road, there isn't much left to see here except the burning buildings, of which the barber shop and the local bath are totally decimated beyond recognition.");
	set_property("light", 3);
	set_property("indoors", 2);
	set_smell("default", "It smells like burnt skin and hair.");
	set_listen("default", "You hear screaming and fighting off to the east.");
	set_exits( ({
	"road4.c",
	"xroads.c"}),
	({"east", "west"}));
}
void reset() {
    ::reset();
    if(!present("beastman"))
    {
	i = random(2)+1;
	while(i--)
	{
	new(MON+"beastman.c")->move(this_object());
	new(MON+"beastman.c")->move(this_object());
	new(MON+"peasant.c")->move(this_object());
	}
  }
}
