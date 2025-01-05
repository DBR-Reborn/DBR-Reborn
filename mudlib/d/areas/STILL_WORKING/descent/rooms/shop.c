#include "../descent.h"
inherit "/std/vault";

void reset() {
   ::reset();
   seteuid(getuid());
   if (!present("johnny")) {
      new(MON+"johnny")->move(this_object());
   }
}

void create() {
   ::create();
   set_property("indoors",1);
//Either Change the mob or fix combat.  Fighting this guy causes way too much HB loss - stoNey
  //set_property("no attack", 1);
   set_property("light",3);
   add_exit(ROOMS+"road4", "west");
   set("short","The Gnomish General Store");
   set("long",
"This is the Gnomish general store, where you can buy all of the things you would need for life in a small little Gnomish mining settlement. Before you is a large counter, with a sign resting upon it. Behind the counter are the many items that this store sells.");
   set_items( (["sign":"The say reads: 'say johnny, help' for assistance.",
              "iron door" : "It looks very sturdy.",
              "door" : "It is a large iron door."]) );
}

