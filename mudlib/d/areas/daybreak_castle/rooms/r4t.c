#include <std.h>
#include "../a1.h"


inherit "std/room";

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 3);

add_exit(PATH+"r3.c", "south");
add_exit(PATH+"r5.c", "southwest");
add_exit(PATH+"r6.c", "west");
add_exit(PATH+"r7.c", "northwest");
add_exit(PATH+"r8.c", "north");
add_exit(PATH+"r9.c", "northeast");
add_exit(PATH+"r10.c", "east");
add_exit(PATH+"r11.c", "southeast");
//Basic mapping added by Tiny 1/19/2020 

}

void reset(){
object h_rune;
  ::reset();
    
    //HONSPRON 2020 - added a healing rune
    if (!present("rune")) {
	h_rune = new ("/std/diewarzau/obj/misc/h_rune");
		h_rune->move(this_object());
	}
}