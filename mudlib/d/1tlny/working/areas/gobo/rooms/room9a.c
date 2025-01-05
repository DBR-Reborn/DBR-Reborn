  // Area:  Gobo caves
  // Coders: Amel and Arctic
  // May, 97
  // Room: room9a.c

#include <dirs.h>
#include <std.h>
#include <def.h>
#include "../gobo.h"

inherit "/d/areas/gobo/funs";
  inherit ROOM;

  int rat_present;

  void create(){
    ::create();
    set_property("indoors", 1);
    set_property("light", 1);
    set_property("night light", 0);
    set("short", "A small cave.");
    set("long","You have entered what looks to be the gobo version of a storage cave.  It is a small offshoot of the cave to the south.  Some barrels are stacked in the back corner and some large sheets of moss are piled here.");
    set_items( ([({"barrel","barrels"}):"Four foot barrels are stored here but remain empty since the bottoms have rotted out.",({"moss","piles"}):"Large sheets of moss that have been harvested are here.",({"wall","walls"}): "The stone here is solid and rough having never been worked.","ceiling":"The true height of the ceiling can't be determined as it is dark cluttered with stalagtites."]) );
set_exits((["south":GOBROOMS+"room9"]));
    set_smell("default", "The smell of rodents abounds here.");
    set_listen("default","Small chittering sounds come from behind some barrels in the back.");
    set_search("barrel",(:call_other,TO,"search_barrel":));
  }

  void reset() {
    int rand;
    ::reset();
rat_present = random(4);
    rand = random(6);
 if(!present("cave_moss"))
     {
      while(rand > 0){
  //    new(GOBOBJECTS"cave_moss")->move(TO);
      rand--;
      }
     }
  }

  void search_barrel(){
  if (rat_present>0){
     write("While searching the barrels some rats are disturbed and come skittering out.\n");
     say(TPQCN+" searches the barrels and disturbs some rats.\n");
  while (rat_present>0){
      new(GOBMONSTERS+"rats")->move(TO);
      }
    }
  }
