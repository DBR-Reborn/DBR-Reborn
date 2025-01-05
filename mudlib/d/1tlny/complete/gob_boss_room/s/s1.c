//      Wizard:  Khojem
//      Main Gallery
//      gallery.c

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	
if (!present("guard")) {
	  new("/d/1tlny/complete/gob_boss_room/s/m1.c")->move(this_object());
	}

}

void create() {
    ::create();
    set_property("light", -1);
    set_property("indoors", 1);
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set("short", "Special Secret Room");
    set("long", "This is a muggy room with skulls of all creaturs scattered along the floor. The guard in this room seems unpleasant and seems hungry for new prey. This guard is not like ones you have seen before. To the north seems to be a stronger Goblin yet it awaits to be seen.\n   0\n   |\n   @   \n   | \n   0\n");
    add_exit("/d/areas/goblin/areas/idolroom","south");    
    add_exit("/d/1tlny/complete/gob_boss_room/s/s2.c","north");

}
