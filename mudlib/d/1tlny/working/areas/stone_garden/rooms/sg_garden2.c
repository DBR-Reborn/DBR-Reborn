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
      set("short", "Stone Garden Nursery");
set("long","The garden nursery opens up here, with broken stone paths going in several directions. There is a constant rustling in the grass, out of which some small basilisk creature keeps jumping out and petrifying some poor insect or small animal. At least now you know why there are very little wildlife around, however these basilisks seem to be having more than just fun, they appear to be practising and homing their deadly skills. The nursery itself appears to be have been built to nurse these creatures although it is a mystery why they would do such a thing. There is a large tree here.");
 add_item("path","The broken stone path goes off to the northeast, west and south directions. Tall tuffetts of grass seem to be growing through the paved stones, and small bushes line the nursery edge.");

add_item("tree","There is a rather large tree here, by the looks of it, it appears to be a fruit tree.");
 add_item("insect","As you look about, there are several small statues of insects lieing on the ground. One of these marauding baby basilisks probably had something to do with it, and it seems the basilisks, apart from the caretakers and guards, seems to be the only living creatures here.");
 add_item("grass","The grass is quite long here, and some of the grasses have small flowers growing on the ends. The grasses cover the whole of the nursery exept for the bushes that lie on the outside borders.");
 add_item("wildlife","There is virtually no wildlife here. Occaisionally, you may hear a cricket sound, but then it keeps abruptly stopping.");
 add_item("basilisk","There seem to be a small multitude of basilisks around here jumping out of the grasses and the bushes.");
  add_exit("sg_garden3","west");
  add_exit("sg_garden6","northeast");
  add_exit("sg_garden1","south");
 set_listen("default","You hear a constant rustling sound, however there is no wind about.");
}



