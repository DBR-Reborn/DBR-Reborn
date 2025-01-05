//          Wizard: Delsius
//          tunnel_47
//          May 97

#include <std.h>
#include "/wizards/delsius/defs/defs.h"
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
     set_exits((["south":TUN_ROOMS+"tunnel_46"]));
}
void reset() {
   ::reset();
   if(!present("worker")) new(TUN_MON+"worker")->move(this_object());
}
