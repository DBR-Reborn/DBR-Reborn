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
 set("long","This is the entrance to another section of the stone garden, the narrow passage being marked either side by tall thick, thorny hedges. There is a sign here also just in front of the narrow passage pointing north.");
 add_item("sign","There is a sign here. Perhaps you should try and read it. It seems to be written in some gutteral kind of scrawl.");
 add_item("nursery","The nursery is just north of here. You see a small black creature running around in there, but youre not sure what it is from here.");
 add_item("hedges","These very tall thorny hedges look quite sharp, and mark the entrance to the passage north.");
  add_exit("sg_room9","south");
  add_exit("sg_garden1","northwest");
  add_pre_exit_function("northwest","chk_nw");
}


int chk_nw(){
  if((present("stone guard") && this_player()->is_player())
  || (!this_player()->is_player() && !this_player()->id("acolyte"))
  || (!this_player()->is_player() && !this_player()->id("guard")))
  {
    write("You are forbidden to enter the sacred nursery, says the guard "
          "sternly.");
    return 0;
  }
  else 
    return 1;
}


  void reset() {
    ::reset();
   if(!present("nursery_guard")) {
   new(MON_PATH+"nursery_guard")->move(this_object());
   }
  }
