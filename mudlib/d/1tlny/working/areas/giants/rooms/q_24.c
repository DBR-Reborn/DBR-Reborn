#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set( "short", "The huge quarry." );
    set( "day long", @EndText
Standing in a corner you feel very small as the
southern and western walls tower up around you.
The eastern wall can be seen in the distance,
marking out the end of this quarry.
EndText
);
    set( "night long", @EndText
You are walking around under the dim light of the
stars. It is very quiet and peaceful here, not at
all like this place is during the day.
EndText
);
    set_exits( ({ ROOMS_PATH+"q_23", ROOMS_PATH+"q_34" }), ({ "north",
"east" }) );
}

void reset()
{
    int i;
    ::reset();
    if(!query_night())
    {
// puts out 1 slave-driver and 1-3 slaves in room if none are there
      if(!present("slave"))    
      {
        for(i = 1 + random(2); i >= 0; i--)
        {
          new(MOBS_PATH+"slave.c")->move(TO);
        }
      }
      if(!present("slave-driver"))
      {
        new(MOBS_PATH+"slave-driver.c")->move(TO);
      }
    }
}
