#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set( "short", "Northern end of the quarry." );
    set( "day long", @EndText
You are at the most northern point of the quarry.
Work here has stopped and the northern wall is
perfectly flat and towering almost 100 feet towards
the sky. You can see that it is slightly more grey
in colour than the other almost perfectly white walls.
The rock type must be getting slightly different from
here on, maybe that is why they quit expanding in this
direction. The quarry is wide open to the south, with
workers everywhere.
EndText
);
    set( "night long", @EndText
You are standing  at the dark northern end of the
quarry. The slightly brighter open parts of the quarry
is south of here.
EndText
);
    set_exits( ({ ROOMS_PATH+"q_11" }), ({ "south" }) );
}

void reset()
{
    int i;
    ::reset();
    if(!query_night())
    {
// puts out 1 slave-driver and 1-2 slaves in room if none are there
      if(!present("slave"))    
      {
        for(i = 1 + random(1); i >= 0; i--)
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
