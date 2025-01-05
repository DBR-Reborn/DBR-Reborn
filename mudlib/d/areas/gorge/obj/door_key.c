
//      key for door on first floor of demon gorge

#include <std.h>
inherit OBJECT;

void create() {
     ::create();
     set_name("key");
     set("id",({"door key","key","keys"}));
     set("short","A door key");
     set("long","This is the key to the stone door");
     set_weight(50);
     set_value(0);
     set_property("no save",1);
}
