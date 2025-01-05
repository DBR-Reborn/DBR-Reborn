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
"%^BOLD%^%^YELLOW%^flaming "
"cross %^RESET%^of the church to the west "
"bathes the street with a soft dim yellow light.  "
"A large stone wall of a bulding is to the south, and "
"Northern Row continues to the east and west.\n");
set("day long","%^RESET%^%^ORANGE%^Dry "
"cobble stones feel warm benieth your feet, "
"well worn by the citizens of Shao-tan.  "
"The majority of citizens on this street appear to be "
"messageners and men of the cloth, although"
" the odd lawman is seen walking his beaten path.\n"
"\n"
"Northern Row continues east towards the cemetary and west "
"towards the church.  Church street begins to the north.");
add_exit("1st12", "west");
add_exit("nr7", "east");
add_exit("ch1", "north");

}
