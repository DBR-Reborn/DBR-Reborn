#include "../munitio.h"
inherit "/std/vault";

private int open;

void reset() {
   ::reset();
   seteuid(getuid());
     if (!present("feika")) {
        new(MON+"feika")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit(ROOMS+"city2", "north");
   set("short","The Armoursmith Shop");
   set("long",
"This is the Armoursmith Shop.  Various objects of armour adorn the "
"walls and counters.  A sturdily built, sweaty shopkeeper peers at "
"you from behind a small table.  There is a large wooden door to the "
"east.  There is a sign on the wall.");
   set_items( (["sign":"The say reads: 'say feika, help' for assistance.",
              "wooden door" : "It looks very sturdy."]) );
}
