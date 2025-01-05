#include <std.h>

inherit ROOM;

void reset() {
	::reset();
	
if (!present("newbie")) {
	  new("/d/newbieville/mon/newbie.c")->move(this_object());
	}

}

void create() {
    ::create();
    set_property("light", -1);
    set_property("indoors", 1);
    set_property("no scry", 1);
    set_property("no teleport", 1);
    set_property("no summon", 1);
    set("short", "Special Secret newbie room");
    set("long", "Special Secret newbie room in this room you should type %^YELLOW%^'kill newbie'%^RESET%^ after he dies you should do %^YELLOW%^'look corpse'%^RESET%^ and then %^YELLOW%^'get all from corpse'%^RESET%^");
    add_exit("/d/newbieville/rooms/townsquare","up");    

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
