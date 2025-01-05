//      Wizard:  Myrddin
//      village_109.c
//      June 97

#include "../defs.h"

inherit "std/room";

void reset(){
  ::reset();
}  

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "East Wall");
    set("long",
	"You stand on top of the east wall.  Over the wall, you can "
              "see the ancient forest over a short span of cleared ground, "
              "and some plains beyond that.  To the west, you see the tops "
              "of some of the larger buildings in the village.  The wall "
              "continues to the north and to the south.\n" );
    set("night long",
	"You stand on top of the east wall.  Over the wall, you can "
              "barely make out the ancient forest in the moonlight.  To "
              "To the west, you see the tops of some of the larger "
              "buildings in the village, highlighted by the glow from the "
              "fire.  The wall continues to the north and to the south.\n" );
set_smell("default", "The smells of human habitation mix with the "
                    "smells of the forest.  The smell of smoke lingers over it "
                    "all.");
    set_listen("default", "The village is completely silent.");
    set_items(([
     ({ "forest", "woods", "trees", "depths" }) :
         "The forest is thick, filled with ancient trees.  They have been "
         "cleared for a short distance around the village.",
    ({ "village" }) :
         "It is definitely small.  Not many people could live in it "
         "comfortably.  Perhaps no one lives in it anymore.",
    ({ "wall", "walls", "embankment", "walkway" }) :
         "The wall is solid and well made, if only wood.  The earth "
         "embankment on the inside serves to both support the wall "
         "itself and to provide a platform for attacking at opponents "
         "outside the wall.",
    ({ "fire", "light", "bonfire" }) :
         "The source of the light is too far away to see clearly, but its "
         "light gives form to the buildings in the village.",
    ({ "moonlight" }) :
         "It glows off the forest and the nearby hill.",
    ({ "plains" }) :
         "They are too far to see clearly, but they would probably be a "
         "good place to set up a farm.  Maybe it's not too late for a "
         "career change.",
    ({ "building", "buildings" }) :
         "The buildings in the village are made of wood, which comes "
         "as no surprise to you.  This place must be very vulnerable to "
         "accidental fires.  You wonder if they have had to rebuild part "
         "of it in the past due to fire.",
]));
set_exits((["north":HIV_ROOMS+"village_108.c",
                 "south":HIV_ROOMS+"village_110.c"])); 
}

