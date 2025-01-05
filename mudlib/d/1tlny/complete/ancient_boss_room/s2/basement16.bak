
#include "../ruins.h"
#include <std.h>
#include <under.h>

inherit "std/room";
int x;
void create() {
::create() ;
set_property("light", 1);
set_property("indoors", 0);
add_exit(ROOMS+"basement15.c", "east");
add_exit(ROOMS+"basement17.c", "south");
set("short", "The Basement Of An Ancient House");
set("day long", @ext The Basement Of An Ancient House. This walls around you
are filled with cracks and chipped paint. The cieling is falling apart and
has alot of holes in it. There seems to be just enough light coming throw
the holes in the ceiling to let you see. You are standing in a small
passage. The passage way continues east and south. You see a old wooden %^YELLOW%^board%^RESET%^ here.

    @--0
    |
    0
ext);

set("night long", @ext The Basement Of An Ancient House. This walls around you
are filled with cracks and chipped paint. The cieling is falling apart and
has alot of holes in it. You are standing in a small passage. The passage
way continues east and south. You see a old wooden %^YELLOW%^board%^RESET%^ here.
   
    @--0
    |
    0
ext);


  add_item("board", "The board looks decayed and rotten to the core should probably %^YELLOW%^search board%^RESET%^");

set_search("board","This board has been sitting here for years and years undisturbed what would happen if you %^YELLOW%^lift%^RESET%^ it?");
 set_search("default"," You see a %^RED%^board%^RESET%^. maybe if you tried to search board you might notice somthing more.");
    
x = 0;
}


void init(){
   ::init();
   add_action("lift_board","lift");
}
int lift_board(string str){
string clas;
  if(!str){
    write("lift what?");
    return 1;
  }
  if(str == "board"){
//    if(!wizardp(this_player())){
//      write("Hmm..seems to be magically stuck. Check back later.");
//      return 1;
//    }
      write("You lift the board and load screams canbe herd from the north as if you tore out someones heart");
      clas = (this_player()->query_class());
      if(x == 0){
        if(clas == "thief" || clas == "child" || wizardp(this_player()) || (this_player()) ){
          tell_room(this_object(),"As the board moves a hidden passage is revealed to the north!");
          add_exit("/d/1tlny/complete/ancient_boss_room/s2/s1.c","north");
          delayed_call("close_door",20);
          x = 1;
        }
        else {
          write("You feel the grate vibrate slightly and suddenly your "
            "dropping through the thick air!!\nYou slam into a stone "
             "floor after dropping through the darkness. As you glance "
            "up you see the grate far above slam shut!");
         say(this_player()->query_cap_name()+" pulls something in the "
           "grate and gasps as the grate collaspes and "+
            this_player()->query_possessive()+" body falls into the "
            "opening!");
         tell_room(UNTHIEF+"thief_du","You hear a scream above you!\n"
          +this_player()->query_cap_name()+" falls through the opening in "
          "the ceiling and slams into the hard stone floor in a cloud "
          "of straw and dust!",this_player());
         this_player()->move(UNTHIEF+"thief_du");
         return 1;
        }
      }
      else {
       if(clas == "thief" || clas == "child" || wizardp(this_player()) || (this_player()) ){
         write("You lift on the board and the secret door vanishes");
         remove_exit("north");
         remove_delayed_call("close_door");
         x = 0;
       }
       else {
          write("You feel the grate vibrate slightly and suddenly your "
            "dropping through the thick air!!\nYou slam into a stone "
             "floor after dropping through the darkness. As you glance "
            "up you see the grate far above slam shut!");
         say(this_player()->query_cap_name()+" pulls something in the "
           "grate and gasps as the grate collaspes and "+
            this_player()->query_possessive()+" body falls into the "
            "opening!");
          this_player()->move(UNTHIEF+"thief_du");
          return 1;
        }
    }
 say(this_player()->query_cap_name()+" lifts the board to the side.");
    return 1;
   }
}
void close_door(){
   remove_exit("north");
   tell_room(this_object(),"The board falls back into place!\n");
   x = 0;
   return;
}

