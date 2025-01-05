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
You are standing just north of what seems to be
the most recent addition to the storm giant quarry.
The quarry opens up to the northwest. Looking in
that direction from here shows the magnificent,
natural stone floor, stretching out a long way
in front of you.
EndText
);
    set( "night long", @EndText
This place is very quiet and peaceful at night and
none of the alarms of the daily work can be heard.
The only thing you hear are the noise of an occasional
cricket.
EndText
);
    set_exits( ({ ROOMS_PATH+"q_24", ROOMS_PATH+"q_35", ROOMS_PATH+"q_33"
}), ({ "west", "south", "north" }) );
}
void reset()
{
    int i;
    ::reset();
    if(!query_night())
    {
// puts out 2 slave-drivers and 1-5 slaves in room if none are there
      if(!present("slave"))    
      {
        for(i = 1 + random(4); i >= 0; i--)
        {
          new(MOBS_PATH+"slave.c")->move(TO);
        }
      }
      if(!present("slave-driver"))
      {
        new(MOBS_PATH+"slave-driver.c")->move(TO);
        new(MOBS_PATH+"slave-driver.c")->move(TO);
      }
    }
}
