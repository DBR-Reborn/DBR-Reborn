#include <std.h>
#include <shao.h>

inherit ROOM;

void init(){
::init();
call_out("undead_moan",10);
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Shadow Lane");
set("long","%^RESET%^A dense fog layers the "
"street, almost totaly imparing vision.  You "
"can just barely make out two silhouettes to the "
"east and west that resemble buildings or walls of some sort."
"\n");
    add_exit("nr9", "south");
    add_exit("shad6", "north");
set_smell("default","The odour of rotting flesh lingers "+
"in the night air, but your not sure from wich direction...\n");
set_listen("moans","You hear what you think is "+
"muffled moans, and whines of aggony, but you "+
"can't pin point a direction");
}
void undead_moan(){
if(!query_night())
tell_room(PATH+"shad5","%^CYAN%^As the "
"dense fog shifts and swirls, a "
"shape or perhaps an unexplained silhouete "
"seems to be shifting it's position.\n");
else{
tell_room(PATH+"shad5","%^CYAN%^A brief but "
"bone chilling breeze suddenly blows "
"against your body, yet the dense fog "
"remains undisturbed... something is "
"wrong.... something is very wrong..\n");
}
remove_call_out("undead_moan");
call_out("undead_moan",60);
}
