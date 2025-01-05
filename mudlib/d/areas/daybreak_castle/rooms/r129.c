#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void reset() {
        ::reset();
if (!present("castle warrior")) 
new(MON+"castlewarrior.c")->move(this_object());
new(MON+"castlewarrior.c")->move(this_object());
}


void create()
{
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set_property("indoors", 1);

 
    set( "short", "The southern entrance." );
    set( "day long", @EndText
your are standing in a room filled with death that it burns your eyes. you find it hard to keep your eyes open but you sense something more powerful is just one more room away. you have to decide to stand your ground and run like a coward.
	
	
EndText);

    set( "night long", @EndText
your are standing in a room filled with death that it burns your eyes. you find it hard to keep your eyes open but you sense something more powerful is just one more room away. you have to decide to stand your ground and run like a coward.

EndText);

add_exit(PATH+"r130.c", "northeast");

add_exit(PATH+"r38.c", "west");

}
