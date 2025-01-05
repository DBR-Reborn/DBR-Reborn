  // Area:  Gobo caves
  // Coders: Amel and Arctic
  // Date: May, 97
// Room: room9c.c

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
    set("short", "A small cave.");
    set("long","This is a small cave that is only some fifteen meters acrosst.  The air is humid and warm here allowing some natural plant growth to occur.  Most of the plants are of the fungus variety in several different shapes and sizes.");
set_items( ([({"plants","plant"}):"The two plants most abundant are mushrooms and a cave moss that is growing in large sheets.",({"wall","walls"}):"The stone here is solid and rough having never been worked.","ceiling":"The ceiling is only about four meters here."]) );
set_exits((["west":GOBROOMS+"room9"]));
    set_smell("default", "A strong smell of plants fills the air.");
    set_listen("default","There is nothing but silence.");
  }

  void reset() {
    int rand;
    ::reset();
  rand = random(10);
/*
if(rand == 0 && !present("gobo_female")) new(GOBMONSTERS+"gobo_female")->move(TO);
      if (!present("pmushroom")) pmushroom_present = random(4);
      if (!present("cave_moss_present")) cave_moss_present = random(6);
      if (pmushroom_present>0) add_item("mushroom","These are large mushrooms with bright red and green patches of color on them.");
      if (cave_moss_present>0) add_item("moss","This is a light green moss that apears to be growing quite quickly.");
*/
  }

  void init(){
   ::init();
    add_action("gather_plants","gather");
  }

  void gather_plants(string str){
 if(!str || str != "mushroom" || str != "moss") write("What would you like to gather?");
  else if(str == "mushroom" && pmushroom_present > 0) {
     write("You gather some mushrooms from the flora about the cave.\n");
     say(TPQCN+" gathers some mushrooms from the flora about the cave.\n");
     new(GOBMISC+"pmushroom")->move(TO);
pmushroom_present--;
if(pmushroom_present=0) remove_item("mushroom");
     }
    else if(str == "moss" && cave_moss_present >0) {
     write("You gather some moss from the vegatation about the cave.\n");
     say(TPQCN+" gathers some moss from the vegatation about the cave.\n");
     new(GOBMISC+"cave_moss")->move(TP);
     cave_moss_present--;
     if(cave_moss_present=0) remove_item("moss");
     }
    else{
     write("There doesn't seem to be any more worth gathering.\n");
     say(TPQCN+" looks over the vegatation for a moment.\n");
    }
  }
