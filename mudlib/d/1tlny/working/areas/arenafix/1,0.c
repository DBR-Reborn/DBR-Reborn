/*  /d/damned/arena/1,0.c
 *  Made for DarkeMUD
 *  Created by Geldron 031296
 *  Copyright (c) 1996, DarkeMUD
 *  Do not remove this header
 */

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    replace_program(ROOM);
    set_property("light", 2);
    set_property("night light", 1);
    set_short("South Block of Arena");
    set_long("This is the south block of the Arena, close to the "
      "exit.  The arena extends north, east, and west.");
    set_smell("default", "Blood and carcasses are scattered everywhere, "
      "filling up the arena with a nasty smell.");
    set_exits( ([
      "north" : "/d/damned/arena/1,1",
      "east" : "/d/damned/arena/2,0",
      "west" : "/d/damned/arena/0,0",
      "south" : "/d/damned/arena/booths_room",
    ]) );
}
