//  Made by Tailwind for RI Guildhall.
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    set_pre_exit_functions( ({"southeast"}), ({"enter_fun"}) );
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "The Entrance to the Royal-Infantry Camp");
    set("long", "Here at the base of the mountains, you find the entrance to the Royal-Infantry camp. A small dirt path runs northwest, back to the mountain path, and to the southeast, where one can enter the camp. A small sign is posted on a tree.");
    add_exit("/d/damned/guilds/royal-infantry/tentcamp", "southeast");
    add_exit("/d/areas/nelfton/rooms/path6", "northwest");
}

void reset() {
  ::reset();
  if(!present("guard")) {
    new("/d/damned/guilds/royal-infantry/guard")->move(this_object());
    new("/d/damned/guilds/royal-infantry/guard")->move(this_object());
  }
}

int enter_fun() {
  if(present("guard")) {
    if(((string)this_player()->query_class() !="royal-infantry") && ((string)this_player()->query_class() !="child")) {
      write("The guard stops you from passing, and points to the sign.");
      return 0;
    }
    else
      write("The guard looks at you, and lets you pass.");
  }
  return 1;
}