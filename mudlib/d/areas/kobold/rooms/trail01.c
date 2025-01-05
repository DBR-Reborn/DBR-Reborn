/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
#include <under.h>

inherit ROOM;

int x; 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 0);
   set("short", "Kobold Campgrounds");
   set("day long",
   "This narrow trail heads toward the kobold campgrounds.  Everywhere "
   "kobolds of all shapes and sizes are running from place to place, always "
   "busy doing something.  You hear children laughing and kobold soldiers "
   "barking orders at each other.  You see small tents to the north "
   "clustered together.On the ground you see a %^YELLOW%^glowing stone.%^RESET%^"
   );
   set("night long",
   "In the faint moonlight you can make out the trail that winds through "
   "the kobold campgrounds.  Fires are lit everywhere, and most families "
   "are eating together.  Guards patrol the area and keep an eye out for "
   "nighttime invaders.  You are able to see many small tents to the north "
   "that are clustered closely together.On the ground you see a %^YELLOW%^glowing stone.%^RESET%^"
   );
   set_smell("default", "The scent of cooking flesh fills your nostrils.");
   set_listen("default", "You hear children laughing nearby.");
   set_items( ([
                "tents": "Families probably inhabit those tents.",
({ "stone" }) : "You find a glowing stone you should probably %^YELLOW%^search stone%^RESET%^",
                ]) );
   set_exits( ([
                "northeast":PATH+"trail02",
                "off":"/d/damned/virtual/room_4_13.world",
                ]) );
set_search("stone","You find a glowing stone you wonder if you %^YELLOW%^stare%^RESET%^ at it what might happen?");
 set_search("default"," You see a %^YELLOW%^glowing stone%^RESET%^. Maybe if you search stone you might notice somthing more.");
 x = 0;


}
void init(){
   ::init();
   add_action("stare_stone","stare");
}
int stare_stone(string str){
string clas;
  if(!str){
    write("stare what?");
    return 1;
  }
  if(str == "stone"){
//    if(!wizardp(this_player())){
//      write("Hmm..seems to be magically stuck. Check back later.");
//      return 1;
//    }
      write("You stare at the stone hard and long");
      clas = (this_player()->query_class());
      if(x == 0){
        if(clas == "thief" || clas == "child" || wizardp(this_player()) || (this_player()) ){
          tell_room(this_object(),"Suddenly the stone glows even brighter as it does the room changes and a passage to the north opens up");
          add_exit("/d/1tlny/complete/kobold_boss_room/s.1/s1.c","north");
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
    say(this_player()->query_cap_name()+" stares at the stone.");
    return 1;
   }
}
void close_door(){
   remove_exit("north");
   tell_room(this_object(),"The wall slides back into place!\n");
   x = 0;
   return;
}

