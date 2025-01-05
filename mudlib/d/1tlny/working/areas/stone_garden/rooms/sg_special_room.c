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
      set("short", "Shrine");
 set("long", "You are standing before a large shrine, in which appears to be a golden basilisk. The shrine is adorned with precious jewels, and is very well kept. There is a few candles burning just inside shrine, lighting up the inner section and there is a general feeling of awe here. The path encircles the shrine here, then heading off in various directions.");
 add_item("basilisk","There is a large golden basilisk here. Apparently some people here seem to revere this creature of death. The basilisk appears to be made of solid gold, although it still appears menacing.");
 add_item("jewels","There are many jewels set into the shrine. All of them seem permanently stuck there unfortunately.");
 add_item("jewel","This jade jewel is quite large, about the size of a small childs fist. It is just one of the many jewels set into the shrine, and this jewel gives off a irridesent green glow.");
 add_item("candles","There are a few candles lighting the inner part of the shrine. Their light casts shadows on the back wall of the shrine, and seem to enhance the features of the basilisk.");
 add_item("shrine","The shrine stands about 6 foot high from base to roof. There is a small inner area in which the golden basilisk and the candles are. The shrine itself appears to be made of the finest marble and fine jewels run along its surface.");


  add_exit("sg_room4","west");
  add_exit("sg_room9","north");
  add_exit("sg_room14","east");
 set_smell("default","The aroma of incense fills the air here");



}



