#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Northern Row");
set("night long","%^RESET%^The massive "
"%^BOLD%^%^YELLOW%^flamming cross "
"%^RESET%^of the church to the east "
"bathes the street with a soft dim yellow light.  "
"A large stone wall of a bulding is to the south, and "
"Northern Row continues to the east and west.\n");
set("day long","%^RESET%^%^ORANGE%^Dry cobble stones "
"feel warm benieth your feet, "
"well worn by the citizens of Shao-tan.  "
"The majority of citizens on this street appear to be "
"well dressed senate types and men of the cloth, although"
" the odd lawman is seen walking his beaten path.\n"
"\n"
"Northern Row continues west towards city hall and east "
"towards the church.  Holy Row begins to the north.");
add_exit("nr4", "west");
add_exit("1st12", "east");
add_exit("hr9", "north");

}
