#include <std.h>
#include <shao.h>

inherit ROOM;
void init(){
    ::init();
    add_action("kick_wall", "kick");
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("night light", 0);
    set("short", "alley");
    set("long","%^BOLD%^This alley isn't very well lit, "
      "but it is free from the usual garbage, crates, and boxes"
      " you usually find in the Shao-tan back alleys...\n"
      "It continues west, a street is to the east.\n"
      "Buildings of various size and quality suround "
      "this alley in all directions except west and east.\n");
    set_items( ([
	({"building","buildings"}):
	"Looking around you see four of them...\n"+
	"One small wooden building, one medium sized "+
	"wooden buildings, and two larger building to the "+
"north and northwest that look to be made of stone.\n",
	({"wooden buildings","small buildings",
	  "small wooden buildings","wood building","small building"
	  ,"small wooden building"}):
	"The wood buildings appeer to be the homes of "
	"citizens...\n",
	({"medium building","stone building","medium stone building"}):
"they look very sturdy.\n"
      ]) );
    add_exit("al2", "west");
    add_exit("1st5", "east");

    set_smell("default","A musty, almost sweaty aroma lingers"
      "in the air.\n");
    set_listen("default","muffled sounds of music can just "
      "barely be heard...\n");
}
