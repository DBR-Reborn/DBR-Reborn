//  Made by Tailwind for New Shards.
#include "../newshards.h"
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 0);
    set("short", "Inside the Mage's Hut.");
    set("long", "This sparsely furnished little hut is the home of someone who practices magic, you can tell. Various spell components lie strewn on a table, and a bookcase has a bountiful amount of spellbooks in it.");
    add_exit(ROOMS+"street2", "west");
}

void reset() {
     ::reset();
if(!present("mage")) {
new(MON+"mage")->move(this_object());
}
}