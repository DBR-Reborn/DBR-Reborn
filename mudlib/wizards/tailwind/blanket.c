#include <std.h>

inherit OBJECT;
 
void create() {
  ::create();
    set_name("blanket");
    set_id( ({ "blanket"}) );
    set_short("A comfortable Shaman blanket");
    set_long("This could keep you warm and cozy at night.");
    set_weight(1);
    set_value(0);
}
