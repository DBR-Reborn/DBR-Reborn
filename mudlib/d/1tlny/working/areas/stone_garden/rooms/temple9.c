#include <daemons.h>
#include <stone_garden.h>

inherit "/std/vault";

private int open;


void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/wizards/shade/stone_garden/rooms/temple8", "north");
   set_door("stone door", "/wizards/shade/stone_garden/rooms/temple8", "north",
  "stone garden key");
   set_open("stone door", 0);
   set_locked("stone door", 1);

   set("short","Basilisk Lair");
   set("long",
 "This is the dark lair of the basilisk. The only light is a dim torch on the far "
 "wall. There is a nest of eggs here, and you can only hope that those "
 "eggs are not the young of which you think they are. The whole room is dark "
 "dank and miserable. Ideal breeding conditions i would think for a "
 "creature of death.");
 add_item("torch","There is a small torch on the far wall. It is the only thing giving off a very dim light in this room.");
 add_item("nest","The basilisk nest is made of dead, moist grasses and plants which must have been taken from the garden above. The rotting vegetation would provide ideal temperatures for the hatching of the offspring.");
 add_item("eggs","There are numerous basilisk eggs here, of which in appearance are like large smooth rocks. The eggs are either composed of solid stone, but more likely have a shell which is immensely strong which protects the basilisk inside.");
 add_item("walls","The walls here are scratched and marred, testimony to the iron claws you read about that basilisks are reported to have.");

 add_item("wood door","The door to the north from this lair is made of petrified wood.");

 }
  void reset() {
  ::reset();
  if(!present("mother_basilisk")) {
  new(MON_PATH+"mother_basilisk")->move(this_object());
   
   }
 }

