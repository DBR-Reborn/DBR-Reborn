#include <std.h>
#include "athens.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "%^RED%^In front of the Beorhtnoth Inn%^RESET%^" );
    set( "day long", @EndText
    You stand in front of the fabled %^BLUE%^YELLOW%^Beorhtnoth Inn%^RESET%^
where many a mighty quest has begun. Many elves
and other travelers are walking into and out of the
doors to the inn, and a sign hangs out from the roof.
Several young hobbit boys stand around staring at
the motly assortment of races.
EndText
);
    set_smell("default", "Food and alcohol waft through the air.");
    set_listen("default", "Hearty laughter and music come from the inn.");
    set_exits( ({ PATH+"downtown7.c", PATH+"downtown1.c", "beoinn.c" }), ({ "north", "east", "southwest" }) );
}
