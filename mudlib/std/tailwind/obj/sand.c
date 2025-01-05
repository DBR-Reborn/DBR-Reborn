#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("sand");
    set_id( ({ "sand", "pile of sand"}) );
    set_short("A pile of sand");
    set_long("This pile of sand could be used for making glass items with the right skill.");
    set_weight(1);
    set_value(0);
}
