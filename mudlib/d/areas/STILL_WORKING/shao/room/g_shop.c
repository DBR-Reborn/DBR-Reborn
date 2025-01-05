#include <shao.h>
#include <std.h>
inherit "/std/vault";


void reset() {
    ::reset();
    seteuid(getuid());
    if (!present("slim")) {
	new("/d/damned/akkad/obj/mon/slim")->move(this_object());
    }
    if(query_night()){
	if(!present("guard")){
	    new(MON_PATH+"m_guard")->
	    move(this_object());
	    move(this_object());
	}
    }
}

void create() {
    ::create();
    set_property("indoors",1);
    set_property("light",3);
    add_exit(PATH+"sr6","north");
    add_exit(PATH+"g_store","east");
add_exit(PATH+"1st6","west");
    set_door("iron door", PATH+"g_store","east",
      "g store");
    set_open("iron door", 0);
    set_locked("iron door", 1);
    set_lock_level("iron door", 22);
    set("short","The Adventurer's General Store");
    set("long",
      "General type store and shit.... Don't use it... its not done."
      "\n");
    set_items( (["sign":"The say reads: 'say slim, help' for assistance.",
	"iron door" : "It looks very sturdy.",
	"door" : "It is a large iron door."]) );
}

