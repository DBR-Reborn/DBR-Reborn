// Wizard : Hood
// file: jail.c
// Shao-tan Jail 
#include <shao.h>

inherit VAULT;

int searched;
int removed;
int opened;

void init(){
::init();
add_action("s_desk","search");
add_action("stand_on","stand");
add_action("peer_window","peer");
}

void reset(){
::reset();
searched = 0;
removed = 0;
opened = 0;
}

void create(){
::create();
set_property("indoors", 1);
set_property("light", 2);
set("short", "Shao-tan jail");
set("day long", "Day light shines through the barred window, "
"and makes sleep imposible for any occupants of the jail cells "
"across from it.  "
"The solid stone walls are decorated with various shields and "
"weapons taken off a few notorious criminals that have been "
"put in the jail over the years.  "

"A large oak desk sits beside the heavy iron door that "
"leads to the jail cells.\n");
set("night long", "A few lanterns hang from the stone "
"walls, shedding a soft light throughout the room.  "
"A barred window on the north wall provides the only "
"view of the dark night outside.  A large oak desk sits "
"to the left of a solid looking iron door on the "
"south side of the room.\n");
set_items(([
({"lantern", "lanterns"}):
"Brass oil filled lanterns, wich can improve vision on "
"even the darkest of nights.\n",
({"wall", "walls","stone wall","stone walls"}):
"The walls look very thick and very sturdy...\n"
"various shields and weapons decorate the top portions of "
"them.\n",
({"shields", "weapons","shield","weapon"}):
"A few pieces of equipment that catch your eye are:\n"
"a rather odd looking shield with the symbol of a stone wolf"
" and the letters word Fireknife embeded into it..."
"an unholy looking black dagger with a pure white bone hilt..."
"and an ancient mithril flail that looks to be in mint condition.\n",
({"desk","oak desk","large desk","large oak destk"}):
"A large desk with lots of papers and scrolls cluttering "
"the top...\n"
"The desk itself appears to have a drawer.\n",
({"window","barred window"}):
"The window looks out onto Northern Row...\n",
({"door","iron door"}):
"A large and sturdy door iron-barred door stands to the right of "
"the desk, and another door is on the east wall.\n"
]));
set_smell("default","An oddly pleasant aroma of lantern oil and oak"
" wood lingers in the air.\n");
add_exit("1st11", "east");
set_door("iron door",PATH+"1st11","east",0);
add_exit("jail_cells", "south");
}
int s_desk(string str){
if(str == "desk" || str == "oak desk"){
if(!searched){
write("You search the papers and scrolls on the desk, "
"but dun find a dam thing, and prolly won't...");
searched++;
return 1;
}
notify_fail("You search that empty hole between yer ears"
" and finaly think : 'WTF do I want to search????'\n");
return 0;
}
}
