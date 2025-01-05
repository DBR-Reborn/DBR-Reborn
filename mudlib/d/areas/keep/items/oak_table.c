#include <std.h>

/* This table is the oak table located in the assassins quarters of the black keep. The table is bolted well into the floor and cannot be removed. Placed on top of this is a contract which is used in the areas quest impaled with a death dagger. */ 

inherit OBJECT;

void create() {
::create();
set_name("oak table");
set("id", ({ "table", "oak table", "thick table", "thick oak table" }));
set_short("A thick oak table");
set_long("This is an extremely thick table, fashioned completely of rough oak and bolted very professionally into the floor."); 
set_weight(10000000);
set_value(0);
}
