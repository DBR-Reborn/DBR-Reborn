//From: Gobos, A newbie area
//Created by: Amel and Arctic
//May 97 
//Room1b 

#include <dirs.h> 
#include <std.h>
#include <gobo.h>

inherit ROOM; 
  
void reset()
{
  ::reset();
  remove_exit("cave");
}

void create()
{
  ::create(); 
  set_property("indoors", 0);  /* outdoors */
  set_property("light", 0); 
  set("short","The canyon floor."); 
  set("day long",
"The narrow canyon suddenly opens up into a wide expanse of flat ground. "
"Looking up, the sides grow much steeper and the shadows much deeper. "
"You seem to be standing at the base of a large cauldron. The walls are " 
"steep but there are level grades that stretch around the sides of the "
"cliffs with various cave openings throughout. The nearest entrance is "
"straight to the north and partially covered with some dead brush."); 
  set("night long",
"You move into the darkness and find yourself even more cut off from "
"the light. The small gravel that crunches beneath your feet echoes "
"softly around the canyon and you can feel the pressing weight of darkness "
"about you. You can see a dim light coming from a small opening to the "
"north."); 
  set_items( ([ 
"caves":"There are several caves scattered around the canyoun at "
         "various heights. The closesest is at ground level.",
"brush":"The brush looks like an amateur attempt to camouflage the "
        "cave entrance.", 
"opening":"The opening is blocked by some brush."]));
  set_exits((["south":"room1a"])); 
  set_smell("default", 
"The smell of decaying trash and feces fills the air."); 
  set_listen("default", 
"Soft echos of a repeating sound reach your ear mixing with the huming "
"of small insects." ); 
  set_search("brush",(:call_other, this_object(), "search_brush":));  
}

void search_brush()
{
  write("You search the brush carefully and reveal the cave entrance.\n");
  say(this_player()->query_cap_name()+
      " searches the brush and reveals the cave entrance.\n");
  add_exit("room2","cave");
  return;
}
