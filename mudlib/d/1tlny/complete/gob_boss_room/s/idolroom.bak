#include <std.h>
#include "../goblin.h"
#include <under.h>

inherit ROOM;

void reset() {
	::reset();
if(!present("statue"))
new(MON+"idol.c")->move(this_object());
if(!present("goblin")) 
new(MON+"goblin_silly.c")->move(this_object());
}

int x;
void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 3);
	set("short", "    \n     \n   @   \n   | \n   0\nThe room with a statue of a god");
	set("long", "This is a large and spacious room which seems to be overtly clean.  There is nothing in this room except for a large statue.  The statue pretty much fills the whole room up with its massive size. behind the statue you see a dnagling %^YELLOW%^chain%^RESET%^\n    \n     \n   @   \n   | \n   0\n");
set_exits( ({(ROOMS+"hallway")}), ({"south"}));
	add_exit("room1", "down");
	add_exit("cave3", "west");
	add_invis_exit("west");
	add_invis_exit("down");
set_items(([

     ({ "boulder", "rock" }) :
        "Huge boulder can be seen on the north wall",
     ({ "chain" }) : "A chain dangles from the statue from the back maybe you should take a closer look at it and %^YELLOW%^search chain%^RESET%^"
     ]));
  set_search("chain","This chain is attached to the statue and appears to be dangling freely from the back maybe if you %^YELLOW%^pull%^RESET%^ it something might happen?");
 set_search("default"," You see a %^YELLOW%^chain%^RESET%^ attached to the statue. maybe if you tried to search chain you might notice somthing more.");
x = 0;
}

void init(){
   ::init();
   add_action("pull_chain","pull");
}
int pull_chain(string str){
string clas;
  if(!str){
    write("pull what?");
    return 1;
  }
  if(str == "chain"){
//    if(!wizardp(this_player())){
//      write("Hmm..seems to be magically stuck. Check back later.");
//      return 1;
//    }
      write("You pull the chain very hard and hear loud clanking sounds");
      clas = (this_player()->query_class());
      if(x == 0){
        if(clas == "thief" || clas == "child" || wizardp(this_player()) || (this_player()) ){
          tell_room(this_object(),"A huge bolder rolls away from a north whole and you see a passage to the north");
          add_exit("/d/1tlny/complete/gob_boss_room/s/s1.c","north");
          delayed_call("close_door",10);
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
         write("You pull the chain and the boulder rolls back into place!");
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
    say(this_player()->query_cap_name()+" pulls the chain with a loud clanking sound.");
    return 1;
   }
}
void close_door(){
   remove_exit("north");
   tell_room(this_object(),"The boulder roles back into place!\n");
   x = 0;
   return;
}
