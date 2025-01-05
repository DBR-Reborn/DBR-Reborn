//      Wizard:  Myrddin
//      village_23.c
//      June 97

#include "../defs.h"

inherit "/std/room";

int found = 0;

void reset(){
  ::reset();
}  

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Secret Room");
    set("long",
	"You seem to have found the villages secret treasury.  "
              "Unfortunately, most of their valuables seems to be furs "
              "waiting to be shipped to market.  However, you might be "
              "able to find something else of value just sitting around, "
              "assuming some other enterprising thief hasnt beaten you "
              "too it.  A small ladder leads back up.\n" );
    set_smell("default", "The room is filled with the stench of cured "
                   "furs.");
    set_listen("default", "The building is silent.");
    set_search("furs", (: call_other, this_object(), "search_furs" :) );
    set_items(([
     ({ "furs" }) :
         "There are all kinds, such as bear, beaver and deer.  You name "
         "it, it is in here.  But it is all too heavy to take with you, and it "
         "really, really stinks.",
     ({ "ladder" }) :
         "It is made of wood, it is small, and it leads back up.",
]));
    new("d/damned/virtual/great-helm.armour")->move(this_object());
    new("d/damned/virtual/breast-plate.armour")->move(this_object());
    new(HIV_OBJ+"bsword")->move(this_object());
    new(HIV_OBJ+"bsword")->move(this_object());

    set_exits((["up":HIV_ROOMS+"village_23.c"])); 

}


void search_furs() {
  object coins;
   if(this_player()->query_skill("perception") >= 50 && found ==0) {
      message("info", "You search the furs and find some money!",
this_player());
      message("info", this_player()->query_cap_name() +
         " searches the furs and finds some money!",
          this_object(), this_player());
          coins = new("/std/obj/coins");
          coins->set_money("gold",200);
          coins->move(this_object() );
found = 1;

   }
   else {
      message("info", "You don't see anything.  Be realistic, do you "
                    "think they have anything worth hiding in those?",
         this_player());
      message("info", this_player()->query_cap_name() +" searches "
                     "the furs, but gives up after finding nothing.",
            this_object(), this_player() );
   }
   return;
}


