#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Western parts of the quarry.");
    set( "day long", @EndText
Being some 100 feet below normal groundlevel makes the
air somewhat damp and veils of fog are forming around
you. Everywhere you hear the slammering of the slaves
working and the shouting of orders from the slave-drivers.
EndText
);
    set( "night long", @EndText
Being some 100 feet below normal groundlevel makes the
air somewhat damp and veils of fog are forming around
you. The place is quiet and it feels very mysterious
to be underground but still under the sky filled with
stars.
EndText
);
    set_exits( ({ ROOMS_PATH+"q_03", ROOMS_PATH+"q_05" }), ({ "north",
"south" }) );
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
