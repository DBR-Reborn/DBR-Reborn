#include <std.h>
#include "../chaos.h"

inherit ROOM;

void create() {
	::create();
	set("short", "A room");
	set_property("indoors", 2);
	set_smell("default", "The air is permeated by soot and the smell of charcoal.");
}
void reset(){
	::reset();
	if(!present("torch")) {
/*	
new("/wizards/blial/stuff/worldmap.c")->move(this_object());
	new("/wizards/blial/stuff/worldmap.c")->move(this_object());
	new("/wizards/blial/stuff/worldmap.c")->move(this_object());
	new("/wizards/blial/stuff/worldmap.c")->move(this_object());
	new("/wizards/blial/stuff/worldmap.c")->move(this_object());
	new("/wizards/blial/stuff/worldmap.c")->move(this_object());
	new("/wizards/blial/stuff/worldmap.c")->move(this_object());
	new("/wizards/blial/stuff/worldmap.c")->move(this_object());
	new("/wizards/blial/stuff/worldmap.c")->move(this_object());
	new("/wizards/blial/stuff/worldmap.c")->move(this_object());
*/
	new(OBJ+"bear.c")->move(this_object());
	new(OBJ+"bear.c")->move(this_object());
	new(OBJ+"bear.c")->move(this_object());
	new(OBJ+"bear.c")->move(this_object());
	new(OBJ+"bear.c")->move(this_object());
	new(OBJ+"bear.c")->move(this_object());
	new(OBJ+"bear.c")->move(this_object());
	new(OBJ+"bear.c")->move(this_object());
	new(OBJ+"bear.c")->move(this_object());
	new(OBJ+"bear.c")->move(this_object());
/*
	new("/wizards/blial/stuff/worldmap.c")->move(this_object());
	new("/wizards/blial/stuff/worldmap.c")->move(this_object());
	new("/wizards/blial/stuff/worldmap.c")->move(this_object());
	new("/wizards/blial/stuff/worldmap.c")->move(this_object());
*/
	new("/std/obj/torch.c")->move(this_object());
	new("/std/obj/torch.c")->move(this_object());
	new("/std/obj/torch.c")->move(this_object());
	new("/std/obj/torch.c")->move(this_object());
	new("/std/obj/torch.c")->move(this_object());
	new("/std/obj/torch.c")->move(this_object());
	new("/std/obj/torch.c")->move(this_object());
	new("/std/obj/torch.c")->move(this_object());
	new("/std/obj/torch.c")->move(this_object());
	new("/std/obj/torch.c")->move(this_object());
	new("/std/obj/torch.c")->move(this_object());
	new("/std/obj/torch.c")->move(this_object());
    }
}
