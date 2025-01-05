//      Wizard:  Myrddin
//      village_24.c
//      June 97

#include "../defs.h"

inherit "/std/room";

int found_a;
int found_b;
int found_c;

void reset(){
  ::reset();
  found_a = 0;
  found_b = 0;
  found_c = 0;
}  

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Village Store");
    set("long",
	"A quick glance tells you that this is the villages store.  The "
              "same glance tells you that it was  stripped of valuables "
              "when most people fled the village.   All you see are empty "
              "shelves, a box and barrels along the bare walls.\n" );
    set_smell("default", "Moving indoors finally gets you away from "
              "the smell of the smoke.");
    set_listen("default", "The building is silent, though you hear the "
             "faint echo of people outside.");
    set_search("shelves", (: call_other, this_object(), "search_shelves" :) ); 
    set_search("box", (: call_other, this_object(), "search_box" :) ); 
    set_search("barrels", (: call_other, this_object(), "search_barrels" :) ); 
    set_items(([
     ({ "barrel", "barrels" }) :
         "Most of the barrels were taken from the store when everyone "
         "fled.  A couple broken ones remain in the store.",
     ({ "box", "boxes" }) :
         "Only one broken box remains.",
     ({ "shelf", "shelves" }) :
         "The shelves are bare, though something might have gotten "
         "missed in the rush to escape.",
]));
    set_exits((["east":HIV_ROOMS+"village_13.c",
                     "south":HIV_ROOMS+"village_15.c"])); 

}

void search_shelves() {
   object ob;
   if(this_player()->query_skill("perception") >= 
                              25 && found_a ==0) {
      message("info", "You search the shelves and find a bag left on "
                    "one.",
this_player());
      message("info", this_player()->query_cap_name() +
         " searches the shelves and finds a bag left on one of them.",
          this_object(), this_player());
      ob = new(HIV_OBJ+"bag");
      ob->move(this_object());
      found_a = 1;
   }
   else {
      message("info", "You don't find anything.  This place was "
                    "stripped very efficiently.",
         this_player());
      message("info", this_player()->query_cap_name() +" searches "
                     "the shelves, but gives up after finding nothing. ",
            this_object(), this_player() );
   }
   return;
}

void search_box() {
   object ob;
   if(this_player()->query_skill("perception") >= 
 			25 && found_b ==0) {
      message("info", "You search the box and find some food in it.",
this_player());
      message("info", this_player()->query_cap_name() +
         " searches the box and finds some food in it.",
          this_object(), this_player());
      ob = new(HIV_OBJ+"pigsfeet");
      ob->move(this_object());
      found_b = 1;
   }
   else {
      message("info", "You don't find anything.  This place was "
                    "stripped very efficiently.",
         this_player());
      message("info", this_player()->query_cap_name() +" searches "
                     "the box, but gives up after finding nothing. ",
            this_object(), this_player() );
   }
   return;
}

void search_barrels() {
   object ob;
   if(this_player()->query_skill("perception") >= 
 			25 && found_c ==0) {
      message("info", "You search the barrels and find a torch in one "
                     "of them.",
this_player());
      message("info", this_player()->query_cap_name() +
         " searches the barrels and finds a discarded torch in one.",
          this_object(), this_player());
      ob = new(HIV_OBJ+"torch");
      ob->move(this_object());
      found_c = 1;
   }
   else {
      message("info", "You don't find anything.  This place was "
                    "stripped very efficiently.",
         this_player());
      message("info", this_player()->query_cap_name() +" searches "
                     "the barrels, but gives up after finding nothing. ",
            this_object(), this_player() );
   }
   return;
}

