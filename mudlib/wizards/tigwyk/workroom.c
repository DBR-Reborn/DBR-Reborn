//      from the Nightmare mudlib
//      an example workroom for new immortals

#include "/adm/include/std.h"

inherit "/std/locker_room";

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The workroom of a new immortal");
set( "day long", @EndText
It is %^YELLOW%^day%^RESET%^ outside.
A new immortal works here.
hall    [area for posts and boards for wizards and players]
square  [takes you to DBR church}
portal  [area created by TLNY takes you to all current working areas]
spells  [all spells and skills in the entire mud currently TLNY2020]
EndText);

set( "night long", @EndText
It is %^BOLD%^BLUE%^night%^RESET%^ outside.
A new immortal works here.
hall    [area for posts and boards for wizards and players]
square  [takes you to DBR church}
portal  [area created by TLNY takes you to all current working areas]
spells  [all spells and skills in the entire mud currently TLNY2020]
EndText);

    set_exits( ({ "/d/standard/square", "/d/standard/adv_main", "/d/daybreak/room/N1" }),
      ({ "square", "hall", "portal" }) );
    add_exit("/d/1tlny/spell_rooms/spell_room_all", "spells");
    set_smell("default", "It smells like a new immortal in here.");
    set_listen("default", "You hear the sounds of code creation.");
}
