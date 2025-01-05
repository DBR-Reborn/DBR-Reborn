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
      set("short", "Garden path");
set("long","As you walk along the path, you can tell that it has been well trodden. Toward the south, the path is a collection of white rounded stones, will to the east, it seems to dissapear altogether turning into a yellow-brown path. Whoever or whatever frequents this byway, you dont know, but by the size of the footprints here, you wouldnt want to find out. The garden statues are few and sparce here, the ones which are here seem to be slightly worn and beginning to show signs of decay.");
 add_item("footprints","The footprints here are seem to resemble demon like, with huge claws out the front, and three major toes, but you cannot be sure. They are big, thats for sure.");
 add_item("footprint","Upon examining one of the many footprints, it is still unclear what it could be, unfortunately you are not a ranger and not skilled with tracking such prints on the ground.");
 add_item("path","The path changes from a collection of smooth white stones coming from the south to a yellow coloured dust to the east.");
 add_item("byway","This section of the stone garden seems to be well used. The statues and garden plants all show signs of stress.");
 add_item("statues","The statues following the path here appear to be starting to show signs of decay here. You would think there would be caretakers or something around here trying to clean things up.");
 add_item("statue","This statue of a man is barely recognisable, it appears to have a drawn sword in its hand, but the sword has been broken at the hilt, and his armour is wearing away. Must be all the rain they have here.");
 add_item("statue sword","The statues sword has been rendered useless by decay.");
  add_exit("sg_room7","south");
  add_exit("sg_room9","east");

 set_listen("default","You hear dull thudding sounds like footsteps in the distance.");
}


  void reset() {
   ::reset();
  seteuid(geteuid());
  if(query_night()) {
  new(MON_PATH+"stone_mage")->move(this_object());
  }
 }

