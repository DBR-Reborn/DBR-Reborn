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
    set_property("light", -4);
    set_property("indoors", 1);
      set("short", "Grove");
 set("long","You have entered a grove in the midst of the garden. Tall hills surround the grove to the north, south, and west, thick brush to the east. Mist hangs in the air here, and it is quite cold. There is an errire feeling here, and as you look around, you notice a few statues with a rather odd feature. Apart from the statues, the grove appears quite tranquil, although bitterly cold. Through the patches in the tree canopy, the few sky which you can see is overcast and stormy.");

 add_item("grove","You are standing in a small clearing with trees and statues lining the clearing, also referred to as a grove.");
 add_item("hills","The hills seem to surround the grove in most directions, trapping the mist and cold that is present here. There is a set of stairs to the south up the sleep incline, but the path seems to be obscured by the dense plant life.");
 add_item("mist","There is a chilling cloud of mist covering the whole of the grove. It hangs suspended in the air, and clings to your clothing making it wet and cold. The whole of the grove is strangely silent, and you notice the trees are deadly still. There is no breeze to be felt, and no warming sun to be seen. It is unbearably cold here.");
 add_item("statues","There are a ring of statues forming a circle around the grove here. They stand upright, all dew covered and each having a particularly evil grin on their faces. Hmm, maybe its just the mist delfecting the light? Still, they all seem to be grinning. There is one big nasty sob statue here also, a huge gargoyle statue with a wicked grin on its face, and it seems to be watching you.");
 add_item("patches","The patches in the tree canopy provide a little light, but the light shining through is nowhere near enough to lift the veil of mist that is hanging here.");
 add_item("canopy","The canopy provided by the trees is quite thick and prevents the cold from leaving this place. It wards of the sunlight like an evil curse, plunging this otherwise tranquil small clearing into a bitterly cold and dank one.");
 add_item("sky","There is one small patch through the canopy which is barely big enough to see part of a sky, overcast and stormy.");
 add_item("sun","There is no sun that you can see, just a few filtered rays of sunlight, making the area slightly easier to see in.");
  add_exit("sg_room13","north");
  add_exit("sg_room15","east");
  add_exit("sg_room16","steps");

 set_listen("default","You hear the sound of water nearby.");
}



