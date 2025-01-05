#include <daemons.h>
#include <stone_garden.h>

inherit "/std/vault";

private int open;

 void init() {
  ::init();
   add_action("insert_medal", "insert");
}

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",3);
   add_exit("/wizards/shade/stone_garden/rooms/sg_clearing", "west");
   set_door("stone door", "/wizards/shade/stone_garden/rooms/sg_clearing", "west",
  "stone garden key");
   set_open("stone door", 0);
   set_locked("stone door", 1);
   set("short","Guard room");
   set("long",
  "This is a guard room where the stone soldiers sleep at night. There are "
  "beds of granite on both sides of the room, and a few figures sleeping. "
 "There is a stone door to the west and an iron door to the south.");
 add_item("stone door","The stone door to the west is quite big, and made of what looks to be solid granite. Its fit into the wall of the hut is very snug, and it has a large ring for a handle, and a large iron lock.");
 add_item("ring","There is a large ring here for a door handle.");
}


  void reset() {
  int i;
  ::reset();
  seteuid(geteuid());
    if(query_night()) {
     if(!present("sleeping_caretaker")) {
  i=2;
  while(i--)
  new(MON_PATH+"sleeping_caretaker")->move(this_object());
    }
   }

  if(!query_night()) {
   if(!present("caretaker")) {
  i=2;
  while(i--)
    new(MON_PATH+"caretaker")->move(this_object());
   }
  }
}


  int insert_medal(string str) {
  //need to alter it to test if person has medallion
 // need to add query limbs
  if(str == "medal into groove") {
write("You insert the Stone Rose medallion into the groove in the wall and an "
  "staircase appears leading down into the darkness below ");
  tell_room(this_object()," "+this_player()->query_cap_name()+"puts his hand up to "+
  "the wall, and a door suddenly opens, revealing a staircase leading down.",this_player());
  add_exit("/wizards/shade/stone_garden/rooms/temple2","stairs");
 return 1;
}
}
