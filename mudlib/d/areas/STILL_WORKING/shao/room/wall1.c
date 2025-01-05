//Wizard : Hood
// file : wall1.c
// Wall paths surounding Shao-tan... bah so I can't spell

#include <shao.h>

inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
set_property("outdoors", 1);
set("short", "stone wall");
set("day long","%^RESET%^%^ORANGE%^The wooden walk-way "
"you stand on"
" is very high, allowing the guards that patrol it "
"a clear view of the city directly north, and also "
" looking over the wall you amagine "
"you would be able to spot anyone trying to attack "
"the city from the south.\n");
set("night long", "%^BOLD%^You have an odd sense of floating.\n"
"The cold stones of the city wall brush against your "
"sides as you stand on the wooden walk-way.  "
"Other then the faint glow of lanterns from the city "
"it is completely dark.\n");
set_exits( ({ "Sgate2", 
//"wall2", 
"cw1"}),
({"ladder", 
//"east", 
"west"}) );
  set_items( ([
"walls" : "The walls are bone chilling, a thin layer of ice has"
" formed and blankets them from top to bottom.\n",
"hatch" : "The laen hatch appears very strong...\n",
  ]) );
set_listen("default", "The footsteps of the ocasional guard "
"are heard walking across the wooden foot bridge overhead.\n");
}


