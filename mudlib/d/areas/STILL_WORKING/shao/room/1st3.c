#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Intersection of 1st & Commoners Row");
set("night long","%^RESET%^The oil lanterns lining the street "
      "flicker, and "
      "sputter making nearbye shadows appear to move and dance.  "
      "The homes of citizens stand on the four corners of this intersection, "
"most of them are boarded up and abandoned, but you notice a dim "
"light in the house on the northwest corner.\n"
"\n"
      "Commoners Row runs east and west while 1st Street continues north "
      "and south.\n");
set("day long", "%^RESET%^%^ORANGE%^You stand "
"at the intersection of "
      "1st Street, that runs north and south, and Commoners Row wich runs "
      "east and west.  The homes of citizens stand on the four "
      "corners of this intersection and also line "
      "both sides of commoners row in both directions.  You see smoke "
      "rising from the chiminy of the "
      " house at the very east end of the street.\n");
    add_exit("com4","west");
    add_exit("com6","east");
    add_exit("1st2","south");
    add_exit("1st4","north");

}
