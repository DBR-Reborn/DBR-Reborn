// Wizard : Hood
// file: jail.c
// Shao-tan Jail 
#include <shao.h>

inherit VAULT;


void init(){
::init();
}

void reset(){
::reset();
}

void create(){
::create();
set_property("indoors", 1);
set_property("light", 2);
set("short", "Shao-tan jail");
set("long","The room in which you now stand "+
"can only be comparable to a dungeon.\n"+
"The flat stone floor is cool benieth your feet."+
" Everything in this room looks like its made "+
"from either solid rock or iron. "+
"The walls are made of large stones, and the numer"
"ous doors leading off from this room look like they "
"are made from iron. Not a single decoration "
"or ounce of colour can be found in here. "+
"Everything is mad from grey rocks or black iron.\n");

set_items(([
({"flat stone","floor","stone floor"}):
"The floor is constructed with HUGE flat slates "+
"of stone. "
"instead of grout, thick iron bars that have been "
"bolted to the stones has been used to "
"fill the gaps.\n",
({"stones", "stone"}):
"The walls and floor are made from stones",
({"large stones","walls","wall","stone wall"}):
"The walls are made from huge stones that "
"would appear to be at least a foot thick "
"judging from the areas where the walls have "
"been cut to make way for doors.\n",
({"door","doors"}):
"There are quite a few doors in this room. "
"The vault doors lead to cells, and you guess "
"that the two iron doors lead to the front of "
"the jail and to the warden's office.\n",
({"ceiling","roof"}):
"The ceiling looks like it was made almost exactly "+
"the same way the floor was built. Except that "
"as an added feature the ceiling is supported by "
"large, thick iron beems.\n",
]));

add_exit("cell1","cell1");
set_door("cell1 vault door",PATH+"cell1","cell1","cell_key");
set_open("cell1 vault door",0);
set_locked("cell1 vault door",1);

add_exit("cell2","cell2");
set_door("cell2 vault door",PATH+"cell2","cell2","cell_key");
set_open("cell2 vault door",0);
set_locked("cell2 vault door",1);

add_exit("cell3","cell3");
set_door("cell3 vault door",PATH+"cell3","cell3","cell_key");
set_open("cell3 vault door",0);
set_locked("cell3 vault door",1);

add_exit("cell4","cell4");
set_door("cell4 vault door",PATH+"cell4","cell4","cell_key");
set_open("cell4 vault door",0);
set_locked("cell4 vault door",1);

add_exit("cell5","cell5");
set_door("cell5 vault door",PATH+"cell5","cell5","cell_key");
set_open("cell5 vault door",0);
set_locked("cell5 vault door",1);

add_exit("cell6","cell6");
set_door("cell6 vault door",PATH+"cell6","cell6","cell_key");
set_open("cell6 vault door",0);
set_locked("cell6 vault door",1);

add_exit("jail", "north");
set_door("iron door",PATH+"jail","north","shao_jail_key");

add_exit("ward_office","west");
set_door("iron door",PATH+"ward_office","west","shao_jail_key");
}
