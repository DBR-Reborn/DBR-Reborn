#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void reset() {
        ::reset();
if (!present("dirty peasant")) 
new(MON+"peasant.c")->move(this_object());
new(MON+"guard.c")->move(this_object()); 

}

void create() {
      
	  
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set_property("indoors", 1);

    //set_property("no attack", 1); 
    //set_property("no cast", 1);
    //set_property("no scry", 1);
    //set_property("no teleport", 1);
    //set_property("no summon", 1);
    set( "short", "The southern entrance." );
    set( "day long", @EndText
It is dark and gloomy here.

You are just standing past an archway that only leads into two directions which may end with death. The stories you have heard about this area may or may not be true but you can hear screams coming from inside and bones breaking. you can hear chains being dragged across the floor as if its checking each room for someome to collect. Disanbody voices echoing from all directions. You can feel a small sensation of the ceiling and walls cracking from old age.
        
%^YELLOW%^You begin to smell rotting flesh and faint foot steps not too far ahead.%^RESET%^

e
EndText);

    set( "night long", @EndText
It is dark and gloomy here.

You are just standing past an archway that only leads into two directions which may end with death. The stories you have heard about this area may or may not be true but you can hear screams coming from inside and bones breaking. you can hear chains being dragged across the floor as if its checking each room for someome to collect. Disanbody voices echoing from all directions. You can feel a small sensation of the ceiling and walls cracking from old age.
        
%^YELLOW%^You begin to smell rotting flesh and faint foot steps not too far ahead.%^RESET%^
EndText);

add_exit(PATH+"r40.c", "north");
//add_exit(PATH+"r34.c", "east");
add_exit(PATH+"r39.c", "south");
add_exit(PATH+"r10.c", "out");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
