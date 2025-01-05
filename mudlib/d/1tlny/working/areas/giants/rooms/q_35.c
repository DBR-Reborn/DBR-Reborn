#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Eastern parts of the quarry." );
    set( "day long", @EndText
You are in a wide passageway between huge walls. To
the south you see the definite end of the quarry. All
around you there are people working and yelling.
EndText
);
    set( "night long", @EndText
You are in a wide passageway between the eastern and
western walls. This place is very quiet and peaceful
at night and none of the alarms of the daily work can
be heard. The only thing you hear are the noise of an
occasional cricket.
EndText
);
    set_exits( ({ ROOMS_PATH+"q_34", ROOMS_PATH+"q_36" }), ({ "north",
"south" }) );
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
