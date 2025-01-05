//       lvl2 of Demon Gorge by Sinclair//

inherit ROOM;
#include <std.h>
#include <def.h>

void create() {
     ::create();
     set_property("light",1);
     set_property("indoors",1);
     set("short", "Demon mining room");
     set("long", "You realize as soon as you enter this room what the oil smell was coming from.  Sitting in the center of the room is a huge drilling machine of some type.  There are several Demons working on drilling a passageway to the east.  The immediately notice you come in and are not happy about it. \n");
set_smell("default", "You are overcome by the smell of fuel.\n");  
     set_listen("default", "The sound of the drilling maching is deafining.\n");
     add_item("machine", "The machine consists of one seat and several levers with a diamond tipped cutter in the front of it.\n");
     add_exit("tun2", "south");
}
