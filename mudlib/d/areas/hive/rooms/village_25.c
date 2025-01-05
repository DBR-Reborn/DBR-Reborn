//      Wizard:  Myrddin
//      village_25.c
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
    set("short", "Smithy");
    set("long",
	"This is definitely the villages smithy.  It looks as cleared "
              "out as the rest of the village.  Any weapons or equipment "
              "of value not being used by the villages defenders is long "
              "gone.  The standard large equipment of the blacksmith is "
              "still here, such as the firepit and hood, but you note that "
              "even the anvil has been taken away.  Easy to replace stuff "
              "like barrels and boxes also remain.\n" );
    set_smell("default", "Moving indoors finally gets you away from "
              "the smell of the smoke.");
    set_listen("default", "The building is silent.");
    set_search("barrels", (: call_other, this_object(), "search_barrels" :)
); 
    set_search("firepit", (: call_other, this_object(), "search_firepit" :)
); 
    set_search("scrap", (: call_other, this_object(), "search_scrap" :) ); 
    set_items(([
     ({ "barrel", "barrels" }) :
         "Three of the barrels still have liquids in them.  You note that "
         "one has water, one has salt water and the third has oil.  "
         "Apparently it has something to do with forging different kinds "
         "of implements.",
     ({ "box", "boxes" }) :
         "They look like they were used to store nails, scrap and "
         "horseshoes.",
     ({ "firepit" }) :
          "It still has a lot of burned out coal in it, but it is no longer "
          "hot at all.",
     ({ "hood" }) :
         "It is made of leather, and is used to carry smoke from the "
         "firepit outside.",
]));
    set_exits((["south":HIV_ROOMS+"village_16.c"])); 

}

void search_barrels() {
   object ob;
   if(this_player()->query_skill("perception") >= 
                              25 && found_a ==0) {
      message("info", "You search the barrels, and find a worn "
                    "sword in one.  Perhaps it can still be of some use.",
this_player());
      message("info", this_player()->query_cap_name() +
         " searches the barrels and finds a worn sword in one of them.",
          this_object(), this_player());
      ob = new("d/damned/virtual/scimitar_3.weapon");
      ob->move(this_object());
      found_a = 1;
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

void search_firepit() {
   object ob;
   if(this_player()->query_skill("perception") >= 
 			25 && found_b ==0) {
      message("info", "You search the firepit and discover a worn "
                    "spear that was used to stir the coals.",
this_player());
      message("info", this_player()->query_cap_name() +
         " searches the firepit and finds a worn spear in it.",
          this_object(), this_player());
      ob = new("d/damned/virtual/spear_3.weapon");
      ob->move(this_object());
      found_b = 1;
   }
   else {
      message("info", "You don't find anything.  This place was "
                    "stripped very efficiently.",
         this_player());
      message("info", this_player()->query_cap_name() +" searches "
                     "the firepit, but gives up after finding nothing. ",
            this_object(), this_player() );
   }
   return;
}

void search_scrap() {
   object ob;
   if(this_player()->query_skill("perception") >= 
 			25 && found_c ==0) {
      message("info", "You search the scrap pile and find a very good "
                    "dagger!  It must have been dropped in there by "
                    "accident.",
this_player());
      message("info", this_player()->query_cap_name() +
         " searches the scrap pile finds a dagger in one.",
          this_object(), this_player());
       ob = new("d/damned/virtual/dagger_6.weapon");
       ob->move(this_object());
      found_c = 1;
   }
   else {
      message("info", "You don't find anything.  This place was "
                    "stripped very efficiently.",
         this_player());
      message("info", this_player()->query_cap_name() +" searches "
                     "the scrap pile, but gives up after finding "
                     "nothing.",
            this_object(), this_player() );
   }
   return;
}


