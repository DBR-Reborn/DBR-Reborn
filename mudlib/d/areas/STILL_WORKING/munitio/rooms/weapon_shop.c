#include "../munitio.h"
inherit "/std/vault";

private int open;

void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("marko")) {
      new(MON+"marko")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit(ROOMS+"city3", "north");
   set("short","The Weaponsmith Shop");
   set("long",
"This is the Weaponsmith shop.  Weapons hang about on the walls and "
"decorate various tables.  A burly blacksmith grunts at you from "
"behind a large counter.\nThere is a sign on the wall.");
   set_items( (["sign":"The say reads: 'say marko, help' for assistance.",
              "wooden door" : "It looks very sturdy."]) );
}
