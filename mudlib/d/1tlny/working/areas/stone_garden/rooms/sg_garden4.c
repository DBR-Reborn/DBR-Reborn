//  Wizard: Shade Maelstorm
 // not sure how poison works, but i would like it to go for like random(20)+5 rounds
 // of 7 hp each time
//  Area: Stone Garden
//  Theme: This is a stone garden, in which basilisks and other stoning
// creatures will play.

//  Monsters: The monsters will include caretakers, guards, gardeners, baby
//  basilisks, and other smaller insects, as well as some stone statues.

#include <std.h>
#include <stone_garden.h>

inherit ROOM;
object acolyte;
 int examine_count;

  void init() {
    ::init();
    add_action("rock","examine");
  }

void create() {
    ::create();
 examine_count=0;
    set_property("light", 2);
    set_property("indoors", 1);
      set("short", "Stone Garden Nursery");
 set("long","Walking through the nursery, you come to a thick hedge blocking any further passage north. Shrubs and bushes abound here, with tall grass which is constantly rustling and there is a medium sized rock here, half covered by grass.");
 add_item("hedge","A thick thorny hedge lies to the north here, preventing anyone from going further in that direction.");
 add_item("grass","The grass is long here, and it is constantly moving in certain parts, although there is no breeze about.");
 add_item("rock","To one side of the path, is a medium sized rock, half covered by the grass. Its looks worthy of perhaps a closer examination.");
  add_exit("sg_garden5","east");
  add_exit("sg_garden3","south");
  set_no_clean(1);
 set_listen("default","You hear a constant rustling coming from the grass.");
}


int rock(string str) {
 int skill;

 skill=(int)this_player()->query_skill("perception");
 if(examine_count<3) {
  if( str=="rock" ) {
 examine_count++;
 if((random(100)+10)>skill) {
 write("An immature basilisk jumps out from behind the rock and startles you, causing you to back into the thorny bush!.");
 tell_room(this_object(),this_player()->query_cap_name() +" gets scared when a basilisk jumps out at him unexpectedly, and accidently backs into the thorny hedge.",this_player());
this_player()->add_poisoning(random(30));
 write("%^GREEN%^You have been poisoned!");
}
else
 switch(random(2)) {
case 0:
  write("An immature young basilisk jumps out from behind the rock and attacks you!. ");
  tell_room(this_object(),this_player()->query_cap_name() +" suprises a young basilisk from behind a small boulder. It attacks him. ",this_player());
   new(MON_PATH+"angry_b_basilisk")->move(this_object());
 break;

case 1:write("You find nothing behind the rock.");
  break;
 }
return 1;
}
  notify_fail("What did you want to examine? ");
return 0;
}
   }

void reset() {
  ::reset();
  if(!present("gardener")) 
    new(MON_PATH+"troll_gardener")->move(this_object());
  if(!acolyte)
  { 
    acolyte = new(MON_PATH+"wandering_acolyte");
    acolyte -> move(this_object());
  }
}
