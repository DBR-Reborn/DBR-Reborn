#include <std.h>
#include <shao.h>

inherit ROOM;

void init() {
    ::init();
call_out("priest_move",10);
add_action("pray_demon", "pray");
}

void create() {
    ::create();
    set("short", "Shao-tan Temple");
set("day long","%^RESET%^This"
" is the Shao-tan temple of the damned.\n"
      "Shadows cling to the walls and corners, leaving it fairly dark "
      "and gloomy.  It seems odd that the suns rays just seem to "
      "die before they are able to shed light into this building...\n"
"You notice a spiral staircase leading up "
"into the ceiling.\n");
set("night long","%^RESET%^%^CYAN%^This is the "
"Shao-tan temple "
      "of the damned.\n"
      "Shadows cling to the walls and corners, leaving it fairly dark "
      "and gloomy.  If not for the dim lanterns hanging from the "
      "occasional wall, it would be pitch black in here.");
set_property("light", 2);
set_property("night light", 1);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set_items( ([ "northern world map" : (: call_other, this_object(),
	  "read_world_map" :),
	"southern world map" : (: call_other, this_object(), "read_world\
_map2" :),
	"city map" : (: call_other, this_object(), "read_city_map" :),
	"map" : "There is a 'city map', a 'northern world map', "
	"and a 'southern world map'.",
	"maps" : "There is a 'city map', a 'northern world map'."
	"and a 'southern world map'.",
      ]) );
add_exit("church1", "up");
add_exit("1st12", "south");
add_pre_exit_function("up","go_up");
add_pre_exit_function("south","go_south");
add_exit("hr2", "north");
add_pre_exit_function("north","go_north");
}

int pray_demon() {
    if(!this_player()->query_ghost()) {
	notify_fail("You are already alive.\n");
	return 0;
}
    this_player()->revive();
    this_player()->set_hp(10);
    this_player()->set_heart_beat(1);
    return 1;
}


int read_city_map() {
    this_player()->more("/wizards/hood/area/Shao_map");
    return 1;
}

int read_world_map() {
    this_player()->more("/wizards/mikus/world_map");
    return 1;
}

int read_world_map2() {
    this_player()->more("/wizards/mikus/world_map2");
    return 1;
}
void priest_move(){
switch(random(4)){
case 0:write("%^CYAN%^A robed figure moves "
"silently in the shadows and up the stairs...\n");
break;
case 1:write("%^CYAN%^A flash of "
"%^RESET%^%^BOLD%^%^YELLOW%^yellow light "
"%^RESET%^%^CYAN%^creeps down the stairs, then "
"fades...\n");
break;
case 2:write("%^CYAN%^A nearbye shadow "
"seems to change shapes, and move... it must be "
"your amagination.\n");
break;
case 3:write("%^CYAN%^A chilling breeze "
"blows across your body, almost as if it "
"traveled right through your soul...\n");
break;
}
remove_call_out("priest_move");
call_out("priest_move",50);
}
int go_north(){
remove_call_out("priest_move");
return 1;
}
int go_south(){
remove_call_out("priest_move");
return 1;
}
int go_up(){
remove_call_out("priest_move");
return 1;
}
