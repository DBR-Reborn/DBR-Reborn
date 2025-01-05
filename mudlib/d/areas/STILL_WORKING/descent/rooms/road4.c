//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set("short", "On the road of the Gnomish Settlement - Merchant District.");
    set("long", "All around you are Gnomish merchants, hawking their wares at you. You shrug them off long enough to get into the clear. From your new, unobscured vantage point, you see two buildings to the east and west. The road continues north, out of here, and south, where there appears a residential district is present.");
    add_exit(ROOMS+"road5", "south");
    add_exit(ROOMS+"forge", "west");
    add_exit(ROOMS+"shop", "east");
    add_exit(ROOMS+"road3", "north");
        if(!present("gnome")){
  new(MON+"gnome")->move(this_object());
  new(MON+"gnome")->move(this_object());
}
}
