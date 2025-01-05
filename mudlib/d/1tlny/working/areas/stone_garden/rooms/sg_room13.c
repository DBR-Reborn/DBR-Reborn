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
      set("short", "Northern hillside");
 set("long","You work your way along the northern hillside on the garden. The stone path continues up and down the hill, but the vegatation seems to overgrow it in places until it is continually hidden from view. Down the hillside, you see a small clearing in the distance, while further up the hill, the woods continue.");
 add_item("hillside","The hill here is of a nice gradual slope leading down into what appears to be a small clearing far below.");
 add_item("path","The stone path which runs throughout the garden, continues up and down the hillside, twisting this way and that to avoid huge stone trees, which seem to cover the path, and the hillside in a deep shade.");
 add_item("clearing","There appears to be a clearing far below at the bottom of the hill.");
 add_item("woods","The trees here are thick and wide, their huge branches preventing most of the light from reaching the hillside. The hillside itself must from the outside look like a huge green mound, with trees covering its whole surface, except for a few spots.");
 add_item("trees","As with all the other vegetation, the trees seem to be made of stone. Their petrified trunks are quite huge, their branches equally so, spreading across each other, so as to block out most sunlight from this place. You would tend to wonder how the plants underneath the canopy would grow with such little sunlight.");
 add_item("plants","The plant life here consists of many grasses, shrubs and bushes, which seem to be rampant here.");
 add_item("grasses","The grasses appear to be the only vegetation that isnt made of stone you notice. It forms a nice natural cover to the woodland floor.");
 add_item("shrubs","There are many small shrubs growing on this hillside. They all appear to be the same types however, and all appear petrified, their small thorny branches however signalling a potential hazard to the unwary.");
 add_item("bushes","The bushes and shrubs are growing freely on the hillside, looking like small porcelain models.");
  add_exit("sg_room12","west");
  add_exit("sg_room14","south");

 set_listen("default","You hear a trickling sound of water far off in the distance.");
}
 void reset() {
  ::reset();
 seteuid(geteuid());
 if(!query_night()) {
  new(MON_PATH+"adult_basilisk")->move(this_object());
  }
 }


