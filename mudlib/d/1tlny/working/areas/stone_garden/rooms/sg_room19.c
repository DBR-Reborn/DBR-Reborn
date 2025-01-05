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
      set("short", "Small stone pathway");
     set("long", "You stand at the entrance of a large stone garden. Several "+
      "tall boulders intricatly carved with figures adorn the left and right side of "+
    "the path leading into the garden of Stone. A rusted open iron gate marks"+
    "the entrance to the garden, the small pebbled path goes into the park.");
    set_items(([
      ({ "passageway", "passage" }) : (: call_other, this_object(), "look_at_passage" :),
      ({ "graffiti", "letters", "lettering", "writing", "write" }) :
       "It doesn't make much sense to you.",
      ({ "alley", "dirty", "dirt" }) : "It is surrounded by brick walls."
      ])); 
  add_exit("sg_clearing","south");
  add_exit("sg_room3","northeast");
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "You hear a strange hissing sound, which sends an icy cold "+
    "shiver down your back. It seems to be coming from further inside the park");
}



