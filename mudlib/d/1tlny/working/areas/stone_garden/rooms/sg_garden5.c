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
      set("short", "Small pathway");
 set("long","You are walking along a small pathway of broken stone. You see several gardeners here and there cultivating and pruning the various shrubs and bushes here. Long grasses grow through the broken stone and various plants and flowers appear to be thriving here.");
 add_item("stone","The stone appears to be of the same rock as the path in the rest of the garden, just that for some reason, it is crumbling in this area. Someone obviously needs to do some repair work on this part of the path.");
 add_item("gardeners","There are, or were several gardeners around here. You can tell by the tools lieing all over the ground.");
 add_item("shrubs","Various small shrubs are growing quite nicely here. They look like they need a good pruning to me. The gardeners seem to have missed a few patches of bush.");
  add_exit("sg_garden6","east");
 add_item("plants", "Small plants are growing through the long grasses here. Strangely enough, they appear to be the same plant.");
 add_item("flowers","Numerous small flowers are growing in the nursery, and occaisionally you see a small bee land on one of them, before a baby basilisk jumps out of the grass and petrifies it.");
 add_item("bee","There are no bees to be seen at this moment, and the air is silent except for that damn rustling sound in the grass all the time.");
  add_exit("sg_garden4","west");
}

  void reset() {
    ::reset();
    if(!present("baby_basilisk")) {
     if(!present("troll_gardener")) {
     new(MON_PATH+"troll_gardener")->move(this_object());
     }
    new(MON_PATH+"baby_basilisk")->move(this_object());
  }
}


