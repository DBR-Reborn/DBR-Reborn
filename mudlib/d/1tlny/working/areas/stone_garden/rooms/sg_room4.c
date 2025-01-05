//  Wizard: Shade Maelstorm
// reminder: fix format of text on notify fail.
//  Area: Stone Garden
//  Theme: This is a stone garden, in which basilisks and other stoning
// creatures will play.

//  Monsters: The monsters will include caretakers, guards, gardeners, baby
//  basilisks, and other smaller insects, as well as some stone statues.

#include <std.h>
#include <stone_garden.h>

inherit ROOM;

 void init() {
  ::init();
   add_action("writing","read");
 }

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
      set("short", "Cross roads");
 set("long","You seem to be at a major intersection within the garden here. The smooth stone path goes off in all four directions, and you spy a small gazebo down the grassed hill to the west. There is a large stone monolith here, which seems to have some scrawling on it. The bushes and trees seem to be less frequent here and you get the impression of being on a very small grassed plain.");
 add_item("path","The stone path heads out in all four directions, north, south, east and west. The west path seems to have a tranquil feel to it, while the eastern path eminates dread. Decisions, decisions.");
 add_item("gazebo", "There seems to be a small gazebo down the hill to the west. Its roof seems to be made of some metal, and seems to reflect when the sun comes out from behind the clouds, which you seem to notice is a rare occurence.");
 add_item("bushes","The bushes are less numerous here, and more of a grassy plain feel to this part of the garden is given. Almost like a grass cemetary....");
 add_item("trees","The trees are few, sparce in this part of the garden. The few ones that are here draw a dark silouhette against the clouded sky.");
 add_item("monolith","The stone monolith here is standing to one side of the crossroads. The scrawling appear to be writing of some sort at first glance. Maybe you should attempt to read the scrawl?");
  add_exit("sg_room5","west");
  add_exit("sg_room3","south");
  add_exit("sg_room6","north");
  add_exit("sg_special_room","east");
}

 int writing(string str) {
 if((str=="scrawl") && this_player()->query_lang_prof("troll")>5) {
   write("The scrawl appears to be be some sort of guide to the garden. The letters on the monoliths base appear to resemble troll work, and you can just make out the message. It says 'north' - Nursery, 'south' - Entrance ,'west' - Gazebo,'east' - Shrine.");
  return 1;
   }
 notify_fail("You fail to decipher the writing, it appears to be written in some language, you do not " +
 "know or do not know well enough.\n");
  return 0;
 }


