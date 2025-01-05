#include "../shards.h"
inherit "std/vault";

void reset() {
        ::reset();
        if(!present("demon"))
  new(MON+"demon")->move(this_object());
        }

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"ak_victory4", "west");
    add_exit(ROOMS+"ak_haven5", "north"); 
    add_exit(ROOMS+"ak_shop5", "south");
    set("short","Doom Market");
    set("long","Rubble litters the ground, and you walk carefully. As your eyes take in the full destruction of this area of the former town marketplace, you can scarcely believe that this has really happened. What the hell could do this? There is a collapsed building to your east, but the one to the south is enterable. A sign rests on the ground - another is on the southern building.");
    add_item("sign 1", "This sign points south.\n"
    "*************************\n"
    "        Magic Shop\n"
    "*************************\n");
    add_item("sign 2", "This sign points east.\n"
    "*********************************\n"
    "          The Chest Shop\n"
    "*********************************\n");
}
