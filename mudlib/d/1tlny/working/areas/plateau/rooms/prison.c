
#include <std.h>
#include "/wizards/garetjax/plateau/defs.h"

inherit ROOM;
int counter;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Quicksand");
   set_long(
      "You are sinking in quicksand!!"
    );
  }


void init()    
{
  ::init();
  counter = 0;
  call_out("wait", 5, ({this_player(), counter}));  
}


void wait(mixed *args)   
{
  args[0] -> add_hp(-random(50));
  message("info", "%^RED%^ You sink through the quicksand!!!\n",args[0]); 
  args[1] += 1;
  if(args[1] == 6)
    call_out("getmeoutofhere", 5, args);
  else
    call_out("wait", 5, args);
}

void getmeoutofhere(mixed *args)  
{
    message("info", "%^RED%^ You sink all the way through the floating plateau, and fall to the earth below!!!!.", args[0], this_object());
   args[0] -> move_player(PLATROOMS + "entrance.c");
    args[0]->force_me("look");
}

