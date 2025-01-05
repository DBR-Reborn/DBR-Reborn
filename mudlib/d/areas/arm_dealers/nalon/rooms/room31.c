#include <dirs.h>
#include <std.h>
#include "../monk.h"
#include <under.h>

inherit ROOM;

int x;
void create() {
  ::create();
   set_property("light",2);
   add_exit(MONKROOMS+"room26", "east");
   set("short","Meditation area   \n    \n   @--0\n    \n   \n");
   set("long",
"This is where peaceful monks come to relax and "
"meditate.  A soft grassy area has been cleared out "
"for them to sit while they ponder the meaning of life. "
"To the east is a fire pit. You see a %^YELLOW%^Buddha%^RESET%^ here.    \n    \n   @--0\n    \n   \n");
   add_item("fire pit","A large fire pit in which the monks "
"burn special materials with there wood, to help expand "
"there minds.");
   add_item("pit","A large fire pit in which the monks "
"burn special materials with there wood, to help expand "
"there minds.");
   add_item("area","A soft patch of grass to keep the monks "
"comfortable while they meditate.");
  add_item("buddha", "The large buddha sits in front of the north wall you should probably %^YELLOW%^search buddha%^RESET%^");
set_search("buddha","You find a buddha set not to firmly maybe if you %^YELLOW%^push%^RESET%^ it out of the way you can see what is behind it");
 set_search("default"," You see a %^YELLOW%^buddha%^RESET%^. Maybe if you search buddha you might notice somthing more.");
 x = 0;


}
void init(){
   ::init();
   add_action("push_buddha","push");
}
int push_buddha(string str){
string clas;
  if(!str){
    write("push what?");
    return 1;
  }
  if(str == "buddha"){
//    if(!wizardp(this_player())){
//      write("Hmm..seems to be magically stuck. Check back later.");
//      return 1;
//    }
      write("You push the buddha out of the way");
      clas = (this_player()->query_class());
      if(x == 0){
        if(clas == "thief" || clas == "child" || wizardp(this_player()) || (this_player()) ){
          tell_room(this_object(),"A The buddha moves and a passage to the north opens in the wall!");
          add_exit("/d/1tlny/complete/caravan_boss_room/s/s1.c","north");
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
    say(this_player()->query_cap_name()+" Pushes the buddha to the side.");
    return 1;
   }
}
void close_door(){
   remove_exit("north");
   tell_room(this_object(),"The buddha slides back into place!\n");
   x = 0;
   return;
}

void reset() {
  ::reset();
   if(!present("monk")){
   new(MONKMOBS+"med_monk.c")->move(this_object());
   new(MONKMOBS+"med_monk.c")->move(this_object());
   new(MONKMOBS+"med_monk.c")->move(this_object());
   }
}
