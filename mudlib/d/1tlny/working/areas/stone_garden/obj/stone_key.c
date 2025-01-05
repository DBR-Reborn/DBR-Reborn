//  Wizard:  Shade Maelstorm
//  Stone caretakers hut key
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("stone key");
    set_id( ({ "stone garden key", "key" }) );
    set_short("stone key");
  set_long("A rather large, heavy stone key marked with scratches.\n");
    set_weight(20);
    set_value(0);
}

