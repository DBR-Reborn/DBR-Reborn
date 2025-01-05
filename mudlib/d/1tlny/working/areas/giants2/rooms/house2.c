#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "A Storm-Giant home." );
    set( "day long", @EndText
You have entered a Storm-Giant home. This place looks even bigger
then you imagined from the outside. The space between the walls and
the height to the roof gives the room the impression of a void and
somehow you feel some kind of depression that you can't really put
your finger on. The furniture seems to be kept at a minimum, a table
with some chairs and a few beds. Very basic. The only decoration
seems to be a painting hanging from the eastern wall.  
EndText
); 
set( "night long", @EndText
You have entered a Storm-Giant home. This place looks even bigger
then you imagined from the outside. The space between the walls and
the height to the roof gives the room the impression of a void and
somehow you feel some kind of depression that you can't really put
your finger on. The furniture seems to be kept at a minimum, a table
with some chairs and a few beds. Very basic. The only decoration
seems to be a painting hanging from the eastern wall.
EndText 
); 
 
    add_item("house","This house is HUGE.");
    add_item("bed","A very large stone bed.");
    add_item("beds","Two very large stone beds.");
    add_item("table","A large stone table with some chairs grouped around
it.");
    add_item("chairs","Some stone chairs grouped around the table.");
    add_item("walls","This house is HUGE.");
    add_item("wall","The wall towers almost 30 feet above you.");
    add_item("roof","The roof seems to be made of stone... hopefully it
won't fall in.");
    add_item("door","This enormous stone door stands open."); 
    add_item("painting","Two grim faced young men dressed for battle.");
    set_exits( ({
ROOMS_PATH+"village10" }), ({
"south" }) );
}
