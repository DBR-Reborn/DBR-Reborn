#include <std.h>

inherit "/std/food";

int body;
void create() {
string body;
	::create();
	set_name("corpse");
	set_id( ({"corpse", "body"}));

	switch(random(5)){
	case 0:body= "decapitated corpse";
	case 1:body="vicously scarred body";
	case 2:body="horribly burnt corpse";
	case 3:body="limbless corpse";
	case 4:body="bent and twisted corpse";
}
	set_short(body);
	set_long("A body found amonst the wreckage and carnage cause by Chaos in the northern city of Kislev.");
	set_weight(20);
	set_strength(30);
	set_float_value(0.70);
	return;
}
