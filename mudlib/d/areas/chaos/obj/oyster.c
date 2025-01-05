#include <std.h>

inherit "/std/food";

void create() {
	::create();
	set_name("oyster");
	set_id( ({"oyster", "food"}));
	set_short("Luscious oyster");
	set_long("A piece of a large oyster, cut and trimmed to serve.  Some consider this an aphrodesiac.");
	set_weight(2);
	set_strength(40);
	set_float_value(0.30);
	set_value(3);
	return;
}
