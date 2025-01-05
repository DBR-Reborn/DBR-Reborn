#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Fountain." );
    set( "day long", @EndText
This is the middle of the huge marketplace. In the center stands
a marvellous stone fountain with strange marks and carvings. As 
you look around, you see walls in the distance, surrounding the 
marketplace. This place sure makes you feel small. This part of
the marketplace is bustling with activity. An endless stream of
citizens come here filling enormous water buckets from the fountain.

(A fountain etc will be placed here once Deorwin learns how to do it) ;) 
EndText
); 


    set( "night long", @EndText
This is the middle of the huge marketplace. In the center stands
a marvellous stone fountain with strange marks and carvings. As 
you look around, you see walls in the distance, surrounding the 
marketplace. This place sure makes you feel small.  

(A fountain etc will be placed here once Deorwin learns how to do it) ;)
EndText
); 
    add_item("walls","These walls towers no less then 30 feet above you.");
    add_item("ground","The ground is covered with huge stone bricks.");
    add_item("marketplace","Truly an amazing sight, the ground of the
marketplace is made of gigantic stone bricks. Walls tower in all directions,
surrounding the area and in the middle of all, a fountain can be seen.");
    add_item("fountain","Shaped of solid rock, you realize that the
craftsmanship of this fountain is astonishing.");
    add_item("marks","Someone seems to have made them with their bare
hands.");
    add_item("carvings","You can tell these carvings have been made by a
very skilled sculptor.");
        set_exits( ({ ROOMS_PATH+"market14", ROOMS_PATH+"market12",
ROOMS_PATH+"market8", ROOMS_PATH+"market18" }), ({ "east", "west", "south",
"north" }) );     
}
