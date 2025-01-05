inherit ROOM;
#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"

int search_count;

void reset() {
    ::reset();
    search_count=0;
}

void create() {
  ::create();
   set_property("light",2);
   set_property("night light",2);
   set_property("indoors", 1);
   set("short", "The kitchen");
   set("day long", @DAY
This is where the halflings maids and cooks serve and slave over
a hot stove, for little pay or appreciation.  The kitchen contains
a lot of counter space, oven, and many hanging utensils for cooking.
A pantry for storing the food is also here, the fat owners of the
house obviously wanting to stalk up on grub.  To the east is
the dining room, and south of here is the living room.
DAY
);
   set("night long", @NIGHT
This is the kitchen, and just because it is night time doesnt mean
there is no activity.  Poorer halflings use this room to cook for
there employers at any time of day, or night.  The room is well lit,
providing easy access to the oven, counters and cooking utensils. 
A pantry used to store mass ammounts of food is here, allowing the
house owners never to leave if they desire.  To the east is a
darkened dining room, and south is a living room.
NIGHT
);
   add_item("oven", "A large fancy oven used to cook large meals");
   add_item("counter", "The counter provides an area for the "+
   "preperation of food.");
   add_item("utensils", "From large spoons to oven mits, the kitchen "+
   "is fully equiped to deal with the houses cooking needs");
   add_item("pantry", "The pantry stores a lot of food.");
   set_listen("default","It sounds like busy cooks working hard.");
   set_smell("default","The smell of food cooking wafts though the air.");
   add_exit(TARAROOMS+"rhs4", "south");
   add_exit(TARAROOMS+"rhs2.c", "east");
    set_search("pantry",(: call_other, this_object(),"do_search" :));
    search_count=0;
}

void do_search() {
  int skill;
  object ob;
  string zplayer;
  say(this_player()->query_cap_name()+" looks like he's searching "+
    "though the pantry.\n");
  skill=((int)this_player()->query_skill("perception"))-15;
  if((random(100)<skill) && search_count<1){
    search_count=1;
    write("You rummage though the pantry.\n"+
      "You manage to find some apples, and set them down.\n");

    ob=new(TARAOBJ+"apples");
    ob->move(this_object());
  }
  else
    write("You find nothing worth eating.");
  return;
}
