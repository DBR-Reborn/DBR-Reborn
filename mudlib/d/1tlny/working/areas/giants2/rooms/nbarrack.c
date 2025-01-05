#include <std.h>
#include "giants_paths.h"

inherit ROOM;

void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 2);
    set( "short", "Northern Guard Barrack." );
    set( "day long", @EndText
You have entered a guard barrack. Here the guards who are not 
on duty rests. Unlike most guardposts you have seen this place 
seems to be in order. The Storm-Giants obviously take their duties
seriously. In the middle of the room a table with three chairs
can be seen. The floor is covered with dust from the somewhat
cracked walls surrounding the room. To the south a road can be seen.
EndText
); 

    set( "night long", @EndText
You have entered a guard barrack. Here the guards who are not 
on duty rests. Unlike most guardposts you have seen this place 
seems to be in order. The Storm-Giants obviously take their duties
seriously. In the middle of the room a table with three chairs
can be seen. The floor is covered with dust from the somewhat
cracked walls surrounding the room. To the south a road can be seen.
EndText
); 

      add_item("walls","These impressive walls seem to tower no less
than 30 feet above you.");
      add_item("cracks","Some cracks in the wall.. you wonder what could 
break solid stone.");      add_item("floor","Fine stone splinters covers much of the floor.");
      add_item("table","An enormous stone table..."); 
      add_item("chairs","3 stone chairs surrounding the table.");
   set_exits( ({ ROOMS_PATH+"road2" }), ({ "south" }) );
}


