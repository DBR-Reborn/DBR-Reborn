//Wizard : Hood
// File : Sgate2.c
// South-Gate guard post of Shao-tan

#include <shao.h>

inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
set_property("indoors", 1);
set("short", "Guard Post");
set("night long", "%^BOLD%^The guards post feels like a small "
"fortress. It appears that a large solid rock was butted up "
"against the city wall and this room was carved into it. "
"The two walls facing south and east only stand about four "
"feet high. Rusted Iron bars stretch up the rest of the way "
"and into the ceiling.  Providing a clear view of the area to "
"the east, south and southeast.\n");
set("day long", "The thick stone walls and roof keep this "
"guard post cool in the days hot sun. Through the iron bars"
" you notice the city gate of Shao-tan has been "
"opened for the daily "
"trafic of citizens and vistors that leave and enter "
"the city via the south entrance.  Another guard gate is "
"seen on the east side of the city entrance.  Looking "
"behind you, you spot a worn and well hidden ladder.\n");
set_exits( ({ "s_entrance", "wall1"}),
({"east", "ladder"}) );
add_pre_exit_function("ladder", "go_ladder");
  set_items( ([
"walls" : "The walls are bone chilling, a thin layer of ice has"
" formed and blankets them from top to bottom.\n",
"hatch" : "The laen hatch appears very strong...\n",
  ]) );
set_listen("default", "The footsteps of the ocasional guard "
"are heard walking across the wooden foot bridge overhead.\n");
}
int go_ladder(){
write("You boldly climb the old ladder.\n");
tell_room("/wizards/hood/area/room/wall1",
this_player()->query_cap_name()+" steps off a ladder.\n");
return 1;
}


