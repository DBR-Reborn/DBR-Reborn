//  Wizard: Shade Maelstorm
 // need to alter messages so when boulder rolls back, doesnt currently tell room.
 // few probs with room.
 //1. cant go sw after moving boulder, and im not sure why. it worked
 // before i put in the sit at bench stuff.
 // not sure if the third switch works, ie that it gives you both hp and mp

//  Area: Stone Garden
//  Theme: This is a stone garden, in which basilisks and other stoning
// creatures will play.

//  Monsters: The monsters will include caretakers, guards, gardeners, baby
//  basilisks, and other smaller insects, as well as some stone statues.

#include <std.h>
#include <stone_garden.h>

inherit ROOM;

int sit_count;

void init() {
  ::init();
  add_action("boulder", "rotate");
 add_action("do_sit","sit");
}

void create() {
    ::create();

 sit_count=0;

    set_property("light", 2);
    set_property("indoors", 1);
      set("short", "Southwest corner of Garden");
 set("long","This is the southwest corner of the garden. Various trees and shrubs adorn the sides of the path, and there is a table in a small clearing here.  You spy one small insect on one of the nearby trees right next to the table.");
 add_item("table", "There is a large stone table here. The table top appears smooth and there is two large marble benches for seats. Maybe you should sit down at the table and rest a little?");
 add_item("trees","The trees adorn the garden with brilliant shades of green. Theyre leaves appear deadly silent, though, and for the first time you notice, there is no breeze whatsoever in this garden.");
 add_item("statue","The statues here seem to be primarily of powerful creatures, and there are a few dragon statues here, with evil grinning faces");
 add_item("tree","There is one tree here which overlooks the table. Upon closer inspection, you spy a small insect on its trunk. The tree appears strange somehow, somethings wrong with it...A dread comes over you, as you realise this tree is made of stone. It seems to have retained its colour but seems to be made of solid rock!");
  add_item("insect","There is a small insect on the trunk of this tree. You go to pick it up and find its made of stone......You begin to wonder....");
add_item("shrubs","Many small shrubs line the path here. They add a nice decoration to the garden, and appear nicely pruned.");
  add_exit("sg_room4","north");
  add_exit("sg_room2","east");
   add_post_exit_function("southwest","check_boulder");
}
int boulder(string str) {
  if ( str=="boulder" && this_player()->query_stats( "strength") >120) {
  write("You rotate the boulder revealing a hidden hole path through the stone wall.");
  tell_room(this_object(), "Wierd... "+this_player()->query_cap_name()+" seems to be hugging that big rock over there",this_player());
  add_exit("sg_room19","southwest");
  return 1;
}
  notify_fail("You are not strong enough to move the boulder.\n");
  return 0;
}

 int do_sit(string str) {
  if(str=="on bench" ) {
 if(sit_count<1) {
  sit_count++;
 write("You take a seat on the stone bench and marvel at the stone surroundings.");
 switch(random(3)) {
 case 0:this_player()->add_hp(50)+25;
   break;
case 1:this_player()->add_mp(50)+25;
  break;
case 2:this_player()->add_hp(50)+25;
   this_player()->add_mp(50)+25;
 break;
}
  }
  else
 write("The seat feels quite uncomfortable you notice as you sit down.");
 }
 }
 void reset() {
  ::reset();
  seteuid(geteuid());
   if(!query_night()) {
  new(MON_PATH+"stone_dragon")->move(this_object());
  }
 }

  int check_boulder() {
    message("info","The boulder rolls back into place",environment());
  remove_exit("southwest");
}
