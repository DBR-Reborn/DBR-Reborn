#include <std.h>
#include "nevin.h"
#include <under.h>

inherit ROOM;
int x; 
void create() {
	::create();
	set_property("indoors", 0);
	set_property("light", 1);
	set_property("no castle", 1);
	set("short", "South Canyon Wall");
	set("long", @ext
		In this corner of the canyon, pushed up against the southern 
	wall, is what appears to be a make shift camp.  Pots and pans 
		as well as some animal remains can be found in a large pile.  
		A newly opened wine casks lay covered between some rocks...at 
		least the bandits that are milling about know how to take care 
		of the wine. On the ground you see a strange looking %^YELLOW%^stick%^RESET%^
    0   
    |   
    @--0	
ext);
	set_smell("default", "The smell of unwashed bodies wafts into your nose.");
	set_items( ([
		"camp":  "It's just a small collection of trail beaten tents.",
({ "stick" }) : "You find a glowing stick you should probably %^YELLOW%^search stick%^RESET%^",
                ]) );
	set_exits( ([
		"north": ROOMS+"canyon4.c",
		"east": ROOMS+"canyon6.c"
	]) );
set_search("stick","You find a strange looking stick you wonder if you %^YELLOW%^throw%^RESET%^ it what might happen?");
 set_search("default"," You see astrange looking %^YELLOW%^stick%^RESET%^. Maybe if you search stick you might notice somthing more.");
 x = 0;


}
void init(){
   ::init();
   add_action("throw_stick","throw");
}
int throw_stick(string str){
string clas;
  if(!str){
    write("throw what?");
    return 1;
  }
  if(str == "stick"){
//    if(!wizardp(this_player())){
//      write("Hmm..seems to be magically stuck. Check back later.");
//      return 1;
//    }
      write("You throw the stick has hard as you can");
      clas = (this_player()->query_class());
      if(x == 0){
        if(clas == "thief" || clas == "child" || wizardp(this_player()) || (this_player()) ){
          tell_room(this_object(),"As you throw the stick it magically seems to spin and come right back to the same spot on the floor and something opens up beneath you!");
          add_exit("/d/1tlny/complete/bandit_boss_room/s.1/s1.c","down");
          delayed_call("close_door",20);
          x = 1;
        }
        else {
          write("You feel the grate vibrate slightly and suddenly your "
            "dropping through the thick air!!\nYou slam into a stick "
             "floor after dropping through the darkness. As you glance "
            "up you see the grate far above slam shut!");
         say(this_player()->query_cap_name()+" pulls something in the "
           "grate and gasps as the grate collaspes and "+
            this_player()->query_possessive()+" body falls into the "
            "opening!");
         tell_room(UNTHIEF+"thief_du","You hear a scream above you!\n"
          +this_player()->query_cap_name()+" falls through the opening in "
          "the ceiling and slams into the hard stick floor in a cloud "
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
            "dropping through the thick air!!\nYou slam into a stick "
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
    say(this_player()->query_cap_name()+" throws the stick.");
    return 1;
   }
}
void close_door(){
   remove_exit("down");
   tell_room(this_object(),"The secret door slides back into place!\n");
   x = 0;
   return;
}


void reset() {
	::reset();
	if(!find_object("_bandit1"))
		new(MON+"bandit1.c")->
		move(this_object());
	if(!find_object("_bandit2"))
		new(MON+"bandit2.c")->
		move(this_object());
	if(!find_object("_bandit3"))
		new(MON+"bandit3.c")->
		move(this_object());
	if(!find_object("_bandit4"))
		new(MON+"bandit4.c")->
		move(this_object());
	if(!find_object("bandit leader"))
		new(MON+"bandit_leader.c")->
		move(this_object());
}
