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
      set("short", "Northwest corner of garden");
 set("long","You at at the northeastern part of the stone garden. The garden path winds and works its way to the west here, small bushes lining the pathway. The sky although bleak and grey shines through the sparse cover of trees which are spaced evenly along the path. Statues line the path, and here and there you stop to notice the wickedly contorted faces on them.");
 add_item("path","The stone path continues to the south and west of here. The path is made up of slabs of stone, arranged in a tile typed fashion. The white stone blocks have been placed together very tightly and looks very professional. It appears as if a great craftsman had been hired to make the path itself.");
 add_item("sky","The sky is bleak, and stormy, occaisionally the sun may peer from behind the clouds, but it is a rare occurrence. It almost looks as if it is about to storm.");
 add_item("statues","The statues here are mainly of peasants and farmers, all have disturbing expressions on their faces or are looking at the ground at something that isnt there.");
 add_item("faces","The faces on the statues are hideously deformed in that all have horrible expressions of fear and terror on them. Many of them appear to be peasants, and they all share the same afflication it would seem. Some have their hands up in front of their faces, while others appear to be looking at the ground.");
 add_item("slabs","These stone slabs make up the path. They are a series of stone blocks arranged in a tile like fashion, packed together very tightly.");
  add_exit("sg_room9","west");
  add_exit("sg_room12","south");
}



