
#include <std.h>
inherit "/std/vault";

void create() {
     ::create();
     set_property("indoors", 1);
     set_property("light", 1);
     set("short", "Stairway leading down");
     set("long", "This stairway will someday lead you deeper into the gorge.. But now it is under repair.\n");
     add_exit("dm6", "south");
     set_door("door", "dm6", "south", "door key");
     set_string("door", "open", "The stone door slides open easily.\n");
     set_lock_level("door",99);
     set_post_exit_functions( ({"south", "down"}),({"lock_door", "lock_door"}) );
     set_open("door",0);
     set_locked("door",1);

}
int lock_door() {
     set_open("door",0);
     set_locked("door",1);
     return 1;
}
