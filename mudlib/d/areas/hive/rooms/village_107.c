//      Wizard:  Myrddin
//      village_107.c
//      June 97

#include "../defs.h"

inherit "std/room";

void reset(){
  ::reset();
if(!present("ranger")) {
         new(HIV_MON+"ranger")->move(this_object());
         new(HIV_MON+"ranger")->move(this_object());  
 }  
}

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "North Wall");
    set("long",
	"You stand on top of the north wall.  Over the wall, you can "
              "see the ancient forest over a short span of cleared ground.  "
              "In the distance, you can see the sparse crown of a nearby "
              "hill.  To the south, you see the roaring bonfire, while the "
              "walkway continues to the west and to the east.\n" );
    set("night long",
	"You stand on top of the north wall.  Over the wall, you can "
              "barely make out the ancient forest in the moonlight. To the "
              "south, you see the roaring bonfire, while the walkway "
              "continues to the west and to the east.\n" );
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
    ({ "wall", "walls", "embankment" }) :
         "The wall is solid and well made, if only wood.  The earth "
         "embankment on the inside serves to both support the wall "
         "itself and to provide a platform for attacking at opponents "
         "outside the wall.  You can see some planks here along the "
         "edge of the embankment.",
    ({ "light", "bonfire" }) :
         "The bonfire provides the only light in the town.  From here "
         "you can see some figures around it.",
    ({ "crown", "hill" }) :
         "The trees on it are a bit sparse.  It is probably a bit rocky.",
    ({ "moonlight" }) :
         "It glows off the forest and the nearby hill.",
    ({ "figures" }) :
         "You can see the villagers moving slowly, watching for any "
         "danger.",
    ({ "planks" }) :
         "There are some notches cut into them.  From here it looks like "
         "a ladder down.  You could probably 'climb down'.",
    ({ "building", "buildings" }) :
         "The buildings in the village are made of wood, which comes "
         "as no surprise to you.  This place must be very vulnerable to "
         "accidental fires.  You wonder if they have had to rebuild part "
         "of it in the past due to fire.",
]));
    set_exits((["east":HIV_ROOMS+"village_108.c",
                     "west":HIV_ROOMS+"village_106.c"])); 

}


void init() {
        ::init();
        add_action("climb","climb");
}
int climb(string str) {
        if (str == "down") {
                write("You climb down the planks to the ground below.");
                this_player()->move_player(HIV_ROOMS+"village_14");
                return 1;
        }
        else {
        notify_fail("Climb what?\n");
        return 0;
}}



