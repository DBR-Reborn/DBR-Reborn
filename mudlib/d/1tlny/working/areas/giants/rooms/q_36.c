#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Southeast corner of the quarry." );
    set( "day long", @EndText
You are in the southeast corner of the storm giant
quarry. This must be the most recent addition to this
enormous place. The southern wall is very roughly cut,
showing that they have not worked on it for too long.
EndText
);
    set( "night long", @EndText
This place is very quiet and peaceful at night and
none of the alarms of the daily work can be heard.
The only thing you hear are the noise of an occasional
cricket.
EndText
);
    add_item("walls","Huge walls surround you. The southern wall is roughly
cut, with huge blocks of stone pointing out of it in a very unnatural
way.");
    set_exits( ({ ROOMS_PATH+"q_35" }), ({ "north"}) );
}

void reset()
{
    int i;
    ::reset();
    if(!query_night())
    {
// puts out 3 slave-drivers and 1-8 slaves in room if none are there
      if(!present("slave"))    
      {
        for(i = 1 + random(7); i >= 0; i--)
        {
          new(MOBS_PATH+"slave.c")->move(TO);
        }
      }
      if(!present("slave-driver"))
      {
        new(MOBS_PATH+"slave-driver.c")->move(TO);
        new(MOBS_PATH+"slave-driver.c")->move(TO);
        new(MOBS_PATH+"slave-driver.c")->move(TO);
      }
    }
}
