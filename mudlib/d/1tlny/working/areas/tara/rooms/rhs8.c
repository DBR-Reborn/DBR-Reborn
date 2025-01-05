inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"


void create() {
  ::create();
   set_property("light",1);
   set_property("night light",1);
   set_property("indoors", 1);
   add_exit(TARAROOMS+"rhs5", "northwest");
   set("short", "A teenage halflings room");
   set("day long", @DAY
This is what appears to be the room of a teenage girl.  It
has a bed with bright pink sheets, a small walk in closet with many
lively colored dresses.  A dresser is in the corner, perfumes and
expensive make-up strewn carelessly across its top.  About 
twelve different hats lie on a rack in another corner, whoever
lives in here is obviously spoiled.
DAY
);
   set("night long", @NIGHT
This is the room of the halflings teenage daughter, it is
smelly of perfume at night, as it is at day.   The bed is
covered with bright pink sheets, and the closet is filled
lively colored dresses.  A hat rack with many different hats lie in
a corner, and a dresser with heaps of perfume and make-up lie in
another, proving that this is the room of a spoiled girl.
NIGHT
);
   add_item("bed", "The bed of a stuck up rich girl.");
   add_item("dresser", "Many perfume vials and make-up containers "+
   "lie strewn carelessly across the dressers top.");
   add_item("closer", "Just a closet filled brightly colored "+
   "dresses");
   add_item("dresses", "Dresses only a fashion crazed halfling "+
   "would want to wear");
   add_item("rack", "A hat rack");
   add_item("hats", "An assortment of hats, many different odd colors");
   set_smell("default","It smells very strongly of perfume");
}

void reset() {
  ::reset();
   if(!present("teen")){
   new(TARAMON+"teen_bitch")->move(this_object());
}
}
