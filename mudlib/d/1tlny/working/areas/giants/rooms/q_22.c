#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set( "short", "Eastern parts of the quarry." );
    set( "day long", @EndText
You are in a little corner in the eastern parts of
the storm giant quarry. Tools and rocks are spread
across the ground of this place.
EndText
);
    set( "night long", @EndText
Walking around here you stumble over an occasional shard
of rock. The eastern and northern walls are standing
before you like two giants, dark like the night itself.
EndText
);
    add_item("tools", "Different tools used for working with stone.");
    set_exits( ({ ROOMS_PATH+"q_12", ROOMS_PATH+"q_23" }), ({ "west",
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
