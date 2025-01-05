 //From: Gobos, A newbie area
 //Created by: Amel and Arctic
 //May 97
 //Room 2 
#include <std.h>
#include <dirs.h>
#include <gobo.h>
  
inherit ROOM; 
inherit "/d/areas/gobo/funs";
int room_trap; 
  
void create()
{    
  ::create(); 
  set_property("indoors", 1);  /* indoors */
  set_property("light", 0); 
  set("short","A cave entrance."); 
  set("long",
"Having entered the mouth of the cave you immedieately notice the "
"dampness and the slight rise in temperature.  The walls are rough and "
"unhewn and the floor has a dark shadow cast over it. You can see that the "
"tracks that have been with you up to now disapear here.  Some light "
"enters the room from further ahead but it is diffused and seems to be "
"coming in from the edges of the cave."); 
    set_items(([
"floor":"There is a slight slope downward and there are lines in "
         "the dirt running north-south."])); 
  set_exits((["north":"room3", "south":"room1b"])); 
  set_smell("default", 
"The smell of smoke, trash, and feces wafts through the air."); 
  set_listen("default", 
"Soft muffled sounds seem to be coming from deeper in the cave." ); 
  set_search("floor",(:call_other,this_object(),"search_floor":)); 
  set_pre_exit_functions(({"north"}),({"go_north"})); 
}
 
void init()
{
  ::init();
  add_action("collapse","collapse"); 
}  

int collapse(string str)
{
  if(!str || str != "trap" || str != "pit")
  { 
     write("Collapse what?");
     return 1;
  }else if (room_trap)
  {
    write(
"You force the boards and dirt to fall to the bottom of the pit.. nicely "
"done."); 
    say(this_player()->query_cap_name()+
        " wrecks the trap by collapsing it."); 
    remove_item("floor");
    add_item("floor", 
    "The floor has collapsed in the middle. It looks like a trap has "
    "been sprung.");
    room_trap = 0; 
  }else 
    write("The pit has already been exposed.");
  return 1;
}
    
void reset()
{ 
  ::reset();
  room_trap=1; 
  remove_item("floor");
  add_item("floor", 
  "There is a slight slope running downward and there are lines in the "
  "dirt running north and south.");
}  

void search_floor()
{
  if(room_trap)
  {
    write(
"You search the floor and find a primitive deadfall trap it is easy to "
"collapse and get around.\n"); 
    say(this_player()->query_cap_name()+
" searches the floor and finds a pit, it will be easy to collapse and "
"get around\n"); 
  }else 
  {
    write("The floor trap has already been collapsed.\n");  
    say(this_player()->query_cap_name()+" searches the floor.");
  }
}
  
int go_north()
{
int fuckem;
  if(room_trap) 
  {
    fuckem = gen_rand_damage(20);
    write("%^YELLOW%^You fall into a %^RED%^Pit%^YELLOW%^ as the floor "
          "gives way!!!%^RESET%^\n");
    say("%^YELLOW%^"+ this_player()->query_cap_name()+
" %^YELLOW%^falls into a %^RED%^Pit%^YELLOW%^ as the floor "
"gives way!!!%^RESET%^\n"); 
    this_player()->add_hp(fuckem); 
    remove_item("floor");
    add_item("floor", 
    "The floor has collapsed in the middle. It looks like a trap has "
    "been sprung.");
    room_trap = 0; 
    return 0; 
  }else
  { 
    write("You skirt the edge of the pit as you head north.\n");
    say(this_player()->query_cap_name()+
       " skirts the edge of the pit as they head north.\n"); 
    return 1; 
  }
}
