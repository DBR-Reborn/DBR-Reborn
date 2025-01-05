#include <std.h>
#include <shao.h>

inherit ROOM;


void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Shadow Lane");
set("long","%^RESET%^A thick fog prevents you "
"from seeing any further then about an inch in "
"front of your face.  A bone chilling breeze blows from "
"the north, causing the thick fog to swirl and briefly "
"fluxuate in density.\n"
"for a brief second you thought you saw a street sign"
" that read :\n"
"--== Shadow Lane ==--\n"
"...but the fog quickly rolled back in hindering your sight");
    add_exit("shad1", "south");
    add_exit("shad3", "north");
if(query_night()){
set_smell("default","The odour of rotting flesh lingers "+
"in the night air, but your not sure from wich direction...\n");
}
}
