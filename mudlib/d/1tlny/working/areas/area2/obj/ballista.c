// ballista

#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("a ballista");
    set_id( ({ "ballista" }) );
    set_short("A wheeled ballista");
    set_long("You see a giant bow and arrow of sorts mounted on a "+
    "mobile platform.  This thing looks like it could do a lot of "+
    "damage if activated by trained personel.");
    set_weight(9999);
    set_value(0);
}
