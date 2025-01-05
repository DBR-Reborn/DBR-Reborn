//          Wizard: Delsius
//          spider_soldier
//          June 97

#include <std.h>
inherit MONSTER;

create() {
   string var;
   ::create();
   set_name("spider soldier");
   set_id(({"spider","soldier","spider soldier","arachnoid"}));
   set("race","arachnid");
   set_short("A spider soldier");
   set_long("This rather large spider is about ten times the size of "
            "your typical one.  It's equipped very nicely and appears "
            "to be searching for intruders.");
   set_level(17 + random (1));
   switch(random(2)) {
     case 0: var = "female"; break;
     case 1: var = "male"; break;
}
   set_gender(var);
   set_emotes(5, ({"The soldier paces about the room.",
                   "The soldier eyes you warily.",
                   "The soldier grins evilly."}));
   set_class("fighter");
}
