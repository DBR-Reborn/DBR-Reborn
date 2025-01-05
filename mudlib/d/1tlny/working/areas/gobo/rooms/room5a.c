// Area:  Gobo caves
// Coders: Amel and Arctic
// May, 97
// Room: room5a
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
  set_property("night light", 1); 
  set("short", "A small side passage.\n"); 
  set("long",
"This passage has walls that while narrow seems to have been widened by "
"a mining crew, it quickly opens up into small natural cave "
"stretching some twenty feet across.  At the far end is a pile of rags "
"and hay with a firepit nearby.  Directly behind that is what looks to be "
"a natural crevice in the wall." ); 
    set_items(([
({"rags","bedding","hay"}): "This is just a pile of bedding that is " 
"apparently used by the gobo that who stands watch here.",
({"pit","firepit"}):"A small circular firepit with burning embers glowing " 
"softly.", 
"crevice":"There appears to be movement in the shadows inside the crevice.", 
"cave":"The ceiling vaults to twelve feet or so here and the cave looks "
"quit spacious and livable."]) ); 
    set_exits((["southwest":"room5", "crevice":"room5b"])); 
    set_smell("default", "A cloud of smoke hangs in the air.\n"); 
    set_smell("crevice",
"You can smell the rotting flesh of the diseased coming from the " 
"crevice."); 
    set_listen("default",
"The crackling of embers and a soft moan reach your ears."); 
    set_listen("crevice","A soft moan is coming from the crevice."); 
 
    //set_search(({"pit"}),(:call_other,TO,"search_pit":)); 
    //set_search(({"bedding"}),(:call_other,TO,"search_bedding":)); 
}  

void reset()
{
  ::reset();
  if(!present("gobo_male"))
    new(GOBMONSTERS+"gobo_male")->move(TO);
}

void init() 
{
  ::init(); 
  add_action("take_gravel", "get");
}
 
int take_gravel(string str)
{
  if(!str || str != ("hay" ||"rags" || "bedding"))
    return 0;
   write(
"You try to pick up some of the rags and hay but it only falls apart.\n"); 
   say(TPQCN+
" tries to get some of the rags and hay but it just falls apart.\n"); 
   return 1; 
}
  
void search_pit()
{
  write(
"You poke through the embers in the fireplace but find nothing special.\n"); 
  say(TPQCN+" pokes through the coals in the fireplace.\n"); 
}  

void search_bedding()
{
  write(
"You search through the bedding but find only what civilized people prefer "
"to leave in the outhouse.\n"); 
  say(TPQCN+
" searchs through the bedding and finds a small surprise.\n"); 
}
