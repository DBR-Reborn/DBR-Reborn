#include <std.h>

/* This key is the three pronged key that is required to unlock the blue door in the black keep, which blocks access to the main part of the second floor. The key is found in the clone statues room, where six statues sit in a hexagonal shape. Five of the statues carry weapons, but one does not. To get the key, the player must observe the type of weapons the statues with weapons carry, and get a grand axe from the armory in the keeps opposite wing for the statue without a weapon. All six statues will then glow blue and the key will materialize along with four death soldiers to defend it. */ 

inherit OBJECT;

void create() {
::create();
set_name("blue key");
set("id", ({ "key", "three pronged key", "blue key", "blue three pronged key" }));
set_short("A blue three pronged key");
set_long("This key is painted a striking blue, with a perfect sphere at its top and three prongs at its bottom fashioned in a triangular formation.");
set_weight(20);
set_value(10000);
}
