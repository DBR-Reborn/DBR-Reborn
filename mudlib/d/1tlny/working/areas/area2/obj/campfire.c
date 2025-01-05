// camp fire

#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("a camp fire");
    set_id( ({ "fire" }) );
    set_short("A large camp fire");
    set_long("This large camp fire is built in the middle of the "+
    "ravine floor.  It was made from various dead shrubs and branches "+
    "that now burn with bright flames.");
    set_weight(9999);
    set_value(0);
}
