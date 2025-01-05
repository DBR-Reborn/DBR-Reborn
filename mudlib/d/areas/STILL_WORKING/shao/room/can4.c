#include <std.h>
#include <shao.h>

inherit ROOM;


object mon;

void reset(){
}
void init(){
::init();
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Kcunac Ave");
set("night long","%^RESET%^The oil lanterns lining the street "
      "flicker, and "
"sputter, causing a peacefull, dull wavy wash of light. "+
"Old and faded interlocking bricks form an almost level "
"section of road. "+
"To the west stands a section of the massive wall "
"that surrounds the city of Shao-tan. "
"To the east you see the front of a building. "
"The avenue can be followed "+
"to the north or south from here.\n");
set("day long","%^RESET%^%^ORANGE%^You "
"have arrived at an intersection, "
"Commoners Row begins here heading east. "
"The interlocking bricks of Kcunac "
"Avenue lead off to the north and south. "
"A massive wall flanks the west side "
"of the avenue as far as you can see "
"in both directions. Two homes lay to "
"the northeast and southeast.\n");

add_exit("can3","north");
add_exit("can5","south");
add_exit("com1","east");

set_items(([
({"lantern","lanterns"}):
(:call_other,this_object(),"look_at_lantern":),
({"wall","massive wall"}):
(:call_other,this_object(),"look_at_wall":),
({"road","bricks","interlocking bricks"}):
(:call_other,this_object(),"look_at_road":),
({"houses","home","homes","house"}):
"There is two of them, a northeast "
"house and a southeast house.",
({"southeast house","se house"}):
(:call_other,this_object(),"se_house":),
({"northeast house","ne house"}):
(:call_other,this_object(),"ne_house":),
]));


}
void se_house(){
if(query_night())
write("%^RESET%^Its too dark to really get a "+
"good look at it from here.\n");
else
write("%^RESET%^%^ORANGE%^It looks like it is "
"in pretty poor shape. The stone walls are "
"cracked and most are well into the process "
"of decaying and crumbling.\n");
}

void ne_house(){
if(query_night())
write(
"%^RESET%^Its too dark to get a good look...\n"
"All your able to tell is that there is a dim "
"candle light comming from inside of it.\n");
else
write("%^RESET%^%^ORANGE%^The place is "
"built from grey rocks, and looks like its in "
"fairly good condition. The roof appears "
"to be a little rusted and in need of repairs.\n");
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

void look_at_wall(){
if(query_night())
write("Without the aid of the sun, all that "+
"can be identified is a massive silhouette "+
"that rises from the ground and towers "+
"high above even the tallest building. "+
"You think you see movement at the very top of "+
"it.  Against the backdrop of the moon lit sky "
"the odd silhouette... probably a guard "+
"is seen making his rounds...\n");
else
write("The massive structure looks like it was "
"built by stacking many large boulders "
"on top of each other. The wall stands high above"
" even the tallest buildings in Shao-tan. You guess "
"that the guards you see patrolling it would have "
"an excelent view of the city and also a large area "
"out side the city.\n");
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
write("Its too dark to make out any "+
"real details, all your able to really "+
"obsearve is that the house appears to "
"be made from stone and looks in average "
"condition. No window is visible on the "
"wall.\n");
else
write("The side of the house is made "
"from grey stone, and look in "
"average condition. The roof is slanted "
"at an angle that any rainfall would "
"trickle down off it, and probably end "
"up falling right where you stand.\n");
}

