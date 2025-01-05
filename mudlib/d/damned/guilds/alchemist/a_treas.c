//      Edited by Tailwind
//
//      Blessed ReturnLIB
//      Tailwind 10/28/98

#include <std.h>

inherit "/std/locker_room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/d/damned/guilds/alchemist/train_room", "west");
   set("short","The Alchemists' Treasury");
   set("long",
"This is the Alchemists' Treasury.  Any alchemist may store items here, "
"but they are open to use by any other alchemist.  Several lockers and "
"chests lie about.  \nMAKE SURE you close a chest after using it, "
"or the items may be lost!");
}

