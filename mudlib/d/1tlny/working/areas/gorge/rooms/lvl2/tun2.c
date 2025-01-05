//lvl2 of demon gorge by Sinclair//

inherit ROOM;
#include <std.h>
#include <def.h>

void create() {
     ::create();
     set_property("light",-4);
     set_property("indoors",1);
     set("short", "A Dark tunnel");
     set("long","You are standing in the middle of several tunnel passages. The tunnel is mostly non-descript mainly because of the lack of light to show any features.  Only the smooth walls can be faintly made out.\n");
     set_smell("default", "The scent of oil fills your nostrils");
     set_listen("default", "There is a definate scratching sound coming from the north.\n");
     add_exit("tun3", "east");
     add_exit("dp1","south");
     add_exit("tav", "west");
     add_exit("tun20", "north");
     add_exit("tun30", "northeast");
     add_exit("tun40", "northwest");
     add_exit("tun39", "southeast");
     add_exit("tun49", "southwest");
}
