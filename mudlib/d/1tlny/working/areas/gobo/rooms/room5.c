// Area:  Gobo cave
// Coders: Amel and Arctic
// May, 97
// Room: room5.c
  
#include <dirs.h>
#include <std.h>
#include <def.h>
#include <gobo.h>

inherit ROOM;
  
void create()
{
  ::create(); 
  set_property("indoors", 1); 
  set_property("light", 1); 
  set_property("night light", 0); 
  set("short", "A small underground juncture.\n"); 
  set("long",
"You trudge through the cave and find the walls open into a small " 
"juncture.  The main, if you could call it that, passage continues "
"north deeper in to the complex and a narrow passage runs off to the north "
"east.  The floor has a little gravel on it and crunches under your feet. "
"The walls appear to have been chiseled on a bit to make passage easier to "
"traverse."); 
    set_items(([
({"wall","walls"}): "The walls are solid stone slightly smoother than " 
"other areas.", 
({"floor","gravel"}):"The floor is covered with a thin layer of gravel " 
"apparently from the work of the chiseling.",
"passage":"The passage travels some distance and there is dim light "
"coming from it."])); 
    set_exits((["northeast":"room5a","south":"room4","north":"room6"])); 
    set_smell("default", 
"The smoke of burning wet wood hangs in the air.\n"); 
    set_listen("default",
"Soft rumbling sounds and the occasional faint echo of a ringing sound "
"reach your ears."); 
  set_listen("passage","A soft moan comes from the passage.\n"); 
}  

void init()
{
  ::init(); 
  add_action("take_gravel", "get"); 
}  

int take_gravel(string str)
{
  if(!str || str != "gravel") 
    return 0;
  write("You pick up a handful of gravel and seeing that it is quite " 
        "ordinary toss it to the side.\n"); 
  say(TPQN+" picks up some gravel and after examining it tosses it to "
      "the side\n"); 
  return 1;
}  

void reset() 
{
  ::reset(); 
  if(!present("gobo_male") && (random(10) == 1))
    new(GOBMONSTERS+"gobo_malea")->move(TO);
}
