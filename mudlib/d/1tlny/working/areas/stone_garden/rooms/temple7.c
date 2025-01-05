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
      set("short", "Domed room.");
 set("long","You emerge from one the tunnels into a large domed room. There are many archways leading out of here, and all of them look identical. You have found what the sound of dripping water was coming from. There is a small fountain in the centre of the room. The water flow from the fountain has been reduced to almost nothing.");
 add_item("fountain","There is a small fountain here, that must draw its water from further underground. The water in the fountain's basin appears to change color slightly, although with the increased light in the room, it is still not bright enough to be sure.");
 add_item("archways","The exits from this room a huge stone arches, leading to passages to other rooms of the temple. They are all similiar and it is very hard to tell which one you just came from.");
 add_item("walls","The walls in this temple appear to be covered with some kind of green moss. The moss seems to flourish in this dark dank atmosphere, and has grown quite well down here. Most of the walls surface is covered in moss.");
add_item("moss","This green plant seems to be covering half the walls. You wonder how anyone or anything could like in such a dismal place.");
add_item("torches","The torches along the walls seem to be brighter here, the light while not ideal, is much better here, and you can just make out the ceiling of the domed room.");
 set_listen("default","You hear the sound of trickling water here.");

  add_exit("temple4","northwest");
   add_exit("temple5","north");
  add_exit("temple6","southwest");
  add_exit("temple2","east");
  add_exit("temple8","south");
}


