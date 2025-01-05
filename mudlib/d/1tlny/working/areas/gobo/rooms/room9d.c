  // Area:  Gobo caves
  // Coders: Amel and Arctic
  // Date: May, 97
  // Room: room9d.c

#include <dirs.h>
#include <std.h>
#include <def.h>
#include "../gobo.h"

inherit "/d/areas/gobo/funs";
  inherit ROOM;

  int pmushroom_present,cave_moss_present;

  void create(){
    ::create();
    set_property("indoors", 1);
    set_property("light", 1);
    set_property("night light", 0);
    set("short", "A medius size cave.");
    set("long","A cave that is some twenty meters long and has a remarkable lack of both vegetation and debri.  A number of small rocks are scattered on the floor and the cave has a cylyndrical shape.  The wall at the far end is a pile of rubble.");
set_items( ([({"wall","walls"}):"The stone here is smooth and curved in a circular shape.","ceiling":"The ceiling is arched and runs smoothly into the walls.","floor":"The floor here is smooth and curves upward at the edges flowing smoothly into the walls.","rocks":"There are a number of small rocks about the cave, they seem to all have rounded edges.","rubble":"There is a pile of rubble here.. perhaps you could dig through it."]) );;
set_exits((["northwest":GOBROOMS+"room9"]));
    set_smell("default", "The air is filled with small particles of dust.");
    set_listen("default","There are some very low sounds, almost a rumbling.");
  }

  void reset() {
    ::reset();
  //  remove_exit_function("east");
  }

  void init(){
    ::init();
    add_action("dig_rubble","dig");
  }

  void dig_rubble(){
    write("You start to dig and then pause as you feel the ground begin to tremble beneath your feet.. ");
    say(TPQCN+" starts to dig through the rubble and pause as you feel the ground begin to tremble beneath your feet.. ");
    delayed_call("load_small_purple_worm", 5);
  }

  void load_small_purple_worm(){
say("%^PURPLE%^A large purple worm bursts through the rubble..\n");
// new(GOBMOSTERS+"small_purple_worm")->move(TO);
  //add_exit((east));
    }
