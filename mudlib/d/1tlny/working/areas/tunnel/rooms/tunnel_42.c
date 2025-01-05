//          Wizard: Delsius
//          tunnel_42
//          May 97

#include <std.h>
#include "/wizards/delsius/defs/defs.h"
inherit ROOM;

void create() {
     ::create();
     set_property("indoors",1);
     set_property("light",-1);
     set("short", "Dead End");
     set("long", "You are now standing in one of the many dead ends "
         "in the tunnel system.  This room, however, seems to be quite "
         "different from the rest.  The ground here is nothing but damp "
         "sand with a rusty hue.  Towards the back of the room are two "
         "candelabras positioned at each end of a wooden coffin.  For "
         "some reason the air is much cooler here than elsewhere... "
         "almost as if there was evil in the air.");
     set_smell("default", "You smell the foul stench of death in the "
               "air");
     set_listen("default", "You hear the sound of bats squeaking all "
                "around you.");
     set_items(([ ({"area","tunnel"}): "Due to the darkness, you can only "
                    "see a few feet in any direction.",
                  ({"wall","walls"}): "The tunnel walls are made of rock "
                    "and are cold and damp with moisture.",
                  ({"rock","rocks"}): "Rocks of various shapes and sizes "
                    "are strewn about the ground.",
                  ({"sand","damp sand","ground"}): "The ground here is "
                    "very damp and covered with sand.  The sand appears "
                    "to be a rusty color... perhaps it's blood-stained?",
                  ({"candelabra","candelabras","candle"}): "The "
                    "candelabra appears to be made of pure gold.  It is "
                    "branched into three directions and contains a long "
                    "black candle in each.  The soft flame flickers "
                    "as the wind blows through the room but fails to blow "
                    "it out... funny thing is that the candles don't "
                    "appear to be melting either, how odd!"]));
     set_exits((["north":TUN_ROOMS+"tunnel_43"]));
}
