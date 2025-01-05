#include "../shards.h"
inherit "std/room";

void init() {
  ::init();
  if((string)this_player()->query_true_name() == "guest") {
    add_action("block_exit", "leave");
  }
}

int block_exit(string str) {
  write("Guests are not allowed to exit the city.");
  return 1;
}
void create() {
   ::create();
     set_property("light",3);
     set_property("night light", 2);
     add_exit(ROOMS+"ak_ngate", "south");
     add_exit("/d/damned/virtual/room_7_4.world","leave");
     set("short","Outside the northern gate of the town");
     set("long","You are standing just outside of the town. To your south is the gate back into the destroyed city. You can also leave by entering the shimmering magic portal next to you.");

}
