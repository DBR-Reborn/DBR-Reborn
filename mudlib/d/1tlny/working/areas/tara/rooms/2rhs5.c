#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"
inherit ROOM;

void reset() {
  ::reset();
   if(!present("donny")) {
     new(TARAMON+"donny")->move(this_object());
   }
}

void create() {
  ::create();
   set_property("light", 2);
   set_property("night light", 1);
   set_property("indoors", 1);
   set("short", "Donny's bedroom");
   set("day long", @DAY
This is the bedroom of Donny, the owner of many companies in
Tara, the pipe shop being his most successful.  He has a large
bed in the middle or the room, and a few shelves on either side.
Although it is day, a few torches are lit to keep this underground
room filled with light.  A thin set of stairs leads up into the
rest of the house.
DAY
);
   set("night long", @NIGHT
This is Donny's bedroom, he is the esteemed owner of many
companies in Tara.  His pipe shop being the most successful.
The bedroom contains a large bed in the middle, and a few shelves on
either side.  A torch is lit near a thin set of stairs, keeping
the room from blackness.
NIGHT
);
   add_item("bed", "A large bed, made for a single man.");
   add_item("shelves", "The shelves contain many different types "+
   "and tabacco pouches.  One spot seems to be missing something, "+
   "a golden holder without a pipe.  How odd.");
   add_item("torches", "Donny spares no expense in the lighting "+
   "of his room.");
   add_item("stairs", "A thin set of stairs that leads up into "+
   "the rest of the house.");
   set_smell("default", "The air smells thickly of smoke.");
   set_listen("default", "It sounds like someone moaning.");
   add_exit(TARAROOMS+"2rhs3", "up");
}
