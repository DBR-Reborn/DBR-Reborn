#include "../shards.h"
inherit "/std/vault";

private int open;

void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("crystal")) {
      new(OBJ+"weapon_store_crystal")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit(ROOMS+"ak_markne", "west");
   set("short","Broken Blades");
   set("long",
"The room is completely and utterly empty, except for thousands of broken blades lying upon the ground. You see no corpses, nothing but broken blades. You walk carefully to avoid losing toes.");
   set_items( (["blades":"There can be no logical explanation for this. None."]) );
}
