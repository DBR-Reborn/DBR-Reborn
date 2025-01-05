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
      set("short", "Stone temple entrance");
   set("long",
  "You are standing at the entrance to the Stone Rose temple. A stairway leads "
  "back up to the guard room, and many dimly lit passages head off into the "
  "darkness. The torches which line the walls barely give off enough light to "
  "see by .");
 add_item("walls","The walls in this temple appear to be covered with some kind of green moss. The moss seems to flourish in this dark dank atmosphere, and has grown quite well down here. Most of the walls surface is covered in moss.");
 add_item("stairs","There is a narrow stairway going up from this room into the guards abode. There is a what appears to be a large stone door there at the top of the stairs.");
 add_item("moss","This green plant seems to be covering half the walls. You wonder how anyone or anything could like in such a dismal place.");
 add_item("torches","The torches along the walls provide a dim light just barely enough to see by.");
 add_item("torch","This is one of the torches aligned along the walls here. Unfortunately, this torch appears to be permanently fixed to the wall.");
 add_item("passages","The passages here go off in various directions, if adventurers were not cautious, they could easily get lost.");
   add_exit("small_hut","stairs");
  add_exit("sg_garden1","northwest");
   add_exit("temple4","southwest");
   add_exit("temple3","east");
  add_pre_exit_function("stairs","chk_stairs");
 set_listen("default","You hear the sound of dripping water coming from the tunnels");
}


int chk_stairs(){
  if((present("guard") && this_player()->is_player())
     || (!this_player()->is_player() && !this_player()->id("acolyte")))
  {
    write("You are forbidden to enter the sacred nursery, says the guard "
          "sternly.");
    return 0;
  }
  else 
    return 1;
}


