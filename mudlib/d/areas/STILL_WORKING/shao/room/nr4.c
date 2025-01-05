#include <std.h>
#include <shao.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_property("outdoors", 1);
    set("short", "Northern Row");
set("night long","%^RESET%^A broken lantern lay "
"at your feet, the shattered glass scattered "
"across the street. To the north lay a set "
"of very grand stairs.  The unsurpassed shine "
"of the stones reflect the moonlight and give "
"off a faint blue glow.  You suspect that such "
"care and craftsmenship would probably only "
"be used on special structures such as "
"Shao-tan City Hall perhaps...\n"
"\n"
"The road you stand on continues east and west.\n");
set("day long","%^RESET%^%^ORANGE%^To "
"the north lay a massive set of stairs, that "
"appear to crafted highly polished white marble. "
"A sign over the grand archway at the top of "
"the steps has something carved into it. "
"Buildings line both sides of this street to "
"the east and west.  It appears that a large "
"flaming cross stands in front of one of the "
"buildings to the far east...\n");
    add_exit("nr3", "west");
    add_exit("nr5", "east");
    add_exit("al8", "south");
add_invis_exit("south");
    add_exit("city_hall", "north");

set_items(([
({"massive stairs","steps","marble"
,"polished marble","stairs","stair case"}):
(:call_other,this_object(),"look_at_stairs":),
({"sign","archway","letters"}):
(:call_other,this_object(),"look_at_sign":),
({"buildings","cross","flaming cross"}):
"buildings of various size line both sides "
"of the street to the east and to the west. "
"A building with a large flaming cross is "
"to the east, but the cross is too far away to "
"see any great detail.\n",
({"road","street"}):
(:call_other,this_object(),"look_at_road":),
]));

}
void look_at_stairs(){
if(!query_night())
write("%^RESET%^%^ORANGE%^The sun "
"shines brightly on the highly polished "
"white marble stairs. You guess they "
"rise at least the length of 2 full grown "
"humans, and each step is about two feet deep "
"and numerious feet long.\n");
else{
write("%^RESET%^Although it is fairly "
"dark, you are still able to see some "
"details of the staircase. A faint blue "
"glow reflects from the hightly polished marble"
" letting you see the massive size of the stair"
"case. Its at least the lenght of two full "
"grown humans in hight, and each step "
"is about two feet deep and numerous feet long.\n");
}
}
void look_at_sign(){
if(!query_night())
write("%^RESET%^%^ORANGE%^With the aid of "
"the sun you are able to see what has been "
"carved into the stone of the archway at the "
"top of the stairs... it reads:\n"
"%^RESET%^%^GREEN%^SHAO-TAN CITY HALL.\n");
else{
write("Its really too dark to do that...\n");
}
}
void look_at_road(){
write("The cobble stone road is "
"in fairly good condition, and very "
"well maintained.\n");
}
