#include <std.h>
#include "../a1.h"

inherit ROOM;

void reset() {
        ::reset();
if (!present("worker")) 
new(MON+"worker.c")->move(this_object());
new(MON+"worker.c")->move(this_object());
}

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set( "short", "tunnel" );
    set( "day long", @EndText
    Even though the sun shines bright outside as you venture deeper into the tunnels the light grows darker you hear dwarven workers busily hauling minerals through out the area
    0   
    |   
    @
    |
    0
EndText
);
    set( "night long", @EndText
   Night time make this room even darker then you can imagine you hear dwarven workers busily hauling minerals through out the area
    0   
    |   
    @
    |
    0
EndText
);
set_exits( ({ 
PATH+"r6.c", 
PATH+"r4.c" 
//PATH+"r5.c"
//PATH+"r6.c" 
}), ({ 
"north", 
"south" 
//"east", 
//"west" 
}) );
}

