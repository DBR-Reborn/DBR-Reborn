// The city Gate house
// Vishnu of Darkemud 071797

#include <std.h>
#include <vishnu.h>

inherit ROOM;

create() {
    	::create();
    	set_property("light",-1);
    	set_property("indoors", 1);
	set_property("city","Kelal");
	set("short", "City Gatehouse");
	set_door("gate", CITY+"gate_inside", "gate",
	    "gate inside");
	set_open("gate", 0);
	set_locked("gate", 1);
        set_lock_level("vault door", 25);
	set("long",
		"A giant stone wall surrounds this massive underground city. "
		"The ominous, black, iron gate before you is the single "
		"way to enter and exit the city. At each side of the gate stands "
		"a massive stone statue of a gargoyle.  The ground is wet, on this "
		"side of the gate, from the dripping cavern ceiling. You don't notice "
		"many travellers entering this city."
		);
	set_items(([ ({"walls", "wall"}) : "The limestone walls are slimy and wet.",
		({"gate", "gates", "door", "doors"}) : "The giant "+
			"door in front of you blocks your entry into the city.",
		"ceiling" : "The ceiling is covered with a spikey veil of stalactites."
			]));
	set_listen("default",
			"You hear the sounds of a bustling city, just beyond the gates."
		);
	add_exit("gate","gate_inside");
	add_exit("up",ROOMS+"e4");

}
void reset() {
	object ob;
	::reset();
	if(!present("statue")) {
	ob = new(CMISC+"statue.c")->move(this_object());
	ob->set("short","Left Gargoyle");
	ob = new(CMISC+"statue.c")->move(this_object());
	ob->set("short","Right Gargoyle");
	}
}
