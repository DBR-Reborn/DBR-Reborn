//  Made by Tailwind for Descent.
#include "../descent.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 2);
    set_property("night light", 2);
    set_property("indoors", 1);
    set("short", "The Gates of the Gnomish Settlement.");
    set("long", "You are before the huge, strong-looking gates of the Gnomish settlement. Stout gnomish guards patrol the walls, ready to fight off their foes. The road you are standing upon continues to the west and northeast.");

set_items( (["road" : "It's made out of dirt.",
"guards" : "They look pretty alert. You wonder what happened.",
"gates" : "The things are made of two feet of steel, and have tough stone walls around them.",
"walls" : "They define impenetrable." ]) );
    add_exit(ROOMS+"road1", "west");
    add_exit(ROOMS+"start", "northeast");
        if(!present("gnome")){
  new(MON+"gnome_guard.c")->move(this_object());
  new(MON+"gnome_guard.c")->move(this_object());
}
}
