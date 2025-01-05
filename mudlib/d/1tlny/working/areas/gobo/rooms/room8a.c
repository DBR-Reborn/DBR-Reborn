
  // Area:  Gobo caves
  // Coders: Amel and Arctic
  // May, 97
  // Room: room8a.c 
#include <dirs.h> 
#include <std.h> 
#include <def.h>
#include "../gobo.h"  

inherit "/d/areas/gobo/funs";
inherit ROOM; 

void create()
{
  ::create(); 
  set_property("indoors", 1); 
  set_property("light", 1); 
  set_property("night light", 0); 
  set("short", "A small cavern."); 
  set("long",
"You have steped into what looks to be a small oval shaped cavern "
"stretching some eighteen meters to the far side and ten meters at the " 
"widest point.  The room is being lit by some kind of flourescent moss "
"and there are a few broken stalagmites scattered about the room.  The "
"room seems remarkably uncluttered like the gobos that use this room have "
"nothing."); 
  set_items( (["shadows":
"Exploring the darkest portion of the cave you find what looks to be the "
"starting point of an underground spring.  The pond is only a few meters "
"across but you can see the water flowing under the wall to the east",
({"tables","stalagmites"}):"There are several scattered about, that "
"look to have been chiseled flat to make eating and working surfaces.",
({"wall","walls"}): "The stone here is solid and rough having never been "
"worked.", 
"ceiling":"The ceiling is only some eight meters overhead and slopes down " 
"towards back of the cavern."]) ); 
  set_exits((["south":GOBROOMS+"room8","pond":GOBROOMS+"room8b"])); 
  set_smell("default", "The air has a stale smell to it."); 
  set_listen("default",
"There is a soft bubbling sound coming from the shadows in the back of "
"the cavern."); 
}
  
void reset() 
{
int rand; 
  ::reset(); 
/* 
 if(!present("gobo_guarda")) new(GOBMONSTERS+"gobo_guarda")->move(TO); 
  if(!present("gobo_female")
  {
    rand = random(6)+1; 
    while(rand > 0)
    {
      new(GOBMONSTERS+"gobo_female")->move(TO); 
      new(GOBMONSTERS+"gobo_child")->move(TO); 
      new(GOBMONSTERS+"gobo_child")->move(TO); 
      rand--; 
    }
  }
*/
}
