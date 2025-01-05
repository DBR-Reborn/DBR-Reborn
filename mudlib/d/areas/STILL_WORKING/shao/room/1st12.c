#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Intersection of 1st Street $ Northern Row");
set("night long","%^RESET%^The oil lanterns lining "
"the street "
"are shadowed by the massive\n"
"%^BOLD%^%^YELLOW%^Flaming Cross "
"%^RESET%^of the Shao-tan church that stands to the "
      "north.  Northern Row leads off to the east and west from "
      "here, and 1st Street heads south to the busness district.  "
      "\n"
"\n"
"The %^BOLD%^%^YELLOW%^glow %^RESET%^from the church "
"cross "
      "flows across the entire street here...\n");
set("day long","%^RESET%^%^ORANGE%^You stand "
"at the intersection of "
"Northern Row, that runs east and west, and 1st Street "
"that heads south.  "
"The infamous Shao-tan church is directly north, to the east "
"and west appear to be some buildings on either sides "
"of Northern Row.\n");
add_exit("nr5", "west");
add_exit("nr6", "east");
add_exit("1st11", "south");
add_exit("church", "north");

}
