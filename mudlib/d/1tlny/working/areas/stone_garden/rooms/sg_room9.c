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
      set("short", "Trampled ground");
 set("long","You enter a heavily trampled part of the stone garden. The path is covered in dust, and there are many footsteps all over thre ground. The few patches of greenery have been trampled into the ground, and this whole part of the garden seems like a huge dustbowl. The grass here is virtually non-existant, and there are no statues at all to be seen here.");
 add_item("path","The white stones of the path are covered under a thick layer of dust. The dust covers all the ground and you start to wonder who or what has been constantly walking around here.");
 add_item("footsteps","There are several footsteps to be seen in the dust, and one is rather larger than the other ones. It is shaped like a birds of preys feet, but much larger in size and with huge claws at the front by the looks of it.");
 add_item("grass","The small amount of grass here is extremely patchy, and barely covers 1/3 of the ground. The rest of it, except for the path is covered in a thick yellow-brown dust.");
 add_item("greenery","About all that remains of the greenery is a few broken branches lieing on the ground. They look sharp, and tripping on them may prove to not be the smartest thing you could do.");
 add_item("ground","The ground here is of a yellow-brown color, with dust all over it, except for the few patches of green grass scattered here and there.");
 add_item("dust","The dust is thick and sticks to almost everything. It is of a yellow-brown colour and has a thick texture.");
 add_item("statues","There are no statues to be seen here, they must have been removed cause they were in danger of getting damaged here by the apparent large flow of traffic.");
    add_exit("sg_room8","west");
  add_exit("sg_room11","east");
  add_exit("sg_room10","north");
  add_exit("sg_special_room","south");
}



