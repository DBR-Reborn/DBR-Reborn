#include "../newshards.h"
inherit "/std/vault";


void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("blackwind")) {
      new(MON+"blackwind")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit(ROOMS+"street3", "south");
   set_open("iron door", 0);
   set_locked("iron door", 1);
   set_lock_level("iron door", 22);
   set("short","The Town General Store");
   set("long",
"This small building seems to be a shop. It has a very sparsely populated inventory. You wonder what happened to all the wares.");
   set_items( (["sign":"The say reads: 'say blackwind, help' for assistance.",
              "iron door" : "It looks very sturdy.",
              "door" : "It is a large iron door."]) );
}

