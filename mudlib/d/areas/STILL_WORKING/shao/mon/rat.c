//  Rat
// rat.c
// Hood


#include <std.h>
inherit MONSTER;

create() {
    ::create();
   set_name("rat");
set_id("rat");
set_short("a dirty little rat");
   set_level(1);
set("long", "A disgusting little creature.\n"+
"It has red eyes and dark black fur, or at least "+
"its so dirty its fur is black at present.\n");
   set_gender("male");
   set("race", "rodent");
   set_alignment(0);
   set_wielding_limbs( ({"right paw","left paw"}) );
   set_body_type("quadruped");
   set_emotes(10,
({"The rat doesn't look like it's happy to see you.",
"The rat scurries around the floor franticly.",
     }),0 );
}

