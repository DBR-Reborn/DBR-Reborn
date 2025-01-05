#include "../shards.h"
inherit "/std/vault";

private int open;

void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("crystal")) {
      new(OBJ+"armor_store_crystal")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit(ROOMS+"ak_markne", "south");
   set("short","Protection from the Inevitable");
   set("long",
"Shattered metal, broken wood, and a massive forge are what stand out here. Judging from the look and shape of the forge, you're pretty certain that this building was an armor shop sometime in its existence.");
   set_items( (["metal":"It brings a new definition to 'scrap metal'.",
              "wood" : "Rotted, disgusting wood."]) );
}
