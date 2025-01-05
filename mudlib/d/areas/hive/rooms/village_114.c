//      Wizard:  Myrddin
//      village_114.c
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
	"You stand on top of the south wall.  Over the wall, you can "
              "see the ancient forest over a short span of cleared ground.  "
              "You can also see a path leading south into the forest and "
              "beyond.   To the north, you see the tops of some of the "
              "buildings in the village.  The wall continues to the east and "
              "to the west.\n" );
    set("night long",
	"You stand on top of the south wall.  Over the wall, you can "
              "You can also see a path leading south into the forest and "
              "beyond.   To the north, you see the tops of some of the "
              "buildings in the village, highlighted by the glow from the "
              "fire.  The wall continues to the east and to the west.\n" );
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
    ({ "building", "buildings" }) :
         "The buildings in the village are made of wood, which comes "
         "as no surprise to you.  This place must be very vulnerable to "
         "accidental fires.  You wonder if they have had to rebuild part "
         "of it in the past due to fire.",
]));
set_exits((["east":HIV_ROOMS+"village_113.c",
                 "west":HIV_ROOMS+"village_115.c"])); 
}

