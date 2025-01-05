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
      set("short", "Stone cemetary");
 set("long","You enter what appears to be a stone cemetary. It is basically just a pile of rubble, assorted parts of statues here and there, stone bush branches, all piled high here. This must be where the caretakers take the rubbish when it is no longer needed, or can no longer server the purpose for which it was made. There is just one exit here, to the northeast, and piles of rubble block all other possible exits.");
 add_item("rubble","There is a huge pile of stone rubble before you. Parts of statues, petrified vegetation are just a few of the things which make up the stone garbage.")
 add_item("statues","None of the pieces are really noticable, parts of arms, legs, weapon pieces, and various other stone items.");
 add_item("rubbish","There is heaps of stone rubbish here, piled high into one pile. You know know why most of the garden seems quite tidy, the caretakers bring all the trash here.");
 add_item("branches","The thorny stone branches are scattered through the pile of stone rubbish. I would be careful about what I go touching now.");
 add_item("branch","You see one of many stone brush branches sticking out of the rubbish pile.");
 add_item("stone","There are many stones here of various sizes, many appear to be parts of arms, hands, and other statue parts.");
 add_item("arms","Yes, you notice some broken stone arms here in the rubbish pile.");
 add_item("hands","One hand with four fingers is at the base of the stone pile.");
  add_exit("sg_clearing","northeast");
    set_smell("default", "A horrible, rotten smell permeates the air.");
    set_listen("default", "You hear a strange hissing sound, which sends an icy cold "+
    "shiver down your back. It seems to be coming from further inside the park");
}



