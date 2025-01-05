/*  /d/damned/arena/2,2.c
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
    set_short("Northeast Block of Arena");
    set_long("This is the northeast block of the Arena.  The arena extends "
      "south and west.");
    set_smell("default", "Blood and carcasses are scattered "
      "everywhere, filling up the arena with a nasty smell.");
    set_exits( ([
      "west" : "/d/damned/arena/1,2",
      "south" : "/d/damned/arena/2,1",
    ]) );
}
