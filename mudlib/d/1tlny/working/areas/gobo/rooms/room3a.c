//From: Gobos, A newbie area
//Created by: Amel and Arctic
//May 97
//Room 3.a 
#include <dirs.h> 
#include <std.h>
#include <gobo.h>
#include <def.h>
  
inherit ROOM; 
int rack_smashed; 
  
void create()
{
  ::create(); 
  set_property("indoors", 1);  /* indoors */
  set_property("light", 0); 
  set("short","A small guard room."); 
  set("long",
"Entering the small side cave you can see how seriously the gobo guards "
"take there job here.  The room is dimly lit from a small fire in the "
"center of the room and is thick with smoke.  A mess of trash is "
"scattered about and a pile of rags has been tossed in the corner.  " 
"Food is rotting on the floor.. but it appears the guards have been " 
"eating it anyway.  A small wooden rack is bolted to the eastern wall "
"and rust can be seen on it and the ground below.\n"); 
  set_items( ([ 
"rags":"These rags look to be several years old and stink like they have " 
"never been washed in all that time.",
"food":"The pile of what looks to be some kind of meat is totally lacking "
"in nutrition except to the flies that cover it.", 
"rack":"This looks to be an old weapons rack of some kind and is made quite " 
"shodily. The bolts that hold it to the wall are rusted and it looks "
"like it could be easily smashed."])); 
  set_exits((["west":"room3"])); 
  set_smell("default", 
"The smell of smoke, trash, and feces wafts through the air."); 
    set_listen("default", 
"Soft muffled sounds seem to be coming from the west."); 
}  

void init()
{ 
  ::init(); 
  add_action("smash","smash"); 
}  

int smash(string str)
{ 
  if(!str || str != "rack") 
  { 
    write("You want to smash what?\n"); 
    return 1; 
  }    
  if(rack_smashed)
  { 
    write(
"The wood chips fly as you smash the weapons rack into bits and pieces.\n"); 
    say(this_player()->query_cap_name()+
" flies into a rage smashing the weapons rack in several pieces.\n"); 
    remove_item("rack"); 
    add_item("rack",
"The weapon rack has been smashed into several pieces which lie scattered " 
"about the room."); 
    rack_smashed = 0; 
  }else 
    write("The rack has already been smashed");
  return 1;
}
  

void reset()
{
object mon;
  ::reset(); 
  rack_smashed = 1; 
  remove_item("rack"); 
  add_item("rack",
"This looks to be an old weapons rack of some kind and is made quite " 
"shodily.  The bolts that hold it to the wall are rusted and it looks "
"like it could be easily smashed."); 
  if(!present("gobo_guard"))
  {
    mon = new(GOBMONSTERS+"gobo_guard");
    mon -> move(TO);
    mon = new(GOBMONSTERS+"gobo_guard");
    mon -> move(TO);
    mon = new(GOBMONSTERS+"gobo_male");
    mon -> move(TO);
  }     
}
