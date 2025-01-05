//  Wizard: Shade Maelstorm
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
      set("short", "Stone Garden path");
 set("long","The ground is quite level here and the garden looks very well taken care of here. Small pruned shrubs and bushes line either side of the garden path, with several statues placed along next to the path at several points. The stone path goes off to the west here, while a dense area of shrubs seem to overgrow onto the east path. There is a sign pointing south here.");
 add_item("shrubs","The small petrified shrubs growing next to the path have been nicely pruned, although you wonder with what as they seem to be made of stone. The follow the path all the way along, providing a really small hedge on either side.");
 add_item("bushes","There are several bushes further off to the side of the path. They seem to all look similiar, but they do not appear to haven fruit or flowers on them, and you begin to wonder what type of bushes they could be.");
 add_item("path","A stone path goes along the garden floor, its seems to be made of the same material as the boulders at the entrance of the garden. Whatever rock it is, it is quite smooth to touch and white in appearance.");
 add_item("sign","There is a sign here pointing toward the east path. Perhaps you should read it?.\n");
  add_exit("sg_room11","north");
  add_exit("sg_room13","east");
}


  int writing(string str) {
 if((str=="sign") && this_player()->query_lang_prof("troll")>5) {
    write("The signpost has the words 'Forbidden Grove' on it.\n");
  return 1;
  }
   notify_fail("You fail to decipher the writing on the signpost, it appears to be written in some language you do not know, or do not know well enough.\n");
  return 0;
  }

