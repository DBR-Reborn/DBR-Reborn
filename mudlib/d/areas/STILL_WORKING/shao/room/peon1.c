#include <std.h>
#include <shao.h>

inherit VAULT;
object mon;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
set("short","Peon Row");
set("night long", "%^RESET%^The oil lanterns lining the street "
"bath the road in an eerie dim light. "
"The road isn't really anything more then "
"a dirt path. It's cluttered with garbage, "
"broken glass, broken equipment and "
"mortal waste.\n");
set("day long","%^RESET%^%^ORANGE%^Your "
"standing on a garbage filled road, that "
"is commonly known as peon row. "
"This narrow dirt path is cluttered with "
"broken glass, broken equipment, mortal "
"waste and various other garbage. "
"To the north you see an old wood shack, "
"while to the south you notice a section of "
"the great Shao-tan wall that surrounds "
"the city. "
"This cruddy dirt path continues "
"east, to the west it looks like another "
"road begins.\n");

add_exit("peon2","east");
add_exit("can7","west");

set_items(([
({"lantern","lanterns","oil lanterns","oil lantern"}):
(:call_other,this_object(),"look_at_lantern":),
({"shack","wooden shack","wood shack"}):
(:call_other,this_object(),"look_at_shack":),
({"road","path","dirt path"}):
(:call_other,this_object(),"look_at_road":),
({"glass","broken glass","equipment",
"broken equipment","garbage","weapons"}):
(:call_other,this_object(),"look_garbage":),
({"waste","mortal waste"}):
(:call_other,this_object(),"look_at_shit":),
({"door","doors"}):
"The shack has a wood door...\n",
]));
    add_exit("cit_home5","north");
set_door("wood door",PATH+"cit_home5","north", 0);

}
int look_garbage(){
say("You see "+this_player()->query_cap_name()+
" looking at the garbage on the road.\n");
write("Useless junk... it's garbage ... except.\n"
"....%^CYAN%^You found a rat...\n");
mon = new(MON_PATH+"rat")->move(this_object());
mon->force_me("kill "+this_player()->query_name());
return 1;
}
void look_at_lantern(){
say("You notice "+this_player()->query_cap_name()+
" inspecting the lanterns along the side of the road.\n");
if(!query_night()){
write("The lanterns are made of old rusted iron.\n"+
"They are currently unlit.\n");
}
else write("The old iron lanterns provide at "+
"best, a dim glow to the street.\n");
}
void look_at_shack(){
say("You notice "+this_player()->query_cap_name()+
"glancing at an old shack.\n");
if(query_night())
write("It's too darke to make out any "+
"good details...\n");
else
write("It looks like it once may have been a house. "
"Now it isn't much more then a medium sized "
"out-house. The wood looks like it is well "
"into the process of decaying and molding...\n");
}
int look_at_shit(){
say("You notice "+this_player()->query_cap_name()+
" looking at crap on the road.\n");
if(query_night()){
write("various little mounds of shit are "
"scattered about the street, luckily it's "
"a cool night and the shit has dried up a bit"
" and the smell is probably not as potent as "
"when it was fresh.\n");
return 1;
}
if(!query_night());
write("various little mounds of shit are "
"scattered about the street, unlucky for you "
"its a hot day and the sun is burning bright "
"and hot. The sight combined with the smell "
"is enough to make you puke!....\n"
"%^CYAN%^...and you do...\n"
"\n"
"%^RESET%^You puke on your shoes...\n");
say(this_player()->query_cap_name()+" just "+
"puked on his shoes.\n");
this_player()->add_hp(-10);
return 1;
}
