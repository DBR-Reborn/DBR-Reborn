#include "../shards.h"
inherit "std/room";

void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("crystal")) {
      new(OBJ+"enchanter_crystal")->move(this_object());
   }
}

void create() {
  ::create();
    set_property("light",3);
    set_property("night light", 2);
    add_exit(ROOMS+"ak_res1", "west");
    set("short","Protecting the Protected");
    set("long","This building is completely untouched. A sign on the wall proclaims: 'In 200 years, the ban shall be lifted.' Apparently, the ban has been lifted, as you are now inside what must be an Arcane Imbuers guild. Books and tables are everywhere, looking the same way as the day they were abandoned. This place is like the eye of a storm; calm, but surrounded by chaos. ");
    
}
