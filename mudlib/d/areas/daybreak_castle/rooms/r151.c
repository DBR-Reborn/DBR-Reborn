#include <std.h>
#include "../a1.h"

inherit ROOM;

int search_count;

void reset() {
        ::reset();
if (!present("castle warrior")) 
new(MON+"castlewarrior.c")->move(this_object());
new(MON+"castlewarrior.c")->move(this_object());
new(MON+"castleguard.c")->move(this_object());
new(MON+"castlewarrior.c")->move(this_object());
new(MON+"castleguard.c")->move(this_object());
new(MON+"castlewarrior.c")->move(this_object());
new(MON+"castleguard.c")->move(this_object());
new(MON+"castleguard.c")->move(this_object());
new(MON+"castleguard.c")->move(this_object());
new(MON+"castlewarrior.c")->move(this_object());
new(MON+"castleguard.c")->move(this_object());
new(MON+"castlewarrior.c")->move(this_object());
new(MON+"castleguard.c")->move(this_object());

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
You are standing in a large room with many torches on the wall providing light to the area. you feel the monster here must be protecting something. you see a statue on the ground scattered as it appered it had been pushed onto the floor. as you look closer you can see the statue baae is loose, maybe it can be move.

%^COLOR220%^Well lit torches line the room.%^RESET%^

%^COLOR87%^Broken statue had fallen from its base.%^RESET%^
EndText);

    set( "night long", @EndText
You are standing in a large room with many torches on the wall providing light to the area. you feel the monster here must be protecting something. you see a statue on the ground scattered as it appered it had been pushed onto the floor. as you look closer you can see the statue baae is loose, maybe it can be move.

%^COLOR220%^Well lit torches line the room.%^RESET%^

%^COLOR87%^Broken statue had fallen from its base.%^RESET%^
EndText);

add_exit(PATH+"r150.c", "north");
//add_exit(PATH+"r146.c", "east");
//add_exit(PATH+"r151.c", "south");
//add_exit(PATH+"r144.c", "west");
//add_exit("/d/damned/virtual/room_11_7.world", "exit");
    //add_invis_exit("north");

}
