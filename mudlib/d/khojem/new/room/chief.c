//      Wizard:  Khojem
//      Orc Chief's Chambers
//      chief.c

#include <std.h>
#include <under.h>

inherit ROOM;

void reset() {
	::reset();
    if (!present("half-orc bodyguard" , this_object()) ) {
      new("/d/khojem/new/mon/orc_bodyguard")->move(this_object());
    }
    if (!present("half-orc chief" , this_object()) ) {
      new("/d/khojem/new/mon/orc_chief")->move(this_object());
    }
}

int x;
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "Half-Orc Chief's Chamber");
    set("long", "You are in the Half-Orc Chief's Chamber.  "+
      "From here the chief makes his plans against the Wood-Elves.  "+
      "A small%^RED%^fire%^RESET%^burns here for light and warmth in the dank cave.\n   \n    \n0--@   \n    \n   \n"
    );
    add_exit("orc9","west");
    set_items(([
     ({ "cave","cavern", "chamber" "chief's chamber" }) :
        "The walls are bare dirt.",
     ({ "walls", "floor" }) :
        "The walls and floor are very hard, dry clay.  Digging out "+
        "would be an impossible task.",
     ({ "fire", "small fire" }) :
        "It is a very, small wood fire and close to burning out. Maybe you should%^YELLOW%^search%^RESET%^it"
    ]));
set_search("fire","This fire burns mythically and magically what would happen if you%^YELLOW%^stomp%^RESET%^it?");
 set_search("default"," You see a%^RED%^fire%^RESET%^burning brightly. maybe if you tried to search fire you might notice somthing more.");
    set_smell("default", "A dank, musty smell fills the air.  You can "+
      "smell wood burning and food cooking.");
    set_listen("default", "The cave is very quiet.");
x = 0;
}


void init(){
   ::init();
   add_action("stomp_fire","stomp");
}
int stomp_fire(string str){
string clas;
  if(!str){
    write("stomp what?");
    return 1;
  }
  if(str == "fire"){
//    if(!wizardp(this_player())){
//      write("Hmm..seems to be magically stuck. Check back later.");
//      return 1;
//    }
      write("You stomp on the fire giggling the whole time");
      clas = (this_player()->query_class());
      if(x == 0){
        if(clas == "thief" || clas == "child" || wizardp(this_player()) || (this_player()) ){
          tell_room(this_object(),"As the fire starts to go out with the burning embers they last fire spakrs leap out to the east wall and burn away a hidden passage!");
          add_exit("/d/khojem/new/room/s2/s1","east");
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
         write("You stomp on the fire and it begins to burn again you quickly hop back as the fire starts and the wall to the east turns into solid rock again!");
         remove_exit("east");
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
    say(this_player()->query_cap_name()+" stomps on the fire giggling the whole time");
    return 1;
   }
}
void close_door(){
   remove_exit("east");
   tell_room(this_object(),"The fire ignites in a huge flame and the wall to the east turns back into solid rock!\n");
   x = 0;
   return;
}
