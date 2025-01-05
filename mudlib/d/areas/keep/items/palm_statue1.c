#include <std.h>

/* This is a statue of a palm which is located in the east section of the black keep. This statue serves no initial purpose other than decoration, but if a disciple immerses the holy soul in the pool of life at the other end of the keep, palm_statue2.c will replace this one. That statue contains the red gem, a vital quest item required to activate the red arcane orb on the second floor. */

inherit OBJECT;

void create() {
::create();
set_name("palm statue 1");
set("id", ({ "statue", "palm statue", "palm", "open palm", "open palm statue", "statue of an open palm" }));
set_short("A statue of an open palm");
set_long("This is a four foot tall statue of a horizontally open palm, fashioned completely of white stone. An inscription on it says 'Lidfino's offerings are recieved here by the worthy.'");
set_weight(10000000);
set_value(0);
}
