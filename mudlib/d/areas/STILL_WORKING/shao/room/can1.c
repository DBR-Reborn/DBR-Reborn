#include <std.h>
#include <shao.h>

inherit ROOM;

int crate_climbed;

object mon;

void reset(){
if(crate_climbed)crate_climbed=0;
}
void init(){
::init();
add_action("climb_crate","climb");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Kcunac Ave");
set("night long", "%^RESET%^The oil lanterns lining the street "
      "flicker, and "
"sputter, causing a peacefull, dull wavy wash of light. "+
"Old and faded interlocking bricks form an almost level "
"section of road. "+
"To the west lay one of the many guard posts of Shao-tan, "+
"while to the east you see the side of a house. "
"Much light filters down to this section of Knunac Ave "
"from the city gate located directly to the northwest.\n"
"\n"
"The avenue can be followed to the south, and exited to "+
"the north.\n");
set("day long", "%^RESET%^%^ORANGE%^The "
"sun has done a nice job "
"of warming the interlocking bricks on wich you "+
"now stand. "
"One of the many guard posts can be seen to the west, "+
"and the side of a citizen's house can be seen to the "
"east. "
"It appears Southern Row is just north of here, while "
"this Avenue looks to continue for quite a ways to the "
"south\n");
add_exit("sr1","north");
add_exit("can2","south");
set_items(([
({"lantern","lanterns"}):
(:call_other,this_object(),"look_at_lantern":),
({"post","guard post"}):
(:call_other,this_object(),"look_at_post":),
({"road","bricks","interlocking bricks"}):
(:call_other,this_object(),"look_at_road":),
({"house","citizens house","home"}):
(:call_other,this_object(),"look_at_house":),
({"window","open window"}):
(:call_other,this_object(),"peeping_tom":),
]));

crate_climbed=0;

}
void look_at_lantern(){
if(query_night())
write("The lantern burns with an unusual"+
"redish flame, and baths the area in a soft"+
" red hue.\n");
else
write("The lantern is not burning right now, "+
"and is probably only warmed by the sun.\n"+
"\n"+
"It appears to be made from iron...\n");
}

void look_at_post(){
if(query_night())
write("Enought light is present in the guard's post "+
"for you to make out some movement inside, although"+
" not enough light exists to make out any great "+
"detail.\n");
else
write("looking through the bars of the guards post"+
" you are able to see that although they have "
"the dangerous job of trying to keep law and order "
"in the town of Shao-tan, they at least get to do "+
"it in the shade.\n");
}

void look_at_road(){
if(query_night())
write("The interlocking stones that make up the road"+
"feel quite cool under your feet, but will probably "+
"warm up once they are exposed to the day's hot "+
"sun.\n");
else
write("Although they are faded and appear to "+
"be very old, the sun's rays still bring out the "+
"red colour of some bricks.\n");
}

void look_at_house(){
if(query_night())
write("You notice the soft glow of candle light "+
"comming from an open window on the side of the. "+
"Since its almost pitch black out, you could "+
"probably get away with taking a quick peek "+
"in the window....\n");
else
write("The stone walls of the house look "+
"very sturdy. The light reflected from the "+
"odd steel roof is almost blinding. Your "+
"not sure if anyone is home, but there is "+
"an open window you could probably take "+
"a peek into.\n");
}

void peeping_tom(){
if(!query_night())
write("The window is a little higher "+
"then you first thought, but you "+
"notice some old shipping crates just "+
"under the window and climb up on top of "
"them to get a good look inside....\n"
"You notice nobody is home, and that the "
"place is well furnished....\n"
"\n"
"Since it IS BROAD DAYLIGHT you decide you "
"better get down before you get busted.\n");
else
write("The window is a little to high,"+
" to see into, you do notice some crates "
"under the window and think you could "
"probably climb them to see into the "
"window..\n");
}
int climb_crate(string str){
if(!str){
notify_fail("what do you want to climb bunghole???");
return 0;
}
if(str == "crate" || str == "crates"){
if(!query_night()){
notify_fail("Your better judgment keeps you from "+
"climbing on top of crates to peek into a "+
"window in broad DAYLIGHT where EVERYONE "+
"could SEE YOU!.\n");
return 0;
}
if(!crate_climbed){
write("%^CYAN%^You climb the crates.....\n");
this_player()->move_player(PATH+"sab_window.c");
crate_climbed=1;
}
}
}
