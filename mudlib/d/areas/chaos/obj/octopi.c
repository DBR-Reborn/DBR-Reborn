#include <std.h>

inherit "/std/food";

void create() {
	::create();
	set_name("octopus");
	set_id( ({"octopus", "octopi", "food"}));
	set_short("Fresh octopus");
	set_long("This is some fresh octopus from the shores of Kislev.  Its nourishing innards are considered one of the rare delicacies in this world.");
	set_weight(20);
	set_strength(80);
	set_float_value(0.70);
	set_value("10");
	return;
}
