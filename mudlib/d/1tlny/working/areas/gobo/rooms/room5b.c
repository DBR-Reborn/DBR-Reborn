// Area:  Gobo caves
// Coders: Amel and Arctic
// May, 97
// Room: 5b
  
#include <dirs.h>
#include <std.h>
#include <def.h>
#include <gobo.h> 

inherit ROOM;
int is_moss;

void create()
{
  ::create(); 
  set_property("indoors", 1); 
  set_property("light", -1); 
  set_property("night light", -1); 
  set("short", "Place of the damned.\n"); 
  set("long",
"The crevice here is only a few feet wide and you can hear gobos crying " 
"and moaning as you step on them in the darkness.  The walls are rough and "
"jagged and covered with some kind of moss."); 
  set_items(([({"walls","water","wall"}):
"The walls are natural here and some water is trickling down the cracks "
"and forming a tiny pool at the bottom.",
"pool":"This pool of water is collecting in a small pool at the base of "
"the wall and seems to be moving?",
"moss": "It looks like some kind of strange plant growth.. that is "
"flourescent."])); 
  set_exits((["out":"room5a"])); 
  set_smell("default", 
"The smell of disease and rotting gobos is almost overwelming here."); 
  set_listen("default",
"The soft moans of the sick and dying abound here."); 
}  

void reset()
{
  int counter; 
  ::reset(); 
  counter = 4; 
  is_moss = 1;
  remove_item("moss");
  add_item("moss",
"It looks like some kind of strange plant growth.. that is flourescent.\n");
  if(!present("gobo_femaled"))
  {
      while (counter > 0)
      {
         new(GOBMONSTERS+"gobo_femaled")->move(TO); 
         new(GOBMONSTERS+"gobo_childd")->move(TO); 
         counter--;
      }
  }
} 
  
void init() 
{
  ::init(); 
  add_action("get_moss", "gather"); 
  add_action("touch_moss","touch"); 
  add_action("touch_moss","feel"); 
  add_action("drink", "drink");
}  

int get_moss(string str)
{
object herb; 

  if(!str || str != "moss") {notify_fail("Gather what?\n"); return 0;}
  if(!is_moss)
  {
    write("You scrape at the wall trying to gather some moss but fail.\n");
    say(TPQCN+" scrapes at the wall trying to gather some moss.\n");
    return 1;
  }
  write(
"You scrape some of the moss off the wall and as it piles on the floor " 
"you see that it provides some with some light.\n"); 
  say(TPQCN+
" collects some moss from the wall, lighting the cave a bit more as the " 
"light spreads out.\n"); 
  new(GOBITEMS+"cave_moss")->move(TO)); 
  remove_item("moss"); 
  add_item("moss", 
"Remnants of a glowing moss can be seen on the walls. It looks like "
"someone has already gathered it.");
  return 1; 
}  

int touch_moss(string str)
{
  if(!str || str != "moss" || str != "wall") 
    return 0;
  write(
"You run your hand over the wall feeling the fuzziness of the moss and "
"the moisture on the rough rock.\n"); 
  say(TPQCN+" runs his hand down the wall.\n"); 
}

/*  
Need to add the filling part and a disease to anyone foolish enough to
drink from here. 
*/  
int drink(string str)
{
  if((!str) || (str != "pond") || (str != "water"))
    return 0; 

  write("You swallow a mouthful of the foul smelling water.\n"); 
  say(TPQCN+" swallows a mouthful of the foul smelling water.\n"); 
  return 1;  
}
