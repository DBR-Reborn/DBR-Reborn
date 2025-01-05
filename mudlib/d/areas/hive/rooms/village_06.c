//      Wizard:  Myrddin
//      village_06.c
//      June 97

#include "../defs.h"

inherit "std/room";

int found = 0;

void reset(){
  ::reset();
   }  

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "Forest Path");
    set("long",
	"With the villagers past, the forest is becoming quiet again.  "
              "The trees in the surrounding forest look to be quite "
              "ancient, hiding untold mysteries.  You wish you could talk "
              "to them about the sights they have seen.  Perhaps they "
              "might even be able to warn you of the danger you are "
              "heading toward. Perhaps it would be a good idea to head "
              "back to the south.\n" );
    set("night long",
             "The path continues to the northeast and to the south.  In the "
             "dark, with all the villagers past, the ancient forest fills you "
             "with fear.  Perhaps you should go to Akkad instead.\n");
    set_smell("default", "The fresh smells of the forest start to put you "
             "at east, until you remember that it also signals that you are "
             "all alone.");
    set_listen("default", "The villagers can be heard to the south, but "
              "they are becoming hard for you to hear.");
   set_search("woods", (: call_other, this_object(), "search_woods" :) ); 
   set_items(([
     ({ "forest", "trees", "depths" }) :
        "The forest is thick, filled with ancient trees.  You are deep "
        "within the woods now, and feel the weight of all creation on "
        "your shoulders.",
     ({ "path" }) :
        "It continues to the northeast and to the south.",
     ({ "woods" }) :
        "As you look more closely at the forest, you see something "
        "glinting on the ground.  Maybe one of the villagers dropped "
        "something... perhaps you should search the woods.",
]));
    set_exits((["northeast":HIV_ROOMS+"village_07.c",
                    "south":HIV_ROOMS+"village_05.c"])); 
}


void search_woods() {
   object ob;
   if(this_player()->query_skill("perception") >= 
                              random(50)+25 && found ==0) {
      message("info", "You search the woods and find a broad sword "
                     "hidden at the base of a tree.",
this_player());
      message("info", this_player()->query_cap_name() +
         " searches the woods and finds a discarded broad sword in "
         "them.",
          this_object(), this_player());
      ob = new(HIV_OBJ+"bsword");
      ob->move(this_object());
      found = 1;
   }
   else {
      message("info", "You don't see anything.  You were mistaken if "
                     "you thought something was there.",
         this_player());
      message("info", this_player()->query_cap_name() +" searches "
                     "the woods, but gives up after finding nothing. ",
            this_object(), this_player() );
   }
   return;
}
