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
Huge shards of rock and different tools for breaking
off the enormous boulders from the walls are scattered
in the area. Workers and slave-drivers are surrounding
you both near and far. Everywhere people are working and
screaming, an occasional whiplash can be heard along with
the screams of some slave who did not work hard enough.
The slammering of hammers against the rock and terrible
crashing sounds as the huge boulders are separated from
the rock-walls fill the air with noise.
EndText
);
    set( "night long", @EndText
Huge shards of rock and different tools for breaking
off the enormous boulders from the walls are scattered
in the area. Everything seems very quiet, and you feel
almost peaceful in this open area.
EndText
);
    add_item("tools","Many tools used for various purposes are lying around
here.");
    add_item("shards","Shards of stone in various sizes are scattered
around the dusty bottom of this quarry.");
    set_exits( ({ ROOMS_PATH+"q_01", ROOMS_PATH+"q_12", ROOMS_PATH+"q_03"
}), ({ "north", "east", "south" }) );
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

