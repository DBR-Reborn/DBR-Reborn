#include <std.h>
#include <shao.h>

inherit ROOM;

void init(){
::init();
add_action("do_search","search");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Shadow Lane");
set("long","%^BOLD%^A thick fog prevents you "
"from seeing any further then about an inch in "
"front of your face.  A bone chilling breeze blows from "
"the north, causing the thick fog to swirl and briefly "
"fluxuate in density.\n"
"You amagine it would be almost imposible to search "
"this section of street had you dropped something.\n");
    add_exit("shad2", "south");
add_exit(PATH+"wall9","east");
add_invis_exit("east");
    add_exit("shad4", "north");
if(query_night()){
set_smell("default","The odour of rotting flesh lingers "+
"in the night air, but your not sure from wich direction...\n");
}
}
int do_search(){
write("As the dense fog is briefly broken up by a gust"+
" of wind, you think you spot a hidden passage "
"to the east.\n");
remove_invis_exit("east");
call_out("re_hide",20);
return 1;
}
void re_hide(){
add_invis_exit("east");
}
