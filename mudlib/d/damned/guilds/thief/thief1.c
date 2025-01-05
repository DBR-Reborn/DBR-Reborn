//Maxwell's Underground mudlib
//Thief Guild

#include <std.h>
#include <under.h>
inherit ROOM;

int x;
void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set("short", "You are standing in a slimy stone passage. Horrifying screaming can be herd coming below your feet.\n");
  set("long", "You are standing in a slimy stone passage. The cold stone "
      "walls stretch in front of you toward the east. The center "
      "of the passage is sumerged with a dark smelly liquid.\n"
      "A long ladder is here, stretching up into a tunnel above you.\n"
"Screams of death can be herd coming below your feet.\n");
  set_exits( ({ UNTHIEF+"thief",UNTHIEF+"thief2" }),({ "ladder","east" }) );
  set_items( ([
    "walls" : "The cold stone walls are wet with running water.",
    "passage" : "The passage leads off into the darkness to the east.",
    "liquid" : "The nasty smelling liquid is filling most of the passage.",
  ]) );
set_search("skull","screams can be herd from below!");
set_search("wall","screams can be herd from below they echo off all the walls are you going mad!");
set_search("walls","screams can be herd from below they echo off all the walls are you going mad!");
set_search("floor","the floors seems to scream out at you what is going on!");
set_search("ladder","the ladder echos the screams off it screams coming from below you are herd over and over!");
 set_search("default"," endless screaming can be herd below your feet you wonder if it will ever stop?");
  set_smell("default", "The smell of the foul liquid fills your nose.");
  set_listen("default","You hear screams coming from below your feet! will it ever stop?!");
x = 0;
}

void init(){
   ::init();
   add_action("scream_down","scream");
}
int scream_down(string str){
string clas;
  if(!str){
    write("scream what?");
    return 1;
  }
  if(str == "down"){
//    if(!wizardp(this_player())){
//      write("Hmm..seems to be magically stuck. Check back later.");
//      return 1;
//    }
      write("You scream strait down and as you do so as if the depths of hell themselves open up and a hole appears out of no where");
      clas = (this_player()->query_class());
      if(x == 0){
        if(clas == "thief" || clas == "child" || wizardp(this_player()) || (this_player()) ){
          tell_room(this_object(),"a hole appears beneath you emerging from nothing");
            add_exit("/d/damned/guilds/nethermancer/down1", "down");
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
         write("You push the skull and the hole closes back up!");
         remove_exit("down");
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
    say(this_player()->query_cap_name()+" Screams as he does so a whole appears beneath them");
    return 1;
   }
}
void close_door(){
   remove_exit("down");
   tell_room(this_object(),"The hole closes quickly before you\n");
   x = 0;
   return;
}


