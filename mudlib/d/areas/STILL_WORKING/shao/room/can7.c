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
"glow with a "
"peacefull yellowish flame. "
"The avenue is constructed from old and faded "
"interlocking bricks that appear "
"to be in need of maintenance. "
"The great wall of Shao-tan stands to the "
"west and south. Kcunac Avenue can be followed north "
"from here, Peon Row leads off to the east. "
"To the northeast you see a building.\n");

set("day long","%^RESET%^%^ORANGE%^You "
"are standing on Kcunac Avenue. "
"The road is cluttered with garbage that "
"has drifted over from Peon Row to the east. "
"Glancing to the west and south you notice "
"the massive Shao-tan wall that protects the city "
"from intruders. "
"A building stands on the northwest corner of the "
"road.\n");

add_exit("can6","north");
add_exit("peon1","east");

set_items(([
({"lantern","lanterns"}):
(:call_other,this_object(),"look_at_lantern":),
({"wall","massive wall"}):
(:call_other,this_object(),"look_at_wall":),
({"road","bricks","interlocking bricks"}):
(:call_other,this_object(),"look_at_road":),
({"home","house","building"}):
(:call_other,this_object(),"look_at_house":),
]));


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
"be made from stone and looks like its "
"in poor "
"condition. It looks abandoned.\n");
else
write("The house is made "
"from grey stone, and looks like its "
"in "
"poor condition. The roof is slanted "
"at an angle that any rainfall would "
"trickle down off it, if not for "
"the numerous holes and rusted out spots.\n");
}
