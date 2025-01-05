#include <std.h>

inherit "/std/food";

void create() {
	::create();
	set_name("prunes");
	set_id( ({"prunes"}));
	set_short("juicy prunes");
	set_long("A few pieces of juicy prunes.");
	set_weight(5);
	set_strength(100);
	set_float_value(0.10);
	set_value(2);
	return;
}
