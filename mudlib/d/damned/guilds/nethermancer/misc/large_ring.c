#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("circular ring");
    set_id(({ "ring", "large ring", "circular ring", "large circular ring", "lesser nexus ring" }));
    set_short("A large circular ring");
    set_long("This is a somewhat large and heavy circular ring fashioned entirely of well crafted marble. Most of the center of its top section is deeply cut into a perfectly circular shape that appears to be capable of holding a notable amount of liquid, with the ring itself serving as the borders and method of carrying it around. Many inscriptions are engraved all over this object, suggesting that it serves a ritualistic purpose of some sort.");
    set_property("nexus type", 1);
    set_weight(1000);
    set_value(50000);
    return;
}
