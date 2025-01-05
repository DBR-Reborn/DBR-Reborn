//      Wizard:  Myrddin
//      village_113.c
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
    set("short", "South Wall");
    set("long",
	"You stand on top of the south wall, directly above the gate.  "
              "Over the wall, you can see the ancient forest over a short "
              "span of cleared ground. You can also see a path leading "
              "south into the forest and beyond.   To the north, you see "
              "the tops of some of the buildings in the village.  The wall "
              "continues to the east and to the west.\n" );
    set("night long",
	"You stand on top of the south wall, directly above the gate.  "
              "Over the wall, you can You can also see a path leading "
              "south into the forest and beyond.   To the north, you see "
              "the tops of some of the buildings in the village, highlighted "
              "by the glow from the fire.  The wall continues to the east "
              "and to the west.\n" );
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
         "outside the wall.  There is no embankment directly below you, "
         "where a space has been left for the southern gate.",
    ({ "fire", "light", "bonfire" }) :
         "The source of the light is too far away to see clearly, but its "
         "light gives form to the buildings in the village.",
    ({ "moonlight" }) :
         "It glows off the forest and the nearby hill.",
    ({ "building", "buildings" }) :
         "The buildings in the village are made of wood, which comes "
         "as no surprise to you.  This place must be very vulnerable to "
         "accidental fires.  You wonder if they have had to rebuild part "
         "of it in the past due to fire.",
    ({ "gate" }) :
         "The gate is made of good hardwood bound in iron bands.  "
         "From your vantage, you can see that it has been left "
         "unguarded.  Perhaps they have bigger worries then a gate no "
         "one is trying to go through.",
]));
set_exits((["east":HIV_ROOMS+"village_112.c",
                 "west":HIV_ROOMS+"village_114.c"])); 
}

