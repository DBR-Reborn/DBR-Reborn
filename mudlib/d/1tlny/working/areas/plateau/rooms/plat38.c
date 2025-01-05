
#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("outdoors", 1);
    set("short", "The Savanah Plateau");
   set_long( "\nYou are on a grassy plateau which stretches out in "
   "all directions. The ground seems to slant towards the middle of the "
   "plateau, and you can see off in the direction of the center, a dark tower."
    " The ground here is %^RED%^QUICKSAND!!!"
    );
    set_exits( ({  "plat47.c", "plat37.c", "plat39.c", "plat33.c" }),
      ({"north", "east", "west", "south" })
    );
   set_smell("default", "It smells like %^RED%^QUICKSAND!!!");
   set_listen("default", "It sounds like %^RED%^QUICKSAND!!!");
}

void init() {
  object player;
    int maxhp, strength, fly;
  ::init();
  player = this_player();
  maxhp = player -> query_max_hp();
  strength = player -> query_stats("strength");
   strength = strength / 8;
  call_out("falls", strength, ({maxhp, player}));
}

void falls(mixed *args){
  object player;
  int maxhp;

  maxhp = args[0];
  player = args[1];
    if(environment(player) == this_object()) {
    message("other action", player->query_cap_name() + "%^RED%^ sinks through the quicksand!!!", this_object(), player);
    message("other action", "%^RED%^You sink into the quicksand!!!", player);
   player->move_player(PLATROOMS + "prison.c");
}
}
