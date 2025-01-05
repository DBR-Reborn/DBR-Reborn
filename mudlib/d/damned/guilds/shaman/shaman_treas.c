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
   add_exit("/d/damned/guilds/shaman/shaman_train_room", "west");
   set("short","The Shaman Storage Room");
   set("long",
"This is the Shamans' Treasury.  Any shaman may store items here, "
"but they are open to use by any other shaman.  Several lockers and "
"chests lie about.  \nMAKE SURE you close a chest or locker after using it, "
"or the items may be lost!");
}

