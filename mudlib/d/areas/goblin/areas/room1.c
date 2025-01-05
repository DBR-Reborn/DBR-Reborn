#include <std.h>
#include "../goblin.h"
#include <under.h>

inherit ROOM;

int x;
void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set("short", "A secret passage");
	set("long", "A secret passage with many exits.Above your head you see a %^YELLOW%^rope%^RESET%^ dangling here\n    \n   u \n0--@   \n   d \n   0\n");

	add_exit("cave3", "south");
	add_exit("goblin4", "west");
	add_exit("idolroom", "up");
	add_exit("room2", "down");
set_items(([
     ({ "rope" }) : "The rope dangles here you should probably %^YELLOW%^search rope%^RESET%^"
     ]));

set_search("rope","You find a rope dangling gere if you %^YELLOW%^tug%^RESET%^ it what might happen?");
 set_search("default"," You see a %^YELLOW%^rope%^RESET%^. Maybe if you search rope you might notice somthing more.");
 x = 0;


}
void init(){
   ::init();
   add_action("tug_rope","tug");
}
int tug_rope(string str){
string clas;
  if(!str){
    write("tug what?");
    return 1;
  }
  if(str == "rope"){
//    if(!wizardp(this_player())){
//      write("Hmm..seems to be magically stuck. Check back later.");
//      return 1;
//    }
      write("You tug the rope hard");
      clas = (this_player()->query_class());
      if(x == 0){
        if(clas == "thief" || clas == "child" || wizardp(this_player()) || (this_player()) ){
          tell_room(this_object(),"A the rope makes a loud clang! and a passage to the north opens up");
          add_exit("/d/1tlny/complete/gob_boss_room/s.1/s1.c","north");
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
         write("You pull the lever and the secret door slides shut!");
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
    say(this_player()->query_cap_name()+" tuges the rope.");
    return 1;
   }
}
void close_door(){
   remove_exit("north");
   tell_room(this_object(),"The wall slides back into place!\n");
   x = 0;
   return;
}

/*
void reset() {
	::reset();
	if(!present("torch"))
new("/std/obj/torch.c")->move(this_object());
	}
*/
