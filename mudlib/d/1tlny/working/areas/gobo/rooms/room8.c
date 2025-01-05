// Area:  Gobo caves
// Coders: Amel and Arctic
// May, 97
// Room: room7.c 
#include <dirs.h> 
#include <std.h> 
#include <def.h>
#include "../gobo.h"  

inherit ROOM; 
inherit "/d/areas/gobo/funs";
  
void create(){
  ::create(); 
  set_property("indoors", 1); 
  set_property("light", 1); 
  set_property("night light", 0);  
  set("short", "A medium size cavern.");  
  set("long",
"You have stepped into what looks to be a medium size cavern stretching " 
"some fifty meters to the far side.  There are a number of broken " 
"stalagmites that seem to be serving as tables to the large crowd of " 
"gobos that live here.  The smoke here is slowly rising to the ceiling "
"and the air seems quite warm."); 
  set_items(([
({"tables","stalagmites"}):"There are several scattered about, some quite "
"large that have been chiseled flat to make eating and working surfaces.",
({"wall","walls"}):"The stone here is solid and rough having never been "
"worked.", 
"ceiling":"The true height of the ceiling can't be determined as it is "
"dark and cluttered with stalagtites."]) ); 
  set_exits((["north":"room8a","south":GOBROOMS+"room6",
              "east":GOBROOMS+"room9","west":GOBROOMS+"room10"]));  
  set_smell("default", "The smell of cooked flesh is quite strong here.");  
  set_listen("default","There is an incessant muttering and grunting from " 
"the inhabitants of nearby caverns filtering in."); 
}  

void reset() 
{
  int rand; 
  ::reset(); 
  rand = random(10) + 1;  
/*
  if( (rand == 10) && (!present("gobo_guarda")))
    new(GOBMONSTERS+"gobo_guarda")->move(TO);  
  if(!present("gobo_male"))
    while(rand > 0)
    {
      new(GOBMONSTERS+"gobo_male")->move(TO); 
      rand--; 
    }
*/
}
