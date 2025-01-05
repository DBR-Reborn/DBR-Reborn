#include <std.h>
#include "../a1.h"

inherit ROOM;

void reset() {
        ::reset();
if (!present("worker")) 
new(MON+"worker.c")->move(this_object());
//new(MON+"worker1.c")->move(this_object());
}

void create()
{
    ::create();
    set_property( "light", 2);
    set_property( "night light", 1);
    set( "short", "tunnel" );
    set( "day long", @EndText
     Daylight sips through the cracks just barely from the southern etrance. You wonder how on earth these dwarfs can work in such dark places?
    0   
    |   
 0--@--0
    |
    0
EndText
);
    set( "night long", @EndText
    The moonlight barely shows much of this entrance and you see dirt piles all around! You should be careful not to slip in the darkness
    0   
    |   
 0--@--0
    |
    0 
EndText
);
set_exits( ({ 
PATH+"r2.c", 
PATH+"a_enter.c", 
PATH+"r4.c",
PATH+"r7.c", 
}), ({ 
"north", 
"south", 
"east",
"west", 
}) );
}

