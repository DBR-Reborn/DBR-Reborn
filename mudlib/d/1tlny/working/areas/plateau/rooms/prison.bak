
#include <std.h>
#include "/wizards/garetjax/plateau/defs.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "Quicksand");
   set_long(
      "You are sinking in quicksand!!"
    );
  }


 void init()    {
    int time, i;
     ::init();
    time = 5;
    for(i=0;i<6;i++)  {    
      call_out("wait", time, this_player());
      time =  time + 5;
}
   call_out("getmeoutofhere", 35, this_player());
}

  void wait(object player)   {
     player->add_hp(-random(50));
     message("other action", "%^RED%^ You sink through the quicksand!!!\n", player, this_object());
}

  void getmeoutofhere(object player)  {
   player->move_player(PLATROOMS + "entrance.c");
}

