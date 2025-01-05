//          Wizard: Delsius
//          tunnel_01
//          May 97
                                        
#include <std.h>
#include "/wizards/delsius/defs/defs.h"
inherit ROOM;

void create() {
     ::create();
     set_property("indoors",1);
     set_property("light",1);
     set("short", "Steep Incline");
     set("long", "You are standing on a steep incline which descends "
        "north into the darkness.  The entrance to the tunnel lies "
       "to the south.");
     set_smell("default", "You smell the decay of flesh and mildew in "
              "the air.");
     set_listen("default", "You hear the sound of wind howling through "
              "the tunnels.");
     set_exits((["north":TUN_ROOMS+"tunnel_02",
                 "south":TUN_ROOMS+"tunnel_ent"]));
     new(TUN_OBJ+"sign")->move (this_object());
}
