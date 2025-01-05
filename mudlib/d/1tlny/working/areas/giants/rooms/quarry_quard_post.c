#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set( "short", "Quarry guard post." );
    set( "day long", @EndText
This is a guard post of the storm-giant quarry. It seems as it
is used to prevent the slaves in the quarry to escape and at
the same time keep unauthorized people from entering it. The
storm-giants take a lot of pride in the expansion of this village
and it is advisable not to interfere with their work. South of
here is the road leading towards the marketplace. The road
continues north also, leading towards the more active parts of
the quarry.
EndText
);
    set( "night long", @EndText
The quarry is quiet at night but this guard post is still fully
active. The poor slaves in the quarry seems to have no way of
escaping their work.
EndText
);
   
    set_exits( ({ ROOMS_PATH+"quarry_road", ROOMS_PATH+"quarry_road2" }),
({ "south", "north" }) );
}

void reset() {
     ::reset();
     if(!present("guard.c"))  {
      new(MOBS_PATH+"guard.c)->move(TO);
      new(MOBS_PATH+"guard.c)->move(TO);
      }
}
 
