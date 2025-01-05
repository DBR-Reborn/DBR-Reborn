#include <std.h>
#include <shao.h>

inherit ROOM;
int kicked;
void init(){
    ::init();
    add_action("kick_wall", "kick");
}

void reset() {
    ::reset();
    kicked = 0;
    remove_item("hole");
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("night light", 0);
    set("short", "alley");
    set("long", "%^BOLD%^Garbage and old crates clutter "
      "the narrow alley, and make passage difficult.\n"
      "The alley continues north, south and east into darkness.  "
      "A stone wall towers over you to the west...\n");
add_exit("nr4", "north");
add_exit("al7", "south");

    set_smell("default", "The smell of piss and garbage is overwhelming.\n");
}
int kick_wall(string str) {
    if(str == "wall" || str == "stone wall" || str == "
north wall" ) {
	if(!kicked){
	    write("You kick the wall as hard as you can and almost "
"break your foot...");
this_player()->add_hp(-50);
	    kicked++;
	    return 1;
	}
	write("You kick the wall and some weak stones crumble under "
	  "your blow...\n"
	  "A small hole in the wall has been formed.\n");

	add_item("hole", "It looks like you could enter the building "
	  "threw it.\n");
	return 1;
    }
    notify_fail("You kick your dumb ass and wonder '"
"wtf do I want to kick?'\n");
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
