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
   add_action("clean_stuff", "clean");
  }

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
      set("short", "Small toolshed");
  set("long", "This is a small toolshed. Here lies a variety of gardening tools"+
  " that the troll gardeners use in the stone garden. There is a small glint"+
  " of light coming through a window on the far side of the room. ");
  add_exit("sg_clearing","east");
  set_smell("default", "It smells very dank and musty in here");
   add_item("tools", "There are many tools lying around including shovels, picks, and gardening forks");
   add_item("shovel", "This looks like a good shovel if you were a gardener. ");
    add_item("picks", "There are some picks lying in the corner, the gardeners to need them to break up the stony ground.");
   add_item("fork", "There is one small gardening fork almost hidden in the corner of the room. It appears to have fallen off the shelf. ");
   add_item("window", "The window is very small and is set into a small alcove. It is extremely dirty."); 
   add_item("alcove", "A small alcove into which the window is set.");
}

   void reset() {
    ::reset();
    if(!present("young_troll")) {
    new(MON_PATH+"young_troll")->move(this_object());
   }
  }

  int clean_stuff(string str) {
if(str == "floor") && if(present("troll cloth",this_player())) {
    message("info", "You should be using a broom to clean the floor, not a cloth", environment());
  }
  if((str == "window") && if(present("troll cloth",this_player()))) {
     message("info", "You rub the cloth against the window and remove some of the dirt from it.",environment());
  }

   if((str == "top of cabinet" && if(present("troll cloth",this_player()))) {
     if(str == "top of cabinet" && if(present("troll cloth",this_player()))) {
    message("info", Wow, cleaning pays off, you find a small chest key, which was covered under a pile of dust.");
    new(OBJ+"chest_key")->move(this_player(this_object());
  // need to make this so it only does it once
   }
   if(str!= window && str!=floor && str!=top of cabinet ) {
   write("Clean what?.");
   }
}
