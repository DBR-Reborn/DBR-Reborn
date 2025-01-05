#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Marketplace." );
    set( "day long", @EndText
As you enter the village, you feel very small when staring
at the HUGE stone walls towering around you. In the middle
of the entrance, the Storm-Giants have placed a guardpost to 
protect themselves from the dangers that lurk outside. To 
the east, a small road leading into the village can be seen.
EndText
); 
    set( "night long", @EndText
As you enter the village, you feel very small when staring
at the HUGE stone walls towering around you. In the middle
of the entrance, the Storm-Giants have placed a guardpost to 
protect themselves from the dangers that lurk outside. To 
the east, a small road, leading into the village can be seen.
EndText
); 
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("wall","The wall towers 30 feet above you.");
    add_item("ground","The ground is covered with huge stone bricks.");
    add_item("guardpost","This guardpost is always manned. Unless something extraordinary has occured.");
    add_item("post","This guardpost is always manned. Unless something extraordinary has occured.");
    set_smell("default", "Dust from the walls fills your lungs, making it hard to breathe.");set_exits( ({ ROOMS_PATH+"worldmapwhereever", ROOMS_PATH+"road" }),
({ "out", "east" }) );
}
