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
	set("short", "   \n    \n   @--0\n    \n   \nCity Guard Post");
	set("long",
		"Chairs are scattered about this messy room.  An old wooden "
		"table sits in the center of the room. A black %^BLACK%^flame%^RESET%^ burns here "
"on a torch near the west wall  Old food, cups, mugs, "
		"and plates sit molding upon its top.  A few make shift beds "
		"have been erected on the far wall to allow some to sleep.  "
		"Upon your entrance filthy looking wenches glance over at you.\n   \n    \n   @--0\n    \n   \n"
	);
	set_items( ([
		"chairs": "Old and barely standing, they are about to fall "
			"apart",
		"table": "Initials have been carved all over its surface.",
		"initials": "nEv!n was here.",
		({"food", "cups", "mugs"}): "Mold of various colours have "
			"begun to grow upon them.",
		"beds": "Old dirty rags and blankets, mingle with unwashed "
			"bodies.",
		"wenches": "The smile at you through missing teeth.  Those "
			"teeth that still remain and blackish and disgusting.",
 ({ "flame", "torch", "west wall" }) :
        "It is a black %^BLACK%^flame%^RESET%^, Maybe you should %^YELLOW%^search%^RESET%^ it",
	]) );
set_search("flame","This black %^BLACK%^flame%^RESET%^ burns mythically and magically what would happen if you %^BLACK%^blow%^RESET%^ it?");
 set_search("default"," You see a black %^BLACK%^flame%^RESET%^ burning pitch black. maybe if you tried to search %^BLACK%^flame%^RESET%^ you might notice somthing more.");

	set_exits( ([
		"east": "/d/nocte/kuril/rooms/fountain_square3"
	]) );
	set_door("door", "/d/nocte/kuril/rooms/fountain_square3", "east", 0);
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
          tell_room(this_object(),"As the flame starts to go out you hear screams of death as the wall to the left turns into a dark black undead HOLE");
          add_exit("/d/1tlny/complete/kuril/s2/s1.c","west");
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
         write("You blow on the flame and it begins to burn again you quickly hop back as the flame starts and the wall to the west turns into solid stone again!");
         remove_exit("west");
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
   remove_exit("west");
   tell_room(this_object(),"The flame brightens and the wall to the west turns back into solid stone!\n");
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
