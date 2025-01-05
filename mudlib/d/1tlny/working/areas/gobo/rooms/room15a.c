  // Area:  Gobo caves
  // Coders: Amel and Arctic
  // May, 97
  // Room: room15a.c

#include <dirs.h>
#include <std.h>
#include <def.h>
#include "../gobo.h"

inherit "/d/areas/gobo/funs";
  inherit ROOM;

int exit_present;

  void create(){
    ::create();
    set_property("indoors", 1);
    set_property("light", -1);
    set("short", "A short passage.");
    set("long","The passage is short and only five meters long and a ceiling three"
    " meters high.  The passage is barren with smooth walls all around, it has"
    " obviously been hollowed out by a mining crew.  There are exits at both"
    " ends of the passages to the east and west.  The area is barely lit by light"
    " seeping between the door cracks.");
    set_items( ([({"wall","walls"}):"The stone here is smooth and polished.","ceiling":
    "The ceiling is only a few meters high here and looks to have been carved out."]));
set_exits((["east":GOBROOMS+"room15","west":GOBROOMS+"room14"]));
    set_smell("default", "The air is stagnant here and the floor is covered with layer"
      " of dust.");
    set_listen("default","The only sound you hear is your heartbeat.");
set_search("wall",(:call_other,this_object(),"search_wall":));
  }

  void reset() {
    ::reset();
    exit_present = 0;
    remove_exit("east");
  }

  void search_wall(){
     if(exit_present == 0){
      if (skill_check("perception", -30) ==1){
      add_exit(GOBMONSTERS+"room15b","north");
      write("A section of the north wall swings back revealing a passage beyond.\n");
      say("A section of the north wall swings back revealing a passage beyond.\n");
      }
     }
  }
