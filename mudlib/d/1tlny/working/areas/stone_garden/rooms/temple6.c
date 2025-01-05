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
      set("short", "Temple Cavern.");
   set("long", "You find yourself in a large cavern, with passages going every which way. "+
  "There are torches lined along the walls, of the cavern giving off just "+
  "a very faint light to see by.");

add_item("walls","The walls in this temple appear to be covered with some kind of green moss. The moss seems to flourish in this dark dank atmosphere, and has grown quite well down here. Most of the walls surface is covered in moss.");
add_item("moss","This green plant seems to be covering half the walls. You wonder how anyone or anything could like in such a dismal place.");
add_item("torches","The torches along the walls provide a dim light just barely enough to see by.");
add_item("torch","This is one of the torches aligned along the walls here. Unfortunately, this torch appears to be permanently fixed to the wall.");
add_item("passages","The passages here go off in various directions, if adventurers were not cautious, they could easily get lost.");
 set_listen("default","You hear the sound of dripping water coming from the tunnels");
  add_exit("temple4","north");
   add_exit("temple5","east");
  add_exit("temple3","northwest");
}

 void reset() {
  ::reset();
  if(!present("adult_basilisk")) {
  new(MON_PATH+"adult_basilisk")->move(this_object());
   }
  }

