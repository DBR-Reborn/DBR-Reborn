//  Made by Tailwind for Eternity.
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "The Command Tent");
    set("long", "This particular tent is where the command of the Royal-Infantry plan strategy for their next incursion against the orcs, kobolds, and other enemies of the Kingdom. Various emissaries rush about, informing various division commanders of the current security situation.");
    add_exit("/d/damned/guilds/royal-infantry/tentcamp", "north");
}
