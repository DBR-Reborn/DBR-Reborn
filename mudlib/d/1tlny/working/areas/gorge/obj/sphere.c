// sphere for opening door on dp1.c//

#include <std.h>
inherit OBJECT;

void create() {
     ::create();
     set_name("fire sphere");
     set("id",({"fire sphere", "sphere"}));
     set("short", "a %^RED%^fire%^RESET%^ sphere");
     set("long", "This sphere is about 7 inches in diameter and glows brightly from within.  A closer look shows a ever-burning flame in the center of the sphere.  The sphere is warm to the touch amazingly.\n");
     set_weight(50);
     set_value(0);
     set_property("no save",1);
}
