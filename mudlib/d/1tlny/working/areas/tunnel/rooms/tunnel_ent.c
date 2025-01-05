//          Wizard: Delsius
//          tunnel_ent
//          May 97

#include <std.h>
#include "/wizards/delsius/defs/defs.h"
inherit ROOM;
                                                     
void create() {
     ::create();
     set_property("indoors", 1);
     set_property("light", 1);
     set("short", "Tunnel Entrance");
     set("long", "You are standing at the entrance of a dark and dismal "
        "tunnel.  A cool breeze can be felt emanating from deep within "
        "the rocky walls ahead.  Small puddles of water are scattered "
        "throughout the area while water glistens along the inner walls.  "
        "To the north, the ground slopes downward into the darkness.");
     set_items( ([ ({"entrance","area"}): "The entrance to this tunnel "
                "is fairly wide.  As you look further into the tunnel, "
                "you notice that it appears to become a bit more narrow.",
                ({"tunnel","walls","wall"}): "The tunnel walls are made "
                "of rock and are cold and damp with moisture.",
                ({"puddles","puddle"}): "You can barely make out your "
                "image in the small puddle of water.",
                "water": "The water is cool to the touch."]));
     set_exits((["north":TUN_ROOMS+"tunnel_01"]));
}
