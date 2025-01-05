//          Wizard: Delsius
//          tunnel_46
//          May 97

#include <std.h>
#include "/wizards/delsius/defs/defs.h"
#include <daemons.h>
inherit ROOM;

void create() {
     ::create();
     set_property("indoors",1);
     set_property("light",-1);
     set("short", "Dark Tunnel");
     set("long", "The area surrounding you is virtually "
         "indistinguishable.  The tunnel walls glimmer with moisture and "
         "the ground is composed of small rocks and sand.  The constant "
         "flow of brisk air is almost enough to numb your senses.");
     set_smell("default", "You smell the decay of flesh and mildew in "
               "the air.");
     set_listen("default", "You hear the sound of wind howling through "
                "the tunnels.");
     set_items(([ ({"area","tunnel"}): "Due to the darkness, you can only "
                    "see a few feet in any direction.",
                  ({"wall","walls"}): "The tunnel walls are made of rock "
                    "and are cold and damp with moisture.",
                  ({"rock","rocks"}): "Rocks of various shapes and sizes "
                    "are strewn about the ground.",
                  "sand": "The ground is covered with your basic, run "
                  "of the mill, sand."]));
     set_exits((["north":TUN_ROOMS+"tunnel_47",
                 "south":TUN_ROOMS+"tunnel_45",
                 "east":TUN_ROOMS+"tunnel_36"]));
}
void reset() {
   object mon;
  if(MOB_TRACK_D->mob_plus("vampire bat", 1))
     mon = new(TUN_MON+"bat")->move(this_object());
   if(MOB_TRACK_D->mob_plus("tunnel rat", 1))
  mon = new(TUN_MON+"rat")->move(this_object());
   if(MOB_TRACK_D->mob_plus("ghost of tunnel worker", 1))
     mon = new(TUN_MON+"ghost")->move(this_object());
}
