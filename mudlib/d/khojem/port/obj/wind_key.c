//   TLNY2020
//   Secret to a secret room
//   for VO
 
#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("an translusent key");
    set_id( ({ "wind_key", "key", "translusent key" }) );
    set_short("translusent key");
    set_long("A translusent key.\n");
    set_weight(10);
    set_value(0);
}

