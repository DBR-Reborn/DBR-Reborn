#include <std.h>

inherit "/std/food";

void create() {
	::create();
	set_name("fish");
	set_id( ({"fish"}));
	set_short("Rotten fish");
	set_long("A decaying piece of rotten fish, with all the trimmings, worms, flies, maggots, and ants.");
	set_weight(5);
	set_strength(30);
	set_float_value(0.70);
	return;
}
