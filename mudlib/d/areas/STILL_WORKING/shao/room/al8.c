#include <std.h>
#include <shao.h>

inherit ROOM;
int k_counter;
int searched;
void init(){
    ::init();
    add_action("kick_wall", "kick");
    add_action("the_hole", "enter");
add_action("look_wall", "look");
add_action("search_wall", "search");
}

void reset() {
    ::reset();
k_counter = 0;
    remove_item("hole");
searched = 0;
remove_item("pipe");
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("night light", 0);
    set("short", "alley");
    set("long", "%^BOLD%^Garbage and old crates clutter "
      "the narrow alley, and make passage difficult.\n"
      "The alley continues north, south and east into darkness.  "
"Large stone walls tower over you to the east and west, the "
"eastern wall seems somehow familar...\n");
    add_exit("nr4", "north");
    add_exit("al7", "south");
set_items(([
({"wall", "walls" }) : 
"There are two of them, a western wall, and eastern wall."
,({"western wall", "west wall"}):
"It looks like the back side of the Shao-tan bar and Inn.\n"
]));

    set_smell("default", "The smell of piss and garbage is overwhelming.\n");
}
int kick_wall(string str) {
    if(str == "wall" || str == "stone wall" || str == "
eastern wall" ) {
if(k_counter = 0) {
	    write("You kick the wall as hard as you can and almost "
	      "break your foot, but a small crack forms...");
k_counter = 1;
	    return 1;
	}
	write("You kick the wall and some weak stones crumble under "
	  "your blow...\n"
	  "A small hole in the wall has been formed.\n");
	add_item("hole", "It looks like you could enter the building "
"through it.\n");
k_counter = 2;
	return 1;
    }
    notify_fail("You kick your dumb ass and wonder '"
      "wtf do I want to kick'\n");
    return 0;
}
int the_hole(string str){
    if(str == "hole") {
	write("You climb through the hole in the wall.");
	tell_room( this_object(), this_player()->cap_name()+"
climbs through a hole in the wall.", ({ this_player() }) );
	this_player()->move_player("nr1");
	return 1;
    }
    notify_fail("Enter WHAT fool?\n");
    return 0;
}
int look_wall(string str) {
if(str == "eastern wall") {
if(k_counter = 0) {
write("The old brick wall seems weaker then you'd expect "
"a jail wall to be.\n");
return 1;
}
if(k_counter = 1) {
write("The old brick wall seems to be cracked...\n");
write("blah fucking reboot");
return 1;
}
if(!str) {
notify_fail("You look at nothing in particular");
return 0;
}
}
}
