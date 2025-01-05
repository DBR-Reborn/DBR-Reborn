#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Southwest corner of the quarry.");
    set( "day long", @EndText
You have reached the southwest corner of the quarry.
The southern wall is not as flat as the others you have
see around here, this must be because they are currently
working on breaking rocks off this wall. Dust fills the
air.
EndText
);
    set( "night long", @EndText
You have reached the southwest corner of the quarry. The
southern wall towers over you, making you feel very small.
Shadows dance across the walls from the light provided
by the stars and a few lanterns being firmly attached to
the wall high up.
EndText
);
    set_exits( ({ ROOMS_PATH+"q_04" }), ({ "north" }) );
}

void reset()
{
    int i;
    ::reset();
    if(!query_night())
    {
// puts out 1 slave-driver and 1-4 slaves in room if none are there
      if(!present("slave"))    
      {
        for(i = 1 + random(3); i >= 0; i--)
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
