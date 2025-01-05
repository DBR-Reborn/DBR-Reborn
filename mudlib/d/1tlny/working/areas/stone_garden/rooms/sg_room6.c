//  Wizard: Shade Maelstorm
//  Area: Stone Garden
//  Theme: This is a stone garden, in which basilisks and other stoning
// creatures will play.

//  Monsters: The monsters will include caretakers, guards, gardeners, baby
//  basilisks, and other smaller insects, as well as some stone statues.

#include <std.h>
#include <stone_garden.h>

inherit ROOM;


void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
      set("short", "Short trail");
 set("long","The path here breaks up into a white pebbled trail here. It looks as if heavy traffic over this part of the path has taken its toll. The stone trail continues up to the northeast. You see the faint outline of some kind of stone structure over in the distance.");
 add_item("flash","You see a fast movement of color in the trees. Before you ccan focus on the exact position of the flash in the trees, it stops. Further attempts to try and see what is was are in vain.");
 add_item("path","The stone path has been reduced to a small collection of white rubble, smooth pebbled stones, worn away by weather and stress. This part of the path obviously needs some repair.");
 add_item("trail","The white trail you notice as you examine it more closely is actually composed of small white pebbles, prolly remnants of the beautiful stone path you have seen elsewhere in the garden. The trail of stones continues to the northeast.");
 add_item("structure","You see a small structure in the distance. It appears to have a roof on it, but is too small for a house....");
 add_item("statues","The statues here are few and very far apart. They all seem human, and all have fear written on their faces...");
  add_exit("sg_room7","east");
  add_exit("sg_room4","south");
}

 void reset() {
  ::reset();
  if((query_night()) && (!present("adult_basilisk"))) {
  new(MON_PATH+"adult_basilisk")->move(this_object());
   }
 }


