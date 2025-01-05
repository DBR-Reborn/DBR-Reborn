//  Wizard:  Shade Maelstorm
//  Troll cleaning cloth
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("troll cloth");
    set_id( ({ "troll cloth", "cloth" }) );
    set_short("troll cloth");
  set_long("This is a very oily, dirty cloth used for cleaning. Its a wonder that it is able to clean anything.\n");
    set_weight(20);
    set_value(5);
}

