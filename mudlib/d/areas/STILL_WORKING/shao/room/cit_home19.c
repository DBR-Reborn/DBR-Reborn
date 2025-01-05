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
set("long",
"You stand on a fairly clean floor made of stone tiles. "
"The stone walls look very solid, but also very old "
"and worn. "
"On the north wall you notice a small window and "
"wood door. "
"The cieling appears to be large slates of stone with "+
"heavy wooden beems supporting them.\n");
set_items(([
({"floor","stone floor"}):
"The floor is made from large flat rocks and stones"+
" that have been sunken into the natural earthen "+
"floor of this house.  The end result is both a "
"stable and solid floor that also looks very decorative.",
({"walls","wall","stone wall","stone walls"}):
"Large stones have been stacked on top of each other "
"to form a solid and strong wall.\n"+
"...hmmm and something is odd about the 'west wall'",
({"west wall"}):
(:call_other,this_object(),"look_at_west_wall":),
({"ceiling","slates"}):
"Large flat stone slates, have been layed over "
"thick wooden beems to form a very sturdy looking "
"cieling",
({"window","out window"}):
(:call_other,this_object(),"look_at_window":),
({"door","wood door"}):
(:call_other,this_object(),"look_at_door":),
]));
set_smell("default","an odd blend of many odors fills the air..\n");
set_smell("odors","You think you detect the faint hint of cigar smoke, perfume, alchohol, and .... cheap sex?");
set_listen("west wall","You think you hear muffled music and voices..");
    add_exit("com4","south");
set_door("wood door",PATH+"com4","south", 0);

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
void look_at_west_wall(){
int skill;
say(this_player()->query_cap_name()+" appears to be "+
"studying the west wall.\n");
skill=((int)this_player()->query_skill("perception"));
if(random(100)<skill){
write("You take a good hard look at the wall, and "+
"notice something very odd.\n"+
"\n"+
"A doorway was once here!  Odd that someone "+
"would have a door leading to another house, and "+
"maybe even a bit stranger that they would then "+
"cover it with a solid wall.\n"+
"But what you find MOST strange is that you "+
"think you here something behind it!\n");
}
else
write("Hmmm nope nothing out of the ordinary, "+
"the old eyes must just be playing tricks...\n");
}
