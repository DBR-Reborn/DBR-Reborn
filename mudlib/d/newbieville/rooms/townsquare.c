#include "../newbieville.h"
#include <std.h>
#include <under.h>

inherit ROOM;
int x;
void create() {
    ::create();
    
    set_property("light", 3);
    set_property("indoors", 0);
    set("short", "   0\n   | \n0--@--0\n   castle \n   0\nTown Square.");
    set("long", @ext This is the town square of Newbieville. In every direction, roads branch out to the ends of town. In front of you is a large castle, presumably that of Lord Tailwind. %^B_RED%^If you are a new player you should type %^YELLOW%^castle%^RESET%^
   0   
   |   
0--@--0
   |   castle
   0

ext);
    add_exit(ROOMS+"castle", "castle");
    add_exit(ROOMS+"lightway", "east");
    add_exit(ROOMS+"shadowroad", "west");
    add_exit(ROOMS+"majestyave", "north");
    add_exit(ROOMS+"commonstreet", "south");

set_items(([
"sign": (: call_other, this_object(), "read_sign" :),
"lever": "a lever that looks like you can pull it",       
]));
set_search("lever","This lever is made if solid iron you wonder if you%^YELLOW%^pull%^RESET%^it something might happen?");


}
int read_sign() {
string msg;

  msg =
"The following directions can lead you to Daybreak\n"
"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
"Go %^YELLOW%^south,south,plains,north,west,west,town%^RESET%^ (You will now be in the city of Daybreak go %^YELLOW%^3 north%^RESET%^)\n\n"
"Once you are in daybreak townsquare you can type %^YELLOW%^'help daybreak'%^RESET%^ for a static map of the city\n\n"
"If other players are on and not idle you can also type %^YELLOW%^'newbie (msg)'%^RESET%^and ask for help\n\n"
"It is suggested that you join a guild and start training right away in their guild trainning rooms type %^YELLOW%^'help guilds'%^RESET%^ and read the help (guildname) if you have not already\n\n"
"Do not save DEV points as your skills reset back to base line cost on each level so it is best to spend all DEV points before each level\n\n"
"Also if you want to learn the game further and in more detail you can type"
" %^YELLOW%^'help commands'%^RESET%^ for a list of commands you can input we have help topics for each command by typing help (command name). I also recommend that you type %^YELLOW%^'help topics'%^RESET%^"
"is also useful to read these on your own time or for reference later on if you want to learn that way.\n\n"
"To start you off on some mechanics of DayBreak you see a %^YELLOW%^lever%^RESET%^ on a stone pidestol what would happen if you search lever?" ;
  this_player()->more(explode(msg, "\n"));
  return 1;
}

void init() {
  ::init();
  add_action("read_it", "read");
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
          tell_room(this_object(),"The lever moves and a passage going down opens in the floor!");
          add_exit("/d/newbieville/rooms/N1","down");
          delayed_call("close_door",25);
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
    say(this_player()->query_cap_name()+" pulles the lever and a secret door opens below your feet.");
    return 1;
   }
}
void close_door(){
   remove_exit("down");
   tell_room(this_object(),"The secret door slides back into place!\n");
   x = 0;
   return;
}
