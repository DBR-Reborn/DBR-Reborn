#include <std.h>

inherit ROOM;


void create() {
	::create();
	set_property("outdoors", 1);
	set("short", "A vast plains.");
	set_property("light", 3);
	set("long", "As you walk north on the dirt path of stone and gravel, you notice the serenity of this area.  The ground is covered with rich, lush grass, spooted with flowers of every kind.  on the side of the road there is a sign, which is also cover in moss.");
	set_exits(
	({//"/wizards/blial/workroom.c",
    "/d/damned/virtual/room_43_10.world",
	"plains2.c"
	})
	,({//"chambers",
"exit", 
"north"}));
	set_item_descriptions( ({"sign"}), ({"Kislev, north 5 miles."}) );
	set_smell("default", "The air smells brisk and clean.");
	set_listen("default", "It is quiet, not a sound can be heard.");
}
