#include <dirs.h>
#include <std.h>
#include "/wizards/shanus/defs/tara.h"
inherit OBJECT;

void create() {
  ::create();
   set_name("golden pipe");
   set_id( ({ "golden pipe", "pipe", "quest object",
     "golden_pipe_quest_object" }) );
   set_short("a golden pipe");
   set_long("A finely crafted golden pipe, it is obviously the "+
   "pride and joy of someone.  Maybe if you returned it to "+
   "that someone they would reward you.");
   set_weight(50);
   set_value(50);
}
