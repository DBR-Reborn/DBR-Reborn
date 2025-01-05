#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit ROOM;

void init() {
  ::init();
   add_action("jump", "jump");
}

int jump(string str)  {
   if(str = str) {
   object player;
   int maxhp;
   player = this_player();
   maxhp = player -> query_max_hp();
   player -> move(PLATROOMS + "entrance.c");
   if(player -> query_flying() == 0)  {
   message("other action", "%^RED%^You take a suicidal leap off the edge, and fall to the ground!!!", player, this_object());
   message("other action", player -> query_cap_name() + "%^RED%^ takes a suicidal leap off the edge of the cliff!!!", this_object(), player);
   player -> add_hp( -((maxhp / 2) + random(50)));
   message("other action", player -> query_cap_name() + "%^RED%^ falls from above and lands at your feet in a pile with a sickening crunch.", PLATROOMS + "entrance.c", this_player());
     player->force_me("look");
}
   else {
   message("other action", player -> query_cap_name() + " jumps off the edge, and flies down to the earth.", this_object(), player);
   message("other action", "You jump off and fly down to the ground.", player, this_object());
   message("other action", player -> query_cap_name() + " floats gently down from above.", PLATROOMS + "entrance.c", this_player());
   player->force_me("look");
   return 1;
}}
}

