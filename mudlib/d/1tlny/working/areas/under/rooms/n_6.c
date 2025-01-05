#include <std.h>

inherit ROOM;

int search_count;
void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	search_count = 0;
	set_short("Moss filled room");
	set_long("This room is a pretty good sized room except that half of it is covered with moss and wet plants.");
	set_items(([
	"moss" : "The moss is so dense that it seems to cover the entire room",
	"plants" : "These plants seem to survive without sunlight here.",
	"water" : "Lots of water seems to pour down into this room.",
	]));
	set_listen("default", 
	"You can hear the sound of rushing water."
	);
	set_smell("default",
	"It smell like rotten vegetables in here."
	);
	set_exits( ({
	"/wizards/blial/under/rooms/n_5",
	}),({
	"south"
	}));
	set_search("moss", (: call_other, this_object(), "do_search" :));
}


void do_search(){
	int skill;
	object ob;
say(this_player()->query_cap_name()+" appears to be searching the moss.");
	skill=((int)this_player()->query_skill("perception"))-50;
	if((random(100)<skill) && search_count<1){
	search_count = 1;
	write("Your search is successful.\n"+
	"You found a ring!\n");
	ob = new("/wizards/blial/under/items/aqua_ring");
	ob->move(this_object());
	return 0;
}
	else{
	write("Your search yields nothing.");
return;
}
}
