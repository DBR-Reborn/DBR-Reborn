#include <std.h>

/* This is the blood stained key that is hidden in the secret hole in the misty field outside the black keep. The key when found does not have immediate use as far as entering the keep, but it is required in order to reach the chamber of the keep's master. The location of the key requires that the player pay attention to room descriptions and observe the area, as there is one other such key of the three keys of the black keep located in a hidden room. */

inherit OBJECT;

void create() {
::create();
set_name("blood stained key");
set("id", ({ "blood key", "key", "stained key", "blood stained key" }));
set_short("A blood stained key");
set_long("This is a key almost completely covered in stained blood. It is about nine inches long, and is shaped as if a demon is spitting it out of its mouth.");
set_weight(20);
set_value(100);
}
