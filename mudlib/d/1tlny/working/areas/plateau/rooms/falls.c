#include <std.h>
#include </wizards/garetjax/plateau/defs.h>

inherit ROOM;

void init() {
  object player;
    int maxhp, strength, fly;
  ::init();
  player = this_player();
  maxhp = player -> query_max_hp();
  strength = player -> query_stats("strength");
   strength = strength / 10;
   fly = player -> query_flying();
  if((fly) == 0)
  call_out("falls", strength, ({maxhp, player}));
}

void falls(mixed *args){
  object player;
  int maxhp;

  maxhp = args[0];
  player = args[1];
    if(environment(player) == this_object()) {
  tell_object(player, "\n%^RED%^You lose control of the ladder, and F"
"\n                                      %^RED%^A"
"\n                                        %^RED%^L"
"\n                                          %^RED%^L");
  player->add_hp(-(maxhp/2 -random(100)));
   player->move_player(PLATROOMS + "entrance.c");
   message("other action", player -> query_cap_name() + " looses control of the ladder, and falls to the earth, far below.", this_object(), this_player()); 
   message("other action", player -> query_cap_name() + " plumets from the sky, landing in a heap at your feet.", PLATROOMS + "entrance.c", this_player());
    player->force_me("look");
}
}
