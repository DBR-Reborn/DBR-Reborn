#include <std.h>

/* This is one of the two crystalline obelisks that are present in the black keep's master room. They cannot be carried away, and serve no special purpose and are used only for decoration. */

inherit OBJECT;

void create() {
::create();
set_name("obelisk");
set("id", ({ "obelisk", "crystal obelisk", "crystalline obelisk" }));
set_short("A crystalline obelisk");
set_long("This is a large somewhat crescent shaped obelisk, fashioned entirely of crystal. It sits on the circular platform atop the stairway and points toward both the other obelisk and the sky. As you look closer at it you can see great magical power shimmering from within."); 
set_weight(10000000);
set_value(0);
}
