
#include <std.h>
#include "/wizards/garetjax/plateau/defs.h"

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "An Ominous Tower");
   set_long(
     "This tower gives you the chills. It is a dark, quiet structure, made "
     "of large stones, carefully fitted togethor. There are cracks in the "
     "walls in which all sorts of critters have made a nest. Mice scurry "
     "under your feet to avoid getting stepped on, and spider webs cover the "
     "walls and ceiling."
     " The solitary torch on the wall looks as if it could go out any minute."
    );
     add_exit("plat7", "out");
add_exit("upstairs2", "up");
     set_smell("default", "The air is dank, and humid.");
     set_listen("default", "The scurrying of mice is heard.");
  }

void init()    {
       int dex;
      object player;
     ::init();
     dex = (int)this_player()->query_stats("dexterity");
      player = this_player();
      dex = dex / 15;
      call_out("tweak", dex, player);
}

void tweak(object player)   {
      object mon;
      if(player->is_player() && environment(player)==this_object())  {
       message("other action", "%^RED%^You accidentally tweak a string on the spider web, and a Hideous Spentaur pops out, and CHARGES!!!!", player, this_object());
     message("other action", player->query_cap_name() + "%^RED%^ accidentally tweaks a string on the spider web, and out pop a Hideous Spentaur, which charges at " + player->query_cap_name(), this_object(), player);
     mon=new(PLATMON + "spid");
     mon->move(this_object());
     mon->force_me("kill " + player->query_cap_name());
}
}
