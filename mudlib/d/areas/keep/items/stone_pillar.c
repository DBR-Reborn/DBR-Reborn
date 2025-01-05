#include <std.h>

/* This is one of the four stone pillars present near the corners of the paladin temple room. It cannot be picked up, and is used solely for room decoration. */

inherit OBJECT;

void create() {
::create();
set_name("pillar");
set("id", ({ "pillar", "stone pillar", "large pillar", "large stone pillar" }));
set_short("A large stone pillar");
set_long("This is a very big pillar fashioned completely of bright white stone. It touches both the floor and ceiling and is positioned equidistant from the corner of the room and the circle containing the paladin insignia in the center.");
set_weight(10000000);
set_value(0);
}
