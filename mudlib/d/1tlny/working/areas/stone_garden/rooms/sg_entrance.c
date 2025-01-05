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
    set_property("outdoors", 1);
   set_property("night light",0);
      set("short", "Entrance");
     set("long", "You stand at the entrance of a large stone garden. Several "+
      "tall boulders intricatly carved with figures adorn the left and right side of "+
  "the path leading into the garden of Stone. A rusted open iron gate marks "+
    "the entrance to the garden, the small pebbled path goes into the park.");
  add_item("boulders","There are tall boulders of granite adorning the sides of the path here.");
    add_exit("sg_room1","west");
    add_exit("sg_room18","east");
    set_listen("default", "You hear a strange hissing sound, which sends an icy cold "+
    "shiver down your back. It seems to be coming from further inside the park");
add_item("path", "The path here seems to consist of smooth stone granite slabs. Its texture is rough, and the slabs are quite firmly put together. An experienced craftsman must have made this path at one stage");
 add_item("gate","The gate seems to be rusted open. It is a large black iron gate, with small spearlets on the top of it, and is extremely strong. It needs a good oiling, but even then, you doubt if it will ever open and close once more.");
 add_item("iron gate","The gate seems to be rusted open. It is a large black iron gate, with small spearlets on the top of it, and is extremely strong. It needs a good oiling, but even then, you doubt if it will ever open and close once more.");
 add_item("rusted gate","The gate seems to be rusted open. It is a large black iron gate, with small spearlets on the top of it, and is extremely strong. It needs a good oiling, but even then, you doubt if it will ever open and close once more.");
 add_item("boulder","This is one of the stone pillars that mark the entrance to the stone garden. They seem to be made of marble and are very smooth. ");
 add_item("boulders","There are two boulders on either side of the path, tall marble columns which mark the garden entrance. They are tall, and the columns themselves are very smooth");
}



 void reset() {
  int i;

  ::reset();
  seteuid(getuid());
 if(!present("garden_guard")) {
  i=2;
  while(i--)
  new("/wizards/shade/stone_garden/mon/garden_guard")->move(this_object());
  }
 }
