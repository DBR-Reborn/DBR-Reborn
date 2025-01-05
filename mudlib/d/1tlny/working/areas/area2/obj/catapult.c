// catapult

#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("a catapult");
    set_id( ({ "catapult" }) );
    set_short("a broken catapult");
    set_long("This large piece of craftsmanship has been disabled by "+
    "the Elven army.  At one time it was used to launch large rocks "+
    "at the Half-orcs.");
    set_weight(9999);
    set_value(0);
}

