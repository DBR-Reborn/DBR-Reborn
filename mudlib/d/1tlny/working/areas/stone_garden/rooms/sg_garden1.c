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
      set("short", "Stone Garden Nursery");
 set("long","You have entered the nursery section of the stone garden. "+
 " You see small basilisks playing around here, and gardeners occaisionally pruning the various grasses. Here the path seems to be broken up into smaller stones, and it appears as if nature is claiming back this part of the path. There seems to be several plants here, very small, but all of the one type. The broken stone path leads southeast and west from here.");
  add_exit("sg_garden2","north");
  add_exit("sg_room10","southeast");
}

  void reset() {
    ::reset();
    if(!present("baby_basilisk")) {
    new(MON_PATH+"baby_basilisk")->move(this_object());
  }
}


