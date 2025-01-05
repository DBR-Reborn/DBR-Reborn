//  Wizard: Shade Maelstorm
 // not sure where the brackets should go in this one , boggle
//  Area: Stone Garden
//  Theme: This is a stone garden, in which basilisks and other stoning
// creatures will play.

//  Monsters: The monsters will include caretakers, guards, gardeners, baby
//  basilisks, and other smaller insects, as well as some stone statues.

#include <std.h>
#include <stone_garden.h>

inherit ROOM;
 int pick_count;

  void init() {
    ::init();
    add_action("flower","pick");
  }

void create() {
    ::create();
 pick_count=0;
    set_property("light", 2);
    set_property("indoors", 1);
      set("short", "North east corner of Nursery");
  set("long","You have reached the northeastern corner of the nursery. The statues that are in the nursery are quite few, however there are more trees here. The northeastern corner resembles more of a small woodland, although you still see gardeners digging up some parts of the garden and weeding it. There are small flowers and grasses growing all around here.");
 add_item("statues","The few statues here appear to be of small animals rather than of man sized ones, some of which are of rabbits, rats, and even the occaisional deer.");
add_item("trees","There are quite a few trees here, all appear to be made of petrified wood.");
 add_item("rabbit","The rabbit statue is one of the few animal statues that seem to be prevalent in this part of the garden. It looks very real, but is hard as stone.");
add_item("rat","One of the rat statues is of a large rat, which has an aggressive look on its face. It appears as if it lost the fight of its life.");
add_item("deer","There is one deer statue in the middle of this corner of the nursery. The statue itself appears to be looking at something on the ground, however there is nothing there to look at.");
add_item("gardeners","There seem to be some gardeners digging up the garden in the nursery, this evident by the patches of freshly turned dirt in several areas. They appear to be planting some type of plant, although the plants here are quite young, and you are unable to tell what plant it actually is.");
add_item("plant","There are small seedlings which seem to have been planted here in some patches.");
 add_item("patches","Patches of dirt have been dug up by someone in order to plant some type of seedlings which are growing here.");
 add_item("seedlings","The seedlings appear to be of a small plant, and are way to young to be able to tell what plant they are.");
 add_item("flowers","There are several flowers here, however there is one which really catches your eye.");
 add_item("flower","There is a large flower rising out of the long grass here, although you are unsure whether it is meant to be here or not though.");
  add_exit("sg_garden5","west");
  add_exit("sg_garden2","southwest");
}


int flower(string str) {
  if( str=="flower" ) {
 if(pick_count<2) {
 pick_count++;
  write("As you reach down to pick up the flower, a young basilisk jumps out and barely misses your hand, petrifying the flower by mistake. It decides it doesnt like you and attacks. ");
  tell_room(this_object(),"A small basilisk jumps from a nearby patch of grass, and petrifys a small flower narrowly missing "+this_player()->query_cap_name() +"",this_player());
   new(MON_PATH+"baby_basilisk")->move(this_object());
 }
 else write("The flower is apparently already petrified, and crumbles in your hand as you pick it up.");
 remove_item("flowers");
 remove_item("flower");
 add_item("flowers","There are several flowers here, all of which are barely just budding.");
 add_item("flower","There are pieces of stone fragments of what look like flower petals laying on the ground.");
 add_item("fragments","There are small stone flower fragments lieing on the ground here.");
}
  notify_fail("What did you want to pick? ");
return 0;
}

  void reset() {
  ::reset();
  if(!present("caretaker")) {
new(MON_PATH+"caretaker")->move(this_object());
}
    if(!present("troll_gardener")) {
    new(MON_PATH+"troll_gardener")->move(this_object());
}
  }
