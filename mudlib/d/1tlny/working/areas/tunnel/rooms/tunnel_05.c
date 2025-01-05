//          Wizard: Delsius
//          tunnel_05
//          May 97

#include <std.h>
#include "/wizards/delsius/defs/defs.h"
inherit ROOM;

void create() {
     ::create();
     set_property("indoors",1);
     set_property("light",1);
     set("short", "Lit Corridor");
     set("long", "You are standing in a well lit corridor with numerous "
         "torches lighting your way.  The air in this room is "
         "considerably warmer compared to other areas in the tunnel.  "
         "A vast room invites you to the south while the darkness awaits "
         "you to the north.");
     set_smell("default", "You smell the potent decay of flesh and "
               "smoke.");
     set_listen("default", "You hear the sounds of moaning and the "
                "crackling of a fire.");
     set_items(([ ({"area","tunnel","corridor"}):  "The narrow corridor "
                    "is a few meters wide.  It opens up into wider "
                    "areas in both directions.",
                  ({"wall","walls"}): "The tunnel walls are made of rock "
                    "and are warmer here and damp with moisture.",
                  ({"torch","torches"}): "Flickering torches protrude "
                    "from both sides of the rocky walls lighting "
                    "your path."]));
     set_exits((["north":TUN_ROOMS+"tunnel_06",
                 "south":TUN_ROOMS+"tunnel_lair"]));
}
