//      Wizard:  Khojem
//      Main Gallery
//      gallery.c

#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	
if (!present("dragon")) {
	  new("/d/1tlny/complete/gob_boss_room/s.1/m2")->move(this_object());
	}

}

void create() {
    ::create();
    set_property("light", -1);
    set_property("indoors", 1);
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set("short", "   \n   \n   @   \n   | \n   0\nSpecial Secret Room2");
    set("long", "Special Secret Room2\n   \n   \n   @   \n   | \n   0\n");
    add_exit("/d/1tlny/complete/gob_boss_room/s.1/s1","south");    

/*    
set_items(([
     ({ "ceiling","beams" }) :
        "Large, beams carved from the trunks of trees in the surrounding forest "+
        "support the large, vaulted ceiling and roof.",
     ({ "gallery" }) :
        "The gallery is void of any furnishings.  A few paintings adorn the walls.",
     ({ "paintings", "painting" }) :
        "Several cheap oil paintings of the king as a proud, young man decorate "+
        "the walls.  Hmm.. the king has a lousy taste for art."
     ]));
    set_smell("default", "The gallery smells of perfumed waters and herbs.");
    set_listen("default", "You hear people murmuring in the distance.");
*/
}
