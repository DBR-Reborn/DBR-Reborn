#include <std.h>
#include <shao.h>

inherit ROOM;

void init(){
::init();
call_out("fog_chats",10);
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
    add_exit("shad5", "south");
    add_exit("shad7", "north");
add_exit("ladder3","east");
add_invis_exit("east");
if(query_night()){
set_smell("default","The odour of rotting flesh lingers "+
"in the night air...");
set_listen("default","You hear what you think is "+
"muffled moans, and whines of agony.");
}
}
void fog_chats(){
switch(random(5)){
case 0:tell_room("%^CYAN%^The dense fog "
"shifts slightly and your able to barely "
"make out the silhouete of two large "
"structures to the east and west.\n");
break;
case 1:tell_room(PATH+"shad6","%^CYAN%^The "
"dense fog swirls and shifts, for a split "
"second you could swear you saw a shadow "
"of something a few feet from you.\n");
break;
case 2:tell_room(PATH+"shad6","%^CYAN%^The "
"fog continually rises and falls, swirls "
"shifts its many layers, for a brief second "
"you thought you may have seen a small gap in "
"the structure to your east.\n");
break;
case 3:tell_room(PATH+"shad6","%^CYAN%^Y"
"ou see a pair of %^RESET%^%^RED%^demonic "
"looking red eyes %^RESET%^%^CYAN%^peering "
"at you through the fog....\n"
"\n"
"or maybe its just an odd shaped lantern...\n");
break;
case 4:tell_room(PATH+"shad6","%^CYAN%^You "
"could swear you hear a low growling sound from "
"withing the fog ahead...\n");
}
remove_call_out("fog_chats");
call_out("fog_chats",60);
}
