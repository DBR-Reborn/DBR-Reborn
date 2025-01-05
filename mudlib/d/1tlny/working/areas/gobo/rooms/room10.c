  // Area:  Gobo caves
  // Coders: Amel and Arctic
  // May, 97
  // Room: room10.c

#include <dirs.h>
#include <std.h>
#include <def.h>
#include "../gobo.h"

inherit "/d/areas/gobo/funs";
inherit ROOM;

  void create(){
    ::create();
    set_property("indoors", 1);
    set_property("light", 1);
    set("short", "A cavern passage.");
    set("long","You step in the passage and after traveling for a few minutes you reach a junction some 5 meters across with one passage continuing west and another branching to the north.  There is a torch hanging on the wall providing some light.");
set_items( ([({"wall","walls"}):"The stone here is solid and rough having never been worked.","ceiling":"The ceiling is only 3 meters high here."]) );
set_exits((["north":GOBROOMS+"room11","west":GOBROOMS+"room10a","east":GOBROOMS+"room8"]));
    set_smell("default", "The smell of burning wood hangs in the air.");
    set_listen("default","There are muttering sounds coming from the passage to the east.");
  }

  void reset() {
    ::reset();
    if(!present("gobo_guarda")) {
  //  new(GOBMONSTERS+"gobo_guarda")->move(TO);
  //  new(GOBMONSTERS+"gobo_guarda")->move(TO);
  //  new(GOBMONSTERS+"gobo_guarda")->move(TO);
      }
    add_item("torch","A standard torch sitting in a mount attached to the wall.\n");
  }

  void init(){
    ::init();
    add_action("take_torch","take");
  }

  void take_torch(string str){
    if(!str || str != "torch") write("You want to take what?\n");
    else{
     write("You take the torch from the stand in the wall.\n");
     say(TPQCN+" takes the torch from the wall.\n");
     remove_item("torch");
  // new(GOBMISC+"torch")->move(TP);
}
     }
