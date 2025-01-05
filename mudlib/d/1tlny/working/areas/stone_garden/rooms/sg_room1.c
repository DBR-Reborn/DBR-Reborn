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
      set("short", "Inside Stone Garden");
  set("long", "You are just inside the park entrance. There are numerous statues in this park, and as you look around, many of them seem terrifingly real. You can just see the pillars from here, and the stone path continues along to the north. Small bushes and other vegetation lines the edge of the park, and the grass here is a lush green. ");
  add_exit("sg_room2","north");
  add_exit("sg_entrance","east");
  set_listen("default","You hear sounds like metal against stone all around here.");
  add_item("grass", "The grass is a lush green, and provides a nice contrast to the grey statues. The grass blankets the whole area, and it appears as if this park is kept in good repair.");
  add_item("path","The stone path continues to the north and southeast of here. The craftsmanship on it is extraordinary.");
  add_item("pillars","The stone pillars marking the entrance to the garden stand off in the distance almost completely covered behind the few trees and tall bushes that line the edge of the park.");
 add_item("statues","There are several statues here, the most noticeable of which is a warrior.");
 add_item("statue","This statue of a warrior is a grim sight, the musclebound warrior is adorned with stone weapons and armour, and has the most grief stricken expression on his face. His hand is raised up to his face, as it he was trying to block his view of something.");
add_item("bush","This bush is just one of many which adorn the edge of the park. This bush seems nice by appearance from a little way off, but upon close inspection, its leaves appear sharp and thorny.");
add_item("vegetation","The vegetation in the park consists of a few scattered trees, some bushes and a lush carpet of grass.");
add_item("bushes","There are many bushes along the edge of the park and seem to be growing very nicely. Someone has obviously pruned them recently by the looks of their shape.");
}



