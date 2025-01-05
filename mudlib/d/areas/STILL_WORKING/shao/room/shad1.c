#include <std.h>
#include <shao.h>

inherit ROOM;

void init(){
::init();
call_out("fog_wave",20);
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Shadow Lane");
set("night long","%^RESET%^An old abandoned "
"building lay "
"to the west, you suspect it may have been a shop many years "
"ago.  This street is enshrouded with a dense fog, you can "
"barely see the ground you stand on.  An unusual "
"bone chilling breeze blows lightly from the north.  "
"Strange that even with the breeze the fog is so thick...\n");
set("day long","%^RESET%^The sun is "
"shining brightly...\n"
"The cobble stones benieth your feet are icy cold, "
"and a dense fog covers the street.  You find it odd "
"that directly to your south, the fog just vanishes "
"a few feet from Southern Row.  To the west you see "
"an old abandoned shop, or at least a building that "
"looks like it once WAS a shop.  To the east"
" lay a section of the Shao-tan wall wich surounds "
"the city.\n");
    add_exit("sr9", "south");
    add_exit("shad2", "north");
add_pre_exit_function("south","go_south");
add_pre_exit_function("north","go_north");

if(query_night()){
set_smell("default","It smells of rotting flesh, but your "
"unsure of what direction the smell is comming from.");
}

}
void fog_wave(){
remove_call_out("fog_wave");
call_out("fog_wave", 60);
if(!query_night())
tell_room(PATH+"shad1","%^CYAN%^A wave of "
"thick and murky "
"fog rolls across the road.\n");
else
tell_room(PATH+"shad1","%^CYAN%^You think you see a "
"figure moving about in the fog, but you "
"could be mistaken, the constant swirling "
"and churning of gasses is decieving.\n");
}
int go_north(){
remove_call_out("fog_wave");
return 1;
}
int go_south(){
remove_call_out("fog_wave");
return 1;
}
