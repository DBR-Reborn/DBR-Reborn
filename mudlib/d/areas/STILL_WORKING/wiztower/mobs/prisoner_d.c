// prisoner
// Wiztower
// Coded by Glitch for DBR
// 07-05-00

#include <std.h>
inherit "/std/monster";

void create() {
   ::create();
   set_name("prisoner");
   set("id", ({"prisoner", "drow"}));
   set_level(random(5));
   set_gender("male");
   set("short","A prisoner");
   set("long", "You see before you a pitifull example of a drow. He is dirty and his hair is matted with filth.");
   set("race", "drow");
   set_body_type("human");
   set_wielding_limbs("right hand");
   set_achats(30, ({
      "The prisoner begs for mercy.",
      "The prisoner says, 'I'll never tell the secret!'",
      "The prisoner flips you the bird.",
      }) );
}

void init(){
   ::init();
   add_action("ask_func", "ask");
   }

int ask_func(string str){
   if((!str) || (str != "secret")) {
     write("The prisoner says, 'What do you want to ask about?");
     say((this_player()->query_cap_name())+ " is told by the prisoner, 'What do you want to ask about?");
     return 0;
     }
   write("The prisoner states, 'The damn wizard is greedy, but can be convinced to teach.'");
   say((this_player()->query_cap_name()) + " asks about, "+str);
   return 1;
}

