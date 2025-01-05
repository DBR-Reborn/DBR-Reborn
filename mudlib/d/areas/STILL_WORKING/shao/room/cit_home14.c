#include <std.h>
#include <shao.h>

inherit VAULT;
object mon;

void init(){
::init();
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
set("short", "Citizen Home");
set("long","You stand on a well polished wood floor. "
"On the north wall you notice a small window and "
"wood door. "
"The rough stone walls run half way up to the cieling, "
"then mud has been packed over the stones and smoothed, "
"perhaps for both decoration and insulation. "
"The cieling appears to be large slates of stone with "+
"heavy wooden beems supporting them.\n");
set_items(([
({"floor","wood floor"}):
"The floor is made from interlocking wood planks"+
" that have been polished to a glass like state.\n",
({"walls","wall","stone wall","stone walls"}):
"Large stones have been stacked on top of each other "
"to form a solid looking wall. Half way up to "
"the ceiling, mud has been tightly packed over "
"the stones and then smoothed down.\n",
({"ceiling","slates"}):
"Large flat stone slates, have been layed over "
"thick wooden beems to form a very sturdy looking "
"cieling",
({"window","out window"}):
(:call_other,this_object(),"look_at_window":),
({"door","wood door"}):
(:call_other,this_object(),"look_at_door":),
]));
set_smell("default","The faint hint of cigar smoke lingers in the air");
    add_exit("com9","north");
set_door("wood door",PATH+"com9","north", 0);

}
void look_at_window(){
if(query_night())
write("Looking out over commoners row, covered by the "
"miss leading blanket of night, it all almost seems "+
"peacefull in a way.\n");
else write("The shines brightly outside, it looks "+
"HOT... dam HOT...\n");
say(this_player()->query_cap_name()+" takes a "+
"peek outside the window.\n");
}
void look_at_door(){
if(query_open("wood door"))
write("the door is open");
else write("the door is closed");
}
