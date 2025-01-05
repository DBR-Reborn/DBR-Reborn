//Room1 of Gobo area
//Created by Arctic and Amel
//May 97
#include <dirs.h> 
#include <std.h> 
#include <gobo.h>

inherit ROOM;  

int number_of_rats; 
void create()
{
  ::create();
  set_property("indoors", 0);  /* outdoors */
  set_property("light", 1); 
  set("short","A wide canyon."); 
  set("day long",
"You enter a pass between two small hills and watch the surounding "
"mountains seem to grow much closer than you remember when you first " 
"started out.  Perhaps coming this way wasn't such a good idea after " 
"all.  The ground grows rocky beneath your feet and the only animal "  
"life seems to be small rodents that scurry about in the shadows. " 
"There is a clear path that heads north further into the hills and "
"the vague tracks that run in both directions indicate that the "
"inhabitants are humanoid."); 
  set("night long",
"You wander into a dark valley with two huge shadows rising up on "
"either side of you.  The night air not only carries the stench of "
"rotting flesh and feces but the sounds of movement and small rocks "
"falling drift to your ears."); 
  set_items( ([ 
"tracks": "The tracks look old and faded but it doesn't look like "
"anything to big made them.", 
"hill":"The green hills rise up a few hundred feet though you do notice " 
"some brown and red patches scattered about them.", 
"shadows":"The shadows are cast by small overhangings and a few "
"boulders that seem to have rolled to the base of the hills.", 
"rodents":"These seem to be rats, small but vicious they are a "
"bit bigger than the city versions.",
({"boulder","boulders"}): "A typical small boulder lies amongst the "
"rubble."]) ); 
  set_exits((["north": "room1a"])); 
  set_smell("default", 
"The smell of decaying trash mixed with grass fills the air."); 
  set_listen("default", 
"The soft scratching noises of rodents and the buzz of insects echos to " 
"your ears" ); 
  set_search("boulder", (:call_other,this_object(), "search_boulder" :)); 
}

void reset()
{
  ::reset();
  number_of_rats = 5;
}
 
void search_boulder()
{
  int number_of_rats_found;
  object mon; 
  number_of_rats_found = random(6); 
  if (number_of_rats_found > number_of_rats)
    number_of_rats_found=number_of_rats; 
  if(number_of_rats_found == 0)
  {
    write("You search the boulders and find only a few rat droppings."); 
    say(this_player()->query_cap_name()+" searches the boulders."); 
  }else if(number_of_rats_found == 1)
  {
    write("You search the boulders and an angry rat scuries out."); 
    say(this_player()->query_cap_name()+ 
" searches the boulders and an angry rat scuries out."); 
  }else
  {
    write("You search the boulders and some angry rats scury out."); 
    say(this_player()->query_cap_name()+ 
" searches the boulders and some angry rats scury out."); 
  }
  number_of_rats -= number_of_rats_found;
  
  while(number_of_rats_found > 0)
  { 
    mon = new(GOBMONSTERS + "rat");
    mon->move(this_object()); 
    number_of_rats_found--; 
  }  
  return; 
}
