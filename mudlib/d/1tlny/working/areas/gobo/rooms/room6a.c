  // Area:  Gobo cave
  // Coders: Amel and Arctic
  // May, 97
  // Room: room6a.c
  // Room A standard hallway type room

#include <dirs.h>
#include <std.h>
#include <def.h>
#include "../gobo.h"

inherit "/d/areas/gobo/funs";
  inherit ROOM;

  void create(){
    ::create();
    set_property("indoors", 1);
    set_property("light", -2);
    set("short", "A small underground passage");
set("long","You trudge through the crevice and find the walls close about you.  The small cave has become a narrow passage and you find your shoulders brushing the walls.");
set_items( (["ceiling":"It is to high to see the top as it rises into the darkness.",
({"wall","walls"}):"The walls are solid stone, rough to the touch as it tears at your clothes.  To the west a faint light is coming in through a crevice."]) );
set_exits((["northwest":GOBROOMS+"room6b","crevice":GOBROOMS+"room6"]));
    set_smell("default", "The smell of stagnant water floats on the slight breeze.\n");
    set_listen("default","A soft echo of your footsteps can be heard from the ceiling.\n");
   set_listen("noises","You hear the sounds of fluttering and the faint sound of water drops.\n");
set_pre_exit_functions(({"northwest","crevice"}),({"leave_room"}));
  }

  void leave_room(){
    int falling_check, rand, falling_damage, size_of_stalactite;
    string desc_of_stalactite;
    falling_check = random(100);
    if(falling_check < 5){
    size_of_stalactite = random(2) + 1;
    switch(size_of_stalactite){
      case 1:desc_of_stalactite = "small shard or rock";
           break;
   case 2:desc_of_stalactite = "good size piece of stone";
           break;
   case 3:desc_of_stalactite = "medium boulder chiseled to a fine point";
           break;
    }
      if (skill_check("perception",30)){
write("A "+desc_of_stalactite+" falls from the ceiling narrowly missing you.\n");
say("A "+desc_of_stalactite+" falls from the ceiling narrowly missing "+TPQCN+".\n");
      }
     else{
write("A "+desc_of_stalactite+" falls from the ceiling impaling you with its weight.\n");
      say(TPQN+" is hit by a "+desc_of_stalactite+" that falls from the darkness above.\n");
      rand = random(100);
      falling_damage =size_of_stalactite * rand;
this_player()->add_hp(gen_rand_damage(falling_damage));
   }
    }
  }
  void reset() {
    ::reset();
  }
