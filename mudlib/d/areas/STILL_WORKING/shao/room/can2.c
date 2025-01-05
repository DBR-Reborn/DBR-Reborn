#include <std.h>
#include <shao.h>

inherit VAULT;


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
set("night long", "%^RESET%^The oil lanterns lining the street "
      "flicker, and "
"sputter, causing a peacefull, dull wavy wash of light. "+
"Old and faded interlocking bricks form an almost level "
"section of road. "+
"To the west stands a section of the massive wall "
"that surrounds the city of Shao-tan. "
"To the east you see the front of a building. "
"The avenue can be followed "+
"to the north or south from here.\n");
set("day long", "%^RESET%^%^ORANGE%^You "
"are standing on "
"a road constructed from interlocking bricks. "
"Lanterns line the brick road as far as you can "
"see, giving it a very peacefull atmosphere. A "
"massive section of wall stands solidly to the "
"west while to the east you see the front of "
"an old building.\n"
"\n"
"The avenue continues north and also south for quite "
"a few blocks...\n");
add_exit("can1","north");
add_exit("can3","south");
add_exit("wall20","west");
add_post_exit_function("north","go_north");
add_post_exit_function("south","go_south");
add_pre_exit_function("west","go_west");
add_invis_exit("west");
set_door("hatch",PATH+"wall20","west","shao_key");
set_open("hatch",0);
set_locked("hatch",1);
set_items(([
({"lantern","lanterns"}):
(:call_other,this_object(),"look_at_lantern":),
({"wall","massive wall"}):
(:call_other,this_object(),"look_at_wall":),
({"road","bricks","interlocking bricks"}):
(:call_other,this_object(),"look_at_road":),
({"building","old building","abandoned building"}):
(:call_other,this_object(),"look_at_building":),
]));


}
int go_north(){
remove_call_out("found_stair");
return 1;
}
int go_south(){
remove_call_out("found_stair");
return 1;
}
int go_west(){
remove_call_out("found_stair");
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
"even the tallest buildings in Shao-tan. You guess "
"the guards that you see patroling it would have "
"an excelent view of the city and also a large area "
"out side the city.\n");
call_out("found_stair",15);
}

void found_stair(){
if(!query_night())
write("%^CYAN%^Odd.... \n"+
"You think you see a well concealed hatch "+
"to the west.\n");
remove_call_out("found_stair");
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

void look_at_building(){
if(query_night())
write("Its too dark to get a good look...\n"+
"Using the little light provided by the lanterns "
"that line the street, you can tell the building "
"is in generaly poor shape. You also notice that "
"it appears to be pitch black inside.\n");
else
write("The building looks like its "
"ready to collapse at any moment. "
"Judging by the cracked, and crumbling "
"wood it's built from, you guess it is "
"probably abandoned.\n");
}

