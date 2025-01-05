#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "A small road." );
    set( "day long", @EndText
This is the end of the road between the village and the entrance.
Directly north of you lies a huge marketplace crowded with citizens.
Some of the usual city noises can be heard but it's surprisingly
quiet for a marketplace of this size. To the south a road, surrounded
by enormous walls, leads out of the village.
EndText
);
    set( "night long", @EndText 
This is the end of the road between the village and the entrance.
Directly north of you lies a huge marketplace that seems empty at this 
hour. To the south a road, surrounded by enormous walls, leads out of 
the village.
EndText
); 
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    add_item("road","This road is covered with huge stonebricks.");
    add_item("marketplace","Truely an amazing sight, the ground of the marketplace is made of gigantic stonebricks. Walls towers in all directions surrounding the 
area and in the middle of all a fountain can be seen.");
    add_item("fountain","Shaped of solid rock you realize that the craftsmanship of this fountain is astonishing.");
    set_exits( ({ ROOMS_PATH+"road5", ROOMS_PATH+"road7" }), ({ "south",
"north" }) );
}
