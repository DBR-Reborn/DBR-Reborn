#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("circular ring");
    set_id(({ "ring", "huge ring", "circular ring", "huge circular ring", "greater nexus ring" }));
    set_short("A huge circular ring");
    set_long("This is an extremely large and considerably heavy ring comprised completely of very rare and well finished marble. The majority of the center of its large top section is cut deep into a circle that by first glance appears to make the entire ring serve as a container for liquid. Numerous intricate inscriptions cover the entire object and look as if they were inscribed by a seasoned professional, which gives the impression that this ring serves a ritualistic purpose of a very high order.");
    set_property("nexus type", 2);
    set_weight(1050);
    set_value(75000);
    return;
}
