//      Wizard:  Khojem
//      Main Gallery
//      gallery.c

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	
if (!present("goblin")) {
	  new("/d/1tlny/complete/ancient_boss_room/s2/m2")->move(this_object());
	}

}

void create() {
    ::create();
    set_property("light", -1);
    set_property("indoors", 1);
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set("short", "Special Secret Room2");
    set("long", "Special Secret Room2");
    add_exit("/d/1tlny/complete/ancient_boss_room/s2/s1","south");    

}
