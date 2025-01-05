//From: Gobos, A newbie area
//Created by: Amel and Arctic
//May 97
//Room 3 
#include <std.h> 
#include <dirs.h>
#include <gobo.h>
  
inherit ROOM; 
  
int dice_present; 
  
void create()
{    
  ::create(); 
  set_no_clean(1);
  set_property("indoors", 1);  /* indoors */
  set_property("light", 0); 
  set("short","A small guard room."); 
  set("long",
"Entering a small cave you immediately notice a torch lighting the area and "
"the smoke that makes the room difficult to breathe in.  This looks like a "
"guard area in that there are 2 small wooden stools here and something "
"small in the corner.  A raggedy curtain hangs over a portion of the east " 
"wall and futher ahead you hear more noise coming from deeper in."); 
    set_items(([
"torch":"This is more of a burning piece of wood set in the " 
                "wall than what most people would call a torch.", 
"curtain":"A tattered cloak hangs across the cavern entrace to the east."]));
    set_exits((["north":"room4", "south":"room2", "east":"room3a"])); 
    set_smell("default", 
"The smell of smoke, trash, and feces wafts through the air."); 
    set_listen("default", 
"Soft muffled sounds seem to be coming from deeper in the cave." ); 
    set_search("corner",(:call_other, this_object(), "search_corner":)); 
    set_pre_exit_functions(({"east"}), ({"go_east"}));
    set_no_clean(1);
}  


int go_east()
{
  write("You push aside the curtain and head into the easter cave.\n");
  say(this_player()->query_cap_name() + 
  " pushes aside the curtain and heads into the easter cave.\n");
  return 1;
}


void reset() 
{
  ::reset(); 
  dice_present=1; 
  if(!present("goblin guard"))      
  {
    new(GOBMONSTERS + "gobo_male") -> move(this_object()); 
    new(GOBMONSTERS + "gobo_male") -> move(this_object()); 
  }
}  


void search_corner() 
{
//after the dice object is made need to add the obj generator here
//and invert the if statement
    
  if(!dice_present)
  {
    write("You search the floor and find a pair of dice that the guards "
          "use for gambling.\n"); 
    say(this_player()->query_cap_name()+
        " searches the floor and finds something.\n"); 
    new(GOBITEMS + "dice")->move(this_object());
    dice_present = 1;
  }else 
     write("You search the floor and find nothing. You must have been " 
           "tricked by the shadows.\n"); 
  return;
}

