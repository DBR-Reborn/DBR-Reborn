#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void reset() {
        ::reset();
if (!present("guard")) 
new(MON+"guard.c")->move(this_object());
new(MON+"guard.c")->move(this_object());
new(MON+"guard.c")->move(this_object());
new(MON+"guard.c")->move(this_object());
}

void create() {
      
	  
    ::create();
    set_property( "light", 3);
    set_property( "night light", 1);
    set_property("indoors", 3);
    set( "short", "The southern entrance." );
    set( "day long", @EndText
your in a well lit room from a huge opening in the wall. you see crumbling rock at the base of the opening and can see the castle square from the opening.

%^COLOR248%^Huge opening in the wall where you can see the Castle square.%^RESET%^
	
	
EndText);

    set( "night long", @EndText
your in a well lit room from a huge opening in the wall. you see crumbling rock at the base of the opening and can see the castle square from the opening.

%^COLOR248%^Huge opening in the wall where you can see the Castle square.%^RESET%^
EndText);

//add_exit(PATH+"r123.c", "north");
//add_exit(PATH+"r149.c", "east");
add_exit(PATH+"r129.c", "southwest");
add_exit(PATH+"r4.c", "square");

}
