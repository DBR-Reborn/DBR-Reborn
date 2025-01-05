  // Area:  Gobo caves
  // Coders: Amel and Arctic
  // May, 97
  // Room: room9.c

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
    set_property("night light", 0);
    set("short", "A medium size cavern.");
    set("long","You have steped into what looks to be a medium size cavern stretching some sizty meters in diameter with a rough circular shape with an alcove of sorts in the north wall.  There are is a large fireplace burning in pit set into the southern wall.  The smoke in the air is the worst you have seen here but is hanging near the ceiling.");
set_items( (["firepit":"A fairly large fire in the shape of a trench, it looks like its used to cook food and heat water.. it must be at least 5 meters long.",({"tables","stalagmites"}):"There are several scattered about, some quite large that have been chisled flat to make eating and working surfaces.",({"wall","walls"}):"The stone here is solid and rough having never been worked.","ceiling":"The ceiling is at least 12 meters high where the bottom of the layer of smoke is blocking your vision."]) );
set_exits((["north":GOBROOMS+"room9a","northeast":GOBROOMS+"room9b","east":GOBROOMS+"room9c","southeast":GOBROOMS+"room9d","west":GOBROOMS+"room8"]));
    set_smell("default", "The smell of cooking flesh is quite strong here.");
set_listen("default","The large fire is making an incessant crackling.");
  }

  void reset() {
    int rand;
    ::reset();
    rand = random(7) + 1;
/*
if(rand == 8 && !present("gobo_guarda")){
        new(GOBMONSTERS+"gobo_guarda")->move(TO);
        new(GOBMONSTERS+"gobo_guarda")->move(TO);
        new(GOBMONSTERS+"gobo_female")->move(TO);
        new(GOBMONSTERS+"gobo_female")->move(TO);
        }
  if(!present("gobo_male")){
      while(rand > 0){
      new(GOBMONSTERS+"gobo_male")->move(TO);
      rand--;
      }
     }
*/
}
