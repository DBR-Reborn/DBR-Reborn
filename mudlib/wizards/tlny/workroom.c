#include "/adm/include/std.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no scry", 1);

    set("short", "The workroom of a new immortal");
set( "day long", @EndText
It is %^YELLOW%^DAY%^RESET%^ outside.

main    [takes you to main workroom]

hall    [area for posts and boards for wizards and players]
square  [takes you to DBR church}
portal  [Daybreak TS takes you to all current working areas]

NO SAVE
EndText);

set( "night long", @EndText
It is %^BOLD%^BLUE%^NIGHT%^RESET%^ outside.

main    [takes you to main workroom]

hall    [area for posts and boards for wizards and players]
square  [takes you to DBR church}
portal  [Daybreak TS takes you to all current working areas]

NO SAVE
EndText);

    set_exits( ({ "/d/standard/square", "/d/standard/adv_main", "/d/daybreak/room/N1" }),
      ({ "square", "hall", "portal" }) );

    add_exit("/std/obj/workroom.c", "main");
    add_exit("/wizards/tlny/workroom1.c", "north");
    add_exit("/wizards/tlny/workroom2.c", "south");
    add_exit("/wizards/tlny/workroom3.c", "east");

    add_exit("/d/newbieville/rooms/newbie4", "guilds");
}
