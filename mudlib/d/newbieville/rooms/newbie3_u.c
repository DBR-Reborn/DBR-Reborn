#include "../newbieville.h"
#include <std.h>
#include <under.h>

inherit ROOM;
int x;

void reset() {
	::reset();
	
//if (!present("rat")) {
	  //new("/d/newbieville/mon/rat.c")->move(this_object());
	//}

}


void create() {
    ::create();
    
    set_property("light", 4);
    set_property("indoors", 1);
    set("short", "Upper Level of The Castle of Tailwind");
    set("long", "This is the upper floor of the castle. \n\nTo learn about special mechanics and secret rooms '%^YELLOW%^read sign%^RESET%^'\n\nAfter you learn about some mechanics you should %^RESET%^ '%^YELLOW%^up%^RESET%^' or '%^YELLOW%^u%^RESET%^' for short from this room and get ready to begin your adventure!%^RESET%^");
    add_exit("/d/newbieville/rooms/newbie3", "down");
    add_exit("/d/newbieville/rooms/newbie4", "up");

    //add_exit("/d/newbieville/rooms/newbie3_n", "north");
    //add_exit("/d/newbieville/rooms/newbie3_e", "east");
    //add_exit("/d/newbieville/rooms/newbie3_w", "west");
    //add_exit("/d/newbieville/rooms/newbie3_s", "south");

set_items( (["sign": (: call_other, this_object(), "read_sign" :),
"lever": "a lever that looks like you can pull it",  
]) );
set_search("lever","This lever is made if solid iron you wonder if you '%^YELLOW%^pull lever%^RESET%^' something might happen?");
set_search("default","you see a lever on a stone pidistol what would happen if you '%^YELLOW%^search lever%^RESET%^'");

return;
}

int read_sign() {
string msg;

  msg = @ext

To start you off on some mechanics of DayBreak you see a %^YELLOW%^lever%^RESET%^ on a stone pedestal what would happen if you search lever?


PRO TIP:
You also get 3 free levels. Before you go and use them you must know that you have DEV points and the base cost of all skills resets back to the default on each level. This means from level 1 to level 2 if it the skill costs you 5 dev points to train attack skill but to train it a 2nd time that level it may cost you 30 if you level to level 2 it will only cost you 5 again. To get these free levels you only need to type 'advance' please join a guild first and use all your DEV points on skills or spells before advancing for this reason. You can also choose to level from level 1 without this benefit.
ext;
  this_player()->more(explode(msg, "\n"));
return 1;
}

void init() {
  ::init();
  add_action("read_it", "read");
  call_out("reset",200,this_player());
   add_action("pull_lever","pull");
  return;
}

int read_it(string str) {
   if(str == "sign") {
      read_sign();
   return 1;
   }
   return 0;
x = 0;

}

int pull_lever(string str){
string clas;
  if(!str){
    write("pull what?");
    return 1;
  }
  if(str == "lever"){
//    if(!wizardp(this_player())){
//      write("Hmm..seems to be magically stuck. Check back later.");
//      return 1;
//    }
      write("You pull the lever");
      clas = (this_player()->query_class());
      if(x == 0){
        if(clas == "thief" || clas == "child" || wizardp(this_player()) || (this_player()) ){
          tell_room(this_object(),"The lever makes a loud clang! and a passage going north opens up you should go '%^YELLOW%^north%^RESET%^'");
          add_exit("/d/newbieville/rooms/N2","north");
          delayed_call("close_door",30);
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
    say(this_player()->query_cap_name()+" pulles the lever and a secret door opens to the north");
    return 1;
   }
}
void close_door(){
   remove_exit("north");
   tell_room(this_object(),"The secret door slides back into place!\n");
   x = 0;
   return;
}
