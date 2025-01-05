#include <std.h>
#include <shao.h>

inherit "std/vault";

void create() {
    ::create();
    set_author("hood");
    set_property("light",2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "1st Street");
    set("day long", "The hot sun warms the cracked and dry "
      "cobble stone street.  To the east and west you see large stone "
"bunkers sunken into the massive stone wall. "
"The bars on the windows and the angle at wich the "
"windows and doors are positioned lead you to "
"believe that the bunkers are probably "
"guard posts...\n"
"Some buildings are visable to the north.\n");
    set("night long", "%^BOLD%^The poorly lit street seems deserted.\n"
      "To the east and west large stone stairs lead up into the "
      "darkness.  The dark forbidding city continues to the north.\n");
add_exit("1street","north");
add_exit("Sgate1","west");
add_exit("Sgate2","east");
    add_item("iron gate", "A large sturdy iron gate.");
set_door("iron gate", "1street", "north", "city key");
    set_open("iron gate", 0);
    set_locked("iron gate", 1);
    set_lock_level("iron gate", 2);

}
