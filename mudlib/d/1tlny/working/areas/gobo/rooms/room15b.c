  // Area:  Gobo caves
  // Coders: Amel and Arctic
  // May, 97
  // Room: room15b.c

#include <dirs.h>
#include <std.h>
#include <def.h>
#include "../gobo.h"

inherit "/d/areas/gobo/funs";
  inherit ROOM;


  void create(){
    ::create();
    set_property("indoors", 1);
    set_property("light", 0);
    set_property("night light", -4);
    set("short", "A short passage.");
    set("day long","The passage is long beyond site sloping upward toward the surface"
    " fairly steeply.  The breeze blows lightly at your back as you look down"
    " the tunnel, the light from the surface traveling even this deep underground.");
    set("night long","The floor is quite steep sloping up.. ");
    set_items( ([({"wall","walls"}):"The stone here is smooth and polished.","ceiling":
    "The ceiling is only a few meters high here and looks to have been carved out."]));
set_exits((["south":GOBROOMS+"room15a"]));
    set_smell("default", "The air is fresh here with a slight breeze to the north.");
    set_listen("default","You can hear the buzzing of small insects.");
  }

  void reset() {
    ::reset();
  }


