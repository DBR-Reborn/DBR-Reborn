//      Wizard:  Myrddin
//      village_19.c
//      June 97

#include "../defs.h"

inherit "/std/room";

int found;

void reset(){
  ::reset();
  found = 0;
}  

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Abandoned House");
    set("long",
	"This building looks like a house.  Well, like it used to be a "
              "house before it was abandoned.  Now it just looks mostly "
              "empty except for some junk sitting on the, you got it, wood "
              "floor.\n" );
    set_smell("default", "Moving indoors finally gets you away from "
              "the smell of the smoke.  However, you can's say it smells "
              "exactly good inside here either.");
    set_listen("default", "The building is quiet.");
    set_search("floorboards", (: call_other, this_object(), "search_floorboards" :) );
    set_items(([
    ({ "junk" }) :
         "Yep, it's junk all right.  The remains of a bed frame, old "
         "clothes not even worth taking, some other crude furniture.  "
         "You get the impression that anything of value they couldn't "
         "take with them they buried in the forest before leaving.",
    ({ "clothes" }) :
         "They are old, dirty, moth eaten, and they wouldn't fit you "
         "anyway.  Trust me, you don't want them.",
    ({ "bed", "frame" }) :
         "It's made of wood all right.  It has about as much value as a "
         "couple branches nailed together.   In other words, none.",
    ({ "furniture" }) :
         "Well, it is in better shape then the bed frame, but you can't "
         "see making any money selling it.  Not that there is anyone to "
         "sell it to, unless you actually want to lug it all the way back to "
         "Akkad.",
    ({ "floor" }) :
         "It is wood, though it's actually cut into planks, unlike most "
         "of the wood items in this village.  It's still not a great "
         "construction job, however, as many of the floorboards are "
         "loose and poorly fitting.",
]));
    set_exits((["east":HIV_ROOMS+"village_10.c"])); 

}

void search_floorboards() {
  object coins;
   if(this_player()->query_skill("perception") >= 15 && found ==0) {
      message("info", "You search the loose floorboards and find some "
                    "money!",
this_player());
      message("info", this_player()->query_cap_name() +
         " searches the floorboards and finds some money!",
          this_object(), this_player());
          coins = new("/std/obj/coins");
          coins->set_money("silver",500);
          coins->move(this_object() );
found = 1;

   }
   else {
      message("info", "You don't see anything.  Be realistic, do you "
                    "think anyone would be dumb enough to hide "
                    "something under loose floorboards?",
         this_player());
      message("info", this_player()->query_cap_name() +" searches "
                     "the floorboards, but gives up after finding nothing.",
            this_object(), this_player() );
   }
   return;
}

