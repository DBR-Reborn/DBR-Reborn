#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "The huge quarry." );
    set( "day long", @EndText
You are in the center parts of this huge quarry.
Surrounding you in all directions are active parts,
where slaves are working very hard producing rocks
for the village walls. The yelling of the slave-
drivers is drowned in the noise of the huge boulders
being dragged across the rocky ground.
EndText
);
    set( "night long", @EndText
The ground in this quarry seems almost perfectly
horizontal. Even though it is not extremly dark,
you can not see where this large area ends.
EndText
);
    set_exits( ({ ROOMS_PATH+"q_02", ROOMS_PATH+"q_11",
ROOMS_PATH+"q_22", ROOMS_PATH+"q_13" }), ({ "west", "north", "east",
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
