#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void reset() {
    object h_rune;
    object forge;
	
        ::reset();
    if (!present("rat")){
        new(MON+"rat.c")->move(this_object());
        new(MON+"rat.c")->move(this_object());
    }
    if(!present("forge")) {
        forge = new("/d/excelsior/tinker/greater_forge");
        forge->set_weight(100000000);
        forge->move(this_object());
    }
    if (!present("rune")) {
        h_rune = new ("/std/diewarzau/obj/misc/h_rune");
        h_rune->move(this_object());
    }
}

void create()
{
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
It is %^YELLOW%^day%^RESET%^ outside.
Daybreak Castle Square is situated at the center of this abandoned and looted castle. a small fire from a forge keeps light to this room and provides a place where items can be forged. The square is surrounded by a circle formation of stone with multiple arch door-ways equality spaced between one another. Each door-way will take you to different areas of the castle. Be warned each area is designed
for all level of players..
%^WHITE%^
Level (01-10)   southwest   -Working-
Level (05-15)   west        -Under Construction-
Level (10-20)   northwest   -Under Construction-
Level (15-25)   north       -Test Mode-
Level (25-30)   northeast   -Under Construction-
Level (30-38)   east        -Working-  
Level (40-60)   southeast   -Under Construction-

 (((Exit)))     south%^RESET%^

EndText);

    set( "night long", @EndText
It is %^BOLD%^BLUE%^night%^RESET%^ outside.
Daybreak Castle Square is situated at the center of this abandoned and looted castle. a small fire from a forge keeps light to this room and provides a place where items can be forged. The square is surrounded by a circle formation of stone with multiple arch door-ways equality spaced between one another. Each door-way will take you to different areas of the castle. Be warned each area is designed
for all level of players..
%^BOLD%^WHITE%^
Level (01-10)   southwest   -Working-
Level (05-15)   west        -Under Construction-
Level (10-20)   northwest   -Under Construction-
Level (15-25)   north       -Test Mode-
Level (25-30)   northeast   -Under Construction-
Level (30-38)   east        -Working-  
Level (40-60)   southeast   -Under Construction-

 (((Exit)))     south%^RESET%^

EndText);

add_exit(PATH+"r3.c", "south");
add_exit(PATH+"r5.c", "southwest");
add_exit(PATH+"under construction.c", "west");
add_exit(PATH+"under construction.c", "northwest");
add_exit(PATH+"r8.c", "north");
add_exit(PATH+"under construction.c", "northeast");
add_exit(PATH+"r10.c", "east");
add_exit(PATH+"under construction.c", "southeast");
}