#include <std.h>

inherit ROOM;

void create() {
    string troom;
    int x = random(100);
    int y = random(100);

    troom = "/d/damned/virtual/room_"+x+"_"+y+".world";

    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "dark etherial vortex");
    set("long", "This swirling vortex of darkness " +
      "exists nowhere that you have ever seen before.  "+
      "You seem unfit for this vortex, and are falling "+
      "fast.");
    set_listen("default", "You hear the tormented wails of souls here.");
    set_exits( ([ "light" : troom ]) );
}

void reset() {
    ::reset();
    seteuid(getuid());
    if (!present("fallen-angel")) {
	new("/std/glen/mon/skeletal_demon")->move(this_object());
    }
}

