#include <std.h>
#include "nevin.h"
#include <under.h>
inherit "/std/vault";




int x;
void create(){
	::create();
	set_property("indoors", 1);
	set_property("light", 2);
	set_property("no castle", 1);
	set("short", "   \n    \n0--@   \n    \n   \nSouth City Guard Post");
	set("long",
		"Tables and chairs have been thrown carelessly into the "
		"corner in order to leave space for make shift beds in the "
		"center of the room.  Bottles and dirty clothing have been "
		"heaped in a corner. A blue %^BLUE%^flame%^RESET%^ burns here "
"on a torch near the east wall  This is the South City Guard Post.  "
		"With the rise of the School of Necromancy, the city guard "
		"has become lazy and inefficient.  Especially with the "
		"elite watchman patrolling the streets, the guard has been "
		"left with little to do except gamble, drink, and cause "
		"trouble.\n   \n    \n0--@   \n    \n   \n"
	);
	set_items( ([
		({"tables", "chairs"}): "From the look of them, they're in "
			"no condition to be used anyway.",
		"beds": "A bed of straw and blankets have been thrown into "
			"together.",
		({"bottles", "clothing", "heap"}): "Time to clean up perhaps?",
    ({ "flame", "torch", "east wall" }) :
        "It is a blue %^BLUE%^flame%^RESET%^, Maybe you should %^YELLOW%^search%^RESET%^ it",
	]) );
set_search("flame","This blue %^BLUE%^flame%^RESET%^ burns mythically and magically what would happen if you %^BLUE%^blow%^RESET%^ it?");
 set_search("default"," You see a blue %^BLUE%^flame%^RESET%^ burning brightly. maybe if you tried to search %^BLUE%^flame%^RESET%^ you might notice somthing more.");

    add_exit("/d/nocte/kuril/rooms/magus_lane4","west");

	set_door("door", "/d/nocte/kuril/rooms/magus_lane4", "west", 
		"kuril south guard post key");
	set_open("door", 1);
	set_locked("door", 0);
x = 0;
}


void init(){
   ::init();
   add_action("blow_flame","blow");
}
int blow_flame(string str){
string clas;
  if(!str){
    write("blow what?");
    return 1;
  }
  if(str == "flame"){
//    if(!wizardp(this_player())){
//      write("Hmm..seems to be magically stuck. Check back later.");
//      return 1;
//    }
      write("You blow on the flame and the room goes deadly silent");
      clas = (this_player()->query_class());
      if(x == 0){
        if(clas == "thief" || clas == "child" || wizardp(this_player()) || (this_player()) ){
          tell_room(this_object(),"As the flame starts to go out you hear screams of death as the wall to the right turns into a huge skeleton head and it's mouth opens wide!");
          add_exit("/d/1tlny/complete/kuril/s1/s1.c","east");
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
         write("You blow on the flame and it begins to burn again you quickly hop back as the flame starts and the wall to the east turns into solid stone again!");
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
    say(this_player()->query_cap_name()+" blows on the flame and the world feels like it goes deep into dispair");
    return 1;
   }
}
void close_door(){
   remove_exit("east");
   tell_room(this_object(),"The flame brightens and the wall to the east turns back into solid stone!\n");
   x = 0;
   return;
}

void reset() {
	::reset();
	if(!present("watchman")) {
		new("/d/nocte/kuril/mon/wm_fighter")->move(TO);
		new("/d/nocte/kuril/mon/wm_fighter")->move(TO);
	}

}
